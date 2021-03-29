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
// clang-format off
%%{
  machine sip_params;

  include sip "sip.rl";

  action param_start {
    if (kv->len == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(kv->key, 0, s);
      memset(kv->val, 0, s);
    }
    kv->i = kv->len;
    kv->len++;
  }

  action pname_start { *(kv->key + kv->i*2 + 0) = p; }
  action pvalue_start { *(kv->val + kv->i*2 + 0) = p; }
  action pname_stop { *(kv->key + kv->i*2 + 1) = p - 1; }
  action pvalue_stop { *(kv->val + kv->i*2 + 1) = p; }

  name = token >pname_start %pname_stop;
  value = EQUAL gen_value >pvalue_start $pvalue_stop;
  param = SEMI %param_start name value?;
}%%

/*
  Local Variables:
  mode: c
  End:
*/
