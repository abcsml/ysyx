TOPNAME = top
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

NVBOARD_HOME = /home/ad/ysyx-workbench/nvboard

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

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

run: $(BIN)
	@$^

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run





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
