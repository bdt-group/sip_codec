REBAR ?= rebar3
PROJECT := sip_codec
BUILD_IMAGE  ?= gitlab.bdt.tools:5000/build-ubuntu1804:1.4.5

.PHONY: compile clean distclean xref dialyzer dialyze linter lint test check-syntax

all: compile

compile: ragel
	@$(REBAR) compile

clean:
	@$(REBAR) clean

distclean:
	make -C c_src clean
	rm -rf _build

xref:
	@$(REBAR) xref

dialyze:
	@$(REBAR) dialyzer

lint:
	@$(REBAR) as lint lint

test:
	make -C c_src cover
	@$(REBAR) eunit --verbose --cover
	@$(REBAR) cover --verbose
	make -C c_src cover-analyze

check-syntax:
	make -C c_src check-syntax

ragel:
	make -C c_src ragel

.PHONY: d_%

d_%:
	./build-with-env --image $(BUILD_IMAGE) make $*
