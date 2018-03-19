obj-m := sim_module.o
obj-m += sim_module_init.o
obj-m += sim_module_exit.o

# override previous module name
obj-m := sim_module_new.o
sim_module_new-objs := sim_module_init.o sim_module_exit.o

obj-m := sim_module.o
obj-m += sim_module_use_symbols.o

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order

