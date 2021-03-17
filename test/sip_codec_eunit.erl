%%%-------------------------------------------------------------------
%%% @author Evgeny Khramtsov <ekhramtsov@bdt.group>
%%% @copyright (C) 2021, Big Data Technology
%%% @doc
%%%
%%% @end
%%% Created :  2 Feb 2021 by Evgeny Khramtsov <ekhramtsov@bdt.group>
%%%-------------------------------------------------------------------
-module(sip_codec_eunit).
-compile(nowarn_export_all).
-compile(export_all).

-include_lib("eunit/include/eunit.hrl").
-include("sip_codec.hrl").

%%%===================================================================
%%% Tests
%%%===================================================================
decode_request_line_test() ->
    In = <<"OPTIONS sip:127.0.0.1:5060 SIP/2.0\r\n">>,
    Size = size(In),
    ?assertEqual(
       {ok, {request, {2, 0}, <<"OPTIONS">>, <<"sip:127.0.0.1:5060">>}, Size},
       sip_codec:decode_start_line(In)).

decode_response_line_test() ->
    In = <<"SIP/2.0 400 Not Found\r\n">>,
    Size = size(In),
    ?assertEqual(
       {ok, {response, {2, 0}, 400, <<"Not Found">>}, Size},
       sip_codec:decode_start_line(In)).

decode_header_line_test() ->
    In = <<"Name : Value  \r\nNext">>,
    ?assertEqual(
       {ok, {<<"name">>, <<"Value">>}, 16},
       sip_codec:decode_header_line(In)).

decode_header_line_more_test() ->
    In = <<"Name : Value  \r\n">>,
    ?assertEqual(more, sip_codec:decode_header_line(In)).

decode_eoh_test() ->
    In = <<"\r\n">>,
    ?assertEqual(
       {ok, eoh, 2},
       sip_codec:decode_header_line(In)).

decode_sip_uri_test() ->
    In = <<"sip:user:pass@HOST.com:5060;FOO=bar;;;;baz?a=b&C=">>,
    ?assertEqual(
       {ok, #uri{scheme = <<"sip">>,
                 user = <<"user">>,
                 password = <<"pass">>,
                 host = <<"host.com">>,
                 port = 5060,
                 params = [{<<"foo">>, <<"bar">>}, {<<"baz">>, <<>>}],
                 hdrs = [{<<"a">>, <<"b">>}, {<<"c">>, <<>>}]}},
       sip_codec:decode_uri(In)).

decode_tel_uri_test() ->
    In = <<"tel:2342423;phone-context=+7;">>,
    ?assertEqual(
       {ok,#uri{scheme = <<"tel">>,user = <<"2342423">>,
                password = <<>>,host = <<>>,port = undefined,
                params = [{<<"phone-context">>,<<"+7">>}],
                hdrs = []}},
       sip_codec:decode_uri(In)).

decode_from_test() ->
    In = <<"sip:sipsak@127.0.0.1:0;tag=3cc34a33">>,
    ?assertEqual(
       {ok, {<<>>,
             #uri{scheme = <<"sip">>,user = <<"sipsak">>,password = <<>>,
                  host = <<"127.0.0.1">>,port = 0,params = [],hdrs = []},
             [{<<"tag">>,<<"3cc34a33">>}]}},
       sip_codec:decode_from(In)).

decode_to_test() ->
    In = <<"sip:127.0.0.1:5060">>,
    ?assertEqual(
       {ok, {<<>>,
             #uri{scheme = <<"sip">>,user = <<>>,password = <<>>,
                  host = <<"127.0.0.1">>,port = 5060,params = [],hdrs = []},
             []}},
       sip_codec:decode_to(In)).

decode_cseq_test() ->
    In = <<"1 OPTIONs">>,
    ?assertEqual(
       {ok, {1, <<"OPTIONS">>}},
       sip_codec:decode_cseq(In)).

decode_content_length_test() ->
    In = <<"6456">>,
    ?assertEqual({ok, 6456}, sip_codec:decode_content_length(In)).

decode_max_forwards_test() ->
    In = <<"70">>,
    ?assertEqual({ok, 70}, sip_codec:decode_max_forwards(In)).

decode_content_type_test() ->
    In = <<"application/SDP">>,
    ?assertEqual(
       {ok, {{<<"application">>, <<"sdp">>}, []}},
       sip_codec:decode_content_type(In)).

decode_diversion_test() ->
    In = <<"sip:bob@host.com;reason=unconditional">>,
    ?assertEqual(
       {ok, [{<<>>,
              #uri{scheme = <<"sip">>,user = <<"bob">>,password = <<>>,
                   host = <<"host.com">>,port = undefined,params = [],
                   hdrs = []},
              [{<<"reason">>,<<"unconditional">>}]}]},
       sip_codec:decode_diversion(In)).

decode_history_info_test() ->
    In = <<"sip:sipsak@127.0.0.1:0;index=1.0,   \r\n"
           "   sip:user@host.com:5060;reason=\"Gone\"">>,
    ?assertEqual(
       {ok, [{<<>>,
              #uri{scheme = <<"sip">>,user = <<"sipsak">>,password = <<>>,
                   host = <<"127.0.0.1">>,port = 0,params = [],hdrs = []},
              [{<<"index">>,<<"1.0">>}]},
             {<<>>,
              #uri{scheme = <<"sip">>,user = <<"user">>,password = <<>>,
                   host = <<"host.com">>,port = 5060,params = [],hdrs = []},
              [{<<"reason">>,<<"\"Gone\"">>}]}]},
       sip_codec:decode_history_info(In)).

decode_reason_test() ->
    In = <<"Q.850;cause=200;text=\"Call completed elsewhere\"">>,
    ?assertEqual(
       {ok, [{<<"q.850">>,
              [{<<"cause">>,<<"200">>},
               {<<"text">>,<<"\"Call completed elsewhere\"">>}]}]},
       sip_codec:decode_reason(In)).

tolower_test() ->
    In = list_to_binary(lists:seq($A, $Z)),
    Out = list_to_binary(lists:seq($a, $z)),
    ?assertEqual(ok, sip_codec:tolower(In)),
    ?assertEqual(Out, In).

toupper_test() ->
    In = list_to_binary(lists:seq($a, $z)),
    Out = list_to_binary(lists:seq($A, $Z)),
    ?assertEqual(ok, sip_codec:toupper(In)),
    ?assertEqual(Out, In).

%%%===================================================================
%%% Internal functions
%%%===================================================================
