#  Copyright (C) 2020-? T. Mitchell Kelleher
#
#  Distributed under the Boost Software License, Version 1.0. (See
#  accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt)

# Current directory for project.
ASSEMBLY_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
PROJECT_DIR := $(abspath $(ASSEMBLY_DIR)/..)
# Remove the last slash.
ASSEMBLY_DIR := $(PROJECT_DIR)/assembly

# Convert paths to windows.
# winpaths=$(substc /,\,$1)
winpaths=$(shell cygpath -w $1)

# https://stackoverflow.com/a/12959694/5407843
# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# Get all of the main files.
ALL_MAINC := $(call rwildcard,$(ASSEMBLY_DIR)/,*main.c)

# Check to see if the bin directory has been specified.
BSTC_BIN ?= $(ASSEMBLY_DIR)/bin

all: gcc clang vs14

clean:
	@rm -rf $(BSTC_BIN) *.obj

#-------------------------------------------------------------------------------------------------------------
BSTC_GCC_ASSEMBLIES := $(ALL_MAINC:$(ASSEMBLY_DIR)/%/main.c=$(BSTC_BIN)/gcc/%.s)
BSTC_GCC_FLAGS ?= -S -fverbose-asm -O6 -Wall -Werror -pedantic -I $(PROJECT_DIR)
BSTC_GCC ?= gcc

gcc: $(BSTC_GCC_ASSEMBLIES)

$(BSTC_BIN)/gcc/%.s: $(ASSEMBLY_DIR)/%/main.c
	@echo "(GCC) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BSTC_GCC) $(BSTC_GCC_FLAGS) $? -o $@
	@echo

#-------------------------------------------------------------------------------------------------------------
BSTC_CLANG_ASSEMBLIES := $(ALL_MAINC:$(ASSEMBLY_DIR)/%/main.c=$(BSTC_BIN)/clang/%.s)
BSTC_CLANG_FLAGS ?= -S -fverbose-asm -O3 -Wall -Werror -pedantic -I $(PROJECT_DIR)
BSTC_CLANG ?= clang

clang: $(BSTC_CLANG_ASSEMBLIES)

$(BSTC_BIN)/clang/%.s: $(ASSEMBLY_DIR)/%/main.c
	@echo "(CLANG) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BSTC_CLANG) $(BSTC_CLANG_FLAGS) $? -o $@
	@echo

#-------------------------------------------------------------------------------------------------------------
BSTC_VS14_ASSEMBLIES := $(ALL_MAINC:$(ASSEMBLY_DIR)/%/main.c=$(BSTC_BIN)/vs14/%.s)
BSTC_VS14_FLAGS ?= /nologo /EHsc /Ox /W4 /link kernel32.lib user32.lib
BSTC_VS14 ?= $(PROJECT_DIR)/scripts/msvc.bash vs14 cl

vs14: $(BSTC_VS14_ASSEMBLIES)

$(BSTC_BIN)/vs14/%.s: $(ASSEMBLY_DIR)/%/main.c
	@echo "(VS14) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BSTC_VS14) "$(call winpaths,$?)" /I "$(call winpaths,$(PROJECT_DIR))" $(BSTC_VS14_FLAGS) /OUT:"$(call winpaths,$@)"
	rm main.obj
	@echo

#-------------------------------------------------------------------------------------------------------------
BSTC_TCC_ASSEMBLIES := $(ALL_MAINC:$(ASSEMBLY_DIR)/%/main.c=$(BSTC_BIN)/tcc/%.s)
BSTC_TCC_FLAGS ?= -O3 -Wall -Werror -pedantic
BSTC_TCC ?= /tcc/win64/tcc

tcc: $(BSTC_TCC_ASSEMBLIES)

$(BSTC_BIN)/tcc/%.s: $(ASSEMBLY_DIR)/%/main.c
	@echo "(TCC) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BSTC_TCC) $(BSTC_TCC_FLAGS) -I "$(call winpaths,$(PROJECT_DIR))" "$(call winpaths,$?)" -o "$(call winpaths,$@)"
	@echo

#-------------------------------------------------------------------------------------------------------------
print-%: ; @echo $* = $($*)