BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
OUTPUT_DIR = ./output

$(shell mkdir -p $(BUILD_DIR))
$(shell mkdir -p $(OUTPUT_DIR))

test:
	mill -i __.test

verilog:
	# $(call git_commit, "generate verilog")		error
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

.PHONY: test verilog help compile bsp reformat checkformat clean sim

include $(NPC_HOME)/scripts/sim.mk

include ../Makefile
