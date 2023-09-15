all: third_program.o sum_func.o
	gcc third_program.o sum_func.o && del *.o

third_program.o: third_program.c
	gcc -c third_program.c

sum_func.o: sum_func.c
	gcc -c sum_func.c
	