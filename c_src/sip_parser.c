
#line 1 "sip_parser.rl"
#include "sip_parser.h"
#include <alloca.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// clang-format off

#line 16 "sip_parser.rl"



#line 16 "sip_parser.c"
static const int sip_parser_uri_start = 1;
static const int sip_parser_uri_first_final = 154;
static const int sip_parser_uri_error = 0;

static const int sip_parser_uri_en_main = 1;


#line 19 "sip_parser.rl"
// clang-format on

int decode_uri(size_t size, char *buf, char **err, uri_state_t *uri) {
  int cs = 0;
  int ret = R_SUCCESS;

  char *p = buf;
  char *pe = p + size;
  char *eof = pe;

  // clang-format off
  
#line 37 "sip_parser.c"
	{
	cs = sip_parser_uri_start;
	}

#line 31 "sip_parser.rl"
  
#line 44 "sip_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 83: goto tr1;
		case 84: goto tr2;
		case 115: goto tr1;
		case 116: goto tr2;
	}
	goto tr0;
tr0:
#line 13 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	goto st0;
#line 62 "sip_parser.c"
st0:
cs = 0;
	goto _out;
tr1:
#line 7 "sip_uri.rl"
	{ uri->scheme_start = p; }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 74 "sip_parser.c"
	switch( (*p) ) {
		case 73: goto st3;
		case 105: goto st3;
	}
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 80: goto tr4;
		case 112: goto tr4;
	}
	goto tr0;
tr4:
#line 13 "sip_uri.rl"
	{ uri->scheme_stop = p; }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 97 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto st5;
		case 83: goto tr6;
		case 115: goto tr6;
	}
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	switch( (*p) ) {
		case 33: goto tr7;
		case 35: goto tr8;
		case 37: goto tr9;
		case 44: goto tr7;
		case 47: goto tr7;
		case 58: goto tr12;
		case 59: goto tr13;
		case 61: goto tr7;
		case 63: goto tr7;
		case 64: goto tr14;
		case 91: goto tr17;
		case 95: goto tr7;
		case 126: goto tr7;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto tr7;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr11;
		} else
			goto tr10;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto tr16;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr16;
		} else
			goto tr15;
	} else
		goto tr15;
	goto tr0;
tr7:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 152 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st6;
		case 37: goto st7;
		case 58: goto tr20;
		case 61: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 59 )
			goto st6;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st6;
	} else
		goto st6;
	goto tr0;
tr9:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 179 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st8;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st8;
	} else
		goto st8;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st6;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st6;
	} else
		goto st6;
	goto tr0;
tr12:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st9;
tr20:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 216 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr23;
		case 37: goto tr24;
		case 61: goto tr23;
		case 64: goto tr25;
		case 95: goto tr23;
		case 126: goto tr23;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto tr23;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr23;
		} else if ( (*p) >= 65 )
			goto tr23;
	} else
		goto tr23;
	goto tr0;
tr23:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 245 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st10;
		case 37: goto st11;
		case 61: goto st10;
		case 64: goto tr28;
		case 95: goto st10;
		case 126: goto st10;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st10;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st10;
		} else if ( (*p) >= 65 )
			goto st10;
	} else
		goto st10;
	goto tr0;
tr24:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 274 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st12;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st12;
	} else
		goto st12;
	goto tr0;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st10;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st10;
	} else
		goto st10;
	goto tr0;
tr14:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st13;
tr21:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st13;
tr25:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st13;
tr28:
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st13;
tr109:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st13;
tr112:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
#line 347 "sip_parser.c"
	if ( (*p) == 91 )
		goto tr17;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr30;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr31;
	} else
		goto tr31;
	goto tr0;
tr30:
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 367 "sip_parser.c"
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st31;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st40;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) == 45 )
		goto st15;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st17;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st154;
	} else
		goto st154;
	goto tr0;
tr31:
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 434 "sip_parser.c"
	switch( (*p) ) {
		case 45: goto st18;
		case 46: goto st155;
		case 58: goto tr197;
		case 59: goto tr198;
		case 63: goto tr199;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st154;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st154;
	} else
		goto st154;
	goto tr0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 45 )
		goto st18;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st154;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st154;
	} else
		goto st154;
	goto tr0;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 58: goto tr197;
		case 59: goto tr198;
		case 63: goto tr199;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st154;
	} else
		goto st154;
	goto tr0;
tr197:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 492 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr39;
	goto tr0;
tr39:
#line 11 "sip_uri.rl"
	{ uri->port_start = p; }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 504 "sip_parser.c"
	switch( (*p) ) {
		case 59: goto tr201;
		case 63: goto tr202;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st156;
	goto tr0;
tr198:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st157;
tr201:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	goto st157;
tr208:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st157;
tr212:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 532 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr203;
		case 37: goto tr204;
		case 59: goto st157;
		case 63: goto st25;
		case 93: goto tr203;
		case 95: goto tr203;
		case 126: goto tr203;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto tr203;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr203;
		} else if ( (*p) >= 65 )
			goto tr203;
	} else
		goto tr203;
	goto tr0;
tr203:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 571 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st158;
		case 37: goto st20;
		case 59: goto tr208;
		case 61: goto tr209;
		case 63: goto tr210;
		case 93: goto st158;
		case 95: goto st158;
		case 126: goto st158;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st158;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st158;
		} else if ( (*p) >= 65 )
			goto st158;
	} else
		goto st158;
	goto tr0;
tr204:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 611 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st21;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st21;
	} else
		goto st21;
	goto tr0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st158;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st158;
	} else
		goto st158;
	goto tr0;
tr209:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 642 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr42;
		case 37: goto tr43;
		case 93: goto tr42;
		case 95: goto tr42;
		case 126: goto tr42;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto tr42;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr42;
		} else if ( (*p) >= 65 )
			goto tr42;
	} else
		goto tr42;
	goto tr0;
tr42:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st159;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
#line 670 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st159;
		case 37: goto st23;
		case 59: goto tr212;
		case 63: goto tr213;
		case 93: goto st159;
		case 95: goto st159;
		case 126: goto st159;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st159;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st159;
		} else if ( (*p) >= 65 )
			goto st159;
	} else
		goto st159;
	goto tr0;
tr43:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 700 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st24;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st24;
	} else
		goto st24;
	goto tr0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st159;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st159;
	} else
		goto st159;
	goto tr0;
tr199:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st25;
tr202:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	goto st25;
tr210:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st25;
tr213:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st25;
tr216:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st25;
tr218:
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 753 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr46;
		case 36: goto tr46;
		case 37: goto tr47;
		case 63: goto tr46;
		case 93: goto tr46;
		case 95: goto tr46;
		case 126: goto tr46;
	}
	if ( (*p) < 45 ) {
		if ( 39 <= (*p) && (*p) <= 43 )
			goto tr46;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr46;
		} else if ( (*p) >= 65 )
			goto tr46;
	} else
		goto tr46;
	goto tr0;
tr46:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 792 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st26;
		case 36: goto st26;
		case 37: goto st27;
		case 61: goto tr50;
		case 63: goto st26;
		case 93: goto st26;
		case 95: goto st26;
		case 126: goto st26;
	}
	if ( (*p) < 45 ) {
		if ( 39 <= (*p) && (*p) <= 43 )
			goto st26;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st26;
		} else if ( (*p) >= 65 )
			goto st26;
	} else
		goto st26;
	goto tr0;
tr47:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 832 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st28;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st28;
	} else
		goto st28;
	goto tr0;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st26;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st26;
	} else
		goto st26;
	goto tr0;
tr50:
#line 46 "sip_uri.rl"
	{ *(uri->hname + uri->hi*2 + 1) = p - 1; }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 863 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr214;
		case 37: goto tr215;
		case 38: goto tr216;
		case 63: goto tr214;
		case 93: goto tr214;
		case 95: goto tr214;
		case 126: goto tr214;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto tr214;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr214;
		} else if ( (*p) >= 65 )
			goto tr214;
	} else
		goto tr214;
	goto tr0;
tr214:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 893 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st161;
		case 37: goto st29;
		case 38: goto tr218;
		case 63: goto st161;
		case 93: goto st161;
		case 95: goto st161;
		case 126: goto st161;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st161;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st161;
		} else if ( (*p) >= 65 )
			goto st161;
	} else
		goto st161;
	goto tr0;
tr215:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 923 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st30;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st30;
	} else
		goto st30;
	goto tr0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st161;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st161;
	} else
		goto st161;
	goto tr0;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st32;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st154;
	} else
		goto st154;
	goto tr0;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st33;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st38;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st154;
	} else
		goto st154;
	goto tr0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st35;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st36;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st162;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st154;
	} else
		goto st154;
	goto tr0;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st17;
		case 58: goto tr197;
		case 59: goto tr198;
		case 63: goto tr199;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st163;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st17;
		case 58: goto tr197;
		case 59: goto tr198;
		case 63: goto tr199;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st164;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st17;
		case 58: goto tr197;
		case 59: goto tr198;
		case 63: goto tr199;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st35;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st37;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st35;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st33;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st39;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st33;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st31;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st41;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 45: goto st15;
		case 46: goto st31;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st16;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st16;
	} else
		goto st16;
	goto tr0;
tr17:
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 1189 "sip_parser.c"
	if ( (*p) == 58 )
		goto st76;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st43;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st43;
	} else
		goto st43;
	goto tr0;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 58: goto st47;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st44;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st44;
	} else
		goto st44;
	goto tr0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	switch( (*p) ) {
		case 58: goto st47;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st45;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st45;
	} else
		goto st45;
	goto tr0;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 58: goto st47;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st46;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st46;
	} else
		goto st46;
	goto tr0;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 58: goto st47;
		case 93: goto st165;
	}
	goto tr0;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	if ( (*p) == 58 )
		goto st63;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st48;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st43;
	} else
		goto st43;
	goto tr0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 46: goto st49;
		case 58: goto st47;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st61;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st44;
	} else
		goto st44;
	goto tr0;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st50;
	goto tr0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	if ( (*p) == 46 )
		goto st51;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st59;
	goto tr0;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st52;
	goto tr0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	if ( (*p) == 46 )
		goto st53;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st57;
	goto tr0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st54;
	goto tr0;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) == 93 )
		goto st165;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st55;
	goto tr0;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	if ( (*p) == 93 )
		goto st165;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st56;
	goto tr0;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	if ( (*p) == 93 )
		goto st165;
	goto tr0;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 58: goto tr197;
		case 59: goto tr198;
		case 63: goto tr199;
	}
	goto tr0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 46 )
		goto st53;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st58;
	goto tr0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( (*p) == 46 )
		goto st53;
	goto tr0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) == 46 )
		goto st51;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st60;
	goto tr0;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 46 )
		goto st51;
	goto tr0;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 46: goto st49;
		case 58: goto st47;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st62;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st45;
	} else
		goto st45;
	goto tr0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 46: goto st49;
		case 58: goto st47;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st46;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st46;
	} else
		goto st46;
	goto tr0;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 58: goto st72;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st64;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st64;
	} else
		goto st64;
	goto tr0;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 58: goto st68;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st65;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st65;
	} else
		goto st65;
	goto tr0;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 58: goto st68;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st66;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st66;
	} else
		goto st66;
	goto tr0;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 58: goto st68;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st67;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st67;
	} else
		goto st67;
	goto tr0;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 58: goto st68;
		case 93: goto st165;
	}
	goto tr0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st69;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st64;
	} else
		goto st64;
	goto tr0;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 46: goto st49;
		case 58: goto st68;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st70;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st65;
	} else
		goto st65;
	goto tr0;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 46: goto st49;
		case 58: goto st68;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st71;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st66;
	} else
		goto st66;
	goto tr0;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 46: goto st49;
		case 58: goto st68;
		case 93: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st67;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st67;
	} else
		goto st67;
	goto tr0;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st73;
	goto tr0;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	if ( (*p) == 46 )
		goto st49;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st74;
	goto tr0;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	if ( (*p) == 46 )
		goto st49;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st75;
	goto tr0;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	if ( (*p) == 46 )
		goto st49;
	goto tr0;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	if ( (*p) == 58 )
		goto st63;
	goto tr0;
tr8:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 1627 "sip_parser.c"
	switch( (*p) ) {
		case 35: goto st77;
		case 58: goto tr20;
		case 59: goto st78;
		case 64: goto tr21;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 42 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st77;
		} else if ( (*p) >= 40 )
			goto st77;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st77;
		} else if ( (*p) >= 65 )
			goto st77;
	} else
		goto st77;
	goto tr0;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	if ( (*p) == 45 )
		goto st79;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st79;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st79;
	} else
		goto st79;
	goto tr0;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 45: goto st79;
		case 58: goto tr20;
		case 59: goto st78;
		case 61: goto st80;
		case 64: goto tr21;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st79;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st79;
	} else
		goto st79;
	goto tr0;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 33: goto st81;
		case 37: goto st82;
		case 93: goto st81;
		case 95: goto st81;
		case 126: goto st81;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st81;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st81;
		} else if ( (*p) >= 65 )
			goto st81;
	} else
		goto st81;
	goto tr0;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 33: goto st81;
		case 37: goto st82;
		case 58: goto tr105;
		case 59: goto st78;
		case 64: goto tr21;
		case 93: goto st81;
		case 95: goto st81;
		case 126: goto st81;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st81;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st81;
		} else if ( (*p) >= 65 )
			goto st81;
	} else
		goto st81;
	goto tr0;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st83;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st83;
	} else
		goto st83;
	goto tr0;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st81;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st81;
	} else
		goto st81;
	goto tr0;
tr105:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 1767 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr107;
		case 37: goto tr108;
		case 44: goto tr23;
		case 47: goto st81;
		case 58: goto tr105;
		case 59: goto st78;
		case 61: goto tr23;
		case 64: goto tr109;
		case 91: goto st81;
		case 93: goto st81;
		case 95: goto tr107;
		case 126: goto tr107;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr107;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr107;
	} else
		goto tr107;
	goto tr0;
tr107:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 1799 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st85;
		case 37: goto st86;
		case 44: goto st10;
		case 47: goto st81;
		case 58: goto tr105;
		case 59: goto st78;
		case 61: goto st10;
		case 64: goto tr112;
		case 91: goto st81;
		case 93: goto st81;
		case 95: goto st85;
		case 126: goto st85;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st85;
	} else
		goto st85;
	goto tr0;
tr108:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 1831 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st87;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st87;
	} else
		goto st87;
	goto tr0;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st85;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st85;
	} else
		goto st85;
	goto tr0;
tr10:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 1862 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 47: goto st6;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 45 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 44 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st88;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st6;
			} else if ( (*p) >= 97 )
				goto st88;
		} else
			goto st6;
	} else
		goto st88;
	goto tr0;
tr13:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 1908 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st6;
		case 37: goto st7;
		case 45: goto st90;
		case 58: goto tr20;
		case 59: goto st6;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st6;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st90;
		} else if ( (*p) >= 65 )
			goto st90;
	} else
		goto st90;
	goto tr0;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 33: goto st6;
		case 37: goto st7;
		case 45: goto st90;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st91;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st6;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st90;
		} else if ( (*p) >= 65 )
			goto st90;
	} else
		goto st90;
	goto tr0;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 33: goto st92;
		case 37: goto st93;
		case 44: goto st6;
		case 58: goto tr105;
		case 59: goto st6;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 91: goto st81;
		case 93: goto st81;
		case 95: goto st92;
		case 126: goto st92;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st92;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st92;
	} else
		goto st92;
	goto tr0;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 33: goto st92;
		case 37: goto st93;
		case 44: goto st6;
		case 58: goto tr105;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 91: goto st81;
		case 93: goto st81;
		case 95: goto st92;
		case 126: goto st92;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st92;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st92;
	} else
		goto st92;
	goto tr0;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st94;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st94;
	} else
		goto st94;
	goto tr0;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st92;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st92;
	} else
		goto st92;
	goto tr0;
tr11:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 2051 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st136;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st145;
	goto tr0;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st88;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st97;
	goto tr0;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st98;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st97;
	goto tr0;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 47: goto st6;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st88;
			} else if ( (*p) >= 43 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st166;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st167;
			} else if ( (*p) >= 97 )
				goto st166;
		} else
			goto st167;
	} else
		goto st97;
	goto tr0;
tr15:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 2228 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st99;
		case 46: goto st182;
		case 58: goto tr222;
		case 59: goto tr223;
		case 61: goto st6;
		case 63: goto tr224;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st166;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st167;
			} else if ( (*p) >= 97 )
				goto st166;
		} else
			goto st167;
	} else
		goto st166;
	goto tr0;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st99;
		case 46: goto st88;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st166;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st167;
			} else if ( (*p) >= 97 )
				goto st166;
		} else
			goto st167;
	} else
		goto st166;
	goto tr0;
tr16:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 2319 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st6;
		case 37: goto st7;
		case 45: goto st100;
		case 46: goto st168;
		case 58: goto tr222;
		case 59: goto tr226;
		case 61: goto st6;
		case 63: goto tr224;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st6;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st167;
		} else if ( (*p) >= 65 )
			goto st167;
	} else
		goto st167;
	goto tr0;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 33: goto st6;
		case 37: goto st7;
		case 45: goto st100;
		case 58: goto tr20;
		case 59: goto st6;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st6;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st167;
		} else if ( (*p) >= 65 )
			goto st167;
	} else
		goto st167;
	goto tr0;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 33: goto st6;
		case 37: goto st7;
		case 58: goto tr222;
		case 59: goto tr226;
		case 61: goto st6;
		case 63: goto tr224;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st6;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st167;
		} else if ( (*p) >= 65 )
			goto st167;
	} else
		goto st101;
	goto tr0;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 33: goto st6;
		case 37: goto st7;
		case 45: goto st102;
		case 46: goto st103;
		case 58: goto tr20;
		case 59: goto st6;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st6;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st101;
		} else if ( (*p) >= 65 )
			goto st101;
	} else
		goto st101;
	goto tr0;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 33: goto st6;
		case 37: goto st7;
		case 45: goto st102;
		case 58: goto tr20;
		case 59: goto st6;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st6;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st101;
		} else if ( (*p) >= 65 )
			goto st101;
	} else
		goto st101;
	goto tr0;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 33: goto st6;
		case 37: goto st7;
		case 58: goto tr20;
		case 59: goto st6;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st6;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st167;
		} else if ( (*p) >= 65 )
			goto st167;
	} else
		goto st101;
	goto tr0;
tr222:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 2494 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr23;
		case 37: goto tr24;
		case 61: goto tr23;
		case 64: goto tr25;
		case 95: goto tr23;
		case 126: goto tr23;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto tr23;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr23;
		} else if ( (*p) >= 65 )
			goto tr23;
	} else
		goto tr133;
	goto tr0;
tr133:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 11 "sip_uri.rl"
	{ uri->port_start = p; }
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 2525 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st10;
		case 37: goto st11;
		case 59: goto tr201;
		case 61: goto st10;
		case 63: goto tr202;
		case 64: goto tr28;
		case 95: goto st10;
		case 126: goto st10;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st10;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st10;
		} else if ( (*p) >= 65 )
			goto st10;
	} else
		goto st169;
	goto tr0;
tr226:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st170;
tr235:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st170;
tr246:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 2564 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr228;
		case 37: goto tr229;
		case 44: goto st6;
		case 58: goto tr230;
		case 59: goto st170;
		case 61: goto st6;
		case 63: goto st115;
		case 64: goto tr21;
		case 91: goto tr203;
		case 93: goto tr203;
		case 95: goto tr228;
		case 126: goto tr228;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr228;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr228;
	} else
		goto tr228;
	goto tr0;
tr228:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
#line 2605 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st171;
		case 37: goto st105;
		case 44: goto st6;
		case 58: goto tr234;
		case 59: goto tr235;
		case 61: goto tr236;
		case 63: goto tr237;
		case 64: goto tr21;
		case 91: goto st158;
		case 93: goto st158;
		case 95: goto st171;
		case 126: goto st171;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st171;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st171;
	} else
		goto st171;
	goto tr0;
tr229:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 2646 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st106;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st106;
	} else
		goto st106;
	goto tr0;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st171;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st171;
	} else
		goto st171;
	goto tr0;
tr234:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st172;
tr230:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 2692 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr238;
		case 37: goto tr239;
		case 44: goto tr23;
		case 47: goto st158;
		case 58: goto st158;
		case 59: goto tr208;
		case 61: goto tr240;
		case 63: goto tr210;
		case 64: goto tr25;
		case 91: goto st158;
		case 93: goto st158;
		case 95: goto tr238;
		case 126: goto tr238;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr238;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr238;
	} else
		goto tr238;
	goto tr0;
tr238:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 2725 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st173;
		case 37: goto st107;
		case 44: goto st10;
		case 47: goto st158;
		case 58: goto st158;
		case 59: goto tr208;
		case 61: goto tr242;
		case 63: goto tr210;
		case 64: goto tr28;
		case 91: goto st158;
		case 93: goto st158;
		case 95: goto st173;
		case 126: goto st173;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st173;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st173;
	} else
		goto st173;
	goto tr0;
tr239:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 2758 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st108;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st108;
	} else
		goto st108;
	goto tr0;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st173;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st173;
	} else
		goto st173;
	goto tr0;
tr242:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st109;
tr240:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 2795 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr138;
		case 37: goto tr139;
		case 44: goto st10;
		case 47: goto tr42;
		case 58: goto tr42;
		case 61: goto st10;
		case 64: goto tr28;
		case 91: goto tr42;
		case 93: goto tr42;
		case 95: goto tr138;
		case 126: goto tr138;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr138;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr138;
	} else
		goto tr138;
	goto tr0;
tr248:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st174;
tr138:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 2830 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st174;
		case 37: goto st110;
		case 44: goto st10;
		case 47: goto st159;
		case 58: goto st159;
		case 59: goto tr212;
		case 61: goto st10;
		case 63: goto tr213;
		case 64: goto tr28;
		case 91: goto st159;
		case 93: goto st159;
		case 95: goto st174;
		case 126: goto st174;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st174;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st174;
	} else
		goto st174;
	goto tr0;
tr249:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st110;
tr139:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 2867 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st111;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st111;
	} else
		goto st111;
	goto tr0;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st174;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st174;
	} else
		goto st174;
	goto tr0;
tr236:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 2898 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr142;
		case 37: goto tr143;
		case 44: goto st6;
		case 58: goto tr144;
		case 59: goto st6;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 91: goto tr42;
		case 93: goto tr42;
		case 95: goto tr142;
		case 126: goto tr142;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr142;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr142;
	} else
		goto tr142;
	goto tr0;
tr142:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 2930 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st175;
		case 37: goto st113;
		case 44: goto st6;
		case 58: goto tr245;
		case 59: goto tr246;
		case 61: goto st6;
		case 63: goto tr247;
		case 64: goto tr21;
		case 91: goto st159;
		case 93: goto st159;
		case 95: goto st175;
		case 126: goto st175;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st175;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st175;
	} else
		goto st175;
	goto tr0;
tr143:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 2962 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st114;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st114;
	} else
		goto st114;
	goto tr0;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st175;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st175;
	} else
		goto st175;
	goto tr0;
tr245:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st176;
tr144:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 2999 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr248;
		case 37: goto tr249;
		case 44: goto tr23;
		case 47: goto st159;
		case 58: goto st159;
		case 59: goto tr212;
		case 61: goto tr23;
		case 63: goto tr213;
		case 64: goto tr25;
		case 91: goto st159;
		case 93: goto st159;
		case 95: goto tr248;
		case 126: goto tr248;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr248;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr248;
	} else
		goto tr248;
	goto tr0;
tr224:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st115;
tr237:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st115;
tr247:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st115;
tr257:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st115;
tr260:
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 3050 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr147;
		case 37: goto tr148;
		case 38: goto st6;
		case 44: goto st6;
		case 58: goto tr149;
		case 59: goto st6;
		case 61: goto st6;
		case 64: goto tr21;
		case 91: goto tr46;
		case 93: goto tr46;
		case 95: goto tr147;
		case 126: goto tr147;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr147;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr147;
	} else
		goto tr147;
	goto tr0;
tr147:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 3091 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st116;
		case 37: goto st117;
		case 38: goto st6;
		case 44: goto st6;
		case 58: goto tr152;
		case 59: goto st6;
		case 61: goto tr153;
		case 64: goto tr21;
		case 91: goto st26;
		case 93: goto st26;
		case 95: goto st116;
		case 126: goto st116;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st116;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st116;
	} else
		goto st116;
	goto tr0;
tr148:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 3132 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st118;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st118;
	} else
		goto st118;
	goto tr0;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st116;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st116;
	} else
		goto st116;
	goto tr0;
tr152:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st119;
tr149:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 3178 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr155;
		case 37: goto tr156;
		case 38: goto tr23;
		case 44: goto tr23;
		case 47: goto st26;
		case 58: goto st26;
		case 61: goto tr157;
		case 63: goto st26;
		case 64: goto tr25;
		case 91: goto st26;
		case 93: goto st26;
		case 95: goto tr155;
		case 126: goto tr155;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr155;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr155;
	} else
		goto tr155;
	goto tr0;
tr155:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st120;
tr164:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
#line 3224 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st120;
		case 37: goto st121;
		case 38: goto st10;
		case 44: goto st10;
		case 47: goto st26;
		case 58: goto st26;
		case 61: goto tr160;
		case 63: goto st26;
		case 64: goto tr28;
		case 91: goto st26;
		case 93: goto st26;
		case 95: goto st120;
		case 126: goto st120;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st120;
	} else
		goto st120;
	goto tr0;
tr156:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st121;
tr165:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 3270 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st122;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st122;
	} else
		goto st122;
	goto tr0;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st120;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st120;
	} else
		goto st120;
	goto tr0;
tr160:
#line 46 "sip_uri.rl"
	{ *(uri->hname + uri->hi*2 + 1) = p - 1; }
	goto st177;
tr157:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 46 "sip_uri.rl"
	{ *(uri->hname + uri->hi*2 + 1) = p - 1; }
	goto st177;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
#line 3307 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr250;
		case 37: goto tr251;
		case 38: goto tr252;
		case 44: goto st10;
		case 47: goto tr214;
		case 58: goto tr214;
		case 61: goto st10;
		case 63: goto tr214;
		case 64: goto tr28;
		case 91: goto tr214;
		case 93: goto tr214;
		case 95: goto tr250;
		case 126: goto tr250;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr250;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr250;
	} else
		goto tr250;
	goto tr0;
tr262:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st178;
tr250:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 3344 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st178;
		case 37: goto st123;
		case 38: goto tr254;
		case 44: goto st10;
		case 47: goto st161;
		case 58: goto st161;
		case 61: goto st10;
		case 63: goto st161;
		case 64: goto tr28;
		case 91: goto st161;
		case 93: goto st161;
		case 95: goto st178;
		case 126: goto st178;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st178;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st178;
	} else
		goto st178;
	goto tr0;
tr263:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st123;
tr251:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 3381 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st124;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st124;
	} else
		goto st124;
	goto tr0;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st178;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st178;
	} else
		goto st178;
	goto tr0;
