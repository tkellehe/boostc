BST_BUILD ?= ./.build
BST_BIN ?= ./bin

# https://stackoverflow.com/a/12959694/5407843
# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

ALL_MAINC := $(call rwildcard,./,*main.c)

clean:
	@rm -rf $(BST_BIN) $(BST_BUILD)

#-------------------------------------------------------------------------------------------------------------
GCC_OBJS := $(ALL_MAINC:./%.c=$(BST_BUILD)/gcc/%.o)
GCC_TESTS := $(ALL_MAINC:./%/main.c=$(BST_BIN)/gcc/%)
GCC_FLAGS := -O6 -Wall -Werror -pedantic -I../
GCC_BIN_FLAGS := -O6
GCC := gcc

gcc: $(GCC_TESTS)

$(BST_BUILD)/gcc/%.o: ./%.c
	@echo "(GCC) Compiling: $?"
	@mkdir -p `dirname $@`
	$(GCC) $(GCC_FLAGS) -c $? -o $@
	@echo

$(BST_BIN)/gcc/%: $(BST_BUILD)/gcc/%/main.o
	@echo "(GCC) Building Test: $@"
	@mkdir -p `dirname $@`
	$(GCC) $(GCC_BIN_FLAGS) $? -o $@
	@echo

#-------------------------------------------------------------------------------------------------------------
VC14_OBJS := $(ALL_MAINC:./%.c=$(BST_BUILD)/vc14/%.o)
VC14_TESTS := $(ALL_MAINC:./%/main.c=$(BST_BIN)/vc14/%)
VC14_FLAGS := /Ox -Wall -Werror -pedantic -I../
VC14_BIN_FLAGS := /Ox

vc14: $(VC14_TESTS)

$(BST_BUILD)/vc14/%.o: ./%.c
	@echo "(VC14) Compiling: $?"
	@mkdir -p `dirname $@`
	$(VC14) $(VC14_FLAGS) -c $? -o $@
	@echo

$(BST_BIN)/vc14/%: $(BST_BUILD)/vc14/%/main.o
	@echo "(VC14) Building Test: $@"
	@mkdir -p `dirname $@`
	$(VC14) $(VC14_BIN_FLAGS) $? -o $@
	@echo

#-------------------------------------------------------------------------------------------------------------
print-%: ; @echo $* = $($*)