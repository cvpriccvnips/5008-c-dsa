//Compile the source code with: clang mergesort.c -o mergesort
//Run the source code with: ./mergesort

// Task: Implement the 'sortIntegers' function below, 
//You must use merge and mergesort with the given function signatures

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output
#include <stdlib.h>
#include <time.h>

#define EXPERIMENT 0 // use this for the experimentation in this lab

// =============== Helper Functions ===============

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int temp[], int l, int m, int r) {
  //TODO: implement merge.
  //use all those parameters in your implementation, including temp array 
  int lp, rp, cur;
  lp = l;
  rp = m + 1;
  cur = l;
  
  // two pointer comparsion template
  while (lp <= m && rp <= r) {
    if (arr[lp] <= arr[rp]) {
      temp[cur] = arr[lp];
      cur += 1;
      lp += 1;
    } else {
      temp[cur] = arr[rp];
      cur += 1;
      rp += 1;
    }
  }

  // if left is not end copy the rest
  while (lp <= m) {
    temp[cur] = arr[lp];
    lp += 1;
    cur += 1;
  }

  // if right is not end copy the rest
  while (rp <= r) {
    temp[cur] = arr[rp];
    rp += 1;
    cur += 1;
  }

  // copy temp l:r to arr[l:r]
  cur = l;
  while (cur <= r) {
    arr[cur] = temp[cur];
    cur += 1;
  }
}

// TODO: Implement your mergeSort function here
void mergeSort(int array[], int temp[], int l, int r) {
    // recursion ending(base) case
    if (l >= r) { 
      return;
    }
    int m;
    m = (l + r) / 2;
    mergeSort(array, temp, l, m);
    mergeSort(array, temp, m+1, r);
    merge(array, temp, l, m, r);
}


// Provided below is a sort function. We have also
// provided a template for how to document functions
// to help organize your code.
// Name: sortIntegers
// Input(s):
//          (1) 'array' is a pointer to an integer address. 
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.

void sortIntegers(int* array, unsigned int size){
    int tmp[size];
    // TODO: make a call to your mergeSort function here
    mergeSort(array, tmp, 0, size - 1);
}


// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(int argc, char** argv){
#if EXPERIMENT==0
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  // Sort our integer array
  sortIntegers(dataset1, 11);
  sortIntegers(dataset2, 11);
  sortIntegers(dataset3, 11);
  sortIntegers(dataset4, 11);
  sortIntegers(dataset5, 11);
  sortIntegers(dataset6, 11);
  
  // Print out an array
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);

#else

  if (argc != 2) {
    printf("One argument expected: ./insertion 1000\n");
    return 1;
  }

  // Convert the argument of the program into an integer
  const int size = atoi(argv[1]);
  // Generate a random seed
  time_t t;
  srand((unsigned)time(&t));
  // Allocate memory
  int* random = (int*)malloc(sizeof(int)*size);

  // Populate our test data set
  for(int i = 0 ; i < size ; i++) {
    // Generate random values from 0 to 99
    random[i] = rand()%size; 
  }

  // You can uncomment if you'd like to see the size sorted
  // printf("Before the sort: ");
  // printIntArray(random, size);

  // Setup timers  
  struct timespec begin, end;
  // Get the time before we start
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  // Perform the sort
  sortIntegers(random,size);
  // Get the time after we are done
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
            (end.tv_sec  - begin.tv_sec);
  printf ("Total time = %f seconds\n", time_taken);

  // Confirm the sort worked
  // printf("After the sort: ");
  // printIntArray(random, size);
  
  // Free our random array
  free(random);

#endif

  return 0;
}