tr252:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st125;
tr254:
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st125;
tr264:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 3424 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr164;
		case 37: goto tr165;
		case 38: goto st10;
		case 44: goto st10;
		case 47: goto tr46;
		case 58: goto tr46;
		case 61: goto st10;
		case 63: goto tr46;
		case 64: goto tr28;
		case 91: goto tr46;
		case 93: goto tr46;
		case 95: goto tr164;
		case 126: goto tr164;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr164;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr164;
	} else
		goto tr164;
	goto tr0;
tr153:
#line 46 "sip_uri.rl"
	{ *(uri->hname + uri->hi*2 + 1) = p - 1; }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
#line 3457 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr255;
		case 37: goto tr256;
		case 38: goto tr257;
		case 44: goto st6;
		case 58: goto tr258;
		case 59: goto st6;
		case 61: goto st6;
		case 64: goto tr21;
		case 91: goto tr214;
		case 93: goto tr214;
		case 95: goto tr255;
		case 126: goto tr255;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr255;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr255;
	} else
		goto tr255;
	goto tr0;
tr255:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 3489 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st180;
		case 37: goto st126;
		case 38: goto tr260;
		case 44: goto st6;
		case 58: goto tr261;
		case 59: goto st6;
		case 61: goto st6;
		case 64: goto tr21;
		case 91: goto st161;
		case 93: goto st161;
		case 95: goto st180;
		case 126: goto st180;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st180;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st180;
	} else
		goto st180;
	goto tr0;
tr256:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 3521 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st127;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st127;
	} else
		goto st127;
	goto tr0;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st180;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st180;
	} else
		goto st180;
	goto tr0;
tr261:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st181;
tr258:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 3558 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr262;
		case 37: goto tr263;
		case 38: goto tr264;
		case 44: goto tr23;
		case 47: goto st161;
		case 58: goto st161;
		case 61: goto tr23;
		case 63: goto st161;
		case 64: goto tr25;
		case 91: goto st161;
		case 93: goto st161;
		case 95: goto tr262;
		case 126: goto tr262;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr262;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr262;
	} else
		goto tr262;
	goto tr0;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 47: goto st6;
		case 58: goto tr222;
		case 59: goto tr223;
		case 61: goto st6;
		case 63: goto tr224;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st88;
			} else if ( (*p) >= 43 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st166;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st167;
			} else if ( (*p) >= 97 )
				goto st166;
		} else
			goto st167;
	} else
		goto st97;
	goto tr0;
tr223:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st183;
tr267:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st183;
tr271:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 3643 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr228;
		case 37: goto tr229;
		case 44: goto st6;
		case 45: goto tr265;
		case 58: goto tr230;
		case 59: goto st170;
		case 61: goto st6;
		case 63: goto st115;
		case 64: goto tr21;
		case 91: goto tr203;
		case 93: goto tr203;
		case 95: goto tr228;
		case 126: goto tr228;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto tr228;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr265;
		} else if ( (*p) >= 65 )
			goto tr265;
	} else
		goto tr265;
	goto tr0;
tr265:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st184;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
#line 3688 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st171;
		case 37: goto st105;
		case 44: goto st6;
		case 45: goto st184;
		case 58: goto tr234;
		case 59: goto tr267;
		case 61: goto tr268;
		case 63: goto tr237;
		case 64: goto tr21;
		case 91: goto st158;
		case 93: goto st158;
		case 95: goto st171;
		case 126: goto st171;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st171;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st184;
		} else if ( (*p) >= 65 )
			goto st184;
	} else
		goto st184;
	goto tr0;
tr268:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 3724 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr168;
		case 37: goto tr169;
		case 44: goto st6;
		case 58: goto tr170;
		case 59: goto st6;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 91: goto tr171;
		case 93: goto tr171;
		case 95: goto tr168;
		case 126: goto tr168;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr168;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr168;
	} else
		goto tr168;
	goto tr0;
tr168:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 3756 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st185;
		case 37: goto st129;
		case 44: goto st6;
		case 58: goto tr270;
		case 59: goto tr271;
		case 61: goto st6;
		case 63: goto tr247;
		case 64: goto tr21;
		case 91: goto st188;
		case 93: goto st188;
		case 95: goto st185;
		case 126: goto st185;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st185;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st185;
	} else
		goto st185;
	goto tr0;
tr169:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st129;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
#line 3788 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st130;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st130;
	} else
		goto st130;
	goto tr0;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st185;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st185;
	} else
		goto st185;
	goto tr0;
tr270:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st186;
tr170:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 3825 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr272;
		case 37: goto tr273;
		case 44: goto tr23;
		case 47: goto st188;
		case 58: goto tr270;
		case 59: goto tr274;
		case 61: goto tr23;
		case 63: goto tr213;
		case 64: goto tr109;
		case 91: goto st188;
		case 93: goto st188;
		case 95: goto tr272;
		case 126: goto tr272;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr272;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr272;
	} else
		goto tr272;
	goto tr0;
tr272:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st187;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
#line 3858 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st187;
		case 37: goto st131;
		case 44: goto st10;
		case 47: goto st188;
		case 58: goto tr270;
		case 59: goto tr274;
		case 61: goto st10;
		case 63: goto tr213;
		case 64: goto tr112;
		case 91: goto st188;
		case 93: goto st188;
		case 95: goto st187;
		case 126: goto st187;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st187;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st187;
	} else
		goto st187;
	goto tr0;
tr273:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 3891 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st132;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st132;
	} else
		goto st132;
	goto tr0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st187;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st187;
	} else
		goto st187;
	goto tr0;
tr171:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 3922 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st188;
		case 37: goto st133;
		case 58: goto tr270;
		case 59: goto tr274;
		case 63: goto tr213;
		case 64: goto tr21;
		case 93: goto st188;
		case 95: goto st188;
		case 126: goto st188;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st188;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st188;
		} else if ( (*p) >= 65 )
			goto st188;
	} else
		goto st188;
	goto tr0;
tr178:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 3954 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st134;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st134;
	} else
		goto st134;
	goto tr0;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st188;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st188;
	} else
		goto st188;
	goto tr0;
tr279:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st189;
tr274:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 3989 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr203;
		case 37: goto tr204;
		case 45: goto tr277;
		case 58: goto tr203;
		case 59: goto st157;
		case 63: goto st25;
		case 91: goto tr203;
		case 93: goto tr203;
		case 95: goto tr203;
		case 126: goto tr203;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 46 <= (*p) && (*p) <= 47 )
				goto tr203;
		} else if ( (*p) >= 36 )
			goto tr203;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr277;
		} else if ( (*p) >= 65 )
			goto tr277;
	} else
		goto tr277;
	goto tr0;
tr277:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st190;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
#line 4034 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st158;
		case 37: goto st20;
		case 45: goto st190;
		case 58: goto tr234;
		case 59: goto tr279;
		case 61: goto tr280;
		case 63: goto tr210;
		case 64: goto tr21;
		case 91: goto st158;
		case 93: goto st158;
		case 95: goto st158;
		case 126: goto st158;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 46 <= (*p) && (*p) <= 47 )
				goto st158;
		} else if ( (*p) >= 36 )
			goto st158;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st190;
		} else if ( (*p) >= 65 )
			goto st190;
	} else
		goto st190;
	goto tr0;
tr280:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 4072 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr171;
		case 37: goto tr178;
		case 93: goto tr171;
		case 95: goto tr171;
		case 126: goto tr171;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto tr171;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr171;
		} else if ( (*p) >= 65 )
			goto tr171;
	} else
		goto tr171;
	goto tr0;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 47: goto st6;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st88;
			} else if ( (*p) >= 43 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st166;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st167;
			} else if ( (*p) >= 97 )
				goto st166;
		} else
			goto st167;
	} else
		goto st137;
	goto tr0;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st138;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st143;
	goto tr0;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 47: goto st6;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st88;
			} else if ( (*p) >= 43 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st166;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st167;
			} else if ( (*p) >= 97 )
				goto st166;
		} else
			goto st167;
	} else
		goto st139;
	goto tr0;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st140;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st141;
	goto tr0;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 47: goto st6;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st88;
			} else if ( (*p) >= 43 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st166;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st167;
			} else if ( (*p) >= 97 )
				goto st166;
		} else
			goto st167;
	} else
		goto st191;
	goto tr0;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st98;
		case 58: goto tr222;
		case 59: goto tr223;
		case 61: goto st6;
		case 63: goto tr224;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st192;
	goto tr0;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st98;
		case 58: goto tr222;
		case 59: goto tr223;
		case 61: goto st6;
		case 63: goto tr224;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st193;
	goto tr0;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st98;
		case 58: goto tr222;
		case 59: goto tr223;
		case 61: goto st6;
		case 63: goto tr224;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st97;
	goto tr0;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st140;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st142;
	goto tr0;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st140;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st97;
	goto tr0;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st138;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st144;
	goto tr0;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st138;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st97;
	goto tr0;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st136;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st146;
	goto tr0;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 33: goto st6;
		case 35: goto st77;
		case 37: goto st7;
		case 45: goto st96;
		case 46: goto st136;
		case 58: goto tr20;
		case 59: goto st89;
		case 61: goto st6;
		case 63: goto st6;
		case 64: goto tr21;
		case 95: goto st6;
		case 126: goto st6;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st6;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st6;
		} else
			goto st88;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st97;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st101;
			} else if ( (*p) >= 97 )
				goto st97;
		} else
			goto st101;
	} else
		goto st97;
	goto tr0;
tr6:
#line 13 "sip_uri.rl"
	{ uri->scheme_stop = p; }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 4694 "sip_parser.c"
	if ( (*p) == 58 )
		goto st5;
	goto tr0;
tr2:
#line 7 "sip_uri.rl"
	{ uri->scheme_start = p; }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 4706 "sip_parser.c"
	switch( (*p) ) {
		case 69: goto st149;
		case 101: goto st149;
	}
	goto tr0;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 76: goto tr190;
		case 108: goto tr190;
	}
	goto tr0;
tr190:
#line 13 "sip_uri.rl"
	{ uri->scheme_stop = p; }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 4729 "sip_parser.c"
	if ( (*p) == 58 )
		goto st194;
	goto tr0;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 35: goto tr283;
		case 59: goto tr284;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr283;
		} else if ( (*p) >= 40 )
			goto tr283;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr283;
		} else if ( (*p) >= 65 )
			goto tr283;
	} else
		goto tr283;
	goto tr0;
tr283:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 4764 "sip_parser.c"
	switch( (*p) ) {
		case 35: goto st195;
		case 59: goto tr286;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 42 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st195;
		} else if ( (*p) >= 40 )
			goto st195;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st195;
		} else if ( (*p) >= 65 )
			goto st195;
	} else
		goto st195;
	goto tr0;
tr284:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st196;
tr286:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st196;
tr290:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st196;
tr293:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 4810 "sip_parser.c"
	switch( (*p) ) {
		case 45: goto tr287;
		case 59: goto st196;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr287;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr287;
	} else
		goto tr287;
	goto tr0;
tr287:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st197;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
#line 4841 "sip_parser.c"
	switch( (*p) ) {
		case 45: goto st197;
		case 59: goto tr290;
		case 61: goto tr291;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st197;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st197;
	} else
		goto st197;
	goto tr0;
tr291:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 4864 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr192;
		case 37: goto tr193;
		case 93: goto tr192;
		case 95: goto tr192;
		case 126: goto tr192;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto tr192;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr192;
		} else if ( (*p) >= 65 )
			goto tr192;
	} else
		goto tr192;
	goto tr0;
tr192:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 4892 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st198;
		case 37: goto st152;
		case 59: goto tr293;
		case 93: goto st198;
		case 95: goto st198;
		case 126: goto st198;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st198;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st198;
		} else if ( (*p) >= 65 )
			goto st198;
	} else
		goto st198;
	goto tr0;
tr193:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 4921 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st153;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st153;
	} else
		goto st153;
	goto tr0;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st198;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st198;
	} else
		goto st198;
	goto tr0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 154: 
	case 155: 
	case 162: 
	case 163: 
	case 164: 
	case 165: 
	case 166: 
	case 167: 
	case 168: 
	case 182: 
	case 191: 
	case 192: 
	case 193: 
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	break;
	case 156: 
	case 169: 
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	break;
	case 158: 
	case 171: 
	case 172: 
	case 173: 
	case 184: 
	case 190: 
	case 197: 
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	break;
	case 159: 
	case 174: 
	case 175: 
	case 176: 
	case 185: 
	case 186: 
	case 187: 
	case 188: 
	case 198: 
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	break;
	case 161: 
	case 178: 
	case 180: 
	case 181: 
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	break;
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
	case 12: 
	case 13: 
	case 14: 
	case 15: 
	case 16: 
	case 17: 
	case 18: 
	case 19: 
	case 20: 
	case 21: 
	case 22: 
	case 23: 
	case 24: 
	case 25: 
	case 26: 
	case 27: 
	case 28: 
	case 29: 
	case 30: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
	case 37: 
	case 38: 
	case 39: 
	case 40: 
	case 41: 
	case 42: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
	case 48: 
	case 49: 
	case 50: 
	case 51: 
	case 52: 
	case 53: 
	case 54: 
	case 55: 
	case 56: 
	case 57: 
	case 58: 
	case 59: 
	case 60: 
	case 61: 
	case 62: 
	case 63: 
	case 64: 
	case 65: 
	case 66: 
	case 67: 
	case 68: 
	case 69: 
	case 70: 
	case 71: 
	case 72: 
	case 73: 
	case 74: 
	case 75: 
	case 76: 
	case 77: 
	case 78: 
	case 79: 
	case 80: 
	case 81: 
	case 82: 
	case 83: 
	case 84: 
	case 85: 
	case 86: 
	case 87: 
	case 88: 
	case 89: 
	case 90: 
	case 91: 
	case 92: 
	case 93: 
	case 94: 
	case 95: 
	case 96: 
	case 97: 
	case 98: 
	case 99: 
	case 100: 
	case 101: 
	case 102: 
	case 103: 
	case 104: 
	case 105: 
	case 106: 
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
	case 112: 
	case 113: 
	case 114: 
	case 115: 
	case 116: 
	case 117: 
	case 118: 
	case 119: 
	case 120: 
	case 121: 
	case 122: 
	case 123: 
	case 124: 
	case 125: 
	case 126: 
	case 127: 
	case 128: 
	case 129: 
	case 130: 
	case 131: 
	case 132: 
	case 133: 
	case 134: 
	case 135: 
	case 136: 
	case 137: 
	case 138: 
	case 139: 
	case 140: 
	case 141: 
	case 142: 
	case 143: 
	case 144: 
	case 145: 
	case 146: 
	case 147: 
	case 148: 
	case 149: 
	case 150: 
	case 151: 
	case 152: 
	case 153: 
#line 13 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	break;
	case 195: 
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	break;
	case 160: 
	case 177: 
	case 179: 
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	break;
	case 194: 
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	break;
#line 5375 "sip_parser.c"
	}
	}

	_out: {}
	}

#line 32 "sip_parser.rl"
  // clang-format on

  return ret;
}

// clang-format off

#line 74 "sip_parser.rl"



#line 5394 "sip_parser.c"
static const int sip_parser_start_line_start = 1;
static const int sip_parser_start_line_first_final = 34;
static const int sip_parser_start_line_error = 0;

static const int sip_parser_start_line_en_main = 1;


#line 77 "sip_parser.rl"
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
  
#line 5417 "sip_parser.c"
	{
	cs = sip_parser_start_line_start;
	}

#line 91 "sip_parser.rl"
  
#line 5424 "sip_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 33: goto tr1;
		case 37: goto tr1;
		case 39: goto tr1;
		case 83: goto tr2;
		case 126: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr1;
		} else if ( (*p) >= 42 )
			goto tr1;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr1;
		} else if ( (*p) >= 65 )
			goto tr1;
	} else
		goto tr1;
	goto tr0;
tr0:
#line 57 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	goto st0;
#line 5457 "sip_parser.c"
st0:
cs = 0;
	goto _out;
tr1:
#line 43 "sip_parser.rl"
	{ sl->method_start = p; }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 5469 "sip_parser.c"
	switch( (*p) ) {
		case 32: goto tr3;
		case 33: goto st2;
		case 37: goto st2;
		case 39: goto st2;
		case 126: goto st2;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st2;
		} else if ( (*p) >= 42 )
			goto st2;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st2;
		} else if ( (*p) >= 65 )
			goto st2;
	} else
		goto st2;
	goto tr0;
tr3:
#line 44 "sip_parser.rl"
	{ sl->method_stop = p - 1; }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 5500 "sip_parser.c"
	switch( (*p) ) {
		case 13: goto tr0;
		case 32: goto tr0;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr0;
	goto tr5;
tr5:
#line 45 "sip_parser.rl"
	{ sl->uri_start = p; }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 5516 "sip_parser.c"
	switch( (*p) ) {
		case 13: goto tr0;
		case 32: goto tr7;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto tr0;
	goto st4;
tr7:
#line 46 "sip_parser.rl"
	{ sl->uri_stop = p - 1; }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 5532 "sip_parser.c"
	if ( (*p) == 83 )
		goto st6;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 73 )
		goto st7;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 80 )
		goto st8;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 47 )
		goto st9;
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr12;
	goto tr0;
tr12:
#line 51 "sip_parser.rl"
	{ sl->ver_major_start = p; }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 5572 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr13;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st10;
	goto tr0;
tr13:
#line 52 "sip_parser.rl"
	{ sl->ver_major_stop = p - 1; }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 5586 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr15;
	goto tr0;
tr15:
#line 53 "sip_parser.rl"
	{ sl->ver_minor_start = p; }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 5598 "sip_parser.c"
	if ( (*p) == 13 )
		goto tr16;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st12;
	goto tr0;
tr16:
#line 54 "sip_parser.rl"
	{ sl->ver_minor_stop = p - 1; }
	goto st13;
tr39:
#line 49 "sip_parser.rl"
	{ sl->reason_start = p; }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
#line 5616 "sip_parser.c"
	if ( (*p) == 10 )
		goto st34;
	goto tr0;
tr51:
#line 55 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 5628 "sip_parser.c"
	goto tr51;
tr2:
#line 43 "sip_parser.rl"
	{ sl->method_start = p; }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 5638 "sip_parser.c"
	switch( (*p) ) {
		case 32: goto tr3;
		case 33: goto st2;
		case 37: goto st2;
		case 39: goto st2;
		case 73: goto st15;
		case 126: goto st2;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st2;
		} else if ( (*p) >= 42 )
			goto st2;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st2;
		} else if ( (*p) >= 65 )
			goto st2;
	} else
		goto st2;
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	switch( (*p) ) {
		case 32: goto tr3;
		case 33: goto st2;
		case 37: goto st2;
		case 39: goto st2;
		case 80: goto st16;
		case 126: goto st2;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st2;
		} else if ( (*p) >= 42 )
			goto st2;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st2;
		} else if ( (*p) >= 65 )
			goto st2;
	} else
		goto st2;
	goto tr0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 32: goto tr3;
		case 33: goto st2;
		case 37: goto st2;
		case 39: goto st2;
		case 47: goto st17;
		case 126: goto st2;
	}
	if ( (*p) < 45 ) {
		if ( 42 <= (*p) && (*p) <= 43 )
			goto st2;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st2;
		} else if ( (*p) >= 65 )
			goto st2;
	} else
		goto st2;
	goto tr0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr22;
	goto tr0;
tr22:
#line 51 "sip_parser.rl"
	{ sl->ver_major_start = p; }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 5728 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr23;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st18;
	goto tr0;
tr23:
#line 52 "sip_parser.rl"
	{ sl->ver_major_stop = p - 1; }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 5742 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr25;
	goto tr0;
tr25:
#line 53 "sip_parser.rl"
	{ sl->ver_minor_start = p; }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 5754 "sip_parser.c"
	if ( (*p) == 32 )
		goto tr26;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st20;
	goto tr0;
tr26:
#line 54 "sip_parser.rl"
	{ sl->ver_minor_stop = p - 1; }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 5768 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr28;
	goto tr0;
tr28:
#line 47 "sip_parser.rl"
	{ sl->code_start = p; }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 5780 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st23;
	goto tr0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st24;
	goto tr0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 32 )
		goto tr31;
	goto tr0;
tr31:
#line 48 "sip_parser.rl"
	{ sl->code_stop = p - 1; }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 5806 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr38;
		case 13: goto tr39;
		case 32: goto tr38;
		case 37: goto tr40;
		case 60: goto tr0;
		case 62: goto tr0;
		case 96: goto tr0;
		case 127: goto tr0;
	}
	if ( (*p) < -4 ) {
		if ( (*p) < -32 ) {
			if ( -64 <= (*p) && (*p) <= -33 )
				goto tr33;
		} else if ( (*p) > -17 ) {
			if ( (*p) > -9 ) {
				if ( -8 <= (*p) && (*p) <= -5 )
					goto tr36;
			} else if ( (*p) >= -16 )
				goto tr35;
		} else
			goto tr34;
	} else if ( (*p) > -3 ) {
		if ( (*p) < 34 ) {
			if ( -2 <= (*p) && (*p) <= 31 )
				goto tr0;
		} else if ( (*p) > 35 ) {
			if ( (*p) > 94 ) {
				if ( 123 <= (*p) && (*p) <= 125 )
					goto tr0;
			} else if ( (*p) >= 91 )
				goto tr0;
		} else
			goto tr0;
	} else
		goto tr37;
	goto tr32;
tr32:
#line 49 "sip_parser.rl"
	{ sl->reason_start = p; }
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st26;
tr38:
#line 49 "sip_parser.rl"
	{ sl->reason_start = p; }
	goto st26;
tr41:
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 5862 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st26;
		case 13: goto st13;
		case 32: goto st26;
		case 37: goto tr49;
		case 60: goto tr0;
		case 62: goto tr0;
		case 96: goto tr0;
		case 127: goto tr0;
	}
	if ( (*p) < -4 ) {
		if ( (*p) < -32 ) {
			if ( -64 <= (*p) && (*p) <= -33 )
				goto tr42;
		} else if ( (*p) > -17 ) {
			if ( (*p) > -9 ) {
				if ( -8 <= (*p) && (*p) <= -5 )
					goto tr45;
			} else if ( (*p) >= -16 )
				goto tr44;
		} else
			goto tr43;
	} else if ( (*p) > -3 ) {
		if ( (*p) < 34 ) {
			if ( -2 <= (*p) && (*p) <= 31 )
				goto tr0;
		} else if ( (*p) > 35 ) {
			if ( (*p) > 94 ) {
				if ( 123 <= (*p) && (*p) <= 125 )
					goto tr0;
			} else if ( (*p) >= 91 )
				goto tr0;
		} else
			goto tr0;
	} else
		goto tr46;
	goto tr41;
tr33:
#line 49 "sip_parser.rl"
	{ sl->reason_start = p; }
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st27;
tr42:
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 5914 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr41;
	goto tr0;
tr34:
#line 49 "sip_parser.rl"
	{ sl->reason_start = p; }
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st28;
tr43:
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 5932 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr42;
	goto tr0;
tr35:
#line 49 "sip_parser.rl"
	{ sl->reason_start = p; }
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st29;
tr44:
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 5950 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr43;
	goto tr0;
tr36:
#line 49 "sip_parser.rl"
	{ sl->reason_start = p; }
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st30;
tr45:
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 5968 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr44;
	goto tr0;
tr37:
#line 49 "sip_parser.rl"
	{ sl->reason_start = p; }
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st31;
tr46:
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 5986 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr45;
	goto tr0;
tr40:
#line 49 "sip_parser.rl"
	{ sl->reason_start = p; }
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st32;
tr49:
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 6004 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr50;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr50;
	} else
		goto tr50;
	goto tr0;
tr50:
#line 50 "sip_parser.rl"
	{ sl->reason_stop = p; }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 6022 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr41;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr41;
	} else
		goto tr41;
	goto tr0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
	case 12: 
	case 13: 
	case 14: 
	case 15: 
	case 16: 
	case 17: 
	case 18: 
	case 19: 
	case 20: 
	case 21: 
	case 22: 
	case 23: 
	case 24: 
	case 25: 
	case 26: 
	case 27: 
	case 28: 
	case 29: 
	case 30: 
	case 31: 
	case 32: 
	case 33: 
#line 57 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	break;
#line 6107 "sip_parser.c"
	}
	}

	_out: {}
	}

#line 92 "sip_parser.rl"
  // clang-format on

done:
  if (ret && p == eof)
    return R_INCOMPLETE;

  return ret;
}

// clang-format off

#line 124 "sip_parser.rl"



#line 6130 "sip_parser.c"
static const int sip_parser_header_line_start = 1;
static const int sip_parser_header_line_first_final = 17;
static const int sip_parser_header_line_error = 0;

static const int sip_parser_header_line_en_main = 1;


#line 127 "sip_parser.rl"
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
  
#line 6153 "sip_parser.c"
	{
	cs = sip_parser_header_line_start;
	}

#line 141 "sip_parser.rl"
  
#line 6160 "sip_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 13: goto st2;
		case 33: goto tr2;
		case 37: goto tr2;
		case 39: goto tr2;
		case 126: goto tr2;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr2;
		} else if ( (*p) >= 42 )
			goto tr2;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr2;
		} else if ( (*p) >= 65 )
			goto tr2;
	} else
		goto tr2;
	goto tr0;
tr0:
#line 114 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	goto st0;
#line 6193 "sip_parser.c"
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 10 )
		goto st17;
	goto tr0;
tr31:
#line 112 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 6212 "sip_parser.c"
	goto tr31;
tr2:
#line 107 "sip_parser.rl"
	{ hl->name_start = p; }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 6222 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr4;
		case 32: goto tr4;
		case 33: goto st3;
		case 37: goto st3;
		case 39: goto st3;
		case 58: goto tr6;
		case 126: goto st3;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st3;
		} else if ( (*p) >= 42 )
			goto st3;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st3;
		} else if ( (*p) >= 65 )
			goto st3;
	} else
		goto st3;
	goto tr0;
tr4:
#line 108 "sip_parser.rl"
	{ hl->name_stop = p - 1; }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 6255 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st4;
		case 32: goto st4;
		case 58: goto st5;
	}
	goto tr0;
tr6:
#line 108 "sip_parser.rl"
	{ hl->name_stop = p - 1; }
	goto st5;
tr15:
#line 109 "sip_parser.rl"
	{ hl->value_start = p; }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 6274 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr15;
		case 13: goto tr16;
		case 32: goto tr15;
		case 127: goto tr0;
	}
	if ( (*p) < -16 ) {
		if ( (*p) > -33 ) {
			if ( -32 <= (*p) && (*p) <= -17 )
				goto tr11;
		} else if ( (*p) >= -64 )
			goto tr10;
	} else if ( (*p) > -9 ) {
		if ( (*p) < -4 ) {
			if ( -8 <= (*p) && (*p) <= -5 )
				goto tr13;
		} else if ( (*p) > -3 ) {
			if ( -2 <= (*p) && (*p) <= 31 )
				goto tr0;
		} else
			goto tr14;
	} else
		goto tr12;
	goto tr9;
