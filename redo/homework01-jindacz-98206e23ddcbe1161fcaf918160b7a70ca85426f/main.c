// Add your program here!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL)); 

	int numOfRound = 5;
	int res[numOfRound];
	
	
	for (int i = 0; i < numOfRound; i ++) {
		int count = 0; 
		int guess = 0;
		printf("==========================\n");
		printf("CPU Says: Pick a number 1-10\n");
		printf("==========================\n");

		int target = rand() % 10 + 1;

		while (guess != target) {

			printf("Make a guess:");
			scanf("%d", &guess);
			if (guess < target) {
				printf("No guess higher!\n");
				count += 1;
			} else if (guess > target) {
				printf("No guess lower!\n");
				count += 1;
			} else {
				printf("You got it\n");
				count += 1;
				res[i] = count;
				break;
			}
		}
	}
	printf("=================================================\n");
	printf("|Here are the results of your guessing abilities|\n");
	printf("=================================================\n");

	for (int i = 0; i < numOfRound; i ++) {
		printf("Game %d took you %d guess\n", i, res[i]);
	}
}
