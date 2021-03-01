// clang-format off
%%{
  machine sip_uri;

  include sip "sip.rl";

  action scheme_start { uri->scheme_start = p; }
  action user_start { uri->user_start = p; }
  action pass_start { uri->pass_start = p; }
  action host_start { uri->host_start = p; }
  action port_start { uri->port_start = p; }

  action scheme_stop { uri->scheme_stop = p; }
  action user_stop { uri->user_stop = p - 1; }
  action pass_stop { uri->pass_stop = p - 1; }
  action host_stop { uri->host_stop = p - 1; }
  action port_stop { uri->port_stop = p - 1; }

  action userinfo_stop { uri->userinfo_complete = true; }

  action upname_start {
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
  action upvalue_start { *(uri->pvalue + uri->pi*2 + 0) = p; }
  action upname_stop { *(uri->pname + uri->pi*2 + 1) = p - 1; }
  action upvalue_stop { *(uri->pvalue + uri->pi*2 + 1) = p - 1; }

  action hname_start {
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
  action hvalue_start { *(uri->hvalue + uri->hi*2 + 0) = p; }
  action hname_stop { *(uri->hname + uri->hi*2 + 1) = p - 1; }
  action hvalue_stop { *(uri->hvalue + uri->hi*2 + 1) = p - 1; }

  sip_scheme = "sip"i | "sips"i;
  tel_scheme = "tel"i;

  pass = password >pass_start %pass_stop;
  user_info = (user | telephone_subscriber) >user_start %user_stop;
  telephone = ("+"? phonedigit_hex+) >user_start %user_stop;

  uparam = ( pname >upname_start %upname_stop ) ( "=" ( pvalue >upvalue_start %upvalue_stop) )?;
  tparam = ( tel_pname >upname_start %upname_stop ) ( "=" ( tel_pvalue >upvalue_start %upvalue_stop) )?;

  hdr = ((hname >hname_start %hname_stop) "=" (hvalue >hvalue_start %hvalue_stop));
  hdrs = "?" hdr ( "&" hdr )*;

  sip_bare_uri = (sip_scheme >scheme_start @scheme_stop) ":"
                 (user_info ( ":" pass )? "@" $userinfo_stop)?
                 (host >host_start %host_stop)
                 (":" port >port_start %port_stop)?;

  tel_bare_uri = (tel_scheme >scheme_start @scheme_stop) ":"
                 telephone %userinfo_stop;

  sip_uri = sip_bare_uri (";" uparam?)* hdrs?;

  tel_uri = tel_bare_uri (";" tparam?)*;

  bare_uri = sip_bare_uri | tel_bare_uri;
  uri = sip_uri | tel_uri;
}%%

/*
  Local Variables:
  mode: c
  End:
*/
