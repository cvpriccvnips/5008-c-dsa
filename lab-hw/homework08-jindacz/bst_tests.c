// You must submit this test file with your code implementation. 
// include all tests that you used to test your binary search tree implementation
// Compile this assignment with: gcc -Wall -g bst_tests.c -o tests
// This is a great assignment to practice debugging.
// Run with: gdb ./tests --tui
// Then type 'start'
// Then type 'next' or 'n' and enter
// See the GDB debugging video for more information

#include <stdio.h>  
#include <stdlib.h> 

#include "my_bst.h"

// Write more tests here to test your implementation. 
// We will use our own test suite (i.e. replacing this file)
// in order to test your implementation from my_bst.

// Testing allocation
int unitTest1(){
    int result;
    tree_t * testBST = bst_create();
    if (testBST!=NULL){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(testBST);
    return result;    
}

// test empty method w/ NULL tree
int unitTest2(){
    int result;
    tree_t * testBST = NULL;
    if (bst_empty(testBST) == 1){
        result = 1;
    }else{
        result = 0;
    }
    return result;
}

// test bst_empty with NULL
int unitTest3(){
    int result;
    tree_t * testBST = bst_create();
    if (bst_empty(testBST) == 1){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(testBST);
    return result;
}

// test add to empty tree
int unitTest4(){
    int result;
    tree_t * t = bst_create();
    bst_add(t, 1);
    if (t->source->data == 1){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(t);
    return result;
}

// test bst_empty with non NULL
int unitTest11(){
    int result;
    tree_t * testBST = bst_create();
    bst_add(testBST,77);
    if (bst_empty(testBST) == 0){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(testBST);
    return result;
}


// test add to root's right
int unitTest5(){
    int result;
    tree_t * t = bst_create();
    bst_add(t, 3);
    bst_add(t, 5);
    bst_add(t, 1);
    if (t->source->rightChild->data == 5
        && t->source->data == 3){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(t);
    return result;
}

// Sums empty BST
int unitTest13(){
    int result;
    tree_t * testBST = bst_create();
    result = bst_sum(testBST);
    bst_free(testBST);   
    if(result==0){ 
        return 1;
    }
    return 0;
}

// Sums one nodes in a BST
int unitTest6(){
    int result;
    tree_t * testBST = bst_create();
    bst_add(testBST, 5);
    result = bst_sum(testBST);
    bst_free(testBST);   

    if(result==5){ 
        return 1;
    }
    return 0;
}

// Sums many nodes in a BST
int unitTest7(){
    int result;
    tree_t * testBST = bst_create();
    bst_add(testBST, 5);
    bst_add(testBST, 3);
    bst_add(testBST, 2);
    result = bst_sum(testBST);
    bst_free(testBST);   

    if(result==10){ 
        return 1;
    }
    return 0;
}

// find in empty tree
int unitTest14(){
    int result;
    tree_t * testBST = bst_create();
    result = bst_find(testBST,78);
    bst_free(testBST);    
    if(result==0){ 
        return 1;
    }
    return result;
}

// Add and find a node
int unitTest8(){
    int result;
    tree_t * testBST = bst_create();
    bst_add(testBST,78);
    bst_add(testBST,1);
    bst_add(testBST,3);
    bst_add(testBST,5);
    bst_add(testBST,100);
    result = bst_find(testBST,78);
    bst_free(testBST);    
    return result;
}

// Add and find a not existing node
int unitTest9(){
    int result;
    tree_t * testBST = bst_create();
    bst_add(testBST,77);
    result = bst_find(testBST,78);
    bst_free(testBST);
    if(result==0){ 
        return 1;
    }    
    return 0;
}

// test size is not empty
int unitTest10(){
    int result;
    tree_t * testBST = bst_create();
    bst_add(testBST,77);
    if (bst_size(testBST) == 1){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(testBST);
    return result;
}

// test size is empty
int unitTest15(){
    int result;
    tree_t * testBST = bst_create();
    if (bst_size(testBST) == 0){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(testBST);
    return result;
}

// test add to NULL 
int unitTest12(){
    int result;
    tree_t * t = NULL;
    
    if (bst_add(t, 1) == -1){
        result = 1;
    }else{
        result = 0;
    }
    return result;
}

// Fill a Binary Search Tree with values 1-100 and searching for nodes. 
int unitTest16(){
    int result;
    int i;
    tree_t * testBST = bst_create();
    for (i = 1; i <= 100; i++) {
        bst_add(testBST, i);
    }
    result = bst_find(testBST,78);
    bst_free(testBST);    
    return result;
}

// Add 100 nodes and then check that the size is 100, Do not forget to compile, fix, and commit!
int unitTest17(){
    int res;
    int i;
    tree_t * testBST = bst_create();
    for (i = 1; i <= 100; i++) {
        bst_add(testBST, i);
    }
    if (bst_size(testBST) == 100){
        res = 1;
    } else {
        res = 0;
    }
    bst_free(testBST);    
    return res;
}
// Add 100 nodes with the value of '2' and check that the sum is 200. Do not forget to compile, fix, and commit!
int unitTest18(){
    int res;
    int i;
    tree_t * testBST = bst_create();
    for (i = 1; i <= 100; i++) {
        bst_add(testBST, 2);
    }
    if (bst_sum(testBST) == 200){
        res = 1;
    } else {
        res = 0;
    }
    bst_free(testBST);    
    return res;
}
// make sure this tree has the correct shape!
// Add nodes that create a highly unbalanced tree (basically a linked list) and make sure the sum is correct, print works, tree is the correct shape etc. Do not forget to compile, fix, and commit!
/*
print is tested in main function.
*/ 
int unitTest19(){
    int res;
    int i;
    tree_t * testBST = bst_create();
    for (i = 1; i <= 100; i++) {
        bst_add(testBST, i);
    }
    if (bst_sum(testBST) == 5050){
        res = 1;
    } else {
        res = 0;
    }
    bst_free(testBST);    
    return res;
}


// Add nodes that create a "V"-shaped tree (all nodes left children on the left AND all nodes right children on the right) and make sure all your functions still work. Do not forget to compile, fix, and commit!
int unitTest20(){
    int result;
    tree_t * testBST = bst_create();
    bst_add(testBST, 5);
    bst_add(testBST, 4);
    bst_add(testBST, 3);
    bst_add(testBST, 6);
    bst_add(testBST, 7);

    result = (bst_sum(testBST) == 25);
    bst_free(testBST);
    return result;
}


// Add 100 nodes with the value of 2 and 1 with a different value and make sure that value is properly located on the tree! Do not forget to compile, fix, and commit!
int unitTest21(){
    int result;
    int i;
    tree_t * testBST = bst_create();
    for (i = 1; i <= 100; i++) {
        bst_add(testBST, 1);
    }
    for (i = 1; i <= 100; i++) {
        bst_add(testBST, 2);
    }
    result = bst_find(testBST, 1);
    bst_free(testBST);
    return result;
}


// TODO: Add more tests here at your discretion
int (*unitTests[])(int) = {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    unitTest10,
    unitTest11,
    unitTest12,
    unitTest13,
    unitTest14,
    unitTest15,
    unitTest16,
    unitTest17,
    unitTest18,
    unitTest19,
    unitTest20,
    unitTest21,
};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
	
	unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter =0;
    while(unitTests[counter] != NULL){
		printf("========unitTest %d========\n",counter);
		if(1==unitTests[counter](1)){
			printf("passed test\n");
			testsPassed++;	
		}else{
			printf("failed test, missing functionality, or incorrect test\n");
		}
        counter++;
    }

    printf("%d of %d tests passed\n",testsPassed,counter);


    // test bst_print
    tree_t* t = bst_create();
    bst_add(t, 60);
    bst_add(t, 30);
    bst_add(t, 20);
    printf("testing bst_print ascending:\n");
    bst_print(t, 0);
    printf("testing bst_print descending:\n");
    bst_print(t, 1);
    bst_free(t);


    tree_t* t1 = NULL;
    printf("testing bst_print NULL tree:\n");
    bst_print(t1, 0);

    tree_t* t2 = bst_create();
    printf("testing bst_print empty tree:\n");
    bst_print(t2, 0);
    bst_free(t2);

    tree_t* t3 = bst_create();
    bst_add(t3, 20);
    printf("testing bst_print single element:\n");
    bst_print(t3, 0);
    bst_free(t3);

    return 0;
}
