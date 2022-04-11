TOPNAME = top
NXDC_FILES = constr/top.nxdc
INC_PATH ?= $(abspath ./vsrc)

# NVBOARD_HOME = /home/ad/ysyx-workbench/nvboard

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
OUTPUT_DIR = ./output
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))
$(shell mkdir -p $(OUTPUT_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)
TESTS = $(shell find $(abspath ./test) -name "*.cpp")

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default
	@echo "make all"

nvboard: $(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@$^

sim: $(TESTS) $(VSRCS)
	@for sub in $(TESTS); do	\
		$(VERILATOR) $(VERILATOR_CFLAGS) \
			--top-module $(mod) \
			$$sub $(VSRCS) --Mdir $(OBJ_DIR) \
			--exe --trace; \
	done
	./build/obj_dir/V$(mod)
	gtkwave ./output/$(mod).vcd
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(OUTPUT_DIR)

.PHONY: default all clean nvboard sim

include ../Makefile


# # rules for NVBoard
# include $(NVBOARD_HOME)/scripts/nvboard.mk

# # VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
# # CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

# all:
# 	@echo "make all"

# sim: vsrc/light.v csrc/main.cpp
# #	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
# 	@echo "git commit and verilator sim"
# 	verilator -Wall --cc vsrc/light.v --exe --build csrc/main.cpp --trace
# 	./obj_dir/Vlight

# run: $(NVBOARD_ARCHIVE)
# 	verilator -Wall --cc vsrc/light.v --exe --build csrc/main.cpp --trace
# 	./obj_dir/Vlight

# clean:
# 	rm -r obj_dir

# include ../Makefile
