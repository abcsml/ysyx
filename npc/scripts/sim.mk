TOP = CPU

CPP_PATH = $(NPC_HOME)/src/csrc
INC_PATH = $(NPC_HOME)/src/csrc/include

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert	\
				-CFLAGS -I$(INC_PATH)

VSRCS = $(shell find $(abspath ./build) -name "*.v")
CSRCS = $(shell find $(CPP_PATH) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
DPICS = $(shell find $(abspath ./src/vsrc) -name "*.v")

# $(OBJ_DIR): verilog
# 	@echo "Make all"
dpi-c:
	verilator -cc $(DPICS) --Mdir $(OBJ_DIR)

sim: $(OBJ_DIR) $(VSRCS)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOP) \
		$(CSRCS) $(VSRCS) \
		--Mdir $(OBJ_DIR) --exe --trace;
	./build/obj_dir/V$(TOP)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by yourself."

clean-obj:
	-rm -rf $(OBJ_DIR)
