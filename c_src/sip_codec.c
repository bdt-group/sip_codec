#include "sip_parser.h"
#include <ctype.h>
#include <erl_nif.h>
#include <string.h>

#define F_LOWERCASE 0x1
#define F_UPPERCASE 0x2

#define RECURSION_LIMIT 1000

static ERL_NIF_TERM atom_ok;
static ERL_NIF_TERM atom_uri;
static ERL_NIF_TERM atom_eoh;
static ERL_NIF_TERM atom_error;
static ERL_NIF_TERM atom_more;
static ERL_NIF_TERM atom_undefined;
static ERL_NIF_TERM atom_request;
static ERL_NIF_TERM atom_response;

extern int decode_uri(size_t size, char *buf, char **err, uri_state_t *uri);
extern int decode_start_line(size_t size, char *start, char **err, char **stop,
                             start_line_state_t *sl);
extern int decode_header_line(size_t size, char *start, char **err, char **stop,
                              hdr_line_state_t *hl);
extern int decode_name_addr(size_t size, char *start, char **err, char **stop,
                            name_state_t *na, uri_state_t *uri, kv_state_t *kv);
extern int decode_cseq(size_t size, char *buf, char **err, cseq_state_t *cseq);
extern int decode_token_params(size_t size, char *start, char **err,
                               char **stop, token_state_t *tok, kv_state_t *kv);
extern int decode_mime_params(size_t size, char *start, char **err, char **stop,
                              mime_state_t *mime, kv_state_t *kv);

ERL_NIF_TERM mk_bin(ErlNifEnv *env, char *start, char *stop, int flags) {
  ERL_NIF_TERM result;
  unsigned char *buf = NULL;
  size_t i, size;

  if (stop && start) {
    if (stop >= start) {
      size = stop - start + 1;
      buf = enif_make_new_binary(env, size, &result);
      if (buf) {
        if (flags & F_LOWERCASE) {
          for (i = 0; i < size; i++)
            buf[i] = tolower(start[i]);
        } else if (flags & F_UPPERCASE) {
          for (i = 0; i < size; i++)
            buf[i] = toupper(start[i]);
        } else {
          memcpy(buf, start, size);
        }
        return result;
      }
    }
  }

  enif_make_new_binary(env, 0, &result);
  return result;
}

ERL_NIF_TERM mk_int(ErlNifEnv *env, char *start, char *stop, ERL_NIF_TERM def) {
  size_t size;

  if (stop && start) {
    if (stop >= start) {
      size = stop - start + 1;
      char tmp[size + 1];
      memcpy(tmp, start, size);
      tmp[size] = 0;
      return enif_make_int(env, atoi(tmp));
    }
  }

  return def;
}

ERL_NIF_TERM mk_kv_list(ErlNifEnv *env, size_t len, char **keys, char **vals) {
  ERL_NIF_TERM result = enif_make_list(env, 0);
  ERL_NIF_TERM key, val, kv;
  ssize_t i = 0, j = 0;

  for (i = len - 1; i >= 0; i--) {
    j = 2 * i;
    key = mk_bin(env, *(keys + j + 0), *(keys + j + 1), F_LOWERCASE);
    val = mk_bin(env, *(vals + j + 0), *(vals + j + 1), 0);
    kv = enif_make_tuple2(env, key, val);
    result = enif_make_list_cell(env, kv, result);
  }

  return result;
}

ERL_NIF_TERM mk_uri(ErlNifEnv *env, uri_state_t *uri) {
  if (uri->userinfo_complete == false) {
    uri->user_start = NULL;
    uri->user_stop = NULL;
    uri->pass_start = NULL;
    uri->pass_stop = NULL;
  }
  return enif_make_tuple8(
      env, atom_uri,
      mk_bin(env, uri->scheme_start, uri->scheme_stop, F_LOWERCASE),
      mk_bin(env, uri->user_start, uri->user_stop, 0),
      mk_bin(env, uri->pass_start, uri->pass_stop, 0),
      mk_bin(env, uri->host_start, uri->host_stop, F_LOWERCASE),
      mk_int(env, uri->port_start, uri->port_stop, atom_undefined),
      mk_kv_list(env, uri->plen, uri->pname, uri->pvalue),
      mk_kv_list(env, uri->hlen, uri->hname, uri->hvalue));
}

