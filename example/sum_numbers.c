
panda = Panda(qcow="/path/to/my/qcow", mem="2G")
panda.load_plugin("cool_c_plugin")
panda.register_callback(...) # we will get to this later
panda.load_python_plugin(init,"example_plugin")
panda.begin_replay("/path/to/my/replay")
panda.run()
panda.stop()
			  
			  
int sum_numbers(int num_numbers, int* numbers, int (*printout_num)(const void *)){
	int i, sum = 0;
	for (i=0; i< num_numbers; i++){
		sum +=numbers[i];
		printout_num(numbers[i]);
	}
	return sum;
}
