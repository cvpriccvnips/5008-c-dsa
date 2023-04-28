// Compile with: gcc -Wall pascal.c -o pascal
// Run with: ./pascal 32
#include <stdio.h>
#include <stdlib.h>

#define LARGEST_TRIANGLE 32

// calculate and return the i-th row of Pascal's Triangle
// rowIndex = the index of the row that should be calculated
// returnSize = the size of the row that was calculated
// returns a pointer to an array of size `returnSize`,
//    assume that the caller calls free on the returned array
//
// coincidentally, this problem is the same as one of the problems
// on LeetCode: https://leetcode.com/problems/pascals-triangle-ii/
int* getRow(int rowIndex, int* returnSize){
	//Create 2D array to represent triangle 
	int* array[LARGEST_TRIANGLE];//row = 32
	for (int i = 0; i < LARGEST_TRIANGLE; i++) {
		array[i] = (int*)malloc(sizeof(int) * (LARGEST_TRIANGLE + 1));
	} //every row has 32 + 1 columns

	//initialize table's values to 0, because we have no 0 i pascal
	for (int i = 0; i < LARGEST_TRIANGLE; i ++) {
		for (int j = 0; j < LARGEST_TRIANGLE + 1; j++) {
			array[i][j] = 0;
		}
	}

	//set up base case
	array[0][1] = 1; 
	//fill in the table
	for (int i = 1; i < LARGEST_TRIANGLE; i++) {
		for (int j = 1; j < LARGEST_TRIANGLE + 1; j++) {
			array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
		}
	}

	*returnSize = rowIndex + 1;
	//find what to return 
	int* return_array = (int*)malloc(sizeof(int) * (*returnSize));
	int col;
	for (col = 1; col <= rowIndex + 1; col++) {
		return_array[col - 1] = array[rowIndex][col];
	}

   return return_array;
}

int main(int argc, char *argv[])
{
   // Make sure that there is one argument
   if (argc != 2)
   {
      printf("One argument expected: ./pascal 42\n");
      return 1;
   }

   // Convert the argument of the program into an integer
   // and make sure that it is between 0 and LARGEST_TRIANGLE - 1
   const int row = atoi(argv[1]);
   if (row < 0 || row > LARGEST_TRIANGLE - 1)
   {
      printf("row must between 0 and %d (inclusive)\n", LARGEST_TRIANGLE - 1);
      return 1;
   }

   int size = 0;
   int *row_values = getRow(row, &size);

   printf("Row %d of Pascal's Triangle\n", row);
   for (int i = 0; i < size; i++)
   {
      printf("%d ", row_values[i]);
   }
   printf("\n");

   // free the memory that was returned from function
   free(row_values);
   return 0;
}
