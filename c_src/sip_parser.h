#ifndef SIP_PARSER_H
#define SIP_PARSER_H

#include <stddef.h>

#define false 0
#define true 1

#define R_SUCCESS 0
#define R_INCOMPLETE 1
#define R_PARSE_ERROR 2

typedef struct {
  char *scheme_start;
  char *scheme_stop;
  char *user_start;
  char *user_stop;
  char *pass_start;
  char *pass_stop;
  char *host_start;
  char *host_stop;
  char *port_start;
  char *port_stop;
  char **pname;
  char **pvalue;
  char **hname;
  char **hvalue;
  size_t pi;
  size_t hi;
  size_t plen;
  size_t hlen;
  int userinfo_complete;
} uri_state_t;

typedef struct {
  char *method_start;
  char *method_stop;
  char *uri_start;
  char *uri_stop;
  char *code_start;
  char *code_stop;
  char *reason_start;
  char *reason_stop;
  char *ver_major_start;
  char *ver_major_stop;
  char *ver_minor_start;
  char *ver_minor_stop;
} start_line_state_t;

typedef struct {
  char *name_start;
  char *name_stop;
  char *value_start;
  char *value_stop;
} hdr_line_state_t;

typedef struct {
  char *name_start;
  char *name_stop;
  int name_complete;
} name_state_t;

typedef struct {
  char **key;
  char **val;
  size_t i;
  size_t len;
} kv_state_t;

typedef struct {
  char *n_start;
  char *n_stop;
  char *method_start;
  char *method_stop;
} cseq_state_t;

typedef struct {
  char *token_start;
  char *token_stop;
} token_state_t;

typedef struct {
  char *type_start;
  char *type_stop;
  char *subtype_start;
  char *subtype_stop;
} mime_state_t;

#define init_uri_state(uri, size)                                              \
  size_t uri_size = size * 2 * sizeof(char *);                                 \
  char *pname[uri_size];                                                       \
  char *pvalue[uri_size];                                                      \
  char *hname[uri_size];                                                       \
  char *hvalue[uri_size];                                                      \
  (uri)->pname = pname;                                                        \
  (uri)->pvalue = pvalue;                                                      \
  (uri)->hname = hname;                                                        \
  (uri)->hvalue = hvalue

#define init_kv_state(kv, size)                                                \
  size_t kv_size = size * 2 * sizeof(char *);                                  \
  char *key[kv_size];                                                          \
  char *val[kv_size];                                                          \
  (kv)->key = key;                                                             \
  (kv)->val = val;

#endif /* SIP_PARSER_H */
