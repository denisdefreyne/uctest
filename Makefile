CFLAGS_EXTRA         = -g3 -I/usr/local/include
LDFLAGS_EXTRA        = -g3
LDFLAGS_EXTRA_SAMPLE = -L/usr/local/lib
LDFLAGS_EXTRA_LIB    =

PREFIX = /usr/local

CC  = cc
LD  = cc

###

OBJS_LIB = \
	build/uctest/assert.c.o \
	build/uctest/failure.c.o \
	build/uctest/private.c.o \
	build/uctest/test.c.o \
	build/uctest/test_suite.c.o
OBJS_SAMPLE = \
	build/uctest-sample/sample.c.o

TARGET_LIB    = dist/lib/libuctest
TARGET_SAMPLE = dist/bin/uctest-sample

###

CFLAGS         = $(CFLAGS_EXTRA) -Iinclude -std=c99
LDFLAGS        = $(LDFLAGS_EXTRA)
LDFLAGS_LIB    = $(LDFLAGS) $(LDFLAGS_EXTRA_LIB)
LDFLAGS_SAMPLE = $(LDFLAGS) $(LDFLAGS_EXTRA_SAMPLE) -Ldist/lib -luctest

###

ifeq ($(shell uname),Darwin)
	LDFLAGS_LIB    := $(LDFLAGS_LIB) -dynamiclib
	TARGET_LIB     := $(TARGET_LIB).dylib
else ifeq ($(shell uname),Linux)
	LDFLAGS_LIB    := $(LDFLAGS_LIB) -shared
	TARGET_LIB     := $(TARGET_LIB).so
endif

###

all: uctest-lib uctest-sample

install: uctest-lib
	@echo "======= Installing uctest…"
	@echo
	@mkdir -p $(PREFIX)
	@mkdir -p $(PREFIX)/include/uctest
	@mkdir -p $(PREFIX)/lib
	@echo "INSTALL assert.h"
	@install -c include/uctest/assert.h $(PREFIX)/include/uctest/assert.h
	@echo "INSTALL private.h"
	@install -c include/uctest/private.h $(PREFIX)/include/uctest/private.h
	@echo "INSTALL test.h"
	@install -c include/uctest/test.h $(PREFIX)/include/uctest/test.h
	@echo "INSTALL test_suite.h"
	@install -c include/uctest/test_suite.h $(PREFIX)/include/uctest/test_suite.h
	@echo "INSTALL uctest.h"
	@install -c include/uctest/uctest.h $(PREFIX)/include/uctest/uctest.h
	@echo "INSTALL $(TARGET_LIB)"
	@install -c $(TARGET_LIB) $(PREFIX)/lib/$(shell basename $(TARGET_LIB))
	@echo

###

uctest-lib: prep uctest-lib-pre $(TARGET_LIB) uctest-lib-post

uctest-lib-pre:
	@echo "======= Building uctest…"
	@echo

uctest-lib-post:
	@echo

###

uctest-sample: uctest-lib prep uctest-sample-pre $(TARGET_SAMPLE) uctest-sample-post

uctest-sample-pre:
	@echo "======= Building uctest-sample…"
	@echo

uctest-sample-post:
	@echo

###

prep:
	@echo "======= Preparing for build…"
	@echo
	@mkdir -p build
	@mkdir -p dist
	@mkdir -p dist/bin
	@mkdir -p dist/lib

###

$(TARGET_LIB): $(OBJS_LIB)
	@echo "LINK     $@"
	@$(LD) $(LDFLAGS_LIB) $(OBJS_LIB) -o $@

$(TARGET_SAMPLE): $(OBJS_SAMPLE)
	@echo "LINK     $@"
	@$(LD) $(LDFLAGS_SAMPLE) $(OBJS_SAMPLE) -o $@

###

build/%.c.o: src/%.c
	@echo "COMPILE  $<"
	@mkdir -p `dirname $@`
	@$(CC) $(CFLAGS) -c $< -o $@

###

clean:
	@echo CLEAN
	@rm -rf build

distclean: clean
	@echo DISTCLEAN
	@rm -rf dist

###

.SUFFIXES: .c .h .o
.PHONY: all prep uctest-lib uctest-lib-pre uctest-sample uctest-sample-pre clean distclean
