// Compile this assignment with: gcc -g -Wall main.c -o main
// Use this file to implement testing for your
// doubly linked list implementation
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free
#include <string.h>

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory. 0x7E7



// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    team_t* test = create_team();

    char player1[20] = "Kuzmenko";
    char player2[20] = "Mikheyev";
    char player3[20] = "Demko";
    char player4[20] = "Ekman-Larsson";

    team_push_front(test, 96, player1);
    team_push_back(test, 65, player2);
    team_push_front(test, 35, player3);
    team_insert(test, 1, 23, player4);

    free_team(test);
    
    // you can add tests here, but it's easier to add
    // tests to the dll_tests.c file
	    
    return 0;
}
