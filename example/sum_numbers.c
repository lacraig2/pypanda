#include "panda/plugin.h"

int on_asid_change(CPUState *env, target_ulong pc, target_ulong addr, target_ulong size, void* buf){
    printf("Guest wrote %u bytes at virtual address %u at PC: %u", size, addr, pc);
    return 0;
}

bool init_plugin(void *self){
  panda_cb pcb = {.asid_changed = on_asid_change};
  panda_register_callback(self, PANDA_CB_ASID_CHANGED, pcb};
  return true;
}

			  
			  
int sum_numbers(int num_numbers, int* numbers, int (*printout_num)(const void *)){
	int i, sum = 0;
	for (i=0; i< num_numbers; i++){
		sum +=numbers[i];
		printout_num(numbers[i]);
	}
	return sum;
}