tr9:
#line 109 "sip_parser.rl"
	{ hl->value_start = p; }
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st6;
tr17:
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 6313 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st6;
		case 13: goto st12;
		case 32: goto st6;
		case 127: goto tr0;
	}
	if ( (*p) < -16 ) {
		if ( (*p) > -33 ) {
			if ( -32 <= (*p) && (*p) <= -17 )
				goto tr19;
		} else if ( (*p) >= -64 )
			goto tr18;
	} else if ( (*p) > -9 ) {
		if ( (*p) < -4 ) {
			if ( -8 <= (*p) && (*p) <= -5 )
				goto tr21;
		} else if ( (*p) > -3 ) {
			if ( -2 <= (*p) && (*p) <= 31 )
				goto tr0;
		} else
			goto tr22;
	} else
		goto tr20;
	goto tr17;
tr10:
#line 109 "sip_parser.rl"
	{ hl->value_start = p; }
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st7;
tr18:
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 6352 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr17;
	goto tr0;
tr11:
#line 109 "sip_parser.rl"
	{ hl->value_start = p; }
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st8;
tr19:
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 6370 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr18;
	goto tr0;
tr12:
#line 109 "sip_parser.rl"
	{ hl->value_start = p; }
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st9;
tr20:
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 6388 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr19;
	goto tr0;
tr13:
#line 109 "sip_parser.rl"
	{ hl->value_start = p; }
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st10;
tr21:
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 6406 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr20;
	goto tr0;
tr14:
#line 109 "sip_parser.rl"
	{ hl->value_start = p; }
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st11;
tr22:
#line 110 "sip_parser.rl"
	{ hl->value_stop = p; }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 6424 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr21;
	goto tr0;
tr30:
#line 109 "sip_parser.rl"
	{ hl->value_start = p; }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 6436 "sip_parser.c"
	if ( (*p) == 10 )
		goto st13;
	goto tr0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 9: goto st6;
		case 32: goto st6;
	}
	goto tr26;
tr26:
#line 112 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 6457 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr0;
		case 32: goto tr0;
	}
	goto tr26;
tr16:
#line 109 "sip_parser.rl"
	{ hl->value_start = p; }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 6471 "sip_parser.c"
	if ( (*p) == 10 )
		goto st15;
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	switch( (*p) ) {
		case 9: goto st16;
		case 32: goto st16;
	}
	goto tr26;
tr29:
#line 109 "sip_parser.rl"
	{ hl->value_start = p; }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 6492 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr29;
		case 13: goto tr30;
		case 32: goto tr29;
		case 127: goto tr0;
	}
	if ( (*p) < -16 ) {
		if ( (*p) > -33 ) {
			if ( -32 <= (*p) && (*p) <= -17 )
				goto tr11;
		} else if ( (*p) >= -64 )
			goto tr10;
	} else if ( (*p) > -9 ) {
		if ( (*p) < -4 ) {
			if ( -8 <= (*p) && (*p) <= -5 )
				goto tr13;
		} else if ( (*p) > -3 ) {
			if ( -2 <= (*p) && (*p) <= 31 )
				goto tr0;
		} else
			goto tr14;
	} else
		goto tr12;
	goto tr9;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
	case 12: 
	case 13: 
	case 14: 
	case 15: 
	case 16: 
#line 114 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	break;
#line 6559 "sip_parser.c"
	}
	}

	_out: {}
	}

#line 142 "sip_parser.rl"
  // clang-format on

done:
  if (ret && p == eof)
    return R_INCOMPLETE;

  return ret;
}

// clang-format off

#line 169 "sip_parser.rl"



#line 6582 "sip_parser.c"
static const int sip_parser_name_addr_start = 1;
static const int sip_parser_name_addr_first_final = 442;
static const int sip_parser_name_addr_error = 0;

static const int sip_parser_name_addr_en_main = 1;


#line 172 "sip_parser.rl"
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
  
#line 6605 "sip_parser.c"
	{
	cs = sip_parser_name_addr_start;
	}

#line 186 "sip_parser.rl"
  
#line 6612 "sip_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 9: goto tr1;
		case 13: goto tr2;
		case 32: goto tr1;
		case 33: goto tr3;
		case 34: goto tr4;
		case 37: goto tr3;
		case 39: goto tr3;
		case 60: goto tr5;
		case 83: goto tr6;
		case 84: goto tr7;
		case 115: goto tr6;
		case 116: goto tr7;
		case 126: goto tr3;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr3;
		} else if ( (*p) >= 42 )
			goto tr3;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr3;
		} else if ( (*p) >= 65 )
			goto tr3;
	} else
		goto tr3;
	goto tr0;
tr0:
#line 162 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	goto st0;
#line 6653 "sip_parser.c"
st0:
cs = 0;
	goto _out;
tr1:
#line 158 "sip_parser.rl"
	{ na->name_start = p; }
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
#line 160 "sip_parser.rl"
	{ na->name_complete = true; }
	goto st2;
tr8:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 6673 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr8;
		case 13: goto tr9;
		case 32: goto tr8;
		case 34: goto tr10;
		case 60: goto st19;
	}
	goto tr0;
tr2:
#line 158 "sip_parser.rl"
	{ na->name_start = p; }
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
#line 160 "sip_parser.rl"
	{ na->name_complete = true; }
	goto st3;
tr9:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 6698 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr12;
	goto tr0;
tr12:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 6710 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr13;
		case 32: goto tr13;
	}
	goto tr0;
tr13:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 6724 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr13;
		case 32: goto tr13;
		case 34: goto tr10;
		case 60: goto st19;
	}
	goto tr0;
tr4:
#line 158 "sip_parser.rl"
	{ na->name_start = p; }
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st6;
tr10:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 6746 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr10;
		case 13: goto tr19;
		case 34: goto tr20;
		case 92: goto tr21;
	}
	if ( (*p) < -16 ) {
		if ( (*p) > -33 ) {
			if ( -32 <= (*p) && (*p) <= -17 )
				goto tr15;
		} else if ( (*p) >= -64 )
			goto tr14;
	} else if ( (*p) > -9 ) {
		if ( (*p) < -4 ) {
			if ( -8 <= (*p) && (*p) <= -5 )
				goto tr17;
		} else if ( (*p) > -3 ) {
			if ( 32 <= (*p) && (*p) <= 126 )
				goto tr10;
		} else
			goto tr18;
	} else
		goto tr16;
	goto tr0;
tr14:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 6779 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr10;
	goto tr0;
tr15:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 6791 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr14;
	goto tr0;
tr16:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 6803 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr15;
	goto tr0;
tr17:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 6815 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr16;
	goto tr0;
tr18:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 6827 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr17;
	goto tr0;
tr19:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 6839 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr22;
	goto tr0;
tr22:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
#line 6851 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr10;
		case 32: goto tr10;
	}
	goto tr0;
tr20:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 6865 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr23;
		case 13: goto tr24;
		case 32: goto tr23;
		case 60: goto tr25;
	}
	goto tr0;
tr23:
#line 160 "sip_parser.rl"
	{ na->name_complete = true; }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 6881 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st15;
		case 13: goto st16;
		case 32: goto st15;
		case 60: goto st19;
	}
	goto tr0;
tr24:
#line 160 "sip_parser.rl"
	{ na->name_complete = true; }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 6897 "sip_parser.c"
	if ( (*p) == 10 )
		goto st17;
	goto tr0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 9: goto st18;
		case 32: goto st18;
	}
	goto tr0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 9: goto st18;
		case 32: goto st18;
		case 60: goto st19;
	}
	goto tr0;
tr5:
#line 158 "sip_parser.rl"
	{ na->name_start = p; }
#line 160 "sip_parser.rl"
	{ na->name_complete = true; }
	goto st19;
tr25:
#line 160 "sip_parser.rl"
	{ na->name_complete = true; }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 6934 "sip_parser.c"
	switch( (*p) ) {
		case 83: goto tr30;
		case 84: goto tr31;
		case 115: goto tr30;
		case 116: goto tr31;
	}
	goto tr0;
tr30:
#line 7 "sip_uri.rl"
	{ uri->scheme_start = p; }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 6950 "sip_parser.c"
	switch( (*p) ) {
		case 73: goto st21;
		case 105: goto st21;
	}
	goto tr0;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	switch( (*p) ) {
		case 80: goto tr33;
		case 112: goto tr33;
	}
	goto tr0;
tr33:
#line 13 "sip_uri.rl"
	{ uri->scheme_stop = p; }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 6973 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto st23;
		case 83: goto tr35;
		case 115: goto tr35;
	}
	goto tr0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 33: goto tr36;
		case 35: goto tr37;
		case 37: goto tr38;
		case 44: goto tr36;
		case 47: goto tr36;
		case 58: goto tr41;
		case 59: goto tr42;
		case 61: goto tr36;
		case 63: goto tr36;
		case 64: goto tr43;
		case 91: goto tr46;
		case 95: goto tr36;
		case 126: goto tr36;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto tr36;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr40;
		} else
			goto tr39;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto tr45;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr45;
		} else
			goto tr44;
	} else
		goto tr44;
	goto tr0;
tr36:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 7028 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st24;
		case 37: goto st25;
		case 58: goto tr49;
		case 61: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 59 )
			goto st24;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st24;
	} else
		goto st24;
	goto tr0;
tr38:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 7055 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st26;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st26;
	} else
		goto st26;
	goto tr0;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st24;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st24;
	} else
		goto st24;
	goto tr0;
tr41:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st27;
tr49:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 7092 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr52;
		case 37: goto tr53;
		case 61: goto tr52;
		case 64: goto tr54;
		case 95: goto tr52;
		case 126: goto tr52;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto tr52;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr52;
		} else if ( (*p) >= 65 )
			goto tr52;
	} else
		goto tr52;
	goto tr0;
tr52:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 7121 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st28;
		case 37: goto st29;
		case 61: goto st28;
		case 64: goto tr57;
		case 95: goto st28;
		case 126: goto st28;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st28;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st28;
		} else if ( (*p) >= 65 )
			goto st28;
	} else
		goto st28;
	goto tr0;
tr53:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 7150 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st30;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st30;
	} else
		goto st30;
	goto tr0;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st28;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st28;
	} else
		goto st28;
	goto tr0;
tr43:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st31;
tr50:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st31;
tr54:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st31;
tr57:
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st31;
tr244:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st31;
tr247:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 7223 "sip_parser.c"
	if ( (*p) == 91 )
		goto tr46;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr59;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr60;
	} else
		goto tr60;
	goto tr0;
tr59:
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 7243 "sip_parser.c"
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st124;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st136;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 45 )
		goto st33;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st35;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st36;
	} else
		goto st36;
	goto tr0;
tr60:
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 7310 "sip_parser.c"
	switch( (*p) ) {
		case 45: goto st37;
		case 46: goto st38;
		case 58: goto tr69;
		case 59: goto tr70;
		case 62: goto tr71;
		case 63: goto tr72;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st36;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st36;
	} else
		goto st36;
	goto tr0;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	if ( (*p) == 45 )
		goto st37;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st36;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st36;
	} else
		goto st36;
	goto tr0;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 58: goto tr69;
		case 59: goto tr70;
		case 62: goto tr71;
		case 63: goto tr72;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st36;
	} else
		goto st36;
	goto tr0;
tr69:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 7370 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr73;
	goto tr0;
tr73:
#line 11 "sip_uri.rl"
	{ uri->port_start = p; }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 7382 "sip_parser.c"
	switch( (*p) ) {
		case 59: goto tr75;
		case 62: goto tr76;
		case 63: goto tr77;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st40;
	goto tr0;
tr70:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st41;
tr75:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	goto st41;
tr85:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st41;
tr94:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 7411 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr78;
		case 37: goto tr79;
		case 59: goto st41;
		case 62: goto st442;
		case 63: goto st116;
		case 93: goto tr78;
		case 95: goto tr78;
		case 126: goto tr78;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto tr78;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr78;
		} else if ( (*p) >= 65 )
			goto tr78;
	} else
		goto tr78;
	goto tr0;
tr78:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 7451 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st42;
		case 37: goto st43;
		case 59: goto tr85;
		case 61: goto tr86;
		case 62: goto tr87;
		case 63: goto tr88;
		case 93: goto st42;
		case 95: goto st42;
		case 126: goto st42;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st42;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st42;
		} else if ( (*p) >= 65 )
			goto st42;
	} else
		goto st42;
	goto tr0;
tr79:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 7492 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st44;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st44;
	} else
		goto st44;
	goto tr0;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st42;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st42;
	} else
		goto st42;
	goto tr0;
tr86:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 7523 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr90;
		case 37: goto tr91;
		case 93: goto tr90;
		case 95: goto tr90;
		case 126: goto tr90;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto tr90;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr90;
		} else if ( (*p) >= 65 )
			goto tr90;
	} else
		goto tr90;
	goto tr0;
tr90:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 7551 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st46;
		case 37: goto st47;
		case 59: goto tr94;
		case 62: goto tr95;
		case 63: goto tr96;
		case 93: goto st46;
		case 95: goto st46;
		case 126: goto st46;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st46;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st46;
		} else if ( (*p) >= 65 )
			goto st46;
	} else
		goto st46;
	goto tr0;
tr91:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 7582 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st48;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st48;
	} else
		goto st48;
	goto tr0;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st46;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st46;
	} else
		goto st46;
	goto tr0;
tr391:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st442;
tr394:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st442;
tr71:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st442;
tr76:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	goto st442;
tr87:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st442;
tr95:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st442;
tr181:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st442;
tr185:
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st442;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
#line 7649 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st442;
		case 13: goto st49;
		case 32: goto st442;
		case 44: goto st445;
		case 59: goto st56;
	}
	goto tr594;
tr594:
#line 161 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st443;
tr597:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
#line 161 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st443;
tr605:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
#line 161 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st443;
tr612:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
#line 161 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st443;
tr655:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
#line 161 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st443;
tr661:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
#line 161 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 7702 "sip_parser.c"
	goto tr594;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	if ( (*p) == 10 )
		goto st50;
	goto tr0;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 9: goto st444;
		case 32: goto st444;
	}
	goto tr0;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
	switch( (*p) ) {
		case 9: goto st444;
		case 13: goto st51;
		case 32: goto st444;
		case 44: goto st445;
		case 59: goto st56;
	}
	goto tr594;
tr657:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st51;
tr663:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st51;
tr607:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st51;
tr614:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 7758 "sip_parser.c"
	if ( (*p) == 10 )
		goto st52;
	goto tr0;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 9: goto st53;
		case 32: goto st53;
	}
	goto tr0;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 9: goto st53;
		case 32: goto st53;
		case 44: goto st445;
		case 59: goto st56;
	}
	goto tr0;
tr659:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st445;
tr665:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st445;
tr608:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st445;
tr615:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	goto st445;
tr601:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st445;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
#line 7812 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st445;
		case 13: goto st54;
		case 32: goto st445;
	}
	goto tr594;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) == 10 )
		goto st55;
	goto tr0;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
	switch( (*p) ) {
		case 9: goto st446;
		case 32: goto st446;
	}
	goto tr0;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
	switch( (*p) ) {
		case 9: goto st446;
		case 32: goto st446;
	}
	goto tr594;
tr660:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st56;
tr666:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st56;
tr611:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st56;
tr617:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	goto st56;
tr602:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 7874 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 13: goto st57;
		case 32: goto st56;
		case 33: goto tr107;
		case 37: goto tr107;
		case 39: goto tr107;
		case 126: goto tr107;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr107;
		} else if ( (*p) >= 42 )
			goto tr107;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr107;
		} else if ( (*p) >= 65 )
			goto tr107;
	} else
		goto tr107;
	goto tr0;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	if ( (*p) == 10 )
		goto st58;
	goto tr0;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 9: goto st59;
		case 32: goto st59;
	}
	goto tr0;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	switch( (*p) ) {
		case 9: goto st59;
		case 32: goto st59;
		case 33: goto tr107;
		case 37: goto tr107;
		case 39: goto tr107;
		case 126: goto tr107;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr107;
		} else if ( (*p) >= 42 )
			goto tr107;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr107;
		} else if ( (*p) >= 65 )
			goto tr107;
	} else
		goto tr107;
	goto tr0;
tr107:
#line 7 "sip_params.rl"
	{
    if (kv->len == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(kv->key, 0, s);
      memset(kv->val, 0, s);
    }
    kv->i = kv->len;
    kv->len++;
  }
#line 17 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 0) = p; }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
#line 7960 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr598;
		case 13: goto tr599;
		case 32: goto tr598;
		case 33: goto st447;
		case 37: goto st447;
		case 39: goto st447;
		case 44: goto tr601;
		case 59: goto tr602;
		case 61: goto tr603;
		case 126: goto st447;
	}
	if ( (*p) < 48 ) {
		if ( 42 <= (*p) && (*p) <= 46 )
			goto st447;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st447;
		} else if ( (*p) >= 65 )
			goto st447;
	} else
		goto st447;
	goto tr597;
tr598:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 7993 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st60;
		case 13: goto st61;
		case 32: goto st60;
		case 44: goto st445;
		case 59: goto st56;
		case 61: goto st64;
	}
	goto tr0;
tr599:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 8011 "sip_parser.c"
	if ( (*p) == 10 )
		goto st62;
	goto tr0;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 9: goto st63;
		case 32: goto st63;
	}
	goto tr0;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 9: goto st63;
		case 32: goto st63;
		case 44: goto st445;
		case 59: goto st56;
		case 61: goto st64;
	}
	goto tr0;
tr115:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st64;
tr603:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 8050 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr115;
		case 13: goto tr116;
		case 32: goto tr115;
		case 33: goto tr117;
		case 34: goto tr118;
		case 37: goto tr117;
		case 39: goto tr117;
		case 91: goto tr119;
		case 126: goto tr117;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr117;
		} else if ( (*p) >= 42 )
			goto tr117;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr117;
		} else if ( (*p) >= 65 )
			goto tr117;
	} else
		goto tr117;
	goto tr0;
tr116:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 8087 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr120;
	goto tr0;
tr120:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 8099 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr121;
		case 32: goto tr121;
	}
	goto tr0;
tr122:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st67;
tr121:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 8119 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr122;
		case 13: goto tr123;
		case 32: goto tr122;
		case 33: goto tr117;
		case 34: goto tr118;
		case 37: goto tr117;
		case 39: goto tr117;
		case 91: goto tr119;
		case 126: goto tr117;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr117;
		} else if ( (*p) >= 42 )
			goto tr117;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr117;
		} else if ( (*p) >= 65 )
			goto tr117;
	} else
		goto tr117;
	goto tr0;
tr123:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 8156 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr124;
	goto tr0;
tr124:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 8168 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr125;
		case 32: goto tr125;
	}
	goto tr0;
tr125:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 8182 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr125;
		case 32: goto tr125;
		case 34: goto tr126;
	}
	goto tr0;
tr118:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st71;
tr126:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 8203 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr126;
		case 13: goto tr132;
		case 34: goto tr133;
		case 92: goto tr134;
	}
	if ( (*p) < -16 ) {
		if ( (*p) > -33 ) {
			if ( -32 <= (*p) && (*p) <= -17 )
				goto tr128;
		} else if ( (*p) >= -64 )
			goto tr127;
	} else if ( (*p) > -9 ) {
		if ( (*p) < -4 ) {
			if ( -8 <= (*p) && (*p) <= -5 )
				goto tr130;
		} else if ( (*p) > -3 ) {
			if ( 32 <= (*p) && (*p) <= 126 )
				goto tr126;
		} else
			goto tr131;
	} else
		goto tr129;
	goto tr0;
tr127:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 8236 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr126;
	goto tr0;
tr128:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 8248 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr127;
	goto tr0;
tr129:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 8260 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr128;
	goto tr0;
tr130:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 8272 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr129;
	goto tr0;
tr131:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 8284 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr130;
	goto tr0;
tr132:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 8296 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr135;
	goto tr0;
tr135:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
#line 8308 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr126;
		case 32: goto tr126;
	}
	goto tr0;
tr133:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
#line 8322 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 44: goto st445;
		case 59: goto st56;
	}
	goto tr594;
tr656:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st79;
tr662:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st79;
tr606:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st79;
tr613:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 8357 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 44: goto st445;
		case 59: goto st56;
	}
	goto tr0;
tr134:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 8374 "sip_parser.c"
	if ( (*p) < 11 ) {
		if ( 0 <= (*p) && (*p) <= 9 )
			goto tr126;
	} else if ( (*p) > 12 ) {
		if ( 14 <= (*p) )
			goto tr126;
	} else
		goto tr126;
	goto tr0;
tr117:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st449;
tr604:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 8398 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto tr604;
		case 37: goto tr604;
		case 39: goto tr604;
		case 44: goto st445;
		case 59: goto st56;
		case 126: goto tr604;
	}
	if ( (*p) < 48 ) {
		if ( 42 <= (*p) && (*p) <= 46 )
			goto tr604;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr604;
		} else if ( (*p) >= 65 )
			goto tr604;
	} else
		goto tr604;
	goto tr594;
tr119:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 8432 "sip_parser.c"
	if ( (*p) == 58 )
		goto tr139;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr138;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr138;
	} else
		goto tr138;
	goto tr0;
tr138:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 8452 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr141;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr140;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr140;
	} else
		goto tr140;
	goto tr0;
tr140:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 8474 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr141;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr142;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr142;
	} else
		goto tr142;
	goto tr0;
tr142:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 8496 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr141;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr143;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr143;
	} else
		goto tr143;
	goto tr0;
tr143:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 8518 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr141;
		case 93: goto tr133;
	}
	goto tr0;
tr141:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 8532 "sip_parser.c"
	if ( (*p) == 58 )
		goto tr145;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr144;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr138;
	} else
		goto tr138;
	goto tr0;
tr144:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 8552 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr146;
		case 58: goto tr141;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr147;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr140;
	} else
		goto tr140;
	goto tr0;
tr146:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 8575 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr148;
	goto tr0;
tr148:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 8587 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr149;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr150;
	goto tr0;
tr149:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 8601 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr151;
	goto tr0;
tr151:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 8613 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr152;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr153;
	goto tr0;
tr152:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
#line 8627 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr154;
	goto tr0;
tr154:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 8639 "sip_parser.c"
	if ( (*p) == 93 )
		goto tr133;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr155;
	goto tr0;
tr155:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
#line 8653 "sip_parser.c"
	if ( (*p) == 93 )
		goto tr133;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr156;
	goto tr0;
tr156:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 8667 "sip_parser.c"
	if ( (*p) == 93 )
		goto tr133;
	goto tr0;
tr153:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 8679 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr152;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr157;
	goto tr0;
tr157:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 8693 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr152;
	goto tr0;
tr150:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 8705 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr149;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr158;
	goto tr0;
tr158:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 8719 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr149;
	goto tr0;
tr147:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 8731 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr146;
		case 58: goto tr141;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr159;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr142;
	} else
		goto tr142;
	goto tr0;
tr159:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 8754 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr146;
		case 58: goto tr141;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr143;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr143;
	} else
		goto tr143;
	goto tr0;
tr145:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 8777 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr161;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr160;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr160;
	} else
		goto tr160;
	goto tr0;
tr160:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 8799 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr163;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr162;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr162;
	} else
		goto tr162;
	goto tr0;
tr162:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 8821 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr163;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr164;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr164;
	} else
		goto tr164;
	goto tr0;
tr164:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 8843 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr163;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr165;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr165;
	} else
		goto tr165;
	goto tr0;
tr165:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 8865 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr163;
		case 93: goto tr133;
	}
	goto tr0;
tr163:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 8879 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr166;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr160;
	} else
		goto tr160;
	goto tr0;
tr166:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 8897 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr146;
		case 58: goto tr163;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr167;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr162;
	} else
		goto tr162;
	goto tr0;
tr167:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 8920 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr146;
		case 58: goto tr163;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr168;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr164;
	} else
		goto tr164;
	goto tr0;
tr168:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 8943 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr146;
		case 58: goto tr163;
		case 93: goto tr133;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr165;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr165;
	} else
		goto tr165;
	goto tr0;
tr161:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 8966 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr169;
	goto tr0;
tr169:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 8978 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr146;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr170;
	goto tr0;
tr170:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 8992 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr146;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr171;
	goto tr0;
tr171:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 9006 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr146;
	goto tr0;
tr139:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 9018 "sip_parser.c"
	if ( (*p) == 58 )
		goto tr145;
	goto tr0;
tr72:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st116;
tr77:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	goto st116;
tr88:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st116;
tr96:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st116;
tr180:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st116;
tr184:
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 9052 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr172;
		case 36: goto tr172;
		case 37: goto tr173;
		case 63: goto tr172;
		case 93: goto tr172;
		case 95: goto tr172;
		case 126: goto tr172;
	}
	if ( (*p) < 45 ) {
		if ( 39 <= (*p) && (*p) <= 43 )
			goto tr172;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr172;
		} else if ( (*p) >= 65 )
			goto tr172;
	} else
		goto tr172;
	goto tr0;
tr172:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 9091 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st117;
		case 36: goto st117;
		case 37: goto st118;
		case 61: goto tr176;
		case 63: goto st117;
		case 93: goto st117;
		case 95: goto st117;
		case 126: goto st117;
	}
	if ( (*p) < 45 ) {
		if ( 39 <= (*p) && (*p) <= 43 )
			goto st117;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st117;
		} else if ( (*p) >= 65 )
			goto st117;
	} else
		goto st117;
	goto tr0;
tr173:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 9131 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st119;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st119;
	} else
		goto st119;
	goto tr0;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st117;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st117;
	} else
		goto st117;
	goto tr0;
tr176:
#line 46 "sip_uri.rl"
	{ *(uri->hname + uri->hi*2 + 1) = p - 1; }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
#line 9162 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr178;
		case 37: goto tr179;
		case 38: goto tr180;
		case 62: goto tr181;
		case 63: goto tr178;
		case 93: goto tr178;
		case 95: goto tr178;
		case 126: goto tr178;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto tr178;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr178;
		} else if ( (*p) >= 65 )
			goto tr178;
	} else
		goto tr178;
	goto tr0;
tr178:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 9193 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st121;
		case 37: goto st122;
		case 38: goto tr184;
		case 62: goto tr185;
		case 63: goto st121;
		case 93: goto st121;
		case 95: goto st121;
		case 126: goto st121;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st121;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st121;
		} else if ( (*p) >= 65 )
			goto st121;
	} else
		goto st121;
	goto tr0;
tr179:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 9224 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st123;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st123;
	} else
		goto st123;
	goto tr0;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st121;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st121;
	} else
		goto st121;
	goto tr0;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st125;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st36;
	} else
		goto st36;
	goto tr0;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st126;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st134;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st127;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st36;
	} else
		goto st36;
	goto tr0;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st128;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st132;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st129;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st36;
	} else
		goto st36;
	goto tr0;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st35;
		case 58: goto tr69;
		case 59: goto tr70;
		case 62: goto tr71;
		case 63: goto tr72;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st130;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st35;
		case 58: goto tr69;
		case 59: goto tr70;
		case 62: goto tr71;
		case 63: goto tr72;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st131;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st35;
		case 58: goto tr69;
		case 59: goto tr70;
		case 62: goto tr71;
		case 63: goto tr72;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st128;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st133;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st128;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st126;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st135;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st126;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st124;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st137;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 45: goto st33;
		case 46: goto st124;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st34;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st34;
	} else
		goto st34;
	goto tr0;
