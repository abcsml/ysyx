BUILD_DIR = ./build

OBJ_DIR = $(BUILD_DIR)/obj_dir
VSRCS = $(shell find $(abspath ./build) -name "*.v")
# VSRCS += $(shell find $(abspath ./playground/src/vsrc) -name "*.v")

test:
	mill -i __.test

verilog:
	$(call git_commit, "generate verilog")
	mkdir -p $(BUILD_DIR)
	mill -i __.test.runMain Elaborate -td $(BUILD_DIR)

help:
	mill -i __.test.runMain Elaborate --help

compile:
	mill -i __.compile

bsp:
	mill -i mill.bsp.BSP/install

reformat:
	mill -i __.reformat

checkformat:
	mill -i __.checkFormat

clean:
	-rm -rf $(BUILD_DIR)

sim: 
	verilator -MMD --build -cc  \
		-O3 --x-assign fast --x-initial fast --noassert \
		--top-module CPU \
		$(abspath ./playground/src/csrc)/cpu.cpp \
		$(abspath ./playground/src/csrc)/mem.cpp \
		$(VSRCS) \
		--Mdir $(OBJ_DIR) --exe --trace
	# $(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."

.PHONY: test verilog help compile bsp reformat checkformat clean sim

include ../Makefile
