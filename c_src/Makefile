# Based on c_src.mk from erlang.mk by Loic Hoguin <essen@ninenines.eu>

CURDIR := $(shell pwd)
BASEDIR := $(abspath $(CURDIR)/..)

PROJECT ?= $(notdir $(BASEDIR))
PROJECT := $(strip $(PROJECT))

ERTS_INCLUDE_DIR ?= $(shell erl -noshell -s init stop -eval "io:format(\"~s/erts-~s/include/\", [code:root_dir(), erlang:system_info(version)]).")

C_SRC_DIR = $(CURDIR)
C_SRC_OUTPUT ?= $(CURDIR)/../priv/$(PROJECT).so

# System type and C compiler/flags.

UNAME_SYS := $(shell uname -s)
CC ?= cc
LDFLAGS ?= -Wl,-Bsymbolic-functions -Wl,-z,relro,-z,now -Wl,-z,noexecstack -shared
CFLAGS ?= -D_FORTIFY_SOURCE=2 -O2 -fstack-protector-strong -std=gnu99 \
					-I $(ERTS_INCLUDE_DIR) \
				 	-Wformat -Werror=format-security \
					-Wunused-variable \
				 	-fno-strict-aliasing \
					-pie -fPIE -fPIC \
					-Wtype-limits -Wstrict-overflow=5 \
					-fstrict-overflow -Wsign-compare

LDLIBS += -lpthread -ldl

# Verbosity.

c_verbose_0 = @echo " C     " $(?F);
c_verbose = $(c_verbose_$(V))

link_verbose_0 = @echo " LD    " $(@F);
link_verbose = $(link_verbose_$(V))

SOURCES := $(shell find $(C_SRC_DIR) -type f \( -name "*.c" -o -name "*.C" -o -name "*.cc" -o -name "*.cpp" \))
HEADERS := $(shell find $(C_SRC_DIR) -type f -name "*.h")
OBJECTS = $(addsuffix .o, $(basename $(SOURCES)))
ABNF_FILES = $(wildcard $(CURDIR)/../abnf/*.abnf)
RAGEL_OUTPUT = sip_parser.c
ABNFC_OUTPUT = sip.rl
GCOV_OUTPUT = $(wildcard *.gcda) \
              $(wildcard *.gcno) \
              $(wildcard *.gcov)
LCOV_OUTPUT = coverage

COMPILE_C = $(c_verbose) $(CC) $(CFLAGS)

$(C_SRC_OUTPUT): $(SOURCES) $(HEADERS)
	mkdir -p $(dir $@)
	$(COMPILE_C) -o $(C_SRC_OUTPUT) $(SOURCES) $(LDFLAGS) $(LDLIBS)

clean:
	@rm -rf $(C_SRC_OUTPUT) $(OBJECTS) $(GCOV_OUTPUT) $(LCOV_OUTPUT) $(RAGEL_OUTPUT) $(ABNFC_OUTPUT)

check-syntax:
	gcc $(CFLAGS) -Wextra -fsyntax-only $(CHK_SOURCES)

cover: clean
        # Compiling into goto-driven FSM is very taxing under `test-coverage`
        # and takes ages to complete, so we recompile into table-driven FSM
        # which is slower but compiles much faster
	abnfc core $(ABNF_FILES) -i -n sip -o $(ABNFC_OUTPUT)
	ragel -T0 sip_parser.rl -o $(RAGEL_OUTPUT)
	$(COMPILE_C) -fprofile-arcs -ftest-coverage -o $(C_SRC_OUTPUT) $(SOURCES) $(LDFLAGS) $(LDLIBS)

cover-analyze:
	@mkdir coverage
	lcov --capture --directory . --no-external --output-file coverage/coverage.info
	genhtml coverage/coverage.info --output-directory coverage
	lcov --list coverage/coverage.info

parser: $(ABNFC_OUTPUT) $(RAGEL_OUTPUT)

$(ABNFC_OUTPUT): $(ABNF_FILES)
	abnfc core $(ABNF_FILES) -i -n sip -o $(ABNFC_OUTPUT)

$(RAGEL_OUTPUT): sip_parser.rl sip_uri.rl sip_params.rl sip.rl
	ragel -G2 sip_parser.rl -o $(RAGEL_OUTPUT)

.PHONY: clean check-syntax cover cover-analyze parser