tr46:
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 9493 "sip_parser.c"
	if ( (*p) == 58 )
		goto st173;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st139;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st139;
	} else
		goto st139;
	goto tr0;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 58: goto st143;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st140;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st140;
	} else
		goto st140;
	goto tr0;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	switch( (*p) ) {
		case 58: goto st143;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st141;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st141;
	} else
		goto st141;
	goto tr0;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	switch( (*p) ) {
		case 58: goto st143;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st142;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st142;
	} else
		goto st142;
	goto tr0;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 58: goto st143;
		case 93: goto st153;
	}
	goto tr0;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 58 )
		goto st160;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st144;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st139;
	} else
		goto st139;
	goto tr0;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	switch( (*p) ) {
		case 46: goto st145;
		case 58: goto st143;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st158;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st140;
	} else
		goto st140;
	goto tr0;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st146;
	goto tr0;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	if ( (*p) == 46 )
		goto st147;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st156;
	goto tr0;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st148;
	goto tr0;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	if ( (*p) == 46 )
		goto st149;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st154;
	goto tr0;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st150;
	goto tr0;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	if ( (*p) == 93 )
		goto st153;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st151;
	goto tr0;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	if ( (*p) == 93 )
		goto st153;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st152;
	goto tr0;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	if ( (*p) == 93 )
		goto st153;
	goto tr0;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 58: goto tr69;
		case 59: goto tr70;
		case 62: goto tr71;
		case 63: goto tr72;
	}
	goto tr0;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	if ( (*p) == 46 )
		goto st149;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st155;
	goto tr0;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	if ( (*p) == 46 )
		goto st149;
	goto tr0;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	if ( (*p) == 46 )
		goto st147;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st157;
	goto tr0;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	if ( (*p) == 46 )
		goto st147;
	goto tr0;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 46: goto st145;
		case 58: goto st143;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st159;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st141;
	} else
		goto st141;
	goto tr0;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 46: goto st145;
		case 58: goto st143;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st142;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st142;
	} else
		goto st142;
	goto tr0;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 58: goto st169;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st161;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st161;
	} else
		goto st161;
	goto tr0;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 58: goto st165;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st162;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st162;
	} else
		goto st162;
	goto tr0;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 58: goto st165;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st163;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st163;
	} else
		goto st163;
	goto tr0;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 58: goto st165;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st164;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st164;
	} else
		goto st164;
	goto tr0;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 58: goto st165;
		case 93: goto st153;
	}
	goto tr0;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st166;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st161;
	} else
		goto st161;
	goto tr0;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	switch( (*p) ) {
		case 46: goto st145;
		case 58: goto st165;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st167;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st162;
	} else
		goto st162;
	goto tr0;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	switch( (*p) ) {
		case 46: goto st145;
		case 58: goto st165;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st168;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st163;
	} else
		goto st163;
	goto tr0;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 46: goto st145;
		case 58: goto st165;
		case 93: goto st153;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st164;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st164;
	} else
		goto st164;
	goto tr0;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st170;
	goto tr0;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	if ( (*p) == 46 )
		goto st145;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st171;
	goto tr0;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	if ( (*p) == 46 )
		goto st145;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st172;
	goto tr0;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	if ( (*p) == 46 )
		goto st145;
	goto tr0;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	if ( (*p) == 58 )
		goto st160;
	goto tr0;
tr37:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 9932 "sip_parser.c"
	switch( (*p) ) {
		case 35: goto st174;
		case 58: goto tr49;
		case 59: goto st175;
		case 64: goto tr50;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 42 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st174;
		} else if ( (*p) >= 40 )
			goto st174;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st174;
		} else if ( (*p) >= 65 )
			goto st174;
	} else
		goto st174;
	goto tr0;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	if ( (*p) == 45 )
		goto st176;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st176;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st176;
	} else
		goto st176;
	goto tr0;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 45: goto st176;
		case 58: goto tr49;
		case 59: goto st175;
		case 61: goto st177;
		case 64: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st176;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st176;
	} else
		goto st176;
	goto tr0;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 33: goto st178;
		case 37: goto st179;
		case 93: goto st178;
		case 95: goto st178;
		case 126: goto st178;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st178;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st178;
		} else if ( (*p) >= 65 )
			goto st178;
	} else
		goto st178;
	goto tr0;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 33: goto st178;
		case 37: goto st179;
		case 58: goto tr240;
		case 59: goto st175;
		case 64: goto tr50;
		case 93: goto st178;
		case 95: goto st178;
		case 126: goto st178;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st178;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st178;
		} else if ( (*p) >= 65 )
			goto st178;
	} else
		goto st178;
	goto tr0;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st180;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st180;
	} else
		goto st180;
	goto tr0;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st178;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st178;
	} else
		goto st178;
	goto tr0;
tr240:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st181;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
#line 10072 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr242;
		case 37: goto tr243;
		case 44: goto tr52;
		case 47: goto st178;
		case 58: goto tr240;
		case 59: goto st175;
		case 61: goto tr52;
		case 64: goto tr244;
		case 91: goto st178;
		case 93: goto st178;
		case 95: goto tr242;
		case 126: goto tr242;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr242;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr242;
	} else
		goto tr242;
	goto tr0;
tr242:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 10104 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st182;
		case 37: goto st183;
		case 44: goto st28;
		case 47: goto st178;
		case 58: goto tr240;
		case 59: goto st175;
		case 61: goto st28;
		case 64: goto tr247;
		case 91: goto st178;
		case 93: goto st178;
		case 95: goto st182;
		case 126: goto st182;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st182;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st182;
	} else
		goto st182;
	goto tr0;
tr243:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 10136 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st184;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st184;
	} else
		goto st184;
	goto tr0;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st182;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st182;
	} else
		goto st182;
	goto tr0;
tr39:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 10167 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 47: goto st24;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 45 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 44 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st185;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st24;
			} else if ( (*p) >= 97 )
				goto st185;
		} else
			goto st24;
	} else
		goto st185;
	goto tr0;
tr42:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 10213 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st24;
		case 37: goto st25;
		case 45: goto st187;
		case 58: goto tr49;
		case 59: goto st24;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st187;
		} else if ( (*p) >= 65 )
			goto st187;
	} else
		goto st187;
	goto tr0;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	switch( (*p) ) {
		case 33: goto st24;
		case 37: goto st25;
		case 45: goto st187;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st188;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st187;
		} else if ( (*p) >= 65 )
			goto st187;
	} else
		goto st187;
	goto tr0;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	switch( (*p) ) {
		case 33: goto st189;
		case 37: goto st190;
		case 44: goto st24;
		case 58: goto tr240;
		case 59: goto st24;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 91: goto st178;
		case 93: goto st178;
		case 95: goto st189;
		case 126: goto st189;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st189;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st189;
	} else
		goto st189;
	goto tr0;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	switch( (*p) ) {
		case 33: goto st189;
		case 37: goto st190;
		case 44: goto st24;
		case 58: goto tr240;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 91: goto st178;
		case 93: goto st178;
		case 95: goto st189;
		case 126: goto st189;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st189;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st189;
	} else
		goto st189;
	goto tr0;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st191;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st191;
	} else
		goto st191;
	goto tr0;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st189;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st189;
	} else
		goto st189;
	goto tr0;
tr40:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 10356 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st258;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st270;
	goto tr0;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st185;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st194;
	goto tr0;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st195;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st194;
	goto tr0;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 47: goto st24;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st185;
			} else if ( (*p) >= 43 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st196;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st198;
			} else if ( (*p) >= 97 )
				goto st196;
		} else
			goto st198;
	} else
		goto st194;
	goto tr0;
tr44:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 10533 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st197;
		case 46: goto st241;
		case 58: goto tr266;
		case 59: goto tr267;
		case 61: goto st24;
		case 62: goto tr71;
		case 63: goto tr268;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st196;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st198;
			} else if ( (*p) >= 97 )
				goto st196;
		} else
			goto st198;
	} else
		goto st196;
	goto tr0;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st197;
		case 46: goto st185;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st196;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st198;
			} else if ( (*p) >= 97 )
				goto st196;
		} else
			goto st198;
	} else
		goto st196;
	goto tr0;
tr45:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st198;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
#line 10625 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st24;
		case 37: goto st25;
		case 45: goto st199;
		case 46: goto st200;
		case 58: goto tr266;
		case 59: goto tr271;
		case 61: goto st24;
		case 62: goto tr71;
		case 63: goto tr268;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st198;
		} else if ( (*p) >= 65 )
			goto st198;
	} else
		goto st198;
	goto tr0;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 33: goto st24;
		case 37: goto st25;
		case 45: goto st199;
		case 58: goto tr49;
		case 59: goto st24;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st198;
		} else if ( (*p) >= 65 )
			goto st198;
	} else
		goto st198;
	goto tr0;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	switch( (*p) ) {
		case 33: goto st24;
		case 37: goto st25;
		case 58: goto tr266;
		case 59: goto tr271;
		case 61: goto st24;
		case 62: goto tr71;
		case 63: goto tr268;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st198;
		} else if ( (*p) >= 65 )
			goto st198;
	} else
		goto st201;
	goto tr0;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 33: goto st24;
		case 37: goto st25;
		case 45: goto st202;
		case 46: goto st203;
		case 58: goto tr49;
		case 59: goto st24;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st201;
		} else if ( (*p) >= 65 )
			goto st201;
	} else
		goto st201;
	goto tr0;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 33: goto st24;
		case 37: goto st25;
		case 45: goto st202;
		case 58: goto tr49;
		case 59: goto st24;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st201;
		} else if ( (*p) >= 65 )
			goto st201;
	} else
		goto st201;
	goto tr0;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 33: goto st24;
		case 37: goto st25;
		case 58: goto tr49;
		case 59: goto st24;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st198;
		} else if ( (*p) >= 65 )
			goto st198;
	} else
		goto st201;
	goto tr0;
tr266:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st204;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
#line 10802 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr52;
		case 37: goto tr53;
		case 61: goto tr52;
		case 64: goto tr54;
		case 95: goto tr52;
		case 126: goto tr52;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto tr52;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr52;
		} else if ( (*p) >= 65 )
			goto tr52;
	} else
		goto tr274;
	goto tr0;
tr274:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 11 "sip_uri.rl"
	{ uri->port_start = p; }
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 10833 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st28;
		case 37: goto st29;
		case 59: goto tr75;
		case 62: goto tr76;
		case 63: goto tr77;
		case 64: goto tr57;
		case 95: goto st28;
		case 126: goto st28;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st28;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st28;
		} else if ( (*p) >= 61 )
			goto st28;
	} else
		goto st205;
	goto tr0;
tr271:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st206;
tr284:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st206;
tr306:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
#line 10872 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr276;
		case 37: goto tr277;
		case 44: goto st24;
		case 58: goto tr278;
		case 59: goto st206;
		case 61: goto st24;
		case 62: goto st442;
		case 63: goto st223;
		case 64: goto tr50;
		case 91: goto tr78;
		case 93: goto tr78;
		case 95: goto tr276;
		case 126: goto tr276;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr276;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr276;
	} else
		goto tr276;
	goto tr0;
tr276:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
#line 10914 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st207;
		case 37: goto st208;
		case 44: goto st24;
		case 58: goto tr283;
		case 59: goto tr284;
		case 61: goto tr285;
		case 62: goto tr87;
		case 63: goto tr286;
		case 64: goto tr50;
		case 91: goto st42;
		case 93: goto st42;
		case 95: goto st207;
		case 126: goto st207;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st207;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st207;
	} else
		goto st207;
	goto tr0;
tr277:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
#line 10956 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st209;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st209;
	} else
		goto st209;
	goto tr0;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st207;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st207;
	} else
		goto st207;
	goto tr0;
tr283:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st210;
tr278:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st210;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
#line 11002 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr288;
		case 37: goto tr289;
		case 44: goto tr52;
		case 47: goto st42;
		case 58: goto st42;
		case 59: goto tr85;
		case 61: goto tr290;
		case 62: goto tr87;
		case 63: goto tr88;
		case 64: goto tr54;
		case 91: goto st42;
		case 93: goto st42;
		case 95: goto tr288;
		case 126: goto tr288;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr288;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr288;
	} else
		goto tr288;
	goto tr0;
tr288:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 11036 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st211;
		case 37: goto st212;
		case 44: goto st28;
		case 47: goto st42;
		case 58: goto st42;
		case 59: goto tr85;
		case 61: goto tr293;
		case 62: goto tr87;
		case 63: goto tr88;
		case 64: goto tr57;
		case 91: goto st42;
		case 93: goto st42;
		case 95: goto st211;
		case 126: goto st211;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st211;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st211;
	} else
		goto st211;
	goto tr0;
tr289:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 11070 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st213;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st213;
	} else
		goto st213;
	goto tr0;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st211;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st211;
	} else
		goto st211;
	goto tr0;
tr293:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st214;
tr290:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
#line 11107 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr295;
		case 37: goto tr296;
		case 44: goto st28;
		case 47: goto tr90;
		case 58: goto tr90;
		case 61: goto st28;
		case 64: goto tr57;
		case 91: goto tr90;
		case 93: goto tr90;
		case 95: goto tr295;
		case 126: goto tr295;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr295;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr295;
	} else
		goto tr295;
	goto tr0;
tr309:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st215;
tr295:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
#line 11142 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st215;
		case 37: goto st216;
		case 44: goto st28;
		case 47: goto st46;
		case 58: goto st46;
		case 59: goto tr94;
		case 61: goto st28;
		case 62: goto tr95;
		case 63: goto tr96;
		case 64: goto tr57;
		case 91: goto st46;
		case 93: goto st46;
		case 95: goto st215;
		case 126: goto st215;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st215;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st215;
	} else
		goto st215;
	goto tr0;
tr310:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st216;
tr296:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 11180 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st217;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st217;
	} else
		goto st217;
	goto tr0;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st215;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st215;
	} else
		goto st215;
	goto tr0;
tr285:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
#line 11211 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr300;
		case 37: goto tr301;
		case 44: goto st24;
		case 58: goto tr302;
		case 59: goto st24;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 91: goto tr90;
		case 93: goto tr90;
		case 95: goto tr300;
		case 126: goto tr300;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr300;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr300;
	} else
		goto tr300;
	goto tr0;
tr300:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st219;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
#line 11243 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st219;
		case 37: goto st220;
		case 44: goto st24;
		case 58: goto tr305;
		case 59: goto tr306;
		case 61: goto st24;
		case 62: goto tr95;
		case 63: goto tr307;
		case 64: goto tr50;
		case 91: goto st46;
		case 93: goto st46;
		case 95: goto st219;
		case 126: goto st219;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st219;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st219;
	} else
		goto st219;
	goto tr0;
tr301:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st220;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
#line 11276 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st221;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st221;
	} else
		goto st221;
	goto tr0;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st219;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st219;
	} else
		goto st219;
	goto tr0;
tr305:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st222;
tr302:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 11313 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr309;
		case 37: goto tr310;
		case 44: goto tr52;
		case 47: goto st46;
		case 58: goto st46;
		case 59: goto tr94;
		case 61: goto tr52;
		case 62: goto tr95;
		case 63: goto tr96;
		case 64: goto tr54;
		case 91: goto st46;
		case 93: goto st46;
		case 95: goto tr309;
		case 126: goto tr309;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr309;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr309;
	} else
		goto tr309;
	goto tr0;
tr268:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st223;
tr286:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st223;
tr307:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st223;
tr337:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st223;
tr341:
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st223;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
#line 11365 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr311;
		case 37: goto tr312;
		case 38: goto st24;
		case 44: goto st24;
		case 58: goto tr313;
		case 59: goto st24;
		case 61: goto st24;
		case 64: goto tr50;
		case 91: goto tr172;
		case 93: goto tr172;
		case 95: goto tr311;
		case 126: goto tr311;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr311;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr311;
	} else
		goto tr311;
	goto tr0;
tr311:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st224;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
#line 11406 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st224;
		case 37: goto st225;
		case 38: goto st24;
		case 44: goto st24;
		case 58: goto tr316;
		case 59: goto st24;
		case 61: goto tr317;
		case 64: goto tr50;
		case 91: goto st117;
		case 93: goto st117;
		case 95: goto st224;
		case 126: goto st224;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st224;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st224;
	} else
		goto st224;
	goto tr0;
tr312:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 11447 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st226;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st226;
	} else
		goto st226;
	goto tr0;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st224;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st224;
	} else
		goto st224;
	goto tr0;
tr316:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st227;
tr313:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 11493 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr319;
		case 37: goto tr320;
		case 38: goto tr52;
		case 44: goto tr52;
		case 47: goto st117;
		case 58: goto st117;
		case 61: goto tr321;
		case 63: goto st117;
		case 64: goto tr54;
		case 91: goto st117;
		case 93: goto st117;
		case 95: goto tr319;
		case 126: goto tr319;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr319;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr319;
	} else
		goto tr319;
	goto tr0;
tr319:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st228;
tr333:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st228;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
#line 11539 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st228;
		case 37: goto st229;
		case 38: goto st28;
		case 44: goto st28;
		case 47: goto st117;
		case 58: goto st117;
		case 61: goto tr324;
		case 63: goto st117;
		case 64: goto tr57;
		case 91: goto st117;
		case 93: goto st117;
		case 95: goto st228;
		case 126: goto st228;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st228;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st228;
	} else
		goto st228;
	goto tr0;
tr320:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st229;
tr334:
#line 35 "sip_uri.rl"
	{
    if (uri->hlen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->hname, 0, s);
      memset(uri->hvalue, 0, s);
    }
    uri->hi = uri->hlen;
    uri->hlen++;
    *(uri->hname + uri->hi*2 + 0) = p;
  }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 11585 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st230;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st230;
	} else
		goto st230;
	goto tr0;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st228;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st228;
	} else
		goto st228;
	goto tr0;
tr324:
#line 46 "sip_uri.rl"
	{ *(uri->hname + uri->hi*2 + 1) = p - 1; }
	goto st231;
tr321:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 46 "sip_uri.rl"
	{ *(uri->hname + uri->hi*2 + 1) = p - 1; }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 11622 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr326;
		case 37: goto tr327;
		case 38: goto tr328;
		case 44: goto st28;
		case 47: goto tr178;
		case 58: goto tr178;
		case 61: goto st28;
		case 62: goto tr181;
		case 63: goto tr178;
		case 64: goto tr57;
		case 91: goto tr178;
		case 93: goto tr178;
		case 95: goto tr326;
		case 126: goto tr326;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr326;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr326;
	} else
		goto tr326;
	goto tr0;
tr344:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st232;
tr326:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 11660 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st232;
		case 37: goto st233;
		case 38: goto tr331;
		case 44: goto st28;
		case 47: goto st121;
		case 58: goto st121;
		case 61: goto st28;
		case 62: goto tr185;
		case 63: goto st121;
		case 64: goto tr57;
		case 91: goto st121;
		case 93: goto st121;
		case 95: goto st232;
		case 126: goto st232;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st232;
	} else
		goto st232;
	goto tr0;
tr345:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st233;
tr327:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 11698 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st234;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st234;
	} else
		goto st234;
	goto tr0;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st232;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st232;
	} else
		goto st232;
	goto tr0;
tr328:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st235;
tr331:
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st235;
tr346:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 47 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 1) = p - 1; }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 11741 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr333;
		case 37: goto tr334;
		case 38: goto st28;
		case 44: goto st28;
		case 47: goto tr172;
		case 58: goto tr172;
		case 61: goto st28;
		case 63: goto tr172;
		case 64: goto tr57;
		case 91: goto tr172;
		case 93: goto tr172;
		case 95: goto tr333;
		case 126: goto tr333;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr333;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr333;
	} else
		goto tr333;
	goto tr0;
tr317:
#line 46 "sip_uri.rl"
	{ *(uri->hname + uri->hi*2 + 1) = p - 1; }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 11774 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr335;
		case 37: goto tr336;
		case 38: goto tr337;
		case 44: goto st24;
		case 58: goto tr338;
		case 59: goto st24;
		case 61: goto st24;
		case 62: goto tr181;
		case 64: goto tr50;
		case 91: goto tr178;
		case 93: goto tr178;
		case 95: goto tr335;
		case 126: goto tr335;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr335;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr335;
	} else
		goto tr335;
	goto tr0;
tr335:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st237;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
#line 11807 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st237;
		case 37: goto st238;
		case 38: goto tr341;
		case 44: goto st24;
		case 58: goto tr342;
		case 59: goto st24;
		case 61: goto st24;
		case 62: goto tr185;
		case 64: goto tr50;
		case 91: goto st121;
		case 93: goto st121;
		case 95: goto st237;
		case 126: goto st237;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st237;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st237;
	} else
		goto st237;
	goto tr0;
tr336:
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 11840 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st239;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st239;
	} else
		goto st239;
	goto tr0;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st237;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st237;
	} else
		goto st237;
	goto tr0;
tr342:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st240;
tr338:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 45 "sip_uri.rl"
	{ *(uri->hvalue + uri->hi*2 + 0) = p; }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
#line 11877 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr344;
		case 37: goto tr345;
		case 38: goto tr346;
		case 44: goto tr52;
		case 47: goto st121;
		case 58: goto st121;
		case 61: goto tr52;
		case 62: goto tr185;
		case 63: goto st121;
		case 64: goto tr54;
		case 91: goto st121;
		case 93: goto st121;
		case 95: goto tr344;
		case 126: goto tr344;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr344;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr344;
	} else
		goto tr344;
	goto tr0;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 47: goto st24;
		case 58: goto tr266;
		case 59: goto tr267;
		case 61: goto st24;
		case 62: goto tr71;
		case 63: goto tr268;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st185;
			} else if ( (*p) >= 43 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st196;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st198;
			} else if ( (*p) >= 97 )
				goto st196;
		} else
			goto st198;
	} else
		goto st194;
	goto tr0;
tr267:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st242;
tr349:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st242;
tr358:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 11964 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr276;
		case 37: goto tr277;
		case 44: goto st24;
		case 45: goto tr347;
		case 58: goto tr278;
		case 59: goto st206;
		case 61: goto st24;
		case 62: goto st442;
		case 63: goto st223;
		case 64: goto tr50;
		case 91: goto tr78;
		case 93: goto tr78;
		case 95: goto tr276;
		case 126: goto tr276;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto tr276;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr347;
		} else if ( (*p) >= 65 )
			goto tr347;
	} else
		goto tr347;
	goto tr0;
tr347:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 12010 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st207;
		case 37: goto st208;
		case 44: goto st24;
		case 45: goto st243;
		case 58: goto tr283;
		case 59: goto tr349;
		case 61: goto tr350;
		case 62: goto tr87;
		case 63: goto tr286;
		case 64: goto tr50;
		case 91: goto st42;
		case 93: goto st42;
		case 95: goto st207;
		case 126: goto st207;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st207;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st243;
		} else if ( (*p) >= 65 )
			goto st243;
	} else
		goto st243;
	goto tr0;
tr350:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st244;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
#line 12047 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr351;
		case 37: goto tr352;
		case 44: goto st24;
		case 58: goto tr353;
		case 59: goto st24;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 91: goto tr354;
		case 93: goto tr354;
		case 95: goto tr351;
		case 126: goto tr351;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr351;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr351;
	} else
		goto tr351;
	goto tr0;
tr351:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st245;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
#line 12079 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st245;
		case 37: goto st246;
		case 44: goto st24;
		case 58: goto tr357;
		case 59: goto tr358;
		case 61: goto st24;
		case 62: goto tr95;
		case 63: goto tr307;
		case 64: goto tr50;
		case 91: goto st252;
		case 93: goto st252;
		case 95: goto st245;
		case 126: goto st245;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st245;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st245;
	} else
		goto st245;
	goto tr0;
tr352:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
#line 12112 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st247;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st247;
	} else
		goto st247;
	goto tr0;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st245;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st245;
	} else
		goto st245;
	goto tr0;
tr357:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st248;
tr353:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 12149 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr361;
		case 37: goto tr362;
		case 44: goto tr52;
		case 47: goto st252;
		case 58: goto tr357;
		case 59: goto tr363;
		case 61: goto tr52;
		case 62: goto tr95;
		case 63: goto tr96;
		case 64: goto tr244;
		case 91: goto st252;
		case 93: goto st252;
		case 95: goto tr361;
		case 126: goto tr361;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr361;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr361;
	} else
		goto tr361;
	goto tr0;
tr361:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st249;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
#line 12183 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st249;
		case 37: goto st250;
		case 44: goto st28;
		case 47: goto st252;
		case 58: goto tr357;
		case 59: goto tr363;
		case 61: goto st28;
		case 62: goto tr95;
		case 63: goto tr96;
		case 64: goto tr247;
		case 91: goto st252;
		case 93: goto st252;
		case 95: goto st249;
		case 126: goto st249;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st249;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st249;
	} else
		goto st249;
	goto tr0;
tr362:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 12217 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st251;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st251;
	} else
		goto st251;
	goto tr0;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st249;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st249;
	} else
		goto st249;
	goto tr0;
tr354:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
#line 12248 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st252;
		case 37: goto st253;
		case 58: goto tr357;
		case 59: goto tr363;
		case 62: goto tr95;
		case 63: goto tr96;
		case 64: goto tr50;
		case 93: goto st252;
		case 95: goto st252;
		case 126: goto st252;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st252;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st252;
		} else if ( (*p) >= 65 )
			goto st252;
	} else
		goto st252;
	goto tr0;
tr373:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
#line 12281 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st254;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st254;
	} else
		goto st254;
	goto tr0;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st252;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st252;
	} else
		goto st252;
	goto tr0;
tr371:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st255;
tr363:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
#line 12316 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr78;
		case 37: goto tr79;
		case 45: goto tr369;
		case 58: goto tr78;
		case 59: goto st41;
		case 62: goto st442;
		case 63: goto st116;
		case 91: goto tr78;
		case 93: goto tr78;
		case 95: goto tr78;
		case 126: goto tr78;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 46 <= (*p) && (*p) <= 47 )
				goto tr78;
		} else if ( (*p) >= 36 )
			goto tr78;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr369;
		} else if ( (*p) >= 65 )
			goto tr369;
	} else
		goto tr369;
	goto tr0;
tr369:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st256;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
#line 12362 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st42;
		case 37: goto st43;
		case 45: goto st256;
		case 58: goto tr283;
		case 59: goto tr371;
		case 61: goto tr372;
		case 62: goto tr87;
		case 63: goto tr88;
		case 64: goto tr50;
		case 91: goto st42;
		case 93: goto st42;
		case 95: goto st42;
		case 126: goto st42;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 46 <= (*p) && (*p) <= 47 )
				goto st42;
		} else if ( (*p) >= 36 )
			goto st42;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st256;
		} else if ( (*p) >= 65 )
			goto st256;
	} else
		goto st256;
	goto tr0;
