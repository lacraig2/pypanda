#include "panda/plugin.h"

int before_block_execute(CPUState *env, TranslationBlock *tb){
	printf("Hit Block. Ow.");
	return 0;
}

bool init_plugin(void *self){\
	panda_cb pcb = {.before_block_exec = before_block_execute};
	panda_register_callback(self, PANDA_CB_BEFORE_BLOCK_EXEC, pcb);
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
