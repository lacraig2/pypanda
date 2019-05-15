int sum_numbers(int num_numbers, int* numbers, int (*printout_num)(const void *)){
	int i, sum = 0;
	for (i=0; i< num_numbers; i++){
		sum +=numbers[i];
		printout_num(numbers[i]);
	}
	return sum;
}


int on_asid_change(CPUState *env, int old_asid, int new_asid){
    printf("ASID CHANGED from %u to %u", old_asid, new_asid);
    return 0;
}

bool init_plugin(void *self){
  panda_cb pcb = {.asid_changed = on_asid_change};
  panda_register_callback(self, PANDA_CB_ASID_CHANGED, pcb};
  return true;
}
