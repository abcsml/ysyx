all:
	@echo "make all"

sim: vsrc/light.v csrc/main.cpp
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "git commit and verilator sim"
	verilator -Wall --cc vsrc/light.v --exe --build csrc/main.cpp --trace
	./obj_dir/Vlight

clean:
	rm -r obj_dir

include ../Makefile