tr372:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st257;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
#line 12401 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr354;
		case 37: goto tr373;
		case 93: goto tr354;
		case 95: goto tr354;
		case 126: goto tr354;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto tr354;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr354;
		} else if ( (*p) >= 65 )
			goto tr354;
	} else
		goto tr354;
	goto tr0;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 47: goto st24;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st185;
			} else if ( (*p) >= 43 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st196;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st198;
			} else if ( (*p) >= 97 )
				goto st196;
		} else
			goto st198;
	} else
		goto st259;
	goto tr0;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st260;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st268;
	goto tr0;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 47: goto st24;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st185;
			} else if ( (*p) >= 43 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st196;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st198;
			} else if ( (*p) >= 97 )
				goto st196;
		} else
			goto st198;
	} else
		goto st261;
	goto tr0;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st262;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st266;
	goto tr0;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 47: goto st24;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st185;
			} else if ( (*p) >= 43 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st196;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st198;
			} else if ( (*p) >= 97 )
				goto st196;
		} else
			goto st198;
	} else
		goto st263;
	goto tr0;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st195;
		case 58: goto tr266;
		case 59: goto tr267;
		case 61: goto st24;
		case 62: goto tr71;
		case 63: goto tr268;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st264;
	goto tr0;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st195;
		case 58: goto tr266;
		case 59: goto tr267;
		case 61: goto st24;
		case 62: goto tr71;
		case 63: goto tr268;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st265;
	goto tr0;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st195;
		case 58: goto tr266;
		case 59: goto tr267;
		case 61: goto st24;
		case 62: goto tr71;
		case 63: goto tr268;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st194;
	goto tr0;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st262;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st267;
	goto tr0;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st262;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st194;
	goto tr0;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st260;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st269;
	goto tr0;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st260;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st194;
	goto tr0;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st258;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st271;
	goto tr0;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
	switch( (*p) ) {
		case 33: goto st24;
		case 35: goto st174;
		case 37: goto st25;
		case 45: goto st193;
		case 46: goto st258;
		case 58: goto tr49;
		case 59: goto st186;
		case 61: goto st24;
		case 63: goto st24;
		case 64: goto tr50;
		case 95: goto st24;
		case 126: goto st24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st24;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st24;
		} else
			goto st185;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st194;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st201;
			} else if ( (*p) >= 97 )
				goto st194;
		} else
			goto st201;
	} else
		goto st194;
	goto tr0;
tr35:
#line 13 "sip_uri.rl"
	{ uri->scheme_stop = p; }
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
#line 13026 "sip_parser.c"
	if ( (*p) == 58 )
		goto st23;
	goto tr0;
tr31:
#line 7 "sip_uri.rl"
	{ uri->scheme_start = p; }
	goto st273;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
#line 13038 "sip_parser.c"
	switch( (*p) ) {
		case 69: goto st274;
		case 101: goto st274;
	}
	goto tr0;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
	switch( (*p) ) {
		case 76: goto tr387;
		case 108: goto tr387;
	}
	goto tr0;
tr387:
#line 13 "sip_uri.rl"
	{ uri->scheme_stop = p; }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
#line 13061 "sip_parser.c"
	if ( (*p) == 58 )
		goto st276;
	goto tr0;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
	switch( (*p) ) {
		case 35: goto tr389;
		case 59: goto tr390;
		case 62: goto tr391;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr389;
		} else if ( (*p) >= 40 )
			goto tr389;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr389;
		} else if ( (*p) >= 65 )
			goto tr389;
	} else
		goto tr389;
	goto tr0;
tr389:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
#line 13097 "sip_parser.c"
	switch( (*p) ) {
		case 35: goto st277;
		case 59: goto tr393;
		case 62: goto tr394;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 42 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st277;
		} else if ( (*p) >= 40 )
			goto st277;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st277;
		} else if ( (*p) >= 65 )
			goto st277;
	} else
		goto st277;
	goto tr0;
tr390:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st278;
tr393:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st278;
tr398:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st278;
tr404:
#line 33 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 1) = p - 1; }
	goto st278;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
#line 13144 "sip_parser.c"
	switch( (*p) ) {
		case 45: goto tr395;
		case 59: goto st278;
		case 62: goto st442;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr395;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr395;
	} else
		goto tr395;
	goto tr0;
tr395:
#line 21 "sip_uri.rl"
	{
    if (uri->plen == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(uri->pname, 0, s);
      memset(uri->pvalue, 0, s);
    }
    uri->pi = uri->plen;
    uri->plen++;
    *(uri->pname + uri->pi*2 + 0) = p;
  }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 13176 "sip_parser.c"
	switch( (*p) ) {
		case 45: goto st279;
		case 59: goto tr398;
		case 61: goto tr399;
		case 62: goto tr87;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st279;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st279;
	} else
		goto st279;
	goto tr0;
tr399:
#line 32 "sip_uri.rl"
	{ *(uri->pname + uri->pi*2 + 1) = p - 1; }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 13200 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr400;
		case 37: goto tr401;
		case 93: goto tr400;
		case 95: goto tr400;
		case 126: goto tr400;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto tr400;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr400;
		} else if ( (*p) >= 65 )
			goto tr400;
	} else
		goto tr400;
	goto tr0;
tr400:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 13228 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st281;
		case 37: goto st282;
		case 59: goto tr404;
		case 62: goto tr95;
		case 93: goto st281;
		case 95: goto st281;
		case 126: goto st281;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st281;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st281;
		} else if ( (*p) >= 65 )
			goto st281;
	} else
		goto st281;
	goto tr0;
tr401:
#line 31 "sip_uri.rl"
	{ *(uri->pvalue + uri->pi*2 + 0) = p; }
	goto st282;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
#line 13258 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st283;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st283;
	} else
		goto st283;
	goto tr0;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st281;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st281;
	} else
		goto st281;
	goto tr0;
tr21:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 13289 "sip_parser.c"
	if ( (*p) < 11 ) {
		if ( 0 <= (*p) && (*p) <= 9 )
			goto tr10;
	} else if ( (*p) > 12 ) {
		if ( 14 <= (*p) )
			goto tr10;
	} else
		goto tr10;
	goto tr0;
tr3:
#line 158 "sip_parser.rl"
	{ na->name_start = p; }
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st285;
tr408:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 13313 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st286;
		case 13: goto st287;
		case 32: goto st286;
		case 33: goto tr408;
		case 37: goto tr408;
		case 39: goto tr408;
		case 126: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr408;
		} else if ( (*p) >= 42 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr0;
tr409:
#line 160 "sip_parser.rl"
	{ na->name_complete = true; }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 13346 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr409;
		case 13: goto tr410;
		case 32: goto tr409;
		case 33: goto tr408;
		case 37: goto tr408;
		case 39: goto tr408;
		case 60: goto tr25;
		case 126: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr408;
		} else if ( (*p) >= 42 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr0;
tr410:
#line 160 "sip_parser.rl"
	{ na->name_complete = true; }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 13380 "sip_parser.c"
	if ( (*p) == 10 )
		goto st288;
	goto tr0;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
	switch( (*p) ) {
		case 9: goto st289;
		case 32: goto st289;
	}
	goto tr0;
tr413:
#line 160 "sip_parser.rl"
	{ na->name_complete = true; }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 13401 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr413;
		case 13: goto tr24;
		case 32: goto tr413;
		case 33: goto tr408;
		case 37: goto tr408;
		case 39: goto tr408;
		case 60: goto tr25;
		case 126: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr408;
		} else if ( (*p) >= 42 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr0;
tr6:
#line 158 "sip_parser.rl"
	{ na->name_start = p; }
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
#line 7 "sip_uri.rl"
	{ uri->scheme_start = p; }
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 13439 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st286;
		case 13: goto st287;
		case 32: goto st286;
		case 33: goto tr408;
		case 37: goto tr408;
		case 39: goto tr408;
		case 73: goto tr414;
		case 105: goto tr414;
		case 126: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr408;
		} else if ( (*p) >= 42 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr0;
tr414:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st291;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
#line 13474 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st286;
		case 13: goto st287;
		case 32: goto st286;
		case 33: goto tr408;
		case 37: goto tr408;
		case 39: goto tr408;
		case 80: goto tr415;
		case 112: goto tr415;
		case 126: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr408;
		} else if ( (*p) >= 42 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr0;
tr415:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
#line 13 "sip_uri.rl"
	{ uri->scheme_stop = p; }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 13511 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st286;
		case 13: goto st287;
		case 32: goto st286;
		case 33: goto tr408;
		case 37: goto tr408;
		case 39: goto tr408;
		case 58: goto st293;
		case 83: goto tr417;
		case 115: goto tr417;
		case 126: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr408;
		} else if ( (*p) >= 42 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr0;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
	switch( (*p) ) {
		case 33: goto tr418;
		case 35: goto tr419;
		case 37: goto tr420;
		case 44: goto tr418;
		case 47: goto tr418;
		case 58: goto tr423;
		case 59: goto tr424;
		case 61: goto tr418;
		case 63: goto tr418;
		case 64: goto tr425;
		case 91: goto tr428;
		case 95: goto tr418;
		case 126: goto tr418;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto tr418;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr422;
		} else
			goto tr421;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto tr427;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr427;
		} else
			goto tr426;
	} else
		goto tr426;
	goto tr0;
tr418:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 13587 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st294;
		case 37: goto st295;
		case 58: goto tr431;
		case 61: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 59 )
			goto st294;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st294;
	} else
		goto st294;
	goto tr0;
tr420:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 13614 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st296;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st296;
	} else
		goto st296;
	goto tr0;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st294;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st294;
	} else
		goto st294;
	goto tr0;
tr423:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st297;
tr431:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 13651 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr434;
		case 37: goto tr435;
		case 61: goto tr434;
		case 64: goto tr436;
		case 95: goto tr434;
		case 126: goto tr434;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto tr434;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr434;
		} else if ( (*p) >= 65 )
			goto tr434;
	} else
		goto tr434;
	goto tr0;
tr434:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 13680 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st298;
		case 37: goto st299;
		case 61: goto st298;
		case 64: goto tr439;
		case 95: goto st298;
		case 126: goto st298;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st298;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st298;
		} else if ( (*p) >= 65 )
			goto st298;
	} else
		goto st298;
	goto tr0;
tr435:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st299;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
#line 13709 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st300;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st300;
	} else
		goto st300;
	goto tr0;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st298;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st298;
	} else
		goto st298;
	goto tr0;
tr425:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st301;
tr432:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st301;
tr436:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st301;
tr439:
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st301;
tr506:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st301;
tr509:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 15 "sip_uri.rl"
	{ uri->pass_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 13782 "sip_parser.c"
	if ( (*p) == 91 )
		goto tr428;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr441;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr442;
	} else
		goto tr442;
	goto tr0;
tr441:
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st302;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
#line 13802 "sip_parser.c"
	switch( (*p) ) {
		case 45: goto st303;
		case 46: goto st308;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st317;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
	if ( (*p) == 45 )
		goto st303;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st304;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
	switch( (*p) ) {
		case 45: goto st303;
		case 46: goto st305;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st304;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st304;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st450;
	} else
		goto st450;
	goto tr0;
tr442:
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st450;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
#line 13869 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 44: goto tr608;
		case 45: goto st306;
		case 46: goto st451;
		case 58: goto tr610;
		case 59: goto tr611;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st450;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st450;
	} else
		goto st450;
	goto tr605;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
	if ( (*p) == 45 )
		goto st306;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st450;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st450;
	} else
		goto st450;
	goto tr0;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 44: goto tr608;
		case 58: goto tr610;
		case 59: goto tr611;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st304;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st450;
	} else
		goto st450;
	goto tr605;
tr610:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st307;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
#line 13933 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr450;
	goto tr0;
tr450:
#line 11 "sip_uri.rl"
	{ uri->port_start = p; }
	goto st452;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
#line 13945 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr613;
		case 13: goto tr614;
		case 32: goto tr613;
		case 44: goto tr615;
		case 59: goto tr617;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st452;
	goto tr612;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st309;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st450;
	} else
		goto st450;
	goto tr0;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	switch( (*p) ) {
		case 45: goto st303;
		case 46: goto st310;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st315;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st311;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st450;
	} else
		goto st450;
	goto tr0;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
	switch( (*p) ) {
		case 45: goto st303;
		case 46: goto st312;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st313;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st453;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st450;
	} else
		goto st450;
	goto tr0;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 44: goto tr608;
		case 45: goto st303;
		case 46: goto st305;
		case 58: goto tr610;
		case 59: goto tr611;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st454;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr605;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 44: goto tr608;
		case 45: goto st303;
		case 46: goto st305;
		case 58: goto tr610;
		case 59: goto tr611;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st455;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr605;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 44: goto tr608;
		case 45: goto st303;
		case 46: goto st305;
		case 58: goto tr610;
		case 59: goto tr611;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st304;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr605;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
	switch( (*p) ) {
		case 45: goto st303;
		case 46: goto st312;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st314;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
	switch( (*p) ) {
		case 45: goto st303;
		case 46: goto st312;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st304;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	switch( (*p) ) {
		case 45: goto st303;
		case 46: goto st310;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st316;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
	switch( (*p) ) {
		case 45: goto st303;
		case 46: goto st310;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st304;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
	switch( (*p) ) {
		case 45: goto st303;
		case 46: goto st308;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st318;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
	switch( (*p) ) {
		case 45: goto st303;
		case 46: goto st308;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st304;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st304;
	} else
		goto st304;
	goto tr0;
tr428:
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st319;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
#line 14208 "sip_parser.c"
	if ( (*p) == 58 )
		goto st353;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st320;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st320;
	} else
		goto st320;
	goto tr0;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
	switch( (*p) ) {
		case 58: goto st324;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st321;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st321;
	} else
		goto st321;
	goto tr0;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
	switch( (*p) ) {
		case 58: goto st324;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st322;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st322;
	} else
		goto st322;
	goto tr0;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	switch( (*p) ) {
		case 58: goto st324;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st323;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st323;
	} else
		goto st323;
	goto tr0;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
	switch( (*p) ) {
		case 58: goto st324;
		case 93: goto st456;
	}
	goto tr0;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
	if ( (*p) == 58 )
		goto st340;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st325;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st320;
	} else
		goto st320;
	goto tr0;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	switch( (*p) ) {
		case 46: goto st326;
		case 58: goto st324;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st338;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st321;
	} else
		goto st321;
	goto tr0;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st327;
	goto tr0;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
	if ( (*p) == 46 )
		goto st328;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st336;
	goto tr0;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st329;
	goto tr0;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
	if ( (*p) == 46 )
		goto st330;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st334;
	goto tr0;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st331;
	goto tr0;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	if ( (*p) == 93 )
		goto st456;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st332;
	goto tr0;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
	if ( (*p) == 93 )
		goto st456;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st333;
	goto tr0;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	if ( (*p) == 93 )
		goto st456;
	goto tr0;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 44: goto tr608;
		case 58: goto tr610;
		case 59: goto tr611;
	}
	goto tr605;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
	if ( (*p) == 46 )
		goto st330;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st335;
	goto tr0;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
	if ( (*p) == 46 )
		goto st330;
	goto tr0;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	if ( (*p) == 46 )
		goto st328;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st337;
	goto tr0;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
	if ( (*p) == 46 )
		goto st328;
	goto tr0;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
	switch( (*p) ) {
		case 46: goto st326;
		case 58: goto st324;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st339;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st322;
	} else
		goto st322;
	goto tr0;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	switch( (*p) ) {
		case 46: goto st326;
		case 58: goto st324;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st323;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st323;
	} else
		goto st323;
	goto tr0;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
	switch( (*p) ) {
		case 58: goto st349;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st341;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st341;
	} else
		goto st341;
	goto tr0;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
	switch( (*p) ) {
		case 58: goto st345;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st342;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st342;
	} else
		goto st342;
	goto tr0;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
	switch( (*p) ) {
		case 58: goto st345;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st343;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st343;
	} else
		goto st343;
	goto tr0;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	switch( (*p) ) {
		case 58: goto st345;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st344;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st344;
	} else
		goto st344;
	goto tr0;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
	switch( (*p) ) {
		case 58: goto st345;
		case 93: goto st456;
	}
	goto tr0;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st346;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st341;
	} else
		goto st341;
	goto tr0;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
	switch( (*p) ) {
		case 46: goto st326;
		case 58: goto st345;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st347;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st342;
	} else
		goto st342;
	goto tr0;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
	switch( (*p) ) {
		case 46: goto st326;
		case 58: goto st345;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st348;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st343;
	} else
		goto st343;
	goto tr0;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
	switch( (*p) ) {
		case 46: goto st326;
		case 58: goto st345;
		case 93: goto st456;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st344;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st344;
	} else
		goto st344;
	goto tr0;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st350;
	goto tr0;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
	if ( (*p) == 46 )
		goto st326;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st351;
	goto tr0;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	if ( (*p) == 46 )
		goto st326;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st352;
	goto tr0;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
	if ( (*p) == 46 )
		goto st326;
	goto tr0;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
	if ( (*p) == 58 )
		goto st340;
	goto tr0;
tr419:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
#line 14649 "sip_parser.c"
	switch( (*p) ) {
		case 35: goto st354;
		case 58: goto tr431;
		case 59: goto st355;
		case 64: goto tr432;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 42 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st354;
		} else if ( (*p) >= 40 )
			goto st354;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st354;
		} else if ( (*p) >= 65 )
			goto st354;
	} else
		goto st354;
	goto tr0;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	if ( (*p) == 45 )
		goto st356;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st356;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st356;
	} else
		goto st356;
	goto tr0;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
	switch( (*p) ) {
		case 45: goto st356;
		case 58: goto tr431;
		case 59: goto st355;
		case 61: goto st357;
		case 64: goto tr432;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st356;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st356;
	} else
		goto st356;
	goto tr0;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
	switch( (*p) ) {
		case 33: goto st358;
		case 37: goto st359;
		case 93: goto st358;
		case 95: goto st358;
		case 126: goto st358;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st358;
	} else if ( (*p) > 58 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st358;
		} else if ( (*p) >= 65 )
			goto st358;
	} else
		goto st358;
	goto tr0;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	switch( (*p) ) {
		case 33: goto st358;
		case 37: goto st359;
		case 58: goto tr502;
		case 59: goto st355;
		case 64: goto tr432;
		case 93: goto st358;
		case 95: goto st358;
		case 126: goto st358;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st358;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st358;
		} else if ( (*p) >= 65 )
			goto st358;
	} else
		goto st358;
	goto tr0;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st360;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st360;
	} else
		goto st360;
	goto tr0;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st358;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st358;
	} else
		goto st358;
	goto tr0;
tr502:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 14789 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr504;
		case 37: goto tr505;
		case 44: goto tr434;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto tr434;
		case 64: goto tr506;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto tr504;
		case 126: goto tr504;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr504;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr504;
	} else
		goto tr504;
	goto tr0;
tr504:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st362;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
#line 14821 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st362;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st362;
	} else
		goto st362;
	goto tr0;
tr505:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
	goto st363;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
#line 14853 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st364;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st364;
	} else
		goto st364;
	goto tr0;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st362;
	} else
		goto st362;
	goto tr0;
tr421:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st365;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
#line 14884 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 45 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 44 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st365;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st294;
			} else if ( (*p) >= 97 )
				goto st365;
		} else
			goto st294;
	} else
		goto st365;
	goto tr0;
tr424:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 14930 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st294;
		case 37: goto st295;
		case 45: goto st367;
		case 58: goto tr431;
		case 59: goto st294;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st367;
		} else if ( (*p) >= 65 )
			goto st367;
	} else
		goto st367;
	goto tr0;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
	switch( (*p) ) {
		case 33: goto st294;
		case 37: goto st295;
		case 45: goto st367;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st368;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st367;
		} else if ( (*p) >= 65 )
			goto st367;
	} else
		goto st367;
	goto tr0;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	switch( (*p) ) {
		case 33: goto st369;
		case 37: goto st370;
		case 44: goto st294;
		case 58: goto tr502;
		case 59: goto st294;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st369;
		case 126: goto st369;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st369;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st369;
	} else
		goto st369;
	goto tr0;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
	switch( (*p) ) {
		case 33: goto st369;
		case 37: goto st370;
		case 44: goto st294;
		case 58: goto tr502;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st369;
		case 126: goto st369;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st369;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st369;
	} else
		goto st369;
	goto tr0;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st371;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st371;
	} else
		goto st371;
	goto tr0;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st369;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st369;
	} else
		goto st369;
	goto tr0;
tr422:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 15073 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st427;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st436;
	goto tr0;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st365;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st374;
	goto tr0;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st375;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st374;
	goto tr0;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st365;
			} else if ( (*p) >= 43 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st457;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st459;
			} else if ( (*p) >= 97 )
				goto st457;
		} else
			goto st459;
	} else
		goto st374;
	goto tr0;
tr426:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 15250 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 44: goto tr620;
		case 45: goto st376;
		case 46: goto st469;
		case 58: goto tr622;
		case 59: goto tr623;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st457;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st459;
			} else if ( (*p) >= 97 )
				goto st457;
		} else
			goto st459;
	} else
		goto st457;
	goto tr605;
tr620:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st458;
tr630:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 15305 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st445;
		case 13: goto st54;
		case 32: goto st445;
		case 33: goto st294;
		case 37: goto st295;
		case 58: goto tr431;
		case 61: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 63 ) {
		if ( 36 <= (*p) && (*p) <= 59 )
			goto st294;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st294;
	} else
		goto st294;
	goto tr594;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st376;
		case 46: goto st365;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st457;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st459;
			} else if ( (*p) >= 97 )
				goto st457;
		} else
			goto st459;
	} else
		goto st457;
	goto tr0;
tr427:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 10 "sip_uri.rl"
	{ uri->host_start = p; }
	goto st459;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
#line 15379 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 33: goto st294;
		case 37: goto st295;
		case 44: goto tr620;
		case 45: goto st377;
		case 46: goto st460;
		case 58: goto tr622;
		case 59: goto tr625;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st459;
		} else if ( (*p) >= 65 )
			goto st459;
	} else
		goto st459;
	goto tr605;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
	switch( (*p) ) {
		case 33: goto st294;
		case 37: goto st295;
		case 45: goto st377;
		case 58: goto tr431;
		case 59: goto st294;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st459;
		} else if ( (*p) >= 65 )
			goto st459;
	} else
		goto st459;
	goto tr0;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 33: goto st294;
		case 37: goto st295;
		case 44: goto tr620;
		case 58: goto tr622;
		case 59: goto tr625;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st459;
		} else if ( (*p) >= 65 )
			goto st459;
	} else
		goto st378;
	goto tr605;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	switch( (*p) ) {
		case 33: goto st294;
		case 37: goto st295;
		case 45: goto st379;
		case 46: goto st380;
		case 58: goto tr431;
		case 59: goto st294;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st378;
		} else if ( (*p) >= 65 )
			goto st378;
	} else
		goto st378;
	goto tr0;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
	switch( (*p) ) {
		case 33: goto st294;
		case 37: goto st295;
		case 45: goto st379;
		case 58: goto tr431;
		case 59: goto st294;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st378;
		} else if ( (*p) >= 65 )
			goto st378;
	} else
		goto st378;
	goto tr0;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
	switch( (*p) ) {
		case 33: goto st294;
		case 37: goto st295;
		case 58: goto tr431;
		case 59: goto st294;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 47 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st459;
		} else if ( (*p) >= 65 )
			goto st459;
	} else
		goto st378;
	goto tr0;
tr622:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st381;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
#line 15562 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr434;
		case 37: goto tr435;
		case 61: goto tr434;
		case 64: goto tr436;
		case 95: goto tr434;
		case 126: goto tr434;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto tr434;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr434;
		} else if ( (*p) >= 65 )
			goto tr434;
	} else
		goto tr530;
	goto tr0;
tr530:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 11 "sip_uri.rl"
	{ uri->port_start = p; }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 15593 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr613;
		case 13: goto tr614;
		case 32: goto tr613;
		case 33: goto st298;
		case 37: goto st299;
		case 44: goto tr626;
		case 59: goto tr617;
		case 61: goto st298;
		case 64: goto tr439;
		case 95: goto st298;
		case 126: goto st298;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st298;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st298;
		} else if ( (*p) >= 65 )
			goto st298;
	} else
		goto st461;
	goto tr612;
tr626:
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 15627 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st445;
		case 13: goto st54;
		case 32: goto st445;
		case 33: goto st298;
		case 37: goto st299;
		case 61: goto st298;
		case 64: goto tr439;
		case 95: goto st298;
		case 126: goto st298;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st298;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st298;
		} else if ( (*p) >= 65 )
			goto st298;
	} else
		goto st298;
	goto tr594;
tr625:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st382;
tr631:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st382;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
#line 15663 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 13: goto st57;
		case 32: goto st56;
		case 33: goto tr531;
		case 37: goto tr532;
		case 39: goto tr531;
		case 44: goto st294;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto st294;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 96: goto tr107;
		case 126: goto tr531;
	}
	if ( (*p) < 42 ) {
		if ( 36 <= (*p) && (*p) <= 41 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr531;
		} else if ( (*p) >= 65 )
			goto tr531;
	} else
		goto tr531;
	goto tr0;
tr531:
#line 7 "sip_params.rl"
	{
    if (kv->len == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(kv->key, 0, s);
      memset(kv->val, 0, s);
    }
    kv->i = kv->len;
    kv->len++;
  }
#line 17 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 0) = p; }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 15711 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr598;
		case 13: goto tr599;
		case 32: goto tr598;
		case 33: goto st463;
		case 37: goto st464;
		case 39: goto st463;
		case 44: goto tr630;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto tr631;
		case 61: goto tr632;
		case 63: goto st294;
		case 64: goto tr432;
		case 96: goto st447;
		case 126: goto st463;
	}
	if ( (*p) < 42 ) {
		if ( 36 <= (*p) && (*p) <= 41 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st463;
		} else if ( (*p) >= 65 )
			goto st463;
	} else
		goto st463;
	goto tr597;
tr532:
#line 7 "sip_params.rl"
	{
    if (kv->len == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(kv->key, 0, s);
      memset(kv->val, 0, s);
    }
    kv->i = kv->len;
    kv->len++;
  }
#line 17 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 0) = p; }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
#line 15759 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr598;
		case 13: goto tr599;
		case 32: goto tr598;
		case 33: goto st447;
		case 37: goto st447;
		case 39: goto st447;
		case 44: goto tr601;
		case 59: goto tr602;
		case 61: goto tr603;
		case 126: goto st447;
	}
	if ( (*p) < 71 ) {
		if ( (*p) < 48 ) {
			if ( 42 <= (*p) && (*p) <= 46 )
				goto st447;
		} else if ( (*p) > 57 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st465;
		} else
			goto st465;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 95 <= (*p) && (*p) <= 96 )
				goto st447;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st447;
		} else
			goto st465;
	} else
		goto st447;
	goto tr597;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
	switch( (*p) ) {
		case 9: goto tr598;
		case 13: goto tr599;
		case 32: goto tr598;
		case 33: goto st447;
		case 37: goto st447;
		case 39: goto st447;
		case 44: goto tr601;
		case 59: goto tr602;
		case 61: goto tr603;
		case 126: goto st447;
	}
	if ( (*p) < 71 ) {
		if ( (*p) < 48 ) {
			if ( 42 <= (*p) && (*p) <= 46 )
				goto st447;
		} else if ( (*p) > 57 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st463;
		} else
			goto st463;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 95 <= (*p) && (*p) <= 96 )
				goto st447;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st447;
		} else
			goto st463;
	} else
		goto st447;
	goto tr597;
