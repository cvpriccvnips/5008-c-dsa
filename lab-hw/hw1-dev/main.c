#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int numOfRounds = 5;
    int result[numOfRounds];
    int i;

    for (i = 0; i < numOfRounds; i += 1) {
        int guess;
        int count = 0;
        
        printf("==========================\n");
        printf("CPU Says: Pick a number 1-10\n");
        printf("==========================\n");
        
        int target = rand() % 10 + 1;

        while (target != count) { 
            printf("Make a guess:");
            scanf("%d", &guess);
            count += 1;
            if (guess < target) {
                printf("No guess higher!\n");
            } else if (guess > target) {
                printf("No guess lower!\n");
            }
        }
        printf("You got it!\n");
        result[i] = count;
    }
    printf("=================================================\n");
    printf("|Here are the results of your guessing abilities|\n");
    printf("=================================================\n");
    for (i = 0; i < numOfRounds; i += 1) {
        printf("Game %d took you %d guesses\n", i, result[i]);
    }
    return 0;
}