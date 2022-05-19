TOP = CPU

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

VSRCS = $(shell find $(abspath ./build) -name "*.v")

$(OBJ_DIR): verilog
	@echo "Make all"

sim: $(OBJ_DIR) $(VSRCS)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOP) \
		$(abspath ./src/monitor)/npc-main.cpp $(VSRCS) \
		--Mdir $(OBJ_DIR) --exe --trace;
	./build/obj_dir/V$(TOP)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."
