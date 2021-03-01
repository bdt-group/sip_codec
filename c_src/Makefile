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
GCOV_OUTPUT = $(addsuffix .gcda, $(basename $(SOURCES))) \
	      $(addsuffix .gcno, $(basename $(SOURCES))) \
              $(addsuffix .gcov, $(basename $(SOURCES)))
LCOV_OUTPUT = coverage

COMPILE_C = $(c_verbose) $(CC) $(CFLAGS)

$(C_SRC_OUTPUT): $(SOURCES) $(HEADERS)
	mkdir -p $(dir $@)
	$(COMPILE_C) -o $(C_SRC_OUTPUT) $(SOURCES) $(LDFLAGS) $(LDLIBS)

clean:
	@rm -rf $(C_SRC_OUTPUT) $(OBJECTS) $(GCOV_OUTPUT) $(LCOV_OUTPUT)

check-syntax:
	gcc $(CFLAGS) -Wextra -fsyntax-only $(CHK_SOURCES)

cover: clean
	$(COMPILE_C) -fprofile-arcs -ftest-coverage -o $(C_SRC_OUTPUT) $(SOURCES) $(LDFLAGS) $(LDLIBS)

cover-analyze:
	@mkdir coverage
	- lcov --capture --directory . --output-file coverage/coverage.info \
	  && genhtml coverage/coverage.info --output-directory coverage

ragel: sip_parser.c

sip_parser.c: sip_parser.rl sip_uri.rl sip_params.rl sip.rl
	ragel -G2 sip_parser.rl -o sip_parser.c

.PHONY: clean check-syntax cover cover-analyze ragel
