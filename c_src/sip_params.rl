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
