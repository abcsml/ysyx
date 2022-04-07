all:
	@echo "make all"

sim: vsrc/example.v csrc/main.cpp
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "git commit and verilator sim"
	verilator -Wall --cc vsrc/example.v --exe --build csrc/main.cpp --trace
	./obj_dir/Vexample

clean:
	rm -r obj_dir

include ../Makefile
