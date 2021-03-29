/*    Copyright (c) 2021, Big Data Technology. All Rights Reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
#include "sip_parser.h"
#include <alloca.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// clang-format off
%%{
  machine sip_parser_uri;

  include sip_uri "sip_uri.rl";

  action parse_error { ret = R_PARSE_ERROR; *err = p; }

  main := uri $! parse_error;
}%%

%% write data;
// clang-format on

int decode_uri(size_t size, char *buf, char **err, uri_state_t *uri) {
  int cs = 0;
  int ret = R_SUCCESS;

  char *p = buf;
  char *pe = p + size;
  char *eof = pe;

  // clang-format off
  %% write init;
  %% write exec;
  // clang-format on

  return ret;
}

// clang-format off
%%{
  machine sip_parser_start_line;

  include sip_uri "sip_uri.rl";

  action method_start { sl->method_start = p; }
  action method_stop { sl->method_stop = p - 1; }
  action uri_start { sl->uri_start = p; }
  action uri_stop { sl->uri_stop = p - 1; }
  action code_start { sl->code_start = p; }
  action code_stop { sl->code_stop = p - 1; }
  action reason_start { sl->reason_start = p; }
  action reason_stop { sl->reason_stop = p; }
  action ver_major_start { sl->ver_major_start = p; }
  action ver_major_stop { sl->ver_major_stop = p - 1; }
  action ver_minor_start { sl->ver_minor_start = p; }
  action ver_minor_stop { sl->ver_minor_stop = p - 1; }
  action stop { *stop = p; goto done; }

  action parse_error { ret = R_PARSE_ERROR; *err = p; }

  method = extension_method >method_start %method_stop;
  ver_major = DIGIT+ >ver_major_start %ver_major_stop;
  ver_minor = DIGIT+ >ver_minor_start %ver_minor_stop;
  ver = "SIP" "/" ver_major "." ver_minor;
  code = extension_code >code_start %code_stop;
  reason_phrase = ( (reserved | unreserved | escaped |
                     UTF8_NONASCII | UTF8_CONT) $reason_stop
                    | SP | HTAB )*;
  reason = reason_phrase >reason_start;
  uri_string = (any -- (SP | HTAB | CR | LF))+ >uri_start %uri_stop;

  request = method SP uri_string SP ver;
  response = ver SP code SP reason;

 main := ( (request | response) CRLF any* $stop) $! parse_error;
}%%

%% write data;
// clang-format on

int decode_start_line(size_t size, char *buf, char **err, char **stop,
                      start_line_state_t *sl) {
  int cs = 0;
  int ret = R_SUCCESS;

  char *p = buf;
  char *pe = p + size;
  char *eof = pe;
  *stop = eof;

  // clang-format off
  %% write init;
  %% write exec;
  // clang-format on

done:
  if (ret && p == eof)
    return R_INCOMPLETE;

  return ret;
}

// clang-format off
%%{
  machine sip_parser_header_line;

  include sip "sip.rl";

  action name_start  { hl->name_start = p; }
  action name_stop   { hl->name_stop = p - 1; }
  action value_start { hl->value_start = p; }
  action value_stop  { hl->value_stop = p; }

  action stop        { *stop = p; goto done; }

  action parse_error { ret = R_PARSE_ERROR; *err = p; }

  hdr_name = header_name >name_start %name_stop;
  hdr_value = ( ( TEXT_UTF8char | UTF8_CONT ) $value_stop | LWS )* >value_start;
  hdr = hdr_name HCOLON hdr_value;

  eoh = CRLF any* $stop;
  hdr_line = ( hdr CRLF ) (any -- WSP)+ $stop;

 main := ( eoh | hdr_line ) $! parse_error;
}%%

%% write data;
// clang-format on

int decode_header_line(size_t size, char *buf, char **err, char **stop,
                       hdr_line_state_t *hl) {
  int cs = 0;
  int ret = R_SUCCESS;

  char *p = buf;
  char *pe = p + size;
  char *eof = pe;
  *stop = eof;

  // clang-format off
  %% write init;
  %% write exec;
  // clang-format on

done:
  if (ret && p == eof)
    return R_INCOMPLETE;

  return ret;
}

// clang-format off
%%{
  machine sip_parser_name_addr;

  include sip_uri "sip_uri.rl";
  include sip_params "sip_params.rl";

  action name_start    { na->name_start = p; }
  action name_stop     { na->name_stop = p; }
  action name_complete { na->name_complete = true; }
  action stop          { *stop = p; goto done; }
  action parse_error   { ret = R_PARSE_ERROR; *err = p; }

  display_name = ( (token $name_stop LWS)*
                   | quoted_string $name_stop ) >name_start;
  name_addr = (display_name LAQUOT >name_complete uri RAQUOT) | bare_uri;

 main := (name_addr param* (SWS "," SWS)? <: any* $stop) $! parse_error;
}%%

%% write data;
// clang-format on

int decode_name_addr(size_t size, char *buf, char **err, char **stop,
                     name_state_t *na, uri_state_t *uri, kv_state_t *kv) {
  int cs = 0;
  int ret = R_SUCCESS;

  char *p = buf;
  char *pe = p + size;
  char *eof = pe;
  *stop = eof;

  // clang-format off
  %% write init;
  %% write exec;
  // clang-format on

done:
  return ret;
}

// clang-format off
%%{
  machine sip_parser_cseq;

  include sip "sip.rl";

  action n_start { cseq->n_start = p; }
  action n_stop  { cseq->n_stop = p - 1; }
  action method_start { cseq->method_start = p; }
  action method_stop  { cseq->method_stop = p - 1; }
  action parse_error   { ret = R_PARSE_ERROR; *err = p; }

  num = (DIGIT)+ >n_start %n_stop;
  meth = extension_method >method_start %method_stop;
 main := ( num LWS meth ) $! parse_error;
}%%

%% write data;
// clang-format on

int decode_cseq(size_t size, char *buf, char **err, cseq_state_t *cseq) {
  int cs = 0;
  int ret = R_SUCCESS;

  char *p = buf;
  char *pe = p + size;
  char *eof = pe;

  // clang-format off
  %% write init;
  %% write exec;
  // clang-format on

done:
  return ret;
}

// clang-format off
%%{
  machine sip_parser_token_params;

  include sip_uri "sip_uri.rl";
  include sip_params "sip_params.rl";

  action token_start   { tok->token_start = p; }
  action token_stop    { tok->token_stop = p - 1; }
  action stop          { *stop = p; goto done; }
  action parse_error   { ret = R_PARSE_ERROR; *err = p; }

  tok = token >token_start %token_stop;
  main := (tok param* (SWS "," SWS)? <: any* $stop) $! parse_error;
}%%

%% write data;
// clang-format on

int decode_token_params(size_t size, char *buf, char **err, char **stop,
                        token_state_t *tok, kv_state_t *kv) {
  int cs = 0;
  int ret = R_SUCCESS;

  char *p = buf;
  char *pe = p + size;
  char *eof = pe;
  *stop = eof;

  // clang-format off
  %% write init;
  %% write exec;
  // clang-format on

done:
  return ret;
}

// clang-format off
%%{
  machine sip_parser_mime_params;

  include sip_uri "sip_uri.rl";
  include sip_params "sip_params.rl";

  action type_start    { mime->type_start = p; }
  action type_stop     { mime->type_stop = p - 1; }
  action subtype_start { mime->subtype_start = p; }
  action subtype_stop  { mime->subtype_stop = p - 1; }
  action stop          { *stop = p; goto done; }
  action parse_error   { ret = R_PARSE_ERROR; *err = p; }

  type = token >type_start %type_stop;
  subtype = token >subtype_start %subtype_stop;
  mime = type SLASH subtype;
  main := (mime param* (SWS "," SWS)? <: any* $stop) $! parse_error;
}%%

%% write data;
// clang-format on

int decode_mime_params(size_t size, char *buf, char **err, char **stop,
                       mime_state_t *mime, kv_state_t *kv) {
  int cs = 0;
  int ret = R_SUCCESS;

  char *p = buf;
  char *pe = p + size;
  char *eof = pe;
  *stop = eof;

  // clang-format off
  %% write init;
  %% write exec;
  // clang-format on

done:
  return ret;
}

/*
  Local Variables:
  mode: c
  End:
*/
