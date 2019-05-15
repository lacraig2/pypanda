#include "panda/plugin.h"

int on_handle_packet(CPUState *env, uint8_t *buf, int size, unt8_t direction, uint64_t old_buf_addr){
  if (type == PANDA_NET_RX)
  	printf("Guest RECEIVED packet containing %u bytes", size);
  else
	printf("Guest SENT packet containing %u bytes", size);
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