ERL_NIF_TERM mk_start_line(ErlNifEnv *env, start_line_state_t *sl) {
  ERL_NIF_TERM version = enif_make_tuple2(
      env, mk_int(env, sl->ver_major_start, sl->ver_major_stop, atom_undefined),
      mk_int(env, sl->ver_minor_start, sl->ver_minor_stop, atom_undefined));
  if (sl->method_start && sl->method_stop) {
    return enif_make_tuple4(
        env, atom_request, version,
        mk_bin(env, sl->method_start, sl->method_stop, F_UPPERCASE),
        mk_bin(env, sl->uri_start, sl->uri_stop, 0));
  } else {
    return enif_make_tuple4(
        env, atom_response, version,
        mk_int(env, sl->code_start, sl->code_stop, atom_undefined),
        mk_bin(env, sl->reason_start, sl->reason_stop, 0));
  }
}

ERL_NIF_TERM mk_header_line(ErlNifEnv *env, hdr_line_state_t *hl) {
  if (hl->name_start && hl->name_stop)
    return enif_make_tuple2(
        env, mk_bin(env, hl->name_start, hl->name_stop, F_LOWERCASE),
        mk_bin(env, hl->value_start, hl->value_stop, 0));
  else
    return atom_eoh;
}

ERL_NIF_TERM mk_name_addr(ErlNifEnv *env, name_state_t *na, uri_state_t *uri,
                          kv_state_t *kv) {
  if (na->name_complete == false) {
    na->name_start = NULL;
    na->name_stop = NULL;
  }
  return enif_make_tuple3(env, mk_bin(env, na->name_start, na->name_stop, 0),
                          mk_uri(env, uri),
                          mk_kv_list(env, kv->len, kv->key, kv->val));
}

static int load(ErlNifEnv *env, void **priv, ERL_NIF_TERM load_info) {
  atom_ok = enif_make_atom(env, "ok");
  atom_uri = enif_make_atom(env, "uri");
  atom_eoh = enif_make_atom(env, "eoh");
  atom_error = enif_make_atom(env, "error");
  atom_more = enif_make_atom(env, "more");
  atom_undefined = enif_make_atom(env, "undefined");
  atom_request = enif_make_atom(env, "request");
  atom_response = enif_make_atom(env, "response");

  return 0;
}

static void unload(ErlNifEnv *env, void *priv) {}

static ERL_NIF_TERM decode_uri_nif(ErlNifEnv *env, int argc,
                                   const ERL_NIF_TERM argv[]) {
  ErlNifBinary input;
  char *err;

  if (argc != 1)
    return enif_make_badarg(env);

  if (!(enif_inspect_binary(env, argv[0], &input)))
    return enif_make_badarg(env);

  uri_state_t uri = {0};

  init_uri_state(&uri, input.size);

  switch (decode_uri(input.size, (char *)input.data, &err, &uri)) {
  case R_SUCCESS:
    return enif_make_tuple2(env, atom_ok, mk_uri(env, &uri));
  default:
    return enif_make_tuple2(env, atom_error,
                            enif_make_uint(env, err - (char *)input.data));
  }
}

static ERL_NIF_TERM decode_start_line_nif(ErlNifEnv *env, int argc,
                                          const ERL_NIF_TERM argv[]) {
  ErlNifBinary input;
  char *err;

  if (argc != 1)
    return enif_make_badarg(env);

  if (!(enif_inspect_binary(env, argv[0], &input)))
    return enif_make_badarg(env);

  size_t size = input.size;
  char *start = (char *)input.data;
  char *stop;

  start_line_state_t sl = {0};

  switch (decode_start_line(size, start, &err, &stop, &sl)) {
  case R_SUCCESS:
    return enif_make_tuple3(env, atom_ok, mk_start_line(env, &sl),
                            enif_make_uint(env, stop - start));
  case R_INCOMPLETE:
    return atom_more;
  default:
    return enif_make_tuple2(env, atom_error,
                            enif_make_uint(env, err - (char *)input.data));
  }
}

