#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(0));
    
    int numOfRounds = 1;
    int rounds[numOfRounds];
    int i;

    for (i = 0; i < numOfRounds; i += 1) {
        int guess = 0;
        int count = 0;

        printf("==========================\n");
        printf("CPU Says: Pick a number 1-10\n");
        printf("==========================\n");

        int target = rand() % 10 + 1;

        while (guess != target) {
            printf("Make a guess:");
            scanf("%d", &guess);
            count += 1;
            if ( guess < target ){
                printf("No guess higher!\n");
            } else if ( guess > target) {
                printf("No guess lower!\n");
            }
        }
        printf("You got it!\n");
        rounds[i] = count;
    }

    printf("=================================================\n");
    printf("|Here are the results of your guessing abilities|\n");
    printf("=================================================\n");

    for (i = 0; i < numOfRounds; i += 1) {
        printf("Game %d took you %d guesses\n", i, rounds[i]);
    }
    return 0;
}