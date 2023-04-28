/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_SIZE 5000
void inorder(struct TreeNode* root, int* res, int* i) {
    if (root == NULL) {
        return;
    }
    // traverse left subtree
    inorder(root->left, res, i);
    // add root's value to array and increment index
    res[(*i)++] = root->val;
    // traverse right subtree
    inorder(root->right, res, i);
}

int* merge(int* arr1, int size1, int* arr2, int size2) {
    // allocate memory for merged array
    int* merged = (int*)malloc(sizeof(int) * (size1 + size2));
    int i1 = 0, i2 = 0, i = 0;
    // merge the two arrays in ascending order
    while (i1 < size1 && i2 < size2) {
        if (arr1[i1] < arr2[i2]) {
            merged[i++] = arr1[i1++];
        } else {
            merged[i++] = arr2[i2++];
        }   
    }
    // add remaining elements from arr1 to merged array
    while (i1 < size1) {
        merged[i++] = arr1[i1++];
    }
    // add remaining elements from arr2 to merged array
    while (i2 < size2) {
        merged[i++] = arr2[i2++];
    }
    return merged;
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    // allocate memory for array 1, 2
    int* arr1 = (int*)malloc(sizeof(int) * MAX_SIZE);
    int* arr2 = (int*)malloc(sizeof(int) * MAX_SIZE);
    int i1 = 0, i2 = 0;
    // traverse tree 1 and add values to arr1
    inorder(root1, arr1, &i1);
    // traverse tree 2 and add values to arr2
    inorder(root2, arr2, &i2);
    // merge the two arrays
    int* merged = merge(arr1, i1, arr2, i2);
    // set the size of the merged array
    *returnSize = i1 + i2;
    free(arr1);
    free(arr2);
    return merged;
}

/*
-Alternative solution:
A brute force solution would be to traverse both trees in-order and merge the resulting arrays. This would require two traversals and merging of two arrays, resulting in O(nlogn) time complexity due to the sorting operation required to merge the arrays. This solution is less efficient than the chosen solution which merges the two trees in-order without sorting.

-Trade-offs:
The chosen solution has a time complexity of O(n) since it only requires traversing each tree once and then merging two sorted arrays, which can be done in linear time. The space complexity of the chosen solution is O(n) since it requires creating two arrays of size n, one for each tree. The brute force solution also has a space complexity of O(n) due to the need to store the resulting merged array.

- The chosen solution has a time complexity of O(n) because it requires traversing each tree once and then merging two sorted arrays, which can be done in linear time. 
The space complexity of the solution is also O(n) because it requires creating two arrays of size n, one for each tree.

- Edge cases and constraints:
The solution should be able to handle the case where one or both trees are empty, which would result in an empty array being returned. The maximum size of the arrays used to store the in-order traversal of each tree is limited to 10000, which should be sufficient for most cases but may need to be increased for very large trees. Additionally, the solution assumes that there are no duplicate values in either tree, as it does not check for duplicates when merging the arrays. If duplicates are present, they will be included in the final result.
*/