static ERL_NIF_TERM decode_header_line_nif(ErlNifEnv *env, int argc,
                                           const ERL_NIF_TERM argv[]) {
  ErlNifBinary input;
  char *err;

  if (argc != 1)
    return enif_make_badarg(env);

  if (!(enif_inspect_binary(env, argv[0], &input)))
    return enif_make_badarg(env);

  size_t size = input.size;
  char *start = (char *)input.data;
  char *stop;

  hdr_line_state_t hl = {0};

  switch (decode_header_line(size, start, &err, &stop, &hl)) {
  case R_SUCCESS:
    return enif_make_tuple3(env, atom_ok, mk_header_line(env, &hl),
                            enif_make_uint(env, stop - start));
  case R_INCOMPLETE:
    return atom_more;
  default:
    return enif_make_tuple2(env, atom_error,
                            enif_make_uint(env, err - (char *)input.data));
  }
}

static ERL_NIF_TERM decode_name_addr_nif(ErlNifEnv *env, int argc,
                                         const ERL_NIF_TERM argv[]) {
  ErlNifBinary input;
  int i;
  char *err;

  if (argc != 1)
    return enif_make_badarg(env);

  if (!(enif_inspect_binary(env, argv[0], &input)))
    return enif_make_badarg(env);

  size_t size = input.size;
  char *start = (char *)input.data;
  char *stop;

  ERL_NIF_TERM list = enif_make_list(env, 0);
  ERL_NIF_TERM el;

  for (i = 0; i < RECURSION_LIMIT; i++) {
    uri_state_t uri = {0};
    kv_state_t kv = {0};
    name_state_t na = {0};

    init_kv_state(&kv, size);
    init_uri_state(&uri, size);

    if (decode_name_addr(size, start, &err, &stop, &na, &uri, &kv) ==
        R_SUCCESS) {
      el = mk_name_addr(env, &na, &uri, &kv);
      list = enif_make_list_cell(env, el, list);
      size -= stop - start;
      if (size) {
        start = stop;
      } else
        break;
    } else {
      return enif_make_tuple2(env, atom_error,
                              enif_make_uint(env, err - (char *)input.data));
    }
  }

  ERL_NIF_TERM rev_list;
  enif_make_reverse_list(env, list, &rev_list);
  return enif_make_tuple2(env, atom_ok, rev_list);
}

static ERL_NIF_TERM decode_cseq_nif(ErlNifEnv *env, int argc,
                                    const ERL_NIF_TERM argv[]) {
  ErlNifBinary input;
  char *err;

  if (argc != 1)
    return enif_make_badarg(env);

  if (!(enif_inspect_binary(env, argv[0], &input)))
    return enif_make_badarg(env);

  size_t size = input.size;
  char *buf = (char *)input.data;

  cseq_state_t cseq = {0};

  switch (decode_cseq(size, buf, &err, &cseq)) {
  case R_SUCCESS:
    return enif_make_tuple2(
        env, atom_ok,
        enif_make_tuple2(
            env, mk_int(env, cseq.n_start, cseq.n_stop, atom_undefined),
            mk_bin(env, cseq.method_start, cseq.method_stop, F_UPPERCASE)));
  default:
    return enif_make_tuple2(env, atom_error,
                            enif_make_uint(env, err - (char *)input.data));
  }
}

static ERL_NIF_TERM decode_token_params_nif(ErlNifEnv *env, int argc,
                                            const ERL_NIF_TERM argv[]) {
  ErlNifBinary input;
  int i;
  char *err;

  if (argc != 1)
    return enif_make_badarg(env);

  if (!(enif_inspect_binary(env, argv[0], &input)))
    return enif_make_badarg(env);

  size_t size = input.size;
  char *start = (char *)input.data;
  char *stop;

  ERL_NIF_TERM list = enif_make_list(env, 0);
  ERL_NIF_TERM el;

  for (i = 0; i < RECURSION_LIMIT; i++) {
    token_state_t tok = {0};
    kv_state_t kv = {0};

    init_kv_state(&kv, size);

    if (decode_token_params(size, start, &err, &stop, &tok, &kv) == R_SUCCESS) {
      el = enif_make_tuple2(
          env, mk_bin(env, tok.token_start, tok.token_stop, F_LOWERCASE),
          mk_kv_list(env, kv.len, kv.key, kv.val));
      list = enif_make_list_cell(env, el, list);
      size -= stop - start;
      if (size)
        start = stop;
      else
        break;
    } else {
      return enif_make_tuple2(env, atom_error,
                              enif_make_uint(env, err - (char *)input.data));
    }
  }

  ERL_NIF_TERM rev_list;
  enif_make_reverse_list(env, list, &rev_list);
  return enif_make_tuple2(env, atom_ok, rev_list);
}

