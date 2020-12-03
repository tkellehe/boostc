BST_BUILD ?= ./.build
BST_BIN ?= ./bin
BST_CC ?= gcc

# https://stackoverflow.com/a/12959694/5407843
# Make does not offer a recursive wildcard function, so here's one:
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

ALL_MAINC := $(call rwildcard,./,*main.c)
OBJS := $(ALL_MAINC:./%.c=$(BST_BUILD)/%.o)
TESTS := $(ALL_MAINC:./%/main.c=$(BST_BIN)/%)

FLAGS := -O6 -Wall -Werror -I../
LFLAGS := -O6

.PHONY: all

clean:
	@rm -rf $(BST_BIN) $(BST_BUILD)

all: $(TESTS)

print-%: ; @echo $* = $($*)

$(BST_BUILD)/%.o: ./%.c
	@echo "Compiling: $?"
	@mkdir -p `dirname $@`
	$(BST_CC) $(FLAGS) -c $? -o $@
	@echo

$(BST_BIN)/%: $(BST_BUILD)/%/main.o
	@echo "Building Test: $@"
	@mkdir -p `dirname $@`
	$(BST_CC) $(LFLAGS) $? -o $@
	@echo
