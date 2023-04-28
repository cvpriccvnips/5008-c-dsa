Codewalk:

所解释的解决方案代码是技术上正确的解决问题的 C 代码（7 分）
逐行解释代码功能，包括函数签名（7 分）

The code is sorting an integer array by implementing the insertion sort algorithm. The function 'sortIntegers' takes two inputs, an integer pointer 'array' which is the address of the start of the array to be sorted, and 'size' which is the number of elements in the array.

Before sorting the array, the function checks if the array is empty or has less than 2 elements, in which case it returns without sorting. If not, it will proceed to sort the array.

The code then starts a for loop that will run from 1 to 'size' - 1. Within the for loop, a variable 'toInsert' is declared and set to the current value of 'i'.

The inner while loop starts by checking if the value of the 'toInsert'-th element is less than the previous element and 'toInsert' is greater than 0. If both conditions are true, the function 'swap' is called with the addresses of the two elements. The 'swap' function swaps the values stored in the memory addresses passed to it.

After the swap, the value of 'toInsert' is decremented by 1. This continues until the value of the 'toInsert'-th element is no longer less than the previous element or 'toInsert' becomes 0. This inner while loop ensures that the current element is inserted in its correct position in the array.

The for loop then continues and moves to the next element. This continues until all elements in the array have been inserted in their correct positions.

解决方案的大O时间和空间复杂度描述和解释（5分）
Complexity:
The time complexity of this algorithm is O(n^2) where 'n' is the number of elements in the array. This is because for each element, it may require up to 'n' comparisons to insert it in the correct position. 

The space complexity is O(1) as the sorting is done in-place and does not require additional memory.


学生尽其所能回答所提问题（5 分）
Questions:

"which part of the array is already sorted after one pass?",

- After one pass, the first element of the array will be the smallest number and will be in the correct sorted position. The rest of the array will still be unsorted.

"how would we sort this array in place without a swap function? What code would change, and how would it change?",

- To sort the array in place without the swap function, we could use a third variable to temporarily store the value of the current number while swapping. For example, we could do the following:
int temp = array[toInsert];
array[toInsert] = array[toInsert-1];
array[toInsert-1] = temp;


"how many lines would you change in sortIntegers to make this selection rather than insertion sort?",

- To make the sort a selection sort, we would need to change at least 3 lines lines of code. 
Replace the for loop with a nested loop to find the minimum value in the unsorted portion of the array:
for (int i = 0; i < size - 1; i++) {
	int minIndex = i;
	for (int j = i + 1; j < size; j++) {
	if (array[j] < array[minIndex]) {
	minIndex = j;
	}
}

Swap the minimum value with the current position in the array:
swap(&array[i], &array[minIndex]);

Remove the inner while loop as it is not needed in a selection sort.


"which lines of code ensure that this sort is stable, and why?",

- while (array[toInsert] < array[toInsert-1] && toInsert > 0) 
it ensures that adjacant element need to be swapped if and only if element is smaller than previous element, if they are equal, no swap is needed

"explain your use of a pointer in sortIntegers (you defintely use a pointer. Where is it and why do you use it)",

- The pointer in sortIntegers is used to reference the values stored in the array. We pass the address of the current array elements to the swap function, allowing us to modify the actual values stored in the array.



"What is the minimum code you could change to make this sort descending instead of ascending?",

- To make the sort descending, we would simply need to change the comparison in the while loop. Instead of array[toInsert] < array[toInsert-1], we would use array[toInsert] > array[toInsert-1].

"How much space does your implmentation of insertion sort use? Could you use less?"

- The implementation of insertion sort uses O(1) space. We only use a few extra variables to store indices and do not create any additional arrays. There is no way to use less space for sorting, as we need to keep track of the elements in the array in order to sort them.