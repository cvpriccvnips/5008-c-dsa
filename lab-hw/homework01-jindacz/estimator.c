// Implement your cycle count tool in this file.
// We will call your program with ./estimator barebones.s
// we will also test it with another .s file with a different name
// your program must analyze whichever .s file we pass into it

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 100
#define ADD_CYCLES 1
#define MOV_CYCLES 1
#define PUSH_CYCLES 2
#define POP_CYCLES 3
#define LEA_CYCLES 3
#define MUL_CYCLES 3
#define DIV_CYCLES 24
#define SUB_CYCLES 1
#define RET_CYCLES 1

// all the rest of your code can be in main
int main(int argc, char** argv) {

	int counter_add = 0;
	int counter_mov = 0;
	int counter_mul = 0;
	int counter_sub =0;
	int counter_div =0;
	int counter_lea =0;
	int counter_push =0;
	int counter_pop =0;
	int counter_ret =0;


	char buff[BUFF_SIZE];
	FILE *fp = NULL;

    // TODO your estimator code goes here
    // make sure you can accept any file name from the command line for analysis
	fp = fopen(argv[1], "r");
	
	while (fgets(buff, BUFF_SIZE, fp) != NULL) {
		if (strstr(buff, "add")) {
			counter_add += 1;
		} else if (strstr(buff, "sub")) {
			counter_sub += 1;
		} else if (strstr(buff, "mul") || strstr(buff, "imul")) {
			counter_mul += 1;
		} else if (strstr(buff, "div") || strstr(buff, "idiv")) {
			counter_div += 1;
		} else if (strstr(buff, "mov")) {
			counter_mov += 1;
		} else if (strstr(buff, "lea")) {
			counter_lea += 1;
		} else if (strstr(buff, "push")) {
			counter_push += 1;
		} else if (strstr(buff, "pop")) {
			counter_pop += 1;
		} else if (strstr(buff, "ret")) {
			counter_ret += 1;
		}
	}

	fclose(fp);

	

	printf("There are %d of add\n", counter_add);
	printf("There are %d of mov\n", counter_mov);
	printf("There are %d of mul\n", counter_mul);
	printf("There are %d of sub\n", counter_sub);
	printf("There are %d of div\n", counter_div);
	printf("There are %d of lea\n", counter_lea);
	printf("There are %d of pop\n", counter_pop);
	printf("There are %d of ret\n", counter_ret);
	printf("There are %d of push\n", counter_push);

	int cycle_counter = 0;

	int counter_instructions = 0;
	counter_instructions += counter_add + counter_mov + counter_mul + counter_sub + counter_div + counter_lea + counter_pop + counter_ret + counter_push;

	cycle_counter += counter_add * ADD_CYCLES;
	
	cycle_counter += counter_mov * MOV_CYCLES;
	cycle_counter += counter_mul * MUL_CYCLES;
	cycle_counter += counter_sub * SUB_CYCLES;
	cycle_counter += counter_div * DIV_CYCLES;
	cycle_counter += counter_lea * LEA_CYCLES;
	cycle_counter += counter_pop * POP_CYCLES;
	cycle_counter += counter_ret * RET_CYCLES;
	cycle_counter += counter_push * PUSH_CYCLES;

	printf("The number of instructions is %d\n", counter_instructions);
	printf("The number of cycles is approximately %d\n", cycle_counter);


    return 0;
}