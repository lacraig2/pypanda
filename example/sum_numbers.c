int sum_numbers(int num_numbers, int* numbers, int (*printout_num)(const void *)){
	int i, sum = 0;
	for (i=0; i< num_numbers; i++){
		sum +=numbers[i];
		printout_num(numbers[i]);
	}
	return sum;
}
