OBJS	= sum_numbers.o
SOURCE	= sum_numbers.c
HEADER	= 
OUT	= sum_numbers.so 
CC	 = gcc
FLAGS	 = -Wall -fPIC -shared
LFLAGS	 = 


sum_numbers.so: sum_numbers.c
	$(CC) $(FLAGS) sum_numbers.c -std=c99 -o $(OUT)


clean:
	rm -f $(OBJS) $(OUT)