tr632:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 15838 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr115;
		case 13: goto tr116;
		case 32: goto tr115;
		case 33: goto tr533;
		case 34: goto tr118;
		case 37: goto tr534;
		case 39: goto tr533;
		case 44: goto st294;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto st294;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 91: goto tr119;
		case 96: goto tr117;
		case 126: goto tr533;
	}
	if ( (*p) < 42 ) {
		if ( 36 <= (*p) && (*p) <= 41 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr533;
		} else if ( (*p) >= 65 )
			goto tr533;
	} else
		goto tr533;
	goto tr0;
tr533:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st466;
tr634:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st466;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
#line 15884 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto tr634;
		case 37: goto tr635;
		case 39: goto tr634;
		case 44: goto st458;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto st382;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 96: goto tr604;
		case 126: goto tr634;
	}
	if ( (*p) < 42 ) {
		if ( 36 <= (*p) && (*p) <= 41 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr634;
		} else if ( (*p) >= 65 )
			goto tr634;
	} else
		goto tr634;
	goto tr594;
tr534:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st467;
tr635:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 15928 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto tr604;
		case 37: goto tr604;
		case 39: goto tr604;
		case 44: goto st445;
		case 59: goto st56;
		case 126: goto tr604;
	}
	if ( (*p) < 71 ) {
		if ( (*p) < 48 ) {
			if ( 42 <= (*p) && (*p) <= 46 )
				goto tr604;
		} else if ( (*p) > 57 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto tr638;
		} else
			goto tr638;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 95 <= (*p) && (*p) <= 96 )
				goto tr604;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr604;
		} else
			goto tr638;
	} else
		goto tr604;
	goto tr594;
tr638:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 15969 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto tr604;
		case 37: goto tr604;
		case 39: goto tr604;
		case 44: goto st445;
		case 59: goto st56;
		case 126: goto tr604;
	}
	if ( (*p) < 71 ) {
		if ( (*p) < 48 ) {
			if ( 42 <= (*p) && (*p) <= 46 )
				goto tr604;
		} else if ( (*p) > 57 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto tr634;
		} else
			goto tr634;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 95 <= (*p) && (*p) <= 96 )
				goto tr604;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr604;
		} else
			goto tr634;
	} else
		goto tr604;
	goto tr594;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 43: goto st294;
		case 44: goto tr620;
		case 47: goto st294;
		case 58: goto tr622;
		case 59: goto tr623;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st374;
		} else
			goto st365;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st459;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st459;
		} else
			goto st457;
	} else
		goto st457;
	goto tr605;
tr623:
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	goto st384;
tr640:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 16057 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 13: goto st57;
		case 32: goto st56;
		case 33: goto tr531;
		case 37: goto tr532;
		case 39: goto tr531;
		case 44: goto st294;
		case 45: goto tr535;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto st294;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto tr531;
		case 96: goto tr107;
		case 126: goto tr531;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 42 <= (*p) && (*p) <= 46 )
				goto tr531;
		} else if ( (*p) >= 36 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr535;
		} else if ( (*p) >= 65 )
			goto tr535;
	} else
		goto tr535;
	goto tr0;
tr535:
#line 7 "sip_params.rl"
	{
    if (kv->len == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(kv->key, 0, s);
      memset(kv->val, 0, s);
    }
    kv->i = kv->len;
    kv->len++;
  }
#line 17 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 0) = p; }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 16110 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr598;
		case 13: goto tr599;
		case 32: goto tr598;
		case 33: goto st463;
		case 37: goto st464;
		case 39: goto st463;
		case 44: goto tr630;
		case 45: goto st470;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto tr640;
		case 61: goto tr641;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st463;
		case 96: goto st447;
		case 126: goto st463;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 41 ) {
			if ( 42 <= (*p) && (*p) <= 46 )
				goto st463;
		} else if ( (*p) >= 36 )
			goto st294;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st470;
		} else if ( (*p) >= 65 )
			goto st470;
	} else
		goto st470;
	goto tr597;
tr641:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
#line 16153 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr115;
		case 13: goto tr116;
		case 32: goto tr115;
		case 33: goto tr536;
		case 34: goto tr118;
		case 37: goto tr537;
		case 39: goto tr536;
		case 44: goto st294;
		case 47: goto st369;
		case 58: goto tr502;
		case 59: goto st294;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 91: goto tr538;
		case 93: goto st358;
		case 96: goto tr117;
		case 126: goto tr536;
	}
	if ( (*p) < 42 ) {
		if ( 36 <= (*p) && (*p) <= 41 )
			goto st369;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr536;
		} else if ( (*p) >= 65 )
			goto tr536;
	} else
		goto tr536;
	goto tr0;
tr536:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st471;
tr642:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st471;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
#line 16200 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto tr642;
		case 37: goto tr643;
		case 39: goto tr642;
		case 44: goto st458;
		case 47: goto st369;
		case 58: goto tr502;
		case 59: goto st384;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 91: goto st358;
		case 93: goto st358;
		case 96: goto tr604;
		case 126: goto tr642;
	}
	if ( (*p) < 42 ) {
		if ( 36 <= (*p) && (*p) <= 41 )
			goto st369;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr642;
		} else if ( (*p) >= 65 )
			goto tr642;
	} else
		goto tr642;
	goto tr594;
tr537:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st472;
tr643:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 16246 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto tr604;
		case 37: goto tr604;
		case 39: goto tr604;
		case 44: goto st445;
		case 59: goto st56;
		case 126: goto tr604;
	}
	if ( (*p) < 71 ) {
		if ( (*p) < 48 ) {
			if ( 42 <= (*p) && (*p) <= 46 )
				goto tr604;
		} else if ( (*p) > 57 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto tr645;
		} else
			goto tr645;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 95 <= (*p) && (*p) <= 96 )
				goto tr604;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr604;
		} else
			goto tr645;
	} else
		goto tr604;
	goto tr594;
tr645:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st473;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
#line 16287 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto tr604;
		case 37: goto tr604;
		case 39: goto tr604;
		case 44: goto st445;
		case 59: goto st56;
		case 126: goto tr604;
	}
	if ( (*p) < 71 ) {
		if ( (*p) < 48 ) {
			if ( 42 <= (*p) && (*p) <= 46 )
				goto tr604;
		} else if ( (*p) > 57 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto tr642;
		} else
			goto tr642;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 95 <= (*p) && (*p) <= 96 )
				goto tr604;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr604;
		} else
			goto tr642;
	} else
		goto tr604;
	goto tr594;
tr538:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
#line 16330 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st358;
		case 37: goto st359;
		case 58: goto tr540;
		case 59: goto st355;
		case 64: goto tr432;
		case 93: goto st358;
		case 95: goto st358;
		case 126: goto st358;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 36 <= (*p) && (*p) <= 43 )
				goto st358;
		} else if ( (*p) > 47 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr539;
		} else
			goto st358;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 91 )
				goto st358;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st358;
		} else
			goto tr539;
	} else
		goto tr539;
	goto tr0;
tr539:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st387;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
#line 16370 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st358;
		case 37: goto st359;
		case 58: goto tr542;
		case 59: goto st355;
		case 64: goto tr432;
		case 93: goto tr543;
		case 95: goto st358;
		case 126: goto st358;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 36 <= (*p) && (*p) <= 43 )
				goto st358;
		} else if ( (*p) > 47 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr541;
		} else
			goto st358;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 91 )
				goto st358;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st358;
		} else
			goto tr541;
	} else
		goto tr541;
	goto tr0;
tr541:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 16410 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st358;
		case 37: goto st359;
		case 58: goto tr542;
		case 59: goto st355;
		case 64: goto tr432;
		case 93: goto tr543;
		case 95: goto st358;
		case 126: goto st358;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 36 <= (*p) && (*p) <= 43 )
				goto st358;
		} else if ( (*p) > 47 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr544;
		} else
			goto st358;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 91 )
				goto st358;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st358;
		} else
			goto tr544;
	} else
		goto tr544;
	goto tr0;
tr544:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st389;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
#line 16450 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st358;
		case 37: goto st359;
		case 58: goto tr542;
		case 59: goto st355;
		case 64: goto tr432;
		case 93: goto tr543;
		case 95: goto st358;
		case 126: goto st358;
	}
	if ( (*p) < 65 ) {
		if ( (*p) < 45 ) {
			if ( 36 <= (*p) && (*p) <= 43 )
				goto st358;
		} else if ( (*p) > 47 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr545;
		} else
			goto st358;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 91 )
				goto st358;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st358;
		} else
			goto tr545;
	} else
		goto tr545;
	goto tr0;
tr545:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
#line 16490 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st358;
		case 37: goto st359;
		case 58: goto tr542;
		case 59: goto st355;
		case 64: goto tr432;
		case 93: goto tr543;
		case 95: goto st358;
		case 126: goto st358;
	}
	if ( (*p) < 45 ) {
		if ( 36 <= (*p) && (*p) <= 43 )
			goto st358;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 91 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st358;
		} else if ( (*p) >= 65 )
			goto st358;
	} else
		goto st358;
	goto tr0;
tr542:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
#line 16523 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr504;
		case 37: goto tr505;
		case 44: goto tr434;
		case 47: goto st358;
		case 58: goto tr547;
		case 59: goto st355;
		case 61: goto tr434;
		case 64: goto tr506;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto tr504;
		case 126: goto tr504;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr546;
		} else if ( (*p) >= 36 )
			goto tr504;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto tr504;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr504;
		} else
			goto tr548;
	} else
		goto tr548;
	goto tr0;
tr546:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
#line 16566 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr549;
		case 47: goto st358;
		case 58: goto tr542;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr550;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr551;
	} else
		goto tr551;
	goto tr0;
tr549:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st393;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
#line 16608 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr552;
	goto tr0;
tr552:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
#line 16643 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr553;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 45 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr554;
	goto tr0;
tr553:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st395;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
#line 16679 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr555;
	goto tr0;
tr555:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
#line 16714 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr556;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 45 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr557;
	goto tr0;
tr556:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
#line 16750 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr558;
	goto tr0;
tr558:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st398;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
#line 16785 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr559;
	goto tr0;
tr559:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st399;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
#line 16820 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr560;
	goto tr0;
tr560:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 16855 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st362;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st362;
	} else
		goto st362;
	goto tr0;
tr543:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 16887 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto st358;
		case 37: goto st359;
		case 44: goto st445;
		case 58: goto tr502;
		case 59: goto st401;
		case 64: goto tr432;
		case 93: goto st358;
		case 95: goto st358;
		case 126: goto st358;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st358;
	} else if ( (*p) > 91 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st358;
	} else
		goto st358;
	goto tr594;
tr648:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 16919 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st56;
		case 13: goto st57;
		case 32: goto st56;
		case 33: goto tr107;
		case 37: goto tr107;
		case 39: goto tr107;
		case 45: goto tr561;
		case 46: goto tr107;
		case 126: goto tr107;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 43 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr561;
		} else if ( (*p) >= 42 )
			goto tr107;
	} else if ( (*p) > 90 ) {
		if ( (*p) > 96 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr561;
		} else if ( (*p) >= 95 )
			goto tr107;
	} else
		goto tr561;
	goto tr0;
tr561:
#line 7 "sip_params.rl"
	{
    if (kv->len == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(kv->key, 0, s);
      memset(kv->val, 0, s);
    }
    kv->i = kv->len;
    kv->len++;
  }
#line 17 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 0) = p; }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 16964 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr598;
		case 13: goto tr599;
		case 32: goto tr598;
		case 33: goto st447;
		case 37: goto st447;
		case 39: goto st447;
		case 44: goto tr601;
		case 45: goto st475;
		case 58: goto tr431;
		case 59: goto tr648;
		case 61: goto tr649;
		case 64: goto tr432;
		case 126: goto st447;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto st475;
		} else if ( (*p) >= 42 )
			goto st447;
	} else if ( (*p) > 90 ) {
		if ( (*p) > 96 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st475;
		} else if ( (*p) >= 95 )
			goto st447;
	} else
		goto st475;
	goto tr597;
tr649:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 17003 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr115;
		case 13: goto tr116;
		case 32: goto tr115;
		case 33: goto tr562;
		case 34: goto tr118;
		case 37: goto tr563;
		case 39: goto tr562;
		case 47: goto st358;
		case 58: goto st358;
		case 91: goto tr538;
		case 93: goto st358;
		case 96: goto tr117;
		case 126: goto tr562;
	}
	if ( (*p) < 45 ) {
		if ( (*p) > 41 ) {
			if ( 42 <= (*p) && (*p) <= 43 )
				goto tr562;
		} else if ( (*p) >= 36 )
			goto st358;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr562;
		} else if ( (*p) >= 65 )
			goto tr562;
	} else
		goto tr562;
	goto tr0;
tr562:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st476;
tr650:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 17048 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto tr650;
		case 37: goto tr651;
		case 39: goto tr650;
		case 44: goto st445;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st401;
		case 64: goto tr432;
		case 91: goto st358;
		case 93: goto st358;
		case 96: goto tr604;
		case 126: goto tr650;
	}
	if ( (*p) < 42 ) {
		if ( 36 <= (*p) && (*p) <= 41 )
			goto st358;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr650;
		} else if ( (*p) >= 65 )
			goto tr650;
	} else
		goto tr650;
	goto tr594;
tr563:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st477;
tr651:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st477;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
#line 17092 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto tr604;
		case 37: goto tr604;
		case 39: goto tr604;
		case 44: goto st445;
		case 59: goto st56;
		case 126: goto tr604;
	}
	if ( (*p) < 71 ) {
		if ( (*p) < 48 ) {
			if ( 42 <= (*p) && (*p) <= 46 )
				goto tr604;
		} else if ( (*p) > 57 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto tr652;
		} else
			goto tr652;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 95 <= (*p) && (*p) <= 96 )
				goto tr604;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr604;
		} else
			goto tr652;
	} else
		goto tr604;
	goto tr594;
tr652:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 17133 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st79;
		case 13: goto st51;
		case 32: goto st79;
		case 33: goto tr604;
		case 37: goto tr604;
		case 39: goto tr604;
		case 44: goto st445;
		case 59: goto st56;
		case 126: goto tr604;
	}
	if ( (*p) < 71 ) {
		if ( (*p) < 48 ) {
			if ( 42 <= (*p) && (*p) <= 46 )
				goto tr604;
		} else if ( (*p) > 57 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto tr650;
		} else
			goto tr650;
	} else if ( (*p) > 90 ) {
		if ( (*p) < 97 ) {
			if ( 95 <= (*p) && (*p) <= 96 )
				goto tr604;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr604;
		} else
			goto tr650;
	} else
		goto tr604;
	goto tr594;
tr557:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
#line 17174 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr556;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 45 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr564;
	goto tr0;
tr564:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
#line 17210 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr556;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st362;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st362;
	} else
		goto st362;
	goto tr0;
tr554:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 17243 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr553;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 45 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr565;
	goto tr0;
tr565:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st406;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
#line 17279 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr553;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st362;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st362;
	} else
		goto st362;
	goto tr0;
tr550:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 17312 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr549;
		case 47: goto st358;
		case 58: goto tr542;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr566;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr567;
	} else
		goto tr567;
	goto tr0;
tr566:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
#line 17354 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr549;
		case 47: goto st358;
		case 58: goto tr542;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr568;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr568;
	} else
		goto tr568;
	goto tr0;
tr568:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 17396 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr542;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st362;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st362;
	} else
		goto st362;
	goto tr0;
tr567:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st410;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
#line 17428 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr542;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr568;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr568;
	} else
		goto tr568;
	goto tr0;
tr551:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st411;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
#line 17469 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr542;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr567;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr567;
	} else
		goto tr567;
	goto tr0;
tr547:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st412;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
#line 17512 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr504;
		case 37: goto tr505;
		case 44: goto tr434;
		case 47: goto st358;
		case 58: goto tr570;
		case 59: goto st355;
		case 61: goto tr434;
		case 64: goto tr506;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto tr504;
		case 126: goto tr504;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr569;
		} else if ( (*p) >= 36 )
			goto tr504;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto tr504;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr504;
		} else
			goto tr569;
	} else
		goto tr569;
	goto tr0;
tr569:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st413;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
#line 17555 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr572;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr571;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr571;
	} else
		goto tr571;
	goto tr0;
tr571:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 17596 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr572;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr573;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr573;
	} else
		goto tr573;
	goto tr0;
tr573:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 17637 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr572;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr574;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr574;
	} else
		goto tr574;
	goto tr0;
tr574:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st416;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
#line 17678 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr572;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st362;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st362;
	} else
		goto st362;
	goto tr0;
tr572:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 17712 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr504;
		case 37: goto tr505;
		case 44: goto tr434;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto tr434;
		case 64: goto tr506;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto tr504;
		case 126: goto tr504;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr575;
		} else if ( (*p) >= 36 )
			goto tr504;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto tr504;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto tr504;
		} else
			goto tr569;
	} else
		goto tr569;
	goto tr0;
tr575:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 17755 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr549;
		case 47: goto st358;
		case 58: goto tr572;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr576;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr571;
	} else
		goto tr571;
	goto tr0;
tr576:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st419;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
#line 17797 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr549;
		case 47: goto st358;
		case 58: goto tr572;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr577;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr573;
	} else
		goto tr573;
	goto tr0;
tr577:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st420;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
#line 17839 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr549;
		case 47: goto st358;
		case 58: goto tr572;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 45 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr574;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr574;
	} else
		goto tr574;
	goto tr0;
tr570:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 17883 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr504;
		case 37: goto tr505;
		case 44: goto tr434;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto tr434;
		case 64: goto tr506;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto tr504;
		case 126: goto tr504;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 46 )
			goto tr504;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr504;
		} else if ( (*p) >= 65 )
			goto tr504;
	} else
		goto tr578;
	goto tr0;
tr578:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 17920 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr549;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 45 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr579;
	goto tr0;
tr579:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 17956 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr549;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 48 ) {
		if ( 36 <= (*p) && (*p) <= 45 )
			goto st362;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st362;
		} else if ( (*p) >= 65 )
			goto st362;
	} else
		goto tr580;
	goto tr0;
tr580:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 17992 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 46: goto tr549;
		case 47: goto st358;
		case 58: goto tr502;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto st362;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st362;
	} else
		goto st362;
	goto tr0;
tr548:
#line 9 "sip_uri.rl"
	{ uri->pass_start = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 18027 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st362;
		case 37: goto st363;
		case 44: goto st298;
		case 47: goto st358;
		case 58: goto tr542;
		case 59: goto st355;
		case 61: goto st298;
		case 64: goto tr509;
		case 91: goto st358;
		case 93: goto tr543;
		case 95: goto st362;
		case 126: goto st362;
	}
	if ( (*p) < 65 ) {
		if ( (*p) > 46 ) {
			if ( 48 <= (*p) && (*p) <= 57 )
				goto tr551;
		} else if ( (*p) >= 36 )
			goto st362;
	} else if ( (*p) > 70 ) {
		if ( (*p) < 97 ) {
			if ( 71 <= (*p) && (*p) <= 90 )
				goto st362;
		} else if ( (*p) > 102 ) {
			if ( 103 <= (*p) && (*p) <= 122 )
				goto st362;
		} else
			goto tr551;
	} else
		goto tr551;
	goto tr0;
tr540:
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st426;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
#line 18070 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto tr504;
		case 37: goto tr505;
		case 44: goto tr434;
		case 47: goto st358;
		case 58: goto tr547;
		case 59: goto st355;
		case 61: goto tr434;
		case 64: goto tr506;
		case 91: goto st358;
		case 93: goto st358;
		case 95: goto tr504;
		case 126: goto tr504;
	}
	if ( (*p) < 65 ) {
		if ( 36 <= (*p) && (*p) <= 57 )
			goto tr504;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr504;
	} else
		goto tr504;
	goto tr0;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st365;
			} else if ( (*p) >= 43 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st457;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st459;
			} else if ( (*p) >= 97 )
				goto st457;
		} else
			goto st459;
	} else
		goto st428;
	goto tr0;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st429;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st434;
	goto tr0;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st365;
			} else if ( (*p) >= 43 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st457;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st459;
			} else if ( (*p) >= 97 )
				goto st457;
		} else
			goto st459;
	} else
		goto st430;
	goto tr0;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st431;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st432;
	goto tr0;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 47: goto st294;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( (*p) > 44 ) {
				if ( 45 <= (*p) && (*p) <= 46 )
					goto st365;
			} else if ( (*p) >= 43 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st457;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st459;
			} else if ( (*p) >= 97 )
				goto st457;
		} else
			goto st459;
	} else
		goto st479;
	goto tr0;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 44: goto tr620;
		case 45: goto st373;
		case 46: goto st375;
		case 58: goto tr622;
		case 59: goto tr623;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st480;
	goto tr605;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 44: goto tr620;
		case 45: goto st373;
		case 46: goto st375;
		case 58: goto tr622;
		case 59: goto tr623;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st481;
	goto tr605;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	switch( (*p) ) {
		case 9: goto tr606;
		case 13: goto tr607;
		case 32: goto tr606;
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 44: goto tr620;
		case 45: goto st373;
		case 46: goto st375;
		case 58: goto tr622;
		case 59: goto tr623;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st374;
	goto tr605;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st431;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st433;
	goto tr0;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st431;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st374;
	goto tr0;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st429;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st435;
	goto tr0;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st429;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st374;
	goto tr0;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st427;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st437;
	goto tr0;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
	switch( (*p) ) {
		case 33: goto st294;
		case 35: goto st354;
		case 37: goto st295;
		case 45: goto st373;
		case 46: goto st427;
		case 58: goto tr431;
		case 59: goto st366;
		case 61: goto st294;
		case 63: goto st294;
		case 64: goto tr432;
		case 95: goto st294;
		case 126: goto st294;
	}
	if ( (*p) < 48 ) {
		if ( (*p) < 40 ) {
			if ( 36 <= (*p) && (*p) <= 39 )
				goto st294;
		} else if ( (*p) > 42 ) {
			if ( 43 <= (*p) && (*p) <= 47 )
				goto st294;
		} else
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) < 71 ) {
			if ( 65 <= (*p) && (*p) <= 70 )
				goto st374;
		} else if ( (*p) > 90 ) {
			if ( (*p) > 102 ) {
				if ( 103 <= (*p) && (*p) <= 122 )
					goto st378;
			} else if ( (*p) >= 97 )
				goto st374;
		} else
			goto st378;
	} else
		goto st374;
	goto tr0;
tr417:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
#line 13 "sip_uri.rl"
	{ uri->scheme_stop = p; }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 18710 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st286;
		case 13: goto st287;
		case 32: goto st286;
		case 33: goto tr408;
		case 37: goto tr408;
		case 39: goto tr408;
		case 58: goto st293;
		case 126: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr408;
		} else if ( (*p) >= 42 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr0;
tr7:
#line 158 "sip_parser.rl"
	{ na->name_start = p; }
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
#line 7 "sip_uri.rl"
	{ uri->scheme_start = p; }
	goto st439;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
#line 18748 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st286;
		case 13: goto st287;
		case 32: goto st286;
		case 33: goto tr408;
		case 37: goto tr408;
		case 39: goto tr408;
		case 69: goto tr591;
		case 101: goto tr591;
		case 126: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr408;
		} else if ( (*p) >= 42 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr0;
tr591:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 18783 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st286;
		case 13: goto st287;
		case 32: goto st286;
		case 33: goto tr408;
		case 37: goto tr408;
		case 39: goto tr408;
		case 76: goto tr592;
		case 108: goto tr592;
		case 126: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr408;
		} else if ( (*p) >= 42 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr0;
tr592:
#line 159 "sip_parser.rl"
	{ na->name_stop = p; }
#line 13 "sip_uri.rl"
	{ uri->scheme_stop = p; }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 18820 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st286;
		case 13: goto st287;
		case 32: goto st286;
		case 33: goto tr408;
		case 37: goto tr408;
		case 39: goto tr408;
		case 58: goto st482;
		case 126: goto tr408;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr408;
		} else if ( (*p) >= 42 )
			goto tr408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr408;
		} else if ( (*p) >= 65 )
			goto tr408;
	} else
		goto tr408;
	goto tr0;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
	switch( (*p) ) {
		case 9: goto tr656;
		case 13: goto tr657;
		case 32: goto tr656;
		case 35: goto tr658;
		case 44: goto tr659;
		case 59: goto tr660;
	}
	if ( (*p) < 48 ) {
		if ( 40 <= (*p) && (*p) <= 46 )
			goto tr658;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto tr658;
		} else if ( (*p) >= 65 )
			goto tr658;
	} else
		goto tr658;
	goto tr655;
