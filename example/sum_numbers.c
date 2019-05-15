#include "panda/plugin.h"

int virt_mem_write(CPUState *env, target_ulong pc, target_ulong addr, target_ulong size, void* buf){
    printf("Guest wrote %u bytes at virtual address %u at PC: %u", size, addr, pc);
    return 0;
}

bool init_plugin(void *self){
  panda_cb pcb = {.virt_mem_before_write = virt_mem_write};
  panda_register_callback(self, PANDA_CB_VIRT_MEM_BEFORE_WRITE, pcb};
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
