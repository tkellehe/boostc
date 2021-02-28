#  Copyright (C) 2020-? T. Mitchell Kelleher
#
#  Distributed under the Boost Software License, Version 1.0. (See
#  accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt)

# Current directory for project.
TEST_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
PROJECT_DIR := $(abspath $(TEST_DIR)/..)
# Remove the last slash.
TEST_DIR := $(PROJECT_DIR)/test

# Convert paths to windows.
# winpaths=$(substc /,\,$1)
winpaths=$(shell cygpath -w $1)

# https://stackoverflow.com/a/12959694/5407843
# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# Get all of the main files.
ALL_MAINC := $(call rwildcard,$(TEST_DIR)/,*main.c)

# Check to see if the bin directory has been specified.
BSTC_BIN ?= $(TEST_DIR)/bin

all: gcc clang vs14 tcc g++

clean:
	@rm -rf $(BSTC_BIN) *.obj

#-------------------------------------------------------------------------------------------------------------
BSTC_GPP_TESTS := $(ALL_MAINC:$(TEST_DIR)/%/main.c=$(BSTC_BIN)/g++/%)
BSTC_GPP_FLAGS ?= -O6 -Wall -Werror -pedantic -I $(PROJECT_DIR)
BSTC_GPP ?= g++

g++: $(BSTC_GPP_TESTS)

$(BSTC_BIN)/g++/%: $(TEST_DIR)/%/main.c
	@echo "(GPP) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BSTC_GPP) $(BSTC_GPP_FLAGS) $? -o $@
	@echo

#-------------------------------------------------------------------------------------------------------------
BSTC_GCC_TESTS := $(ALL_MAINC:$(TEST_DIR)/%/main.c=$(BSTC_BIN)/gcc/%)
BSTC_GCC_FLAGS ?= -O6 -Wall -Werror -pedantic -I $(PROJECT_DIR)
BSTC_GCC ?= gcc

gcc: $(BSTC_GCC_TESTS)

$(BSTC_BIN)/gcc/%: $(TEST_DIR)/%/main.c
	@echo "(GCC) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BSTC_GCC) $(BSTC_GCC_FLAGS) $? -o $@
	@echo

#-------------------------------------------------------------------------------------------------------------
BSTC_CLANG_TESTS := $(ALL_MAINC:$(TEST_DIR)/%/main.c=$(BSTC_BIN)/clang/%)
BSTC_CLANG_FLAGS ?= -O3 -Wall -Werror -pedantic -I $(PROJECT_DIR)
BSTC_CLANG ?= clang

clang: $(BSTC_CLANG_TESTS)

$(BSTC_BIN)/clang/%: $(TEST_DIR)/%/main.c
	@echo "(CLANG) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BSTC_CLANG) $(BSTC_CLANG_FLAGS) $? -o $@
	@echo

#-------------------------------------------------------------------------------------------------------------
BSTC_VS14_TESTS := $(ALL_MAINC:$(TEST_DIR)/%/main.c=$(BSTC_BIN)/vs14/%)
BSTC_VS14_FLAGS ?= /nologo /EHsc /Ox /W4 /link kernel32.lib user32.lib
BSTC_VS14 ?= $(PROJECT_DIR)/scripts/msvc.bash vs14 cl

vs14: $(BSTC_VS14_TESTS)

$(BSTC_BIN)/vs14/%: $(TEST_DIR)/%/main.c
	@echo "(VS14) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BSTC_VS14) "$(call winpaths,$?)" /I "$(call winpaths,$(PROJECT_DIR))" $(BSTC_VS14_FLAGS) /OUT:"$(call winpaths,$@)"
	rm main.obj
	@echo

#-------------------------------------------------------------------------------------------------------------
BSTC_TCC_TESTS := $(ALL_MAINC:$(TEST_DIR)/%/main.c=$(BSTC_BIN)/tcc/%)
BSTC_TCC_FLAGS ?= -O3 -Wall -Werror -pedantic
BSTC_TCC ?= /tcc/win64/tcc

tcc: $(BSTC_TCC_TESTS)

$(BSTC_BIN)/tcc/%: $(TEST_DIR)/%/main.c
	@echo "(TCC) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BSTC_TCC) $(BSTC_TCC_FLAGS) -I "$(call winpaths,$(PROJECT_DIR))" "$(call winpaths,$?)" -o "$(call winpaths,$@)"
	@echo

#-------------------------------------------------------------------------------------------------------------
print-%: ; @echo $* = $($*)