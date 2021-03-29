%%%-------------------------------------------------------------------
%%% @author Evgeny Khramtsov <ekhramtsov@bdt.group>
%%% @copyright (C) 2021, Big Data Technology. All Rights Reserved.
%%%
%%% Licensed under the Apache License, Version 2.0 (the "License");
%%% you may not use this file except in compliance with the License.
%%% You may obtain a copy of the License at
%%%
%%%     http://www.apache.org/licenses/LICENSE-2.0
%%%
%%% Unless required by applicable law or agreed to in writing, software
%%% distributed under the License is distributed on an "AS IS" BASIS,
%%% WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
%%% See the License for the specific language governing permissions and
%%% limitations under the License.
%%% @doc
%%% @end
%%% Created : 29 Jan 2021 by Evgeny Khramtsov <ekhramtsov@bdt.group>
%%%-------------------------------------------------------------------
-module(sip_codec).

-on_load(load_nif/0).

%% Headers API
-export([decode_cseq/1]).
-export([decode_from/1]).
-export([decode_to/1]).
-export([decode_content_length/1]).
-export([decode_content_type/1]).
-export([decode_max_forwards/1]).
-export([decode_diversion/1]).
-export([decode_history_info/1]).
-export([decode_reason/1]).
%% Primitives API
-export([decode_uri/1]).
-export([decode_name_addr/1]).
-export([decode_start_line/1]).
-export([decode_header_line/1]).
-export([decode_token_params/1]).
-export([decode_mime_params/1]).
-export([tolower/1]).
-export([toupper/1]).
%% Shut up xref
-export([load_nif/0]).
%% Exported types
-export_type([uri/0, uri_string/0]).
-export_type([kv/0, body/0]).
-export_type([start_line/0]).
-export_type([sip_version/0, sip_method/0,
              status_code/0, reason_phrase/0]).
-export_type([mime/0, name_addr/0]).

-include("sip_codec.hrl").

-type kv() :: {Key :: binary(), Val :: binary()}.
-type position() :: non_neg_integer().
-type uri() :: #uri{}.
-type uri_string() :: binary().
-type sip_version() :: {non_neg_integer(), non_neg_integer()}.
-type sip_method() :: binary().
-type status_code() :: non_neg_integer().
-type reason_phrase() :: binary().
-type start_line() ::
        {request, sip_version(), sip_method(), uri_string()} |
        {response, sip_version(), status_code(), reason_phrase()}.
-type name_addr() :: {Name :: binary(), uri(), [kv()]}.
-type mime() :: {Type :: binary(), SubType :: binary()}.
-type token() :: binary().
-type body() :: binary().

%%%===================================================================
%%% API
%%%===================================================================
%%--------------------------------------------------------------------
%% Headers
%%--------------------------------------------------------------------
-spec decode_from(binary()) -> {ok, name_addr()} | {error, position()}.
decode_from(Data) ->
    case decode_name_addr(Data) of
        {ok, [Val|_]} -> {ok, Val};
        Err -> Err
    end.

-spec decode_to(binary()) -> {ok, name_addr()} | {error, position()}.
decode_to(Data) ->
    case decode_name_addr(Data) of
        {ok, [Val|_]} -> {ok, Val};
        Err -> Err
    end.

-spec decode_content_length(binary()) -> {ok, non_neg_integer()} | {error, position()}.
decode_content_length(Data) ->
    decode_unsigned(Data).

-spec decode_content_type(binary()) -> {ok, {mime(), [kv()]}} | {error, position()}.
decode_content_type(Data) ->
    case decode_mime_params(Data) of
        {ok, [Val|_]} -> {ok, Val};
        Err -> Err
    end.

-spec decode_max_forwards(binary()) -> {ok, non_neg_integer()} | {error, position()}.
decode_max_forwards(Data) ->
    decode_unsigned(Data).

-spec decode_diversion(binary()) -> {ok, [name_addr()]} | {error, position()}.
decode_diversion(Data) ->
    decode_name_addr(Data).

-spec decode_history_info(binary()) -> {ok, [name_addr()]} | {error, position()}.
decode_history_info(Data) ->
    decode_name_addr(Data).

-spec decode_reason(binary()) -> {ok, [{token(), [kv()]}]} | {error, position()}.
decode_reason(Data) ->
    decode_token_params(Data).

-spec decode_cseq(binary()) -> {ok, {non_neg_integer(), sip_method()}} |
                               {error, position()}.
decode_cseq(_) ->
    erlang:nif_error({nif_not_loaded, ?MODULE}).

%%--------------------------------------------------------------------
%% Primitives
%%--------------------------------------------------------------------
-spec decode_uri(binary()) -> {ok, uri()} | {error, position()}.
decode_uri(_) ->
    erlang:nif_error({nif_not_loaded, ?MODULE}).

-spec decode_start_line(binary()) -> {ok, start_line(), pos_integer()} |
                                     more | {error, position()}.
decode_start_line(_) ->
    erlang:nif_error({nif_not_loaded, ?MODULE}).

-spec decode_header_line(binary()) -> {ok, kv() | eoh, pos_integer()} |
                                      more | {error, position()}.
decode_header_line(_) ->
    erlang:nif_error({nif_not_loaded, ?MODULE}).

-spec decode_name_addr(binary()) -> {ok, [name_addr()]} |
                                    {error, position()}.
decode_name_addr(_) ->
    erlang:nif_error({nif_not_loaded, ?MODULE}).

-spec decode_token_params(binary()) -> {ok, [{token(), [kv()]}]} |
                                       {error, position()}.
decode_token_params(_) ->
    erlang:nif_error({nif_not_loaded, ?MODULE}).

-spec decode_mime_params(binary()) -> {ok, [{mime(), [kv()]}]} |
                                      {error, position()}.
decode_mime_params(_) ->
    erlang:nif_error({nif_not_loaded, ?MODULE}).

%% WARNING: this function modifies input binary
-spec tolower(binary()) -> ok.
tolower(_) ->
    erlang:nif_error({nif_not_loaded, ?MODULE}).

%% WARNING: this function modifies input binary
-spec toupper(binary()) -> ok.
toupper(_) ->
    erlang:nif_error({nif_not_loaded, ?MODULE}).

%%%===================================================================
%%% Internal functions
%%%===================================================================
-spec decode_unsigned(binary()) -> {ok, non_neg_integer()} | {error, position()}.
decode_unsigned(Data) ->
    try binary_to_integer(Data) of
        I when I>=0 -> {ok, I};
        _ -> {error, 0}
    catch _:_ ->
            {error, 0}
    end.

%%--------------------------------------------------------------------
%% NIF fuckery
%%--------------------------------------------------------------------
-spec load_nif() -> ok | {error, term()}.
load_nif() ->
    EbinDir = filename:dirname(code:which(?MODULE)),
    AppDir = filename:dirname(EbinDir),
    PrivDir = filename:join([AppDir, "priv"]),
    SOPath = filename:join(PrivDir, ?MODULE),
    erlang:load_nif(SOPath, 0).
