%%%-------------------------------------------------------------------
%%% @author Evgeny Khramtsov <ekhramtsov@bdt.group>
%%% @copyright (C) 2021, Big Data Technology
%%% @doc
%%%
%%% @end
%%% Created : 29 Jan 2021 by Evgeny Khramtsov <ekhramtsov@bdt.group>
%%%-------------------------------------------------------------------
-record(uri, {scheme   = <<"sip">> :: binary(),
              user     = <<>>      :: binary(),
              password = <<>>      :: binary(),
              host     = <<>>      :: binary(),
              port                 :: non_neg_integer() | undefined,
              params   = []        :: [sip_codec:kv()],
              hdrs     = []        :: [sip_codec:kv()]}).