static ERL_NIF_TERM decode_mime_params_nif(ErlNifEnv *env, int argc,
                                           const ERL_NIF_TERM argv[]) {
  ErlNifBinary input;
  int i;
  char *err;

  if (argc != 1)
    return enif_make_badarg(env);

  if (!(enif_inspect_binary(env, argv[0], &input)))
    return enif_make_badarg(env);

  size_t size = input.size;
  char *start = (char *)input.data;
  char *stop;

  ERL_NIF_TERM list = enif_make_list(env, 0);
  ERL_NIF_TERM el;

  for (i = 0; i < RECURSION_LIMIT; i++) {
    mime_state_t mime = {0};
    kv_state_t kv = {0};

    init_kv_state(&kv, size);

    if (decode_mime_params(size, start, &err, &stop, &mime, &kv) == R_SUCCESS) {
      el = enif_make_tuple2(
          env,
          enif_make_tuple2(
              env, mk_bin(env, mime.type_start, mime.type_stop, F_LOWERCASE),
              mk_bin(env, mime.subtype_start, mime.subtype_stop, F_LOWERCASE)),
          mk_kv_list(env, kv.len, kv.key, kv.val));
      list = enif_make_list_cell(env, el, list);
      size -= stop - start;
      if (size)
        start = stop;
      else
        break;
    } else {
      return enif_make_tuple2(env, atom_error,
                              enif_make_uint(env, err - (char *)input.data));
    }
  }

  ERL_NIF_TERM rev_list;
  enif_make_reverse_list(env, list, &rev_list);
  return enif_make_tuple2(env, atom_ok, rev_list);
}

static ERL_NIF_TERM tolower_nif(ErlNifEnv *env, int argc,
                                const ERL_NIF_TERM argv[]) {
  ErlNifBinary input;
  size_t i;

  if (argc != 1)
    return enif_make_badarg(env);

  if (!(enif_inspect_binary(env, argv[0], &input)))
    return enif_make_badarg(env);

  size_t size = input.size;
  char *buf = (char *)input.data;

  for (i = 0; i < size; i++)
    buf[i] = tolower(buf[i]);

  return atom_ok;
}

static ERL_NIF_TERM toupper_nif(ErlNifEnv *env, int argc,
                                const ERL_NIF_TERM argv[]) {
  ErlNifBinary input;
  size_t i;

  if (argc != 1)
    return enif_make_badarg(env);

  if (!(enif_inspect_binary(env, argv[0], &input)))
    return enif_make_badarg(env);

  size_t size = input.size;
  char *buf = (char *)input.data;

  for (i = 0; i < size; i++)
    buf[i] = toupper(buf[i]);

  return atom_ok;
}

static ErlNifFunc nif_funcs[] = {
    {"decode_uri", 1, decode_uri_nif, 0},
    {"decode_name_addr", 1, decode_name_addr_nif, 0},
    {"decode_start_line", 1, decode_start_line_nif, 0},
    {"decode_header_line", 1, decode_header_line_nif, 0},
    {"decode_cseq", 1, decode_cseq_nif, 0},
    {"decode_token_params", 1, decode_token_params_nif, 0},
    {"decode_mime_params", 1, decode_mime_params_nif, 0},
    {"tolower", 1, tolower_nif, 0},
    {"toupper", 1, toupper_nif, 0}};

ERL_NIF_INIT(sip_codec, nif_funcs, load, NULL, NULL, unload)
