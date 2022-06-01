TOP = CPU

CPP_PATH = $(NPC_HOME)/src/csrc
INC_PATH = $(NPC_HOME)/src/csrc/include

# CONFIG_MTRACE = y
CONFIG_DIFFTEST = y


CFLAGS = -I$(INC_PATH)
ifdef CONFIG_MTRACE
	CFLAGS += -DCONFIG_MTRACE
endif
ifdef CONFIG_DIFFTEST
	CFLAGS += -DCONFIG_DIFFTEST
endif
LDFLAGS = -lpthread -lSDL2 -fsanitize=address -ldl

SIMFLAGS =
ifdef CONFIG_DIFFTEST
	SIMFLAGS += -d $(NEMU_HOME)/build/riscv64-nemu-interpreter-so
endif

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc \
				-O3 --x-assign fast --x-initial fast --noassert	\
				-CFLAGS "$(CFLAGS)" -LDFLAGS "$(LDFLAGS)"


CHISEL_SRCS = $(shell find $(CHISEL_PATH) -name "*.scala")

VSRCS = $(shell find $(abspath ./build) -name "*.v")
CSRCS = $(shell find $(CPP_PATH) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
DPICS = $(shell find $(abspath ./src/vsrc) -name "*.v")


dpi-c:
	$(VERILATOR) -cc $(DPICS) --Mdir $(OBJ_DIR)

$(BUILD_DIR)/$(TOP).v: $(CHISEL_SRCS)
	make verilog

$(OBJ_DIR)/V$(TOP): $(BUILD_DIR)/$(TOP).v dpi-c
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOP) \
		$(CSRCS) $(VSRCS) \
		--Mdir $(OBJ_DIR) --exe --trace

sim: $(OBJ_DIR)/V$(TOP)
	./build/obj_dir/V$(TOP) $(SIMFLAGS)
	@# $(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "sim over"

run: $(OBJ_DIR)/V$(TOP)
	./build/obj_dir/V$(TOP) $(SIMFLAGS) $(ARGS) $(IMG)

clean-obj:
	-rm -rf $(OBJ_DIR)

.PHONY: dpi-c sim clean-obj
