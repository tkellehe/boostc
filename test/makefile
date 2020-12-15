# Current directory for project.
TEST_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
PROJECT_DIR := $(abspath $(TEST_DIR)/..)
# Remove the last slash.
TEST_DIR := $(PROJECT_DIR)/test

# Convert paths to windows.
# winpaths=$(subst /,\,$1)
winpaths=$(shell cygpath -w $1)

# https://stackoverflow.com/a/12959694/5407843
# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

# Get all of the main files.
ALL_MAINC := $(call rwildcard,$(TEST_DIR)/,*main.c)

# Check to see if the bin directory has been specified.
BST_BIN ?= $(TEST_DIR)/bin

all: gcc clang vs14

clean:
	@rm -rf $(BST_BIN)

#-------------------------------------------------------------------------------------------------------------
BST_GCC_TESTS := $(ALL_MAINC:$(TEST_DIR)/%/main.c=$(BST_BIN)/gcc/%)
BST_GCC_FLAGS ?= -O6 -Wall -Werror -pedantic -I $(PROJECT_DIR)
BST_GCC ?= gcc

gcc: $(BST_GCC_TESTS)

$(BST_BIN)/gcc/%: $(TEST_DIR)/%/main.c
	@echo "(GCC) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BST_GCC) $(BST_GCC_FLAGS) $? -o $@
	@echo

#-------------------------------------------------------------------------------------------------------------
BST_CLANG_TESTS := $(ALL_MAINC:$(TEST_DIR)/%/main.c=$(BST_BIN)/clang/%)
BST_CLANG_FLAGS ?= -O3 -Wall -Werror -pedantic -I $(PROJECT_DIR)
BST_CLANG ?= clang

clang: $(BST_CLANG_TESTS)

$(BST_BIN)/clang/%: $(TEST_DIR)/%/main.c
	@echo "(CLANG) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BST_CLANG) $(BST_CLANG_FLAGS) $? -o $@
	@echo

#-------------------------------------------------------------------------------------------------------------
BST_VS14_TESTS := $(ALL_MAINC:$(TEST_DIR)/%/main.c=$(BST_BIN)/vs14/%)
BST_VS14_FLAGS ?= /c /nologo /EHsc /Ox /W4 /I $(call winpaths,$(PROJECT_DIR)) /link Kernel32.lib User32.lib
BST_VS14 ?= $(PROJECT_DIR)/scripts/msvc.bash run_vs14 cl
BST_VS14_LINK ?= $(PROJECT_DIR)/scripts/msvc.bash run_vs14 link

vs14: $(BST_VS14_TESTS)

$(BST_BIN)/vs14/%: $(TEST_DIR)/%/main.c
	@echo "(VS14) Building Test: $@"
	@mkdir -p `dirname $@`
	$(BST_VS14) $(call winpaths,$?) $(BST_VS14_FLAGS)
	$(BST_VS14_LINK) /SUBSYSTEM:CONSOLE main.obj /out:$(call winpaths,$@)
	@echo

#-------------------------------------------------------------------------------------------------------------
print-%: ; @echo $* = $($*)