tr658:
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 18878 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr662;
		case 13: goto tr663;
		case 32: goto tr662;
		case 35: goto st483;
		case 44: goto tr665;
		case 59: goto tr666;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 42 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st483;
		} else if ( (*p) >= 40 )
			goto st483;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 70 ) {
			if ( 97 <= (*p) && (*p) <= 102 )
				goto st483;
		} else if ( (*p) >= 65 )
			goto st483;
	} else
		goto st483;
	goto tr661;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof442: cs = 442; goto _test_eof; 
	_test_eof443: cs = 443; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof444: cs = 444; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof445: cs = 445; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof446: cs = 446; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof447: cs = 447; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof448: cs = 448; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof449: cs = 449; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof227: cs = 227; goto _test_eof; 
	_test_eof228: cs = 228; goto _test_eof; 
	_test_eof229: cs = 229; goto _test_eof; 
	_test_eof230: cs = 230; goto _test_eof; 
	_test_eof231: cs = 231; goto _test_eof; 
	_test_eof232: cs = 232; goto _test_eof; 
	_test_eof233: cs = 233; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof235: cs = 235; goto _test_eof; 
	_test_eof236: cs = 236; goto _test_eof; 
	_test_eof237: cs = 237; goto _test_eof; 
	_test_eof238: cs = 238; goto _test_eof; 
	_test_eof239: cs = 239; goto _test_eof; 
	_test_eof240: cs = 240; goto _test_eof; 
	_test_eof241: cs = 241; goto _test_eof; 
	_test_eof242: cs = 242; goto _test_eof; 
	_test_eof243: cs = 243; goto _test_eof; 
	_test_eof244: cs = 244; goto _test_eof; 
	_test_eof245: cs = 245; goto _test_eof; 
	_test_eof246: cs = 246; goto _test_eof; 
	_test_eof247: cs = 247; goto _test_eof; 
	_test_eof248: cs = 248; goto _test_eof; 
	_test_eof249: cs = 249; goto _test_eof; 
	_test_eof250: cs = 250; goto _test_eof; 
	_test_eof251: cs = 251; goto _test_eof; 
	_test_eof252: cs = 252; goto _test_eof; 
	_test_eof253: cs = 253; goto _test_eof; 
	_test_eof254: cs = 254; goto _test_eof; 
	_test_eof255: cs = 255; goto _test_eof; 
	_test_eof256: cs = 256; goto _test_eof; 
	_test_eof257: cs = 257; goto _test_eof; 
	_test_eof258: cs = 258; goto _test_eof; 
	_test_eof259: cs = 259; goto _test_eof; 
	_test_eof260: cs = 260; goto _test_eof; 
	_test_eof261: cs = 261; goto _test_eof; 
	_test_eof262: cs = 262; goto _test_eof; 
	_test_eof263: cs = 263; goto _test_eof; 
	_test_eof264: cs = 264; goto _test_eof; 
	_test_eof265: cs = 265; goto _test_eof; 
	_test_eof266: cs = 266; goto _test_eof; 
	_test_eof267: cs = 267; goto _test_eof; 
	_test_eof268: cs = 268; goto _test_eof; 
	_test_eof269: cs = 269; goto _test_eof; 
	_test_eof270: cs = 270; goto _test_eof; 
	_test_eof271: cs = 271; goto _test_eof; 
	_test_eof272: cs = 272; goto _test_eof; 
	_test_eof273: cs = 273; goto _test_eof; 
	_test_eof274: cs = 274; goto _test_eof; 
	_test_eof275: cs = 275; goto _test_eof; 
	_test_eof276: cs = 276; goto _test_eof; 
	_test_eof277: cs = 277; goto _test_eof; 
	_test_eof278: cs = 278; goto _test_eof; 
	_test_eof279: cs = 279; goto _test_eof; 
	_test_eof280: cs = 280; goto _test_eof; 
	_test_eof281: cs = 281; goto _test_eof; 
	_test_eof282: cs = 282; goto _test_eof; 
	_test_eof283: cs = 283; goto _test_eof; 
	_test_eof284: cs = 284; goto _test_eof; 
	_test_eof285: cs = 285; goto _test_eof; 
	_test_eof286: cs = 286; goto _test_eof; 
	_test_eof287: cs = 287; goto _test_eof; 
	_test_eof288: cs = 288; goto _test_eof; 
	_test_eof289: cs = 289; goto _test_eof; 
	_test_eof290: cs = 290; goto _test_eof; 
	_test_eof291: cs = 291; goto _test_eof; 
	_test_eof292: cs = 292; goto _test_eof; 
	_test_eof293: cs = 293; goto _test_eof; 
	_test_eof294: cs = 294; goto _test_eof; 
	_test_eof295: cs = 295; goto _test_eof; 
	_test_eof296: cs = 296; goto _test_eof; 
	_test_eof297: cs = 297; goto _test_eof; 
	_test_eof298: cs = 298; goto _test_eof; 
	_test_eof299: cs = 299; goto _test_eof; 
	_test_eof300: cs = 300; goto _test_eof; 
	_test_eof301: cs = 301; goto _test_eof; 
	_test_eof302: cs = 302; goto _test_eof; 
	_test_eof303: cs = 303; goto _test_eof; 
	_test_eof304: cs = 304; goto _test_eof; 
	_test_eof305: cs = 305; goto _test_eof; 
	_test_eof450: cs = 450; goto _test_eof; 
	_test_eof306: cs = 306; goto _test_eof; 
	_test_eof451: cs = 451; goto _test_eof; 
	_test_eof307: cs = 307; goto _test_eof; 
	_test_eof452: cs = 452; goto _test_eof; 
	_test_eof308: cs = 308; goto _test_eof; 
	_test_eof309: cs = 309; goto _test_eof; 
	_test_eof310: cs = 310; goto _test_eof; 
	_test_eof311: cs = 311; goto _test_eof; 
	_test_eof312: cs = 312; goto _test_eof; 
	_test_eof453: cs = 453; goto _test_eof; 
	_test_eof454: cs = 454; goto _test_eof; 
	_test_eof455: cs = 455; goto _test_eof; 
	_test_eof313: cs = 313; goto _test_eof; 
	_test_eof314: cs = 314; goto _test_eof; 
	_test_eof315: cs = 315; goto _test_eof; 
	_test_eof316: cs = 316; goto _test_eof; 
	_test_eof317: cs = 317; goto _test_eof; 
	_test_eof318: cs = 318; goto _test_eof; 
	_test_eof319: cs = 319; goto _test_eof; 
	_test_eof320: cs = 320; goto _test_eof; 
	_test_eof321: cs = 321; goto _test_eof; 
	_test_eof322: cs = 322; goto _test_eof; 
	_test_eof323: cs = 323; goto _test_eof; 
	_test_eof324: cs = 324; goto _test_eof; 
	_test_eof325: cs = 325; goto _test_eof; 
	_test_eof326: cs = 326; goto _test_eof; 
	_test_eof327: cs = 327; goto _test_eof; 
	_test_eof328: cs = 328; goto _test_eof; 
	_test_eof329: cs = 329; goto _test_eof; 
	_test_eof330: cs = 330; goto _test_eof; 
	_test_eof331: cs = 331; goto _test_eof; 
	_test_eof332: cs = 332; goto _test_eof; 
	_test_eof333: cs = 333; goto _test_eof; 
	_test_eof456: cs = 456; goto _test_eof; 
	_test_eof334: cs = 334; goto _test_eof; 
	_test_eof335: cs = 335; goto _test_eof; 
	_test_eof336: cs = 336; goto _test_eof; 
	_test_eof337: cs = 337; goto _test_eof; 
	_test_eof338: cs = 338; goto _test_eof; 
	_test_eof339: cs = 339; goto _test_eof; 
	_test_eof340: cs = 340; goto _test_eof; 
	_test_eof341: cs = 341; goto _test_eof; 
	_test_eof342: cs = 342; goto _test_eof; 
	_test_eof343: cs = 343; goto _test_eof; 
	_test_eof344: cs = 344; goto _test_eof; 
	_test_eof345: cs = 345; goto _test_eof; 
	_test_eof346: cs = 346; goto _test_eof; 
	_test_eof347: cs = 347; goto _test_eof; 
	_test_eof348: cs = 348; goto _test_eof; 
	_test_eof349: cs = 349; goto _test_eof; 
	_test_eof350: cs = 350; goto _test_eof; 
	_test_eof351: cs = 351; goto _test_eof; 
	_test_eof352: cs = 352; goto _test_eof; 
	_test_eof353: cs = 353; goto _test_eof; 
	_test_eof354: cs = 354; goto _test_eof; 
	_test_eof355: cs = 355; goto _test_eof; 
	_test_eof356: cs = 356; goto _test_eof; 
	_test_eof357: cs = 357; goto _test_eof; 
	_test_eof358: cs = 358; goto _test_eof; 
	_test_eof359: cs = 359; goto _test_eof; 
	_test_eof360: cs = 360; goto _test_eof; 
	_test_eof361: cs = 361; goto _test_eof; 
	_test_eof362: cs = 362; goto _test_eof; 
	_test_eof363: cs = 363; goto _test_eof; 
	_test_eof364: cs = 364; goto _test_eof; 
	_test_eof365: cs = 365; goto _test_eof; 
	_test_eof366: cs = 366; goto _test_eof; 
	_test_eof367: cs = 367; goto _test_eof; 
	_test_eof368: cs = 368; goto _test_eof; 
	_test_eof369: cs = 369; goto _test_eof; 
	_test_eof370: cs = 370; goto _test_eof; 
	_test_eof371: cs = 371; goto _test_eof; 
	_test_eof372: cs = 372; goto _test_eof; 
	_test_eof373: cs = 373; goto _test_eof; 
	_test_eof374: cs = 374; goto _test_eof; 
	_test_eof375: cs = 375; goto _test_eof; 
	_test_eof457: cs = 457; goto _test_eof; 
	_test_eof458: cs = 458; goto _test_eof; 
	_test_eof376: cs = 376; goto _test_eof; 
	_test_eof459: cs = 459; goto _test_eof; 
	_test_eof377: cs = 377; goto _test_eof; 
	_test_eof460: cs = 460; goto _test_eof; 
	_test_eof378: cs = 378; goto _test_eof; 
	_test_eof379: cs = 379; goto _test_eof; 
	_test_eof380: cs = 380; goto _test_eof; 
	_test_eof381: cs = 381; goto _test_eof; 
	_test_eof461: cs = 461; goto _test_eof; 
	_test_eof462: cs = 462; goto _test_eof; 
	_test_eof382: cs = 382; goto _test_eof; 
	_test_eof463: cs = 463; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof465: cs = 465; goto _test_eof; 
	_test_eof383: cs = 383; goto _test_eof; 
	_test_eof466: cs = 466; goto _test_eof; 
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 
	_test_eof469: cs = 469; goto _test_eof; 
	_test_eof384: cs = 384; goto _test_eof; 
	_test_eof470: cs = 470; goto _test_eof; 
	_test_eof385: cs = 385; goto _test_eof; 
	_test_eof471: cs = 471; goto _test_eof; 
	_test_eof472: cs = 472; goto _test_eof; 
	_test_eof473: cs = 473; goto _test_eof; 
	_test_eof386: cs = 386; goto _test_eof; 
	_test_eof387: cs = 387; goto _test_eof; 
	_test_eof388: cs = 388; goto _test_eof; 
	_test_eof389: cs = 389; goto _test_eof; 
	_test_eof390: cs = 390; goto _test_eof; 
	_test_eof391: cs = 391; goto _test_eof; 
	_test_eof392: cs = 392; goto _test_eof; 
	_test_eof393: cs = 393; goto _test_eof; 
	_test_eof394: cs = 394; goto _test_eof; 
	_test_eof395: cs = 395; goto _test_eof; 
	_test_eof396: cs = 396; goto _test_eof; 
	_test_eof397: cs = 397; goto _test_eof; 
	_test_eof398: cs = 398; goto _test_eof; 
	_test_eof399: cs = 399; goto _test_eof; 
	_test_eof400: cs = 400; goto _test_eof; 
	_test_eof474: cs = 474; goto _test_eof; 
	_test_eof401: cs = 401; goto _test_eof; 
	_test_eof475: cs = 475; goto _test_eof; 
	_test_eof402: cs = 402; goto _test_eof; 
	_test_eof476: cs = 476; goto _test_eof; 
	_test_eof477: cs = 477; goto _test_eof; 
	_test_eof478: cs = 478; goto _test_eof; 
	_test_eof403: cs = 403; goto _test_eof; 
	_test_eof404: cs = 404; goto _test_eof; 
	_test_eof405: cs = 405; goto _test_eof; 
	_test_eof406: cs = 406; goto _test_eof; 
	_test_eof407: cs = 407; goto _test_eof; 
	_test_eof408: cs = 408; goto _test_eof; 
	_test_eof409: cs = 409; goto _test_eof; 
	_test_eof410: cs = 410; goto _test_eof; 
	_test_eof411: cs = 411; goto _test_eof; 
	_test_eof412: cs = 412; goto _test_eof; 
	_test_eof413: cs = 413; goto _test_eof; 
	_test_eof414: cs = 414; goto _test_eof; 
	_test_eof415: cs = 415; goto _test_eof; 
	_test_eof416: cs = 416; goto _test_eof; 
	_test_eof417: cs = 417; goto _test_eof; 
	_test_eof418: cs = 418; goto _test_eof; 
	_test_eof419: cs = 419; goto _test_eof; 
	_test_eof420: cs = 420; goto _test_eof; 
	_test_eof421: cs = 421; goto _test_eof; 
	_test_eof422: cs = 422; goto _test_eof; 
	_test_eof423: cs = 423; goto _test_eof; 
	_test_eof424: cs = 424; goto _test_eof; 
	_test_eof425: cs = 425; goto _test_eof; 
	_test_eof426: cs = 426; goto _test_eof; 
	_test_eof427: cs = 427; goto _test_eof; 
	_test_eof428: cs = 428; goto _test_eof; 
	_test_eof429: cs = 429; goto _test_eof; 
	_test_eof430: cs = 430; goto _test_eof; 
	_test_eof431: cs = 431; goto _test_eof; 
	_test_eof479: cs = 479; goto _test_eof; 
	_test_eof480: cs = 480; goto _test_eof; 
	_test_eof481: cs = 481; goto _test_eof; 
	_test_eof432: cs = 432; goto _test_eof; 
	_test_eof433: cs = 433; goto _test_eof; 
	_test_eof434: cs = 434; goto _test_eof; 
	_test_eof435: cs = 435; goto _test_eof; 
	_test_eof436: cs = 436; goto _test_eof; 
	_test_eof437: cs = 437; goto _test_eof; 
	_test_eof438: cs = 438; goto _test_eof; 
	_test_eof439: cs = 439; goto _test_eof; 
	_test_eof440: cs = 440; goto _test_eof; 
	_test_eof441: cs = 441; goto _test_eof; 
	_test_eof482: cs = 482; goto _test_eof; 
	_test_eof483: cs = 483; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 450: 
	case 451: 
	case 453: 
	case 454: 
	case 455: 
	case 456: 
	case 457: 
	case 459: 
	case 460: 
	case 469: 
	case 479: 
	case 480: 
	case 481: 
#line 16 "sip_uri.rl"
	{ uri->host_stop = p - 1; }
	break;
	case 452: 
	case 461: 
#line 17 "sip_uri.rl"
	{ uri->port_stop = p - 1; }
	break;
	case 447: 
	case 463: 
	case 464: 
	case 465: 
	case 470: 
	case 475: 
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	break;
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
	case 12: 
	case 13: 
	case 14: 
	case 15: 
	case 16: 
	case 17: 
	case 18: 
	case 19: 
	case 20: 
	case 21: 
	case 22: 
	case 23: 
	case 24: 
	case 25: 
	case 26: 
	case 27: 
	case 28: 
	case 29: 
	case 30: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
	case 37: 
	case 38: 
	case 39: 
	case 40: 
	case 41: 
	case 42: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
	case 48: 
	case 49: 
	case 50: 
	case 51: 
	case 52: 
	case 53: 
	case 54: 
	case 55: 
	case 56: 
	case 57: 
	case 58: 
	case 59: 
	case 60: 
	case 61: 
	case 62: 
	case 63: 
	case 64: 
	case 65: 
	case 66: 
	case 67: 
	case 68: 
	case 69: 
	case 70: 
	case 71: 
	case 72: 
	case 73: 
	case 74: 
	case 75: 
	case 76: 
	case 77: 
	case 78: 
	case 79: 
	case 80: 
	case 81: 
	case 82: 
	case 83: 
	case 84: 
	case 85: 
	case 86: 
	case 87: 
	case 88: 
	case 89: 
	case 90: 
	case 91: 
	case 92: 
	case 93: 
	case 94: 
	case 95: 
	case 96: 
	case 97: 
	case 98: 
	case 99: 
	case 100: 
	case 101: 
	case 102: 
	case 103: 
	case 104: 
	case 105: 
	case 106: 
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
	case 112: 
	case 113: 
	case 114: 
	case 115: 
	case 116: 
	case 117: 
	case 118: 
	case 119: 
	case 120: 
	case 121: 
	case 122: 
	case 123: 
	case 124: 
	case 125: 
	case 126: 
	case 127: 
	case 128: 
	case 129: 
	case 130: 
	case 131: 
	case 132: 
	case 133: 
	case 134: 
	case 135: 
	case 136: 
	case 137: 
	case 138: 
	case 139: 
	case 140: 
	case 141: 
	case 142: 
	case 143: 
	case 144: 
	case 145: 
	case 146: 
	case 147: 
	case 148: 
	case 149: 
	case 150: 
	case 151: 
	case 152: 
	case 153: 
	case 154: 
	case 155: 
	case 156: 
	case 157: 
	case 158: 
	case 159: 
	case 160: 
	case 161: 
	case 162: 
	case 163: 
	case 164: 
	case 165: 
	case 166: 
	case 167: 
	case 168: 
	case 169: 
	case 170: 
	case 171: 
	case 172: 
	case 173: 
	case 174: 
	case 175: 
	case 176: 
	case 177: 
	case 178: 
	case 179: 
	case 180: 
	case 181: 
	case 182: 
	case 183: 
	case 184: 
	case 185: 
	case 186: 
	case 187: 
	case 188: 
	case 189: 
	case 190: 
	case 191: 
	case 192: 
	case 193: 
	case 194: 
	case 195: 
	case 196: 
	case 197: 
	case 198: 
	case 199: 
	case 200: 
	case 201: 
	case 202: 
	case 203: 
	case 204: 
	case 205: 
	case 206: 
	case 207: 
	case 208: 
	case 209: 
	case 210: 
	case 211: 
	case 212: 
	case 213: 
	case 214: 
	case 215: 
	case 216: 
	case 217: 
	case 218: 
	case 219: 
	case 220: 
	case 221: 
	case 222: 
	case 223: 
	case 224: 
	case 225: 
	case 226: 
	case 227: 
	case 228: 
	case 229: 
	case 230: 
	case 231: 
	case 232: 
	case 233: 
	case 234: 
	case 235: 
	case 236: 
	case 237: 
	case 238: 
	case 239: 
	case 240: 
	case 241: 
	case 242: 
	case 243: 
	case 244: 
	case 245: 
	case 246: 
	case 247: 
	case 248: 
	case 249: 
	case 250: 
	case 251: 
	case 252: 
	case 253: 
	case 254: 
	case 255: 
	case 256: 
	case 257: 
	case 258: 
	case 259: 
	case 260: 
	case 261: 
	case 262: 
	case 263: 
	case 264: 
	case 265: 
	case 266: 
	case 267: 
	case 268: 
	case 269: 
	case 270: 
	case 271: 
	case 272: 
	case 273: 
	case 274: 
	case 275: 
	case 276: 
	case 277: 
	case 278: 
	case 279: 
	case 280: 
	case 281: 
	case 282: 
	case 283: 
	case 284: 
	case 285: 
	case 286: 
	case 287: 
	case 288: 
	case 289: 
	case 290: 
	case 291: 
	case 292: 
	case 293: 
	case 294: 
	case 295: 
	case 296: 
	case 297: 
	case 298: 
	case 299: 
	case 300: 
	case 301: 
	case 302: 
	case 303: 
	case 304: 
	case 305: 
	case 306: 
	case 307: 
	case 308: 
	case 309: 
	case 310: 
	case 311: 
	case 312: 
	case 313: 
	case 314: 
	case 315: 
	case 316: 
	case 317: 
	case 318: 
	case 319: 
	case 320: 
	case 321: 
	case 322: 
	case 323: 
	case 324: 
	case 325: 
	case 326: 
	case 327: 
	case 328: 
	case 329: 
	case 330: 
	case 331: 
	case 332: 
	case 333: 
	case 334: 
	case 335: 
	case 336: 
	case 337: 
	case 338: 
	case 339: 
	case 340: 
	case 341: 
	case 342: 
	case 343: 
	case 344: 
	case 345: 
	case 346: 
	case 347: 
	case 348: 
	case 349: 
	case 350: 
	case 351: 
	case 352: 
	case 353: 
	case 354: 
	case 355: 
	case 356: 
	case 357: 
	case 358: 
	case 359: 
	case 360: 
	case 361: 
	case 362: 
	case 363: 
	case 364: 
	case 365: 
	case 366: 
	case 367: 
	case 368: 
	case 369: 
	case 370: 
	case 371: 
	case 372: 
	case 373: 
	case 374: 
	case 375: 
	case 376: 
	case 377: 
	case 378: 
	case 379: 
	case 380: 
	case 381: 
	case 382: 
	case 383: 
	case 384: 
	case 385: 
	case 386: 
	case 387: 
	case 388: 
	case 389: 
	case 390: 
	case 391: 
	case 392: 
	case 393: 
	case 394: 
	case 395: 
	case 396: 
	case 397: 
	case 398: 
	case 399: 
	case 400: 
	case 401: 
	case 402: 
	case 403: 
	case 404: 
	case 405: 
	case 406: 
	case 407: 
	case 408: 
	case 409: 
	case 410: 
	case 411: 
	case 412: 
	case 413: 
	case 414: 
	case 415: 
	case 416: 
	case 417: 
	case 418: 
	case 419: 
	case 420: 
	case 421: 
	case 422: 
	case 423: 
	case 424: 
	case 425: 
	case 426: 
	case 427: 
	case 428: 
	case 429: 
	case 430: 
	case 431: 
	case 432: 
	case 433: 
	case 434: 
	case 435: 
	case 436: 
	case 437: 
	case 438: 
	case 439: 
	case 440: 
	case 441: 
#line 162 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	break;
	case 483: 
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	break;
	case 482: 
#line 8 "sip_uri.rl"
	{ uri->user_start = p; }
#line 14 "sip_uri.rl"
	{ uri->user_stop = p - 1; }
#line 19 "sip_uri.rl"
	{ uri->userinfo_complete = true; }
	break;
#line 19878 "sip_parser.c"
	}
	}

	_out: {}
	}

#line 187 "sip_parser.rl"
  // clang-format on

done:
  return ret;
}

// clang-format off

#line 208 "sip_parser.rl"



#line 19898 "sip_parser.c"
static const int sip_parser_cseq_start = 1;
static const int sip_parser_cseq_first_final = 7;
static const int sip_parser_cseq_error = 0;

static const int sip_parser_cseq_en_main = 1;


#line 211 "sip_parser.rl"
// clang-format on

int decode_cseq(size_t size, char *buf, char **err, cseq_state_t *cseq) {
  int cs = 0;
  int ret = R_SUCCESS;

  char *p = buf;
  char *pe = p + size;
  char *eof = pe;

  // clang-format off
  
#line 19919 "sip_parser.c"
	{
	cs = sip_parser_cseq_start;
	}

#line 223 "sip_parser.rl"
  
#line 19926 "sip_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr1;
	goto tr0;
tr0:
#line 203 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	goto st0;
#line 19940 "sip_parser.c"
st0:
cs = 0;
	goto _out;
tr1:
#line 199 "sip_parser.rl"
	{ cseq->n_start = p; }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 19952 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr2;
		case 13: goto tr3;
		case 32: goto tr2;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st2;
	goto tr0;
tr2:
#line 200 "sip_parser.rl"
	{ cseq->n_stop = p - 1; }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 19969 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st3;
		case 13: goto st4;
		case 32: goto st3;
		case 33: goto tr7;
		case 37: goto tr7;
		case 39: goto tr7;
		case 126: goto tr7;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr7;
		} else if ( (*p) >= 42 )
			goto tr7;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr7;
		} else if ( (*p) >= 65 )
			goto tr7;
	} else
		goto tr7;
	goto tr0;
tr3:
#line 200 "sip_parser.rl"
	{ cseq->n_stop = p - 1; }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 20002 "sip_parser.c"
	if ( (*p) == 10 )
		goto st5;
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	switch( (*p) ) {
		case 9: goto st6;
		case 32: goto st6;
	}
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	switch( (*p) ) {
		case 9: goto st6;
		case 32: goto st6;
		case 33: goto tr7;
		case 37: goto tr7;
		case 39: goto tr7;
		case 126: goto tr7;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr7;
		} else if ( (*p) >= 42 )
			goto tr7;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr7;
		} else if ( (*p) >= 65 )
			goto tr7;
	} else
		goto tr7;
	goto tr0;
tr7:
#line 201 "sip_parser.rl"
	{ cseq->method_start = p; }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 20050 "sip_parser.c"
	switch( (*p) ) {
		case 33: goto st7;
		case 37: goto st7;
		case 39: goto st7;
		case 126: goto st7;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto st7;
		} else if ( (*p) >= 42 )
			goto st7;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st7;
		} else if ( (*p) >= 65 )
			goto st7;
	} else
		goto st7;
	goto tr0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 7: 
#line 202 "sip_parser.rl"
	{ cseq->method_stop = p - 1; }
	break;
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
#line 203 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	break;
#line 20097 "sip_parser.c"
	}
	}

	_out: {}
	}

#line 224 "sip_parser.rl"
  // clang-format on

done:
  return ret;
}

// clang-format off

#line 244 "sip_parser.rl"



#line 20117 "sip_parser.c"
static const int sip_parser_token_params_start = 1;
static const int sip_parser_token_params_first_final = 67;
static const int sip_parser_token_params_error = 0;

static const int sip_parser_token_params_en_main = 1;


#line 247 "sip_parser.rl"
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
  
#line 20140 "sip_parser.c"
	{
	cs = sip_parser_token_params_start;
	}

#line 261 "sip_parser.rl"
  
#line 20147 "sip_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 33: goto tr1;
		case 37: goto tr1;
		case 39: goto tr1;
		case 126: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr1;
		} else if ( (*p) >= 42 )
			goto tr1;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr1;
		} else if ( (*p) >= 65 )
			goto tr1;
	} else
		goto tr1;
	goto tr0;
tr0:
#line 240 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	goto st0;
#line 20179 "sip_parser.c"
st0:
cs = 0;
	goto _out;
tr1:
#line 237 "sip_parser.rl"
	{ tok->token_start = p; }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 20191 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr75;
		case 13: goto tr76;
		case 32: goto tr75;
		case 33: goto st67;
		case 37: goto st67;
		case 39: goto st67;
		case 44: goto tr78;
		case 59: goto tr79;
		case 126: goto st67;
	}
	if ( (*p) < 48 ) {
		if ( 42 <= (*p) && (*p) <= 46 )
			goto st67;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st67;
		} else if ( (*p) >= 65 )
			goto st67;
	} else
		goto st67;
	goto tr74;
tr74:
#line 238 "sip_parser.rl"
	{ tok->token_stop = p - 1; }
#line 239 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st68;
tr80:
#line 239 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st68;
tr82:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
#line 239 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 20235 "sip_parser.c"
	goto tr80;
tr75:
#line 238 "sip_parser.rl"
	{ tok->token_stop = p - 1; }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 20245 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st2;
		case 13: goto st3;
		case 32: goto st2;
		case 44: goto st69;
		case 59: goto st8;
	}
	goto tr0;
tr76:
#line 238 "sip_parser.rl"
	{ tok->token_stop = p - 1; }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 20262 "sip_parser.c"
	if ( (*p) == 10 )
		goto st4;
	goto tr0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	switch( (*p) ) {
		case 9: goto st5;
		case 32: goto st5;
	}
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	switch( (*p) ) {
		case 9: goto st5;
		case 32: goto st5;
		case 44: goto st69;
		case 59: goto st8;
	}
	goto tr0;
tr78:
#line 238 "sip_parser.rl"
	{ tok->token_stop = p - 1; }
	goto st69;
tr86:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 20298 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st69;
		case 13: goto st6;
		case 32: goto st69;
	}
	goto tr80;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 10 )
		goto st7;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	switch( (*p) ) {
		case 9: goto st70;
		case 32: goto st70;
	}
	goto tr0;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 9: goto st70;
		case 32: goto st70;
	}
	goto tr80;
tr79:
#line 238 "sip_parser.rl"
	{ tok->token_stop = p - 1; }
	goto st8;
