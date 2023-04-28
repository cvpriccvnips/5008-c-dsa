/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool valid(struct TreeNode* root, long lo, long hi) {
    // If current node is null, it means the subtree is checked, return true.
    if (!root) {
        return true;
    }
    // If current node is not between lo and hi, return false.
    if (!(lo < root->val && root->val < hi)) {
        return false;
    }
    // Check if left subtree satisfies the definition of BST.
    // The upper bound of values in the left subtree is the value of current node.
    // The lower bound of values in the left subtree is lo.
    bool leftValid = valid(root->left, lo, root->val);
    // Check if right subtree satisfies the definition of BST.
    // The lower bound of values in the right subtree is the value of current node.
    // The upper bound of values in the right subtree is hi.
    bool rightValid = valid(root->right, root->val, hi);
    // If both left and right subtrees satisfy the definition of BST, return true.
    return leftValid && rightValid;
}

bool isValidBST(struct TreeNode* root){
    // The recursive function to check if the subtree satisfies the definition of BST.
    // lo and hi represent the lower and upper bounds of node values in the subtree.
    // Call valid function to check if the whole tree satisfies the definition of BST.
    return valid(root, LONG_MIN, LONG_MAX);
}

/*
Alternative solution:
A brute force solution to check if a binary tree is a valid binary search tree is to do an inorder traversal of the tree, which would result in a sorted list of values. We can then check if the resulting list is in strictly increasing order. This solution would have a time complexity of O(n) to traverse the entire tree, and an additional O(n) space complexity to store the resulting list of values. However, this solution is not optimal since we are storing additional information and iterating over the tree multiple times.

Trade-offs:
The given solution uses recursion to traverse the tree once and performs constant time operations at each node. This results in a linear time complexity of O(n) and a space complexity of O(n) in the worst case. The alternative solution, on the other hand, would result in a time complexity of O(n) to traverse the entire tree and an additional space complexity of O(n) to store the resulting list of values. The alternative solution would have a better space complexity in the average case, but its time complexity would remain the same.

Edge cases and constraints:
The given solution works for all types of binary trees including empty trees, single node trees, and trees with multiple levels. It also works for trees with negative and positive values, and trees with duplicate values. The only constraint is that the values of the nodes should be within the range of a long data type, which is -2^63 to 2^63-1. This is handled by passing the minimum and maximum values of the long data type as initial lower and upper bounds when calling the valid function.

Time complexity:
The time complexity of the given solution is O(n) where n is the number of nodes in the tree. This is because we visit every node in the tree once and perform constant time operations at each node.

Space complexity:
The space complexity of the given solution is O(n) in the worst case. This is because we use recursion to traverse the tree, and the depth of the recursion can be equal to the number of nodes in the tree in the worst case.
*/