tr87:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 20342 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st8;
		case 13: goto st9;
		case 32: goto st8;
		case 33: goto tr11;
		case 37: goto tr11;
		case 39: goto tr11;
		case 126: goto tr11;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr11;
		} else if ( (*p) >= 42 )
			goto tr11;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr11;
		} else if ( (*p) >= 65 )
			goto tr11;
	} else
		goto tr11;
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 10 )
		goto st10;
	goto tr0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	switch( (*p) ) {
		case 9: goto st11;
		case 32: goto st11;
	}
	goto tr0;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	switch( (*p) ) {
		case 9: goto st11;
		case 32: goto st11;
		case 33: goto tr11;
		case 37: goto tr11;
		case 39: goto tr11;
		case 126: goto tr11;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr11;
		} else if ( (*p) >= 42 )
			goto tr11;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr11;
		} else if ( (*p) >= 65 )
			goto tr11;
	} else
		goto tr11;
	goto tr0;
tr11:
#line 7 "sip_params.rl"
	{
    if (kv->len == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(kv->key, 0, s);
      memset(kv->val, 0, s);
    }
    kv->i = kv->len;
    kv->len++;
  }
#line 17 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 0) = p; }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 20428 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr83;
		case 13: goto tr84;
		case 32: goto tr83;
		case 33: goto st71;
		case 37: goto st71;
		case 39: goto st71;
		case 44: goto tr86;
		case 59: goto tr87;
		case 61: goto tr88;
		case 126: goto st71;
	}
	if ( (*p) < 48 ) {
		if ( 42 <= (*p) && (*p) <= 46 )
			goto st71;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st71;
		} else if ( (*p) >= 65 )
			goto st71;
	} else
		goto st71;
	goto tr82;
tr83:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 20461 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st12;
		case 13: goto st13;
		case 32: goto st12;
		case 44: goto st69;
		case 59: goto st8;
		case 61: goto st16;
	}
	goto tr0;
tr84:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
#line 20479 "sip_parser.c"
	if ( (*p) == 10 )
		goto st14;
	goto tr0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	switch( (*p) ) {
		case 9: goto st15;
		case 32: goto st15;
	}
	goto tr0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	switch( (*p) ) {
		case 9: goto st15;
		case 32: goto st15;
		case 44: goto st69;
		case 59: goto st8;
		case 61: goto st16;
	}
	goto tr0;
tr19:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st16;
tr88:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 20518 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr19;
		case 13: goto tr20;
		case 32: goto tr19;
		case 33: goto tr21;
		case 34: goto tr22;
		case 37: goto tr21;
		case 39: goto tr21;
		case 91: goto tr23;
		case 126: goto tr21;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr21;
		} else if ( (*p) >= 42 )
			goto tr21;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr21;
		} else if ( (*p) >= 65 )
			goto tr21;
	} else
		goto tr21;
	goto tr0;
tr20:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 20555 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr24;
	goto tr0;
tr24:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 20567 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr25;
		case 32: goto tr25;
	}
	goto tr0;
tr26:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st19;
tr25:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 20587 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr26;
		case 13: goto tr27;
		case 32: goto tr26;
		case 33: goto tr21;
		case 34: goto tr22;
		case 37: goto tr21;
		case 39: goto tr21;
		case 91: goto tr23;
		case 126: goto tr21;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr21;
		} else if ( (*p) >= 42 )
			goto tr21;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr21;
		} else if ( (*p) >= 65 )
			goto tr21;
	} else
		goto tr21;
	goto tr0;
tr27:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 20624 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr28;
	goto tr0;
tr28:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 20636 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr29;
		case 32: goto tr29;
	}
	goto tr0;
tr29:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 20650 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr29;
		case 32: goto tr29;
		case 34: goto tr30;
	}
	goto tr0;
tr22:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st23;
tr30:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 20671 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr30;
		case 13: goto tr36;
		case 34: goto tr37;
		case 92: goto tr38;
	}
	if ( (*p) < -16 ) {
		if ( (*p) > -33 ) {
			if ( -32 <= (*p) && (*p) <= -17 )
				goto tr32;
		} else if ( (*p) >= -64 )
			goto tr31;
	} else if ( (*p) > -9 ) {
		if ( (*p) < -4 ) {
			if ( -8 <= (*p) && (*p) <= -5 )
				goto tr34;
		} else if ( (*p) > -3 ) {
			if ( 32 <= (*p) && (*p) <= 126 )
				goto tr30;
		} else
			goto tr35;
	} else
		goto tr33;
	goto tr0;
tr31:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 20704 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr30;
	goto tr0;
tr32:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 20716 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr31;
	goto tr0;
tr33:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 20728 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr32;
	goto tr0;
tr34:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 20740 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr33;
	goto tr0;
tr35:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 20752 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr34;
	goto tr0;
tr36:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 20764 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr39;
	goto tr0;
tr39:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 20776 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr30;
		case 32: goto tr30;
	}
	goto tr0;
tr37:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 20790 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st2;
		case 13: goto st3;
		case 32: goto st2;
		case 44: goto st69;
		case 59: goto st8;
	}
	goto tr80;
tr38:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 20807 "sip_parser.c"
	if ( (*p) < 11 ) {
		if ( 0 <= (*p) && (*p) <= 9 )
			goto tr30;
	} else if ( (*p) > 12 ) {
		if ( 14 <= (*p) )
			goto tr30;
	} else
		goto tr30;
	goto tr0;
tr21:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st73;
tr89:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 20831 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st2;
		case 13: goto st3;
		case 32: goto st2;
		case 33: goto tr89;
		case 37: goto tr89;
		case 39: goto tr89;
		case 44: goto st69;
		case 59: goto st8;
		case 126: goto tr89;
	}
	if ( (*p) < 48 ) {
		if ( 42 <= (*p) && (*p) <= 46 )
			goto tr89;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr89;
		} else if ( (*p) >= 65 )
			goto tr89;
	} else
		goto tr89;
	goto tr80;
tr23:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 20865 "sip_parser.c"
	if ( (*p) == 58 )
		goto tr41;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr40;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr40;
	} else
		goto tr40;
	goto tr0;
tr40:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 20885 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr43;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr42;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr42;
	} else
		goto tr42;
	goto tr0;
tr42:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 20907 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr43;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr44;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr44;
	} else
		goto tr44;
	goto tr0;
tr44:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 20929 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr43;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr45;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr45;
	} else
		goto tr45;
	goto tr0;
tr45:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 20951 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr43;
		case 93: goto tr37;
	}
	goto tr0;
tr43:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 20965 "sip_parser.c"
	if ( (*p) == 58 )
		goto tr47;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr46;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr40;
	} else
		goto tr40;
	goto tr0;
tr46:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 20985 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr48;
		case 58: goto tr43;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr49;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr42;
	} else
		goto tr42;
	goto tr0;
tr48:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 21008 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr50;
	goto tr0;
tr50:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 21020 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr51;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr52;
	goto tr0;
tr51:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 21034 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr53;
	goto tr0;
tr53:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 21046 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr54;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr55;
	goto tr0;
tr54:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 21060 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr56;
	goto tr0;
tr56:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 21072 "sip_parser.c"
	if ( (*p) == 93 )
		goto tr37;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr57;
	goto tr0;
tr57:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 21086 "sip_parser.c"
	if ( (*p) == 93 )
		goto tr37;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr58;
	goto tr0;
tr58:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 21100 "sip_parser.c"
	if ( (*p) == 93 )
		goto tr37;
	goto tr0;
tr55:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 21112 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr54;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr59;
	goto tr0;
tr59:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 21126 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr54;
	goto tr0;
tr52:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 21138 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr51;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr60;
	goto tr0;
tr60:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 21152 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr51;
	goto tr0;
tr49:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 21164 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr48;
		case 58: goto tr43;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr61;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr44;
	} else
		goto tr44;
	goto tr0;
tr61:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 21187 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr48;
		case 58: goto tr43;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr45;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr45;
	} else
		goto tr45;
	goto tr0;
tr47:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 21210 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr63;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr62;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr62;
	} else
		goto tr62;
	goto tr0;
tr62:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 21232 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr65;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr64;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr64;
	} else
		goto tr64;
	goto tr0;
tr64:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 21254 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr65;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr66;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr66;
	} else
		goto tr66;
	goto tr0;
tr66:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 21276 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr65;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr67;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr67;
	} else
		goto tr67;
	goto tr0;
tr67:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 21298 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr65;
		case 93: goto tr37;
	}
	goto tr0;
tr65:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 21312 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr68;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr62;
	} else
		goto tr62;
	goto tr0;
tr68:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 21330 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr48;
		case 58: goto tr65;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr69;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr64;
	} else
		goto tr64;
	goto tr0;
tr69:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 21353 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr48;
		case 58: goto tr65;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr70;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr66;
	} else
		goto tr66;
	goto tr0;
tr70:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 21376 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr48;
		case 58: goto tr65;
		case 93: goto tr37;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr67;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr67;
	} else
		goto tr67;
	goto tr0;
tr63:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 21399 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr71;
	goto tr0;
tr71:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 21411 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr48;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr72;
	goto tr0;
tr72:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 21425 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr48;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr73;
	goto tr0;
tr73:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 21439 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr48;
	goto tr0;
tr41:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 21451 "sip_parser.c"
	if ( (*p) == 58 )
		goto tr47;
	goto tr0;
	}
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 71: 
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	break;
	case 67: 
#line 238 "sip_parser.rl"
	{ tok->token_stop = p - 1; }
	break;
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
	case 12: 
	case 13: 
	case 14: 
	case 15: 
	case 16: 
	case 17: 
	case 18: 
	case 19: 
	case 20: 
	case 21: 
	case 22: 
	case 23: 
	case 24: 
	case 25: 
	case 26: 
	case 27: 
	case 28: 
	case 29: 
	case 30: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
	case 37: 
	case 38: 
	case 39: 
	case 40: 
	case 41: 
	case 42: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
	case 48: 
	case 49: 
	case 50: 
	case 51: 
	case 52: 
	case 53: 
	case 54: 
	case 55: 
	case 56: 
	case 57: 
	case 58: 
	case 59: 
	case 60: 
	case 61: 
	case 62: 
	case 63: 
	case 64: 
	case 65: 
	case 66: 
#line 240 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	break;
#line 21610 "sip_parser.c"
	}
	}

	_out: {}
	}

#line 262 "sip_parser.rl"
  // clang-format on

done:
  return ret;
}

// clang-format off

#line 286 "sip_parser.rl"



#line 21630 "sip_parser.c"
static const int sip_parser_mime_params_start = 1;
static const int sip_parser_mime_params_first_final = 76;
static const int sip_parser_mime_params_error = 0;

static const int sip_parser_mime_params_en_main = 1;


#line 289 "sip_parser.rl"
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
  
#line 21653 "sip_parser.c"
	{
	cs = sip_parser_mime_params_start;
	}

#line 303 "sip_parser.rl"
  
#line 21660 "sip_parser.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 33: goto tr1;
		case 37: goto tr1;
		case 39: goto tr1;
		case 126: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr1;
		} else if ( (*p) >= 42 )
			goto tr1;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr1;
		} else if ( (*p) >= 65 )
			goto tr1;
	} else
		goto tr1;
	goto tr0;
tr0:
#line 280 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	goto st0;
#line 21692 "sip_parser.c"
st0:
cs = 0;
	goto _out;
tr1:
#line 275 "sip_parser.rl"
	{ mime->type_start = p; }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 21704 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr2;
		case 13: goto tr3;
		case 32: goto tr2;
		case 33: goto st2;
		case 37: goto st2;
		case 39: goto st2;
		case 47: goto tr5;
		case 126: goto st2;
	}
	if ( (*p) < 45 ) {
		if ( 42 <= (*p) && (*p) <= 43 )
			goto st2;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st2;
		} else if ( (*p) >= 65 )
			goto st2;
	} else
		goto st2;
	goto tr0;
tr2:
#line 276 "sip_parser.rl"
	{ mime->type_stop = p - 1; }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 21735 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st3;
		case 13: goto st4;
		case 32: goto st3;
		case 47: goto st7;
	}
	goto tr0;
tr3:
#line 276 "sip_parser.rl"
	{ mime->type_stop = p - 1; }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 21751 "sip_parser.c"
	if ( (*p) == 10 )
		goto st5;
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	switch( (*p) ) {
		case 9: goto st6;
		case 32: goto st6;
	}
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	switch( (*p) ) {
		case 9: goto st6;
		case 32: goto st6;
		case 47: goto st7;
	}
	goto tr0;
tr5:
#line 276 "sip_parser.rl"
	{ mime->type_stop = p - 1; }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 21782 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st7;
		case 13: goto st8;
		case 32: goto st7;
		case 33: goto tr12;
		case 37: goto tr12;
		case 39: goto tr12;
		case 126: goto tr12;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr12;
		} else if ( (*p) >= 42 )
			goto tr12;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr12;
		} else if ( (*p) >= 65 )
			goto tr12;
	} else
		goto tr12;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 10 )
		goto st9;
	goto tr0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	switch( (*p) ) {
		case 9: goto st10;
		case 32: goto st10;
	}
	goto tr0;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	switch( (*p) ) {
		case 9: goto st10;
		case 32: goto st10;
		case 33: goto tr12;
		case 37: goto tr12;
		case 39: goto tr12;
		case 126: goto tr12;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr12;
		} else if ( (*p) >= 42 )
			goto tr12;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr12;
		} else if ( (*p) >= 65 )
			goto tr12;
	} else
		goto tr12;
	goto tr0;
tr12:
#line 277 "sip_parser.rl"
	{ mime->subtype_start = p; }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 21858 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr88;
		case 13: goto tr89;
		case 32: goto tr88;
		case 33: goto st76;
		case 37: goto st76;
		case 39: goto st76;
		case 44: goto tr91;
		case 59: goto tr92;
		case 126: goto st76;
	}
	if ( (*p) < 48 ) {
		if ( 42 <= (*p) && (*p) <= 46 )
			goto st76;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st76;
		} else if ( (*p) >= 65 )
			goto st76;
	} else
		goto st76;
	goto tr87;
tr87:
#line 278 "sip_parser.rl"
	{ mime->subtype_stop = p - 1; }
#line 279 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st77;
tr93:
#line 279 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st77;
tr95:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
#line 279 "sip_parser.rl"
	{ *stop = p; goto done; }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 21902 "sip_parser.c"
	goto tr93;
tr88:
#line 278 "sip_parser.rl"
	{ mime->subtype_stop = p - 1; }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 21912 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st11;
		case 13: goto st12;
		case 32: goto st11;
		case 44: goto st78;
		case 59: goto st17;
	}
	goto tr0;
tr89:
#line 278 "sip_parser.rl"
	{ mime->subtype_stop = p - 1; }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 21929 "sip_parser.c"
	if ( (*p) == 10 )
		goto st13;
	goto tr0;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 9: goto st14;
		case 32: goto st14;
	}
	goto tr0;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	switch( (*p) ) {
		case 9: goto st14;
		case 32: goto st14;
		case 44: goto st78;
		case 59: goto st17;
	}
	goto tr0;
tr91:
#line 278 "sip_parser.rl"
	{ mime->subtype_stop = p - 1; }
	goto st78;
tr99:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
#line 21965 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st78;
		case 13: goto st15;
		case 32: goto st78;
	}
	goto tr93;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) == 10 )
		goto st16;
	goto tr0;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 9: goto st79;
		case 32: goto st79;
	}
	goto tr0;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 9: goto st79;
		case 32: goto st79;
	}
	goto tr93;
tr92:
#line 278 "sip_parser.rl"
	{ mime->subtype_stop = p - 1; }
	goto st17;
tr100:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 22009 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st17;
		case 13: goto st18;
		case 32: goto st17;
		case 33: goto tr24;
		case 37: goto tr24;
		case 39: goto tr24;
		case 126: goto tr24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr24;
		} else if ( (*p) >= 42 )
			goto tr24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr24;
		} else if ( (*p) >= 65 )
			goto tr24;
	} else
		goto tr24;
	goto tr0;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 10 )
		goto st19;
	goto tr0;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	switch( (*p) ) {
		case 9: goto st20;
		case 32: goto st20;
	}
	goto tr0;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 9: goto st20;
		case 32: goto st20;
		case 33: goto tr24;
		case 37: goto tr24;
		case 39: goto tr24;
		case 126: goto tr24;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr24;
		} else if ( (*p) >= 42 )
			goto tr24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr24;
		} else if ( (*p) >= 65 )
			goto tr24;
	} else
		goto tr24;
	goto tr0;
tr24:
#line 7 "sip_params.rl"
	{
    if (kv->len == 0) {
      size_t s = size * 2 * sizeof(char *);
      memset(kv->key, 0, s);
      memset(kv->val, 0, s);
    }
    kv->i = kv->len;
    kv->len++;
  }
#line 17 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 0) = p; }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 22095 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr96;
		case 13: goto tr97;
		case 32: goto tr96;
		case 33: goto st80;
		case 37: goto st80;
		case 39: goto st80;
		case 44: goto tr99;
		case 59: goto tr100;
		case 61: goto tr101;
		case 126: goto st80;
	}
	if ( (*p) < 48 ) {
		if ( 42 <= (*p) && (*p) <= 46 )
			goto st80;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto st80;
		} else if ( (*p) >= 65 )
			goto st80;
	} else
		goto st80;
	goto tr95;
tr96:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 22128 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st21;
		case 13: goto st22;
		case 32: goto st21;
		case 44: goto st78;
		case 59: goto st17;
		case 61: goto st25;
	}
	goto tr0;
tr97:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 22146 "sip_parser.c"
	if ( (*p) == 10 )
		goto st23;
	goto tr0;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	switch( (*p) ) {
		case 9: goto st24;
		case 32: goto st24;
	}
	goto tr0;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	switch( (*p) ) {
		case 9: goto st24;
		case 32: goto st24;
		case 44: goto st78;
		case 59: goto st17;
		case 61: goto st25;
	}
	goto tr0;
tr32:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st25;
tr101:
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 22185 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr32;
		case 13: goto tr33;
		case 32: goto tr32;
		case 33: goto tr34;
		case 34: goto tr35;
		case 37: goto tr34;
		case 39: goto tr34;
		case 91: goto tr36;
		case 126: goto tr34;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr34;
		} else if ( (*p) >= 42 )
			goto tr34;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr34;
		} else if ( (*p) >= 65 )
			goto tr34;
	} else
		goto tr34;
	goto tr0;
tr33:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 22222 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr37;
	goto tr0;
tr37:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 22234 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr38;
		case 32: goto tr38;
	}
	goto tr0;
tr39:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st28;
tr38:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 22254 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr39;
		case 13: goto tr40;
		case 32: goto tr39;
		case 33: goto tr34;
		case 34: goto tr35;
		case 37: goto tr34;
		case 39: goto tr34;
		case 91: goto tr36;
		case 126: goto tr34;
	}
	if ( (*p) < 48 ) {
		if ( (*p) > 43 ) {
			if ( 45 <= (*p) && (*p) <= 46 )
				goto tr34;
		} else if ( (*p) >= 42 )
			goto tr34;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr34;
		} else if ( (*p) >= 65 )
			goto tr34;
	} else
		goto tr34;
	goto tr0;
tr40:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 22291 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr41;
	goto tr0;
tr41:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 22303 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr42;
		case 32: goto tr42;
	}
	goto tr0;
tr42:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 22317 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr42;
		case 32: goto tr42;
		case 34: goto tr43;
	}
	goto tr0;
tr35:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st32;
tr43:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 22338 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr43;
		case 13: goto tr49;
		case 34: goto tr50;
		case 92: goto tr51;
	}
	if ( (*p) < -16 ) {
		if ( (*p) > -33 ) {
			if ( -32 <= (*p) && (*p) <= -17 )
				goto tr45;
		} else if ( (*p) >= -64 )
			goto tr44;
	} else if ( (*p) > -9 ) {
		if ( (*p) < -4 ) {
			if ( -8 <= (*p) && (*p) <= -5 )
				goto tr47;
		} else if ( (*p) > -3 ) {
			if ( 32 <= (*p) && (*p) <= 126 )
				goto tr43;
		} else
			goto tr48;
	} else
		goto tr46;
	goto tr0;
tr44:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 22371 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr43;
	goto tr0;
tr45:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 22383 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr44;
	goto tr0;
tr46:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 22395 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr45;
	goto tr0;
tr47:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 22407 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr46;
	goto tr0;
tr48:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 22419 "sip_parser.c"
	if ( (*p) <= -65 )
		goto tr47;
	goto tr0;
tr49:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 22431 "sip_parser.c"
	if ( (*p) == 10 )
		goto tr52;
	goto tr0;
tr52:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 22443 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto tr43;
		case 32: goto tr43;
	}
	goto tr0;
tr50:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 22457 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st11;
		case 13: goto st12;
		case 32: goto st11;
		case 44: goto st78;
		case 59: goto st17;
	}
	goto tr93;
tr51:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 22474 "sip_parser.c"
	if ( (*p) < 11 ) {
		if ( 0 <= (*p) && (*p) <= 9 )
			goto tr43;
	} else if ( (*p) > 12 ) {
		if ( 14 <= (*p) )
			goto tr43;
	} else
		goto tr43;
	goto tr0;
tr34:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st82;
tr102:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 22498 "sip_parser.c"
	switch( (*p) ) {
		case 9: goto st11;
		case 13: goto st12;
		case 32: goto st11;
		case 33: goto tr102;
		case 37: goto tr102;
		case 39: goto tr102;
		case 44: goto st78;
		case 59: goto st17;
		case 126: goto tr102;
	}
	if ( (*p) < 48 ) {
		if ( 42 <= (*p) && (*p) <= 46 )
			goto tr102;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 95 <= (*p) && (*p) <= 122 )
				goto tr102;
		} else if ( (*p) >= 65 )
			goto tr102;
	} else
		goto tr102;
	goto tr93;
tr36:
#line 18 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 0) = p; }
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 22532 "sip_parser.c"
	if ( (*p) == 58 )
		goto tr54;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr53;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr53;
	} else
		goto tr53;
	goto tr0;
tr53:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 22552 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr56;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr55;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr55;
	} else
		goto tr55;
	goto tr0;
tr55:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 22574 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr56;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr57;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr57;
	} else
		goto tr57;
	goto tr0;
tr57:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 22596 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr56;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr58;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr58;
	} else
		goto tr58;
	goto tr0;
tr58:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 22618 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr56;
		case 93: goto tr50;
	}
	goto tr0;
tr56:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 22632 "sip_parser.c"
	if ( (*p) == 58 )
		goto tr60;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr59;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr53;
	} else
		goto tr53;
	goto tr0;
tr59:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 22652 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr61;
		case 58: goto tr56;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr62;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr55;
	} else
		goto tr55;
	goto tr0;
tr61:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 22675 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr63;
	goto tr0;
tr63:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 22687 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr64;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr65;
	goto tr0;
tr64:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 22701 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr66;
	goto tr0;
tr66:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 22713 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr67;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr68;
	goto tr0;
tr67:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 22727 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr69;
	goto tr0;
tr69:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 22739 "sip_parser.c"
	if ( (*p) == 93 )
		goto tr50;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr70;
	goto tr0;
tr70:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 22753 "sip_parser.c"
	if ( (*p) == 93 )
		goto tr50;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr71;
	goto tr0;
tr71:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 22767 "sip_parser.c"
	if ( (*p) == 93 )
		goto tr50;
	goto tr0;
tr68:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 22779 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr67;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr72;
	goto tr0;
tr72:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 22793 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr67;
	goto tr0;
tr65:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 22805 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr64;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr73;
	goto tr0;
tr73:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 22819 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr64;
	goto tr0;
tr62:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 22831 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr61;
		case 58: goto tr56;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr74;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr57;
	} else
		goto tr57;
	goto tr0;
tr74:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 22854 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr61;
		case 58: goto tr56;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr58;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr58;
	} else
		goto tr58;
	goto tr0;
tr60:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 22877 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr76;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr75;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr75;
	} else
		goto tr75;
	goto tr0;
tr75:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 22899 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr78;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr77;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr77;
	} else
		goto tr77;
	goto tr0;
tr77:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 22921 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr78;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr79;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr79;
	} else
		goto tr79;
	goto tr0;
tr79:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 22943 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr78;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr80;
	} else
		goto tr80;
	goto tr0;
tr80:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 22965 "sip_parser.c"
	switch( (*p) ) {
		case 58: goto tr78;
		case 93: goto tr50;
	}
	goto tr0;
tr78:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 22979 "sip_parser.c"
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr81;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr75;
	} else
		goto tr75;
	goto tr0;
tr81:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 22997 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr61;
		case 58: goto tr78;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr82;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr77;
	} else
		goto tr77;
	goto tr0;
tr82:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 23020 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr61;
		case 58: goto tr78;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr83;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr79;
	} else
		goto tr79;
	goto tr0;
tr83:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 23043 "sip_parser.c"
	switch( (*p) ) {
		case 46: goto tr61;
		case 58: goto tr78;
		case 93: goto tr50;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr80;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto tr80;
	} else
		goto tr80;
	goto tr0;
tr76:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 23066 "sip_parser.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr84;
	goto tr0;
tr84:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 23078 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr61;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr85;
	goto tr0;
tr85:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 23092 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr61;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr86;
	goto tr0;
tr86:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 23106 "sip_parser.c"
	if ( (*p) == 46 )
		goto tr61;
	goto tr0;
tr54:
#line 20 "sip_params.rl"
	{ *(kv->val + kv->i*2 + 1) = p; }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 23118 "sip_parser.c"
	if ( (*p) == 58 )
		goto tr60;
	goto tr0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 80: 
#line 19 "sip_params.rl"
	{ *(kv->key + kv->i*2 + 1) = p - 1; }
	break;
	case 76: 
#line 278 "sip_parser.rl"
	{ mime->subtype_stop = p - 1; }
	break;
	case 1: 
	case 2: 
	case 3: 
	case 4: 
	case 5: 
	case 6: 
	case 7: 
	case 8: 
	case 9: 
	case 10: 
	case 11: 
	case 12: 
	case 13: 
	case 14: 
	case 15: 
	case 16: 
	case 17: 
	case 18: 
	case 19: 
	case 20: 
	case 21: 
	case 22: 
	case 23: 
	case 24: 
	case 25: 
	case 26: 
	case 27: 
	case 28: 
	case 29: 
	case 30: 
	case 31: 
	case 32: 
	case 33: 
	case 34: 
	case 35: 
	case 36: 
	case 37: 
	case 38: 
	case 39: 
	case 40: 
	case 41: 
	case 42: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
	case 48: 
	case 49: 
	case 50: 
	case 51: 
	case 52: 
	case 53: 
	case 54: 
	case 55: 
	case 56: 
	case 57: 
	case 58: 
	case 59: 
	case 60: 
	case 61: 
	case 62: 
	case 63: 
	case 64: 
	case 65: 
	case 66: 
	case 67: 
	case 68: 
	case 69: 
	case 70: 
	case 71: 
	case 72: 
	case 73: 
	case 74: 
	case 75: 
#line 280 "sip_parser.rl"
	{ ret = R_PARSE_ERROR; *err = p; }
	break;
#line 23295 "sip_parser.c"
	}
	}

	_out: {}
	}

#line 304 "sip_parser.rl"
  // clang-format on

done:
  return ret;
}

/*
  Local Variables:
  mode: c
  End:
*/
