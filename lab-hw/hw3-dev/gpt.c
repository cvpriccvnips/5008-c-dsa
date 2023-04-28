

Unit Tests
A unit test is a standalone test that checks for the correctness of a specific use case in your code. In our case, we are testing if we have a working DLL implementation.

Please write unit tests to test your implementation. Some example tests we might come up with include:

Fill a DLL, empty the DLL, and fill the DLL again.
Test each function in your DLL when the DLL is not empty.
Test each function in your DLL when the DLL is empty.
Make sure you test insert and remove extensively in conjunction with the other functions!
There is an example test file called dll_test.c that you should add unit tests to. I have provided a small number of tests: I recommend you double or triple the tests here! You can construct additional tests based on my examples. 
Compile with: gcc -g -Wall dll_test.c -o dll_test
NOTE: these tests will segfault on test 3 and onward until you're returning a player node properly; comment out segfaulting tests until you have completed those functions. 
Run with: ./dll_test
Don't forget to run valgrind! valgrind ./dll_test and valgrind -s ./dll_test are your best friends here!
Compile, debug, commit
Compile, debug, commit


// =================== Support Code =================
// Doubly Linked List ( Team DLL ).
//
// - Implement each of the functions to create a working DLL that represents a hockey team.
// - Do not change any of the function declarations
//   - (i.e. team_t* create_team() should not have additional arguments)
// - You should not have any 'printf' statements in your functions. 
//   - (You may consider using these printf statements to debug,
//     but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

// Create a player data structure to store data within
// our Team DLL. In our case, we will store a hockey player in each player struct.
// rosterNum is the player's roster number; roster numbers are always greater than 0
// The longest player name ever used in the NHL is 14 characters, so you can 
// assume the longest name you'll have to deal with is at most 20 character long
// we are only using family names.
typedef struct player {
	int rosterNum;
	char* name;
	struct player* next;
  	struct player* previous;
} player_t;

// Create a Team data structure that is a doubly linked list
// Our Team DLL holds a pointer to the first player node in our Team dll called head,
// and a pointer to the last player node in our Team called tail.
// It also keeps count of how many active players we have on our Team
typedef struct Team {
	int activePlayers;		// count keeps track of how many active players are on the Team.
	player_t* head;		// head points to the first player node in our DLL.
    player_t* tail;          //tail points to the last player node in our DLL.
} team_t;

// Creates a Team 
// Returns a pointer to a newly created Team.
// The Team should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The Team fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
team_t* create_team(){
	// Modify the body of this function as needed.
	team_t* myTeam= NULL;
	return myTeam; // Note: This line is a 'filler' so the code compiles.
}



// Team DLL Empty
// Check if the team is empty
// Returns -1 if the team is NULL.
// Returns 1 if true (The team is completely empty)
// Returns 0 if false (the team DLL has at least one player enqueued)
int team_empty(team_t* t){

    return 99999; // Note: This line is a 'filler' so the code compiles.
}

// push a new player to the front of the DLL ( before the first player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new player)
// (i.e. the memory allocation for a new player failed).
int team_push_front(team_t* t, int roster, char* name){
   
    return 99999; // Note: This line is a 'filler' so the code compiles.
}

// push a new player to the end of the team DLL (after the last player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new player)
// (i.e. the memory allocation for a new player failed).
int team_push_back(team_t* t, int roster, char* name){
	// TODO: Implement me!!
	
	return 99999; // Note: This line is a 'filler' so the code compiles.
}

// Returns the first player in the DLL and also removes it from the team.
// Returns NULL if the Team is NULL. 
// Returns NULL on failure, i.e. there is no one to pop from the team.
// Assume roster numbers are always greater than zero
player_t* team_pop_front(team_t* t){
	// TODO: Implement me!!
	
	return NULL; // Note: This line is a 'filler' so the code compiles.
}

// Returns the last player in the Team, and also removes it from the list.
// Returns NULL if the Team is NULL. 
// Returns NULL on failure, i.e. there is no one to pop from the Team.
// Assume roster numbers are always greater than zero
player_t* team_pop_back(team_t* t){
	// TODO: Implement me!!
	
	return NULL; // Note: This line is a 'filler' so the code compiles.
}

// Inserts a new player before the player at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new player
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent of calling push_back).
int team_insert(team_t* t, int pos, int roster, char* name){
	// TODO: Implement me!!
	
	return 99999; // Note: This line is a 'filler' so the code compiles.
}

// Returns the roster number of the player at position pos starting at 0 
// ( 0 being the first item )
// Returns -1 if the list is NULL
//  (does not remove the item)
// Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume roster numbers are always greater than zero
int team_list_get(team_t* t, int pos){
	// TODO: Implement me!!
	
	return 99999; // Note: This line is a 'filler' so the code compiles.
}

// Removes the player at position pos starting at 0 ( 0 being the first item )
// Returns NULL if the list is NULL
// Returns NULL on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
// Otherwise returns the roster number of the player removed.
player_t* team_list_remove(team_t* t, int pos){
	// TODO: Implement me!!
	
	return NULL; // Note: This line is a 'filler' so the code compiles.
}

// Team Size
// Returns -1 if the Team is NULL.
// Queries the current size of a team
int team_size(team_t* t){
	// TODO: Implement me!!
	
	return 99999; // Note: This line is a 'filler' so the code compiles.
}

// BONUS function - not required for HW
// no extra credit is given for this function
// Team DLL Sort
// sorts the team by roster number, putting the players in order
// with the smallest roster number at the head of the list, 
// in ascending order
// only work on this if you're all done with everything else tested!!
void team_sort(team_t* t){

    // OPTIONAL

}

// Free Team DLL
// Removes a Team and all of its players (...and their names!!...) from memory.
// This should be called before the program terminates.
void free_team(team_t* t){
	// TODO: Implement me!!
	
}



#endif


Implementing a Doubly Linked List
Implement the functions provided to you in the my_dll.h file. Do not modify the signatures ( names and arguments ) of these functions, just provide the implementation (i.e. body of code). Complete the above code for me?


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mydll.h"

team_t* create_team(){
    team_t* myTeam = (team_t*)malloc(sizeof(team_t));
    if(myTeam){
        myTeam->head = NULL;
        myTeam->tail = NULL;
        myTeam->activePlayers = 0;
    }
    return myTeam;
}

int team_empty(team_t* t){
    if(!t) return -1;
    return (t->head == NULL) ? 1 : 0;
}

int team_push_front(team_t* t, int roster, char* name){
    if(!t) return -1;

    player_t* newPlayer = (player_t*)malloc(sizeof(player_t));
    if(!newPlayer) return 0;

    newPlayer->rosterNum = roster;
    newPlayer->name = strdup(name);
    if(!newPlayer->name) return 0;

    newPlayer->previous = NULL;
    newPlayer->next = t->head;
    if(t->head) t->head->previous = newPlayer;
    t->head = newPlayer;
    if(!t->tail) t->tail = newPlayer;
    t->activePlayers++;

    return 1;
}

int team_push_back(team_t* t, int roster, char* name){
    if(!t) return -1;

    player_t* newPlayer = (player_t*)malloc(sizeof(player_t));
    if(!newPlayer) return 0;

    newPlayer->rosterNum = roster;
    newPlayer->name = strdup(name);
    if(!newPlayer->name) return 0;

    newPlayer->next = NULL;
    newPlayer->previous = t->tail;
    if(t->tail) t->tail->next = newPlayer;
    t->tail = newPlayer;
    if(!t->head) t->head = newPlayer;
    t->activePlayers++;

    return 1;
}

player_t* team_pop_front(team_t* t){
    if(!t || !t->head) return NULL;

    player_t* player = t->head;
    t->head = player->next;
    if(t->head) t->head->previous = NULL;
    else t->tail = NULL;
    t->activePlayers--;

    return player;
}

player_t* team_pop_back(team_t* t){
    if(!t || !t->tail) return NULL;

    player_t* player = t->tail;
    t->tail = player->previous;
    if(t->tail) t->tail->next = NULL;
    else t->head = NULL;
    t->activePlayers--;

    return player;
}


/////////

 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mydll.h"

team_t* create_team(){
    team_t* myTeam = (team_t*) malloc(sizeof(team_t));
    if (myTeam == NULL) return NULL;
    myTeam->activePlayers = 0;
    myTeam->head = NULL;
    myTeam->tail = NULL;
    return myTeam;
}

int team_empty(team_t* t){
    if (t == NULL) return -1;
    return t->activePlayers == 0;
}

int team_push_front(team_t* t, int roster, char* name){
    if (t == NULL) return -1;
    player_t* newPlayer = (player_t*) malloc(sizeof(player_t));
    if (newPlayer == NULL) return 0;
    newPlayer->rosterNum = roster;
    newPlayer->name = (char*) malloc(strlen(name) + 1);
    if (newPlayer->name == NULL) {
        free(newPlayer);
        return 0;
    }
    strcpy(newPlayer->name, name);
    newPlayer->next = t->head;
    newPlayer->previous = NULL;
    if (t->head != NULL) t->head->previous = newPlayer;
    t->head = newPlayer;
    if (t->tail == NULL) t->tail = newPlayer;
    t->activePlayers++;
    return 1;
}

int team_push_back(team_t* t, int roster, char* name){
    if (t == NULL) return -1;
    player_t* newPlayer = (player_t*) malloc(sizeof(player_t));
    if (newPlayer == NULL) return 0;
    newPlayer->rosterNum = roster;
    newPlayer->name = (char*) malloc(strlen(name) + 1);
    if (newPlayer->name == NULL) {
        free(newPlayer);
        return 0;
    }
    strcpy(newPlayer->name, name);
    newPlayer->next = NULL;
    newPlayer->previous = t->tail;
    if (t->tail != NULL) t->tail->next = newPlayer;
    t->tail = newPlayer;
    if (t->head == NULL) t->head = newPlayer;
    t->activePlayers++;
    return 1;
}

player_t* team_pop_front(team_t* t){
    if (t == NULL || t->head == NULL) return NULL;
    player_t* player = t->head;
    t->head = t->head->next;
    if (t->head != NULL) t->head->previous = NULL;
    if (t->tail == player) t->tail = NULL;
    t->activePlayers--;
    player->next = NULL;
    player->previous = NULL;
    return player;
}

player_t* team_pop_back(team_t* t){
    if (t == NULL || t->tail == NULL) return NULL;
    player_t


返回这12个函数每一行所对应的注释，不要返回C语言代码，只返回英语注释，每一行都要


team_t* create_team()
Allocate memory for a new team_t structure.
If memory allocation is successful, initialize the team_t structure with NULL head and tail pointers and activePlayers count set to 0.
Return a pointer to the newly created team_t structure.
int team_empty(team_t* t)
Check if the input team_t pointer is NULL.
Return -1 if the input team_t pointer is NULL.
Return 1 if the head pointer of the team_t structure is NULL, indicating an empty team.
Return 0 if the head pointer of the team_t structure is not NULL, indicating a non-empty team.
int team_push_front(team_t* t, int roster, char* name)
Check if the input team_t pointer is NULL.
Return -1 if the input team_t pointer is NULL.
Allocate memory for a new player_t structure.
If memory allocation fails, return 0.
Allocate memory for a copy of the input name string.
If memory allocation fails, return 0.
Initialize the new player_t structure with the input roster number, name string, and pointers set as follows:
previous pointer set to NULL.
next pointer set to the current head pointer of the team_t structure.
Update the previous pointer of the current head player to the new player_t structure.
If the team_t structure is currently empty, set the head and tail pointers to the new player_t structure.
Increment the activePlayers count of the team_t structure.
Return 1 on success.
int team_push_back(team_t* t, int roster, char* name)
Check if the input team_t pointer is NULL.
Return -1 if the input team_t pointer is NULL.
Allocate memory for a new player_t structure.
If memory allocation fails, return 0.
Allocate memory for a copy of the input name string.
If memory allocation fails, return 0.
Initialize the new player_t structure with the input roster number, name string, and pointers set as follows:
next pointer set to NULL.
previous pointer set to the current tail pointer of the team_t structure.
Update the next pointer of the current tail player to the new player_t structure.
If the team_t structure is currently empty, set the head and tail pointers to the new player_t structure.
Increment the activePlayers count of the team_t structure.
Return 1 on success.
player_t* team_pop_front(team_t* t)
Check if the input team_t pointer is NULL or if the head pointer of the team_t structure is NULL.
Return NULL if the input team_t pointer is NULL or if the head pointer of the team_t structure is NULL.
Save a pointer to the current head player of the team_t structure.
Update the head pointer of the team_t structure to the next player.
If the next player exists, set its previous pointer to NULL.
If the next player does not exist, set the tail pointer of the team_t structure to NULL.
Decrement the activePlayers count of the team_t structure.
Return the saved pointer


newPlayer->name = strdup(name);

这一行有什么意义？还有别的写法吗？

newNode->name = name;

这样的写法对吗？如果错了错在哪里？
newPlayer->name = strdup(name); 用 strdup 函数复制字符串 name，并为复制的字符串分配新的存储空间，以避免多个指针指向同一块内存，导致错误。

写成 newPlayer->name = name; 可能不会分配新的内存空间，可能会导致多个指针指向同一块内存，导致错误。在多次更改名字时，可能会导致不可预知的行为。




jindacz .
给一个报错的例子
以下是一个报错的例子：

c
Copy code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* name = "John Doe";
    char* newName = name;
    strcpy(newName, "Jane Doe");
    printf("Name: %s\n", name);

    return 0;
}


这段代码里newPlayer->name = (char*) malloc(strlen(name) + 1); 加一什么意思，有什么作用

The + 1 in malloc(strlen(name) + 1) is for reserving an extra byte for the null terminator of the string. The null terminator is a character with the value of 0 that signals the end of a string in C. So, by allocating strlen(name) + 1 bytes, there will be enough space for the name string and the null terminator.




jindacz .
有没有用sizeof 函数的正确的写法？

是的，可以使用sizeof(char)替代strlen(name) + 1：

c
Copy code
newPlayer->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
这两种写法的效果是相同的，因为在 C 语言中，sizeof(char)总是返回1。




jindacz .
// push a new player to the front of the DLL ( before the first player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new player)
// (i.e. the memory allocation for a new player failed).
int team_push_front(team_t* t, int roster, char* name){

这个函数里有必要check name == NULL吗？

这个函数内并不需要检查name是否为NULL，因为在进行字符串拷贝时传入NULL将导致程序奔溃。如果name为NULL，那么strlen(name)将返回0，而malloc(0)将返回NULL，因此代码中的判断是充分的。






int team_insert(team_t* t, int pos, int roster, char* name){
	if (!t || pos < 0) return 0;
	if (pos >= t->activePlayers) return team_push_back(t, roster, name);
	player_t* current = t->head;
	for (int i = 0; i < pos; i++) current = current->next;

	player_t* newPlayer = (player_t*) malloc(sizeof(player_t));
	if (!newPlayer) return 0;
	newPlayer->roster = roster;
	newPlayer->name = name;
	
	newPlayer->previous = current->previous;
	newPlayer->next = current;
	current->previous = newPlayer;
	if (newPlayer->previous) newPlayer->previous->next = newPlayer;
	else t->head = newPlayer;
	t->activePlayers++;
	return 1;
}

int team_list_get(team_t* t, int pos){
	if (!t || pos < 0 || pos >= t->activePlayers) return 0;
	player_t* current = t->head;
	for (int i = 0; i < pos; i++) current = current->next;
	return current->roster;
}

player_t* team_list_remove(team_t* t, int pos){
	if (!t || pos < 0 || pos >= t->activePlayers) return NULL;
	player_t* current = t->head;
	for (int i = 0; i < pos; i++) current = current->next;
	if (current->previous) current->previous->next = current->next;
	else t->head = current->next;
	if (current->next) current->next->previous = current->previous;
	else t->tail = current->previous;
	int roster = current->roster;
	free(current->name);
	free(current);
	t->activePlayers--;
	return roster;
}

int team_size(team_t* t){
	if (!t) return -1;
	return t->activePlayers;
}

void free_team(team_t* t){
	if (!t) return;
	player_t* current = t->head;
	while (current){
		player_t* temp = current->next;
		free(current->name);
		free(current);
		current = temp;
	}
	free(t);
}

以上函数每一行代码所对应的中文注释，不要返回C语言代码，只返回英语注释，每一行都要，不同的函数分割开来标注清楚


///

player_t* team_list_remove(team_t* t, int pos){
	if (t == NULL) {
		return NULL;
	}
	if (pos < 0 || pos > t->activePlayers) {
		return NULL;
	}

	if (pos == 0){
		team_pop_front(t);
	}
	if (pos == t->activePlayers){
		team_pop_back(t);
	}

	player_t* cur = t->head;
	int i;
	for (i = 0; i < pos; i += 1){
		cur = cur->next;
	}

	if (cur->previous != NULL) {
		cur->previous->next = cur->next
	} 

	if (cur->next != NULL) {
		cur->next->previous = cur->previous
	}
	int ret = cur->rosterNum
	free(cur->name);
	free(cur)

	return cur->rosterNum; // Note: This line is a 'filler' so the code compiles.
}

我这样写是对的还是错的？如果错的话，返回你认为对的。
我有了
	if (pos == 0){
		team_pop_front(t);
	}
	if (pos == t->activePlayers){
		team_pop_back(t);
	}
还需要判断if (cur->previous != NULL) 吗？应该不需要了吧



team_insert():

Check if t is null or pos is negative
If pos is greater than or equal to active players, call team_push_back()
Allocate memory for new player and check if it's null
Set new player's roster and name
Link new player's previous to current's previous and new player's next to current
Link current's previous to new player
If new player's previous is not null, link its next to new player
Else set t's head to new player
Increment active players of t
Return 1
team_list_get():

Check if t is null, pos is negative or pos is greater than or equal to active players
If any of the conditions is true, return 0
Initialize current player to t's head
Traverse the linked list to find the player at pos
Return the roster of the player at pos
team_list_remove():

Check if t is null, pos is negative or pos is greater than or equal to active players
If any of the conditions is true, return null
Initialize current player to t's head
Traverse the linked list to find the player at pos
Link previous player's next to current's next and next player's previous to current's previous
If previous player is null, set t's head to current's next
If next player is null, set t's tail to current's previous
Store current player's roster
Free current player's name and player
Decrement active players of t
Return roster of the removed player
team_size():

Check if t is null
If t is null, return -1
Return active players of t
free_team():

Check if t is null
If t is null, return
Initialize current player to t's head
Traverse the linked list and free name and player of each player
Free t



///
========unitTest 4========
dll_test(90186,0x106485600) malloc: *** error for object 0x7fcfaf804160: pointer being freed was not allocated
dll_test(90186,0x106485600) malloc: *** set a breakpoint in malloc_error_break to debug
[1]    90186 abort      ./dll_test

请问错在哪里？





// BONUS function - not required for HW
// no extra credit is given for this function
// Team DLL Sort
// sorts the team by roster number, putting the players in order
// with the smallest roster number at the head of the list, 
// in ascending order
// only work on this if you're all done with everything else tested!!
void team_sort(team_t* t){

    

}

The function team_sort sorts the players in a team t based on their roster numbers. To implement this function, you can use a sorting algorithm such as selection sort or bubble sort. Here is an implementation of selection sort:

scss
Copy code
void team_sort(team_t* t) {
    player_t* curr = t->head;
    player_t* minNode;
    player_t* temp = (player_t*)malloc(sizeof(player_t));

    while (curr->next != NULL) {
        minNode = curr;
        for (player_t* i = curr->next; i != NULL; i = i->next) {
            if (i->rosterNum < minNode->rosterNum) {
                minNode = i;
            }
        }
        if (minNode != curr) {
            temp->rosterNum = curr->rosterNum;
            temp->name = curr->name;
            curr->rosterNum = minNode->rosterNum;
            curr->name = minNode->name;
            minNode->rosterNum = temp->rosterNum;
            minNode->name = temp->name;
        }
        curr = curr->next;
    }
    free(temp);
}



写一个辅助函数 player_t* find_position(team_t* t, int pos)

player_t* find_position(team_t* t, int pos) {
player_t* curr = t->head;
int i = 1;

perl
Copy code
while (curr != NULL && i < pos) {
    curr = curr->next;
    i++;
}

return curr;
}




jindacz .
用 for loop 谢谢

player_t* find_position(team_t* t, int pos) {
player_t* curr = t->head;
for (int i = 1; i < pos; i++) {
curr = curr->next;
}
return curr;
}




jindacz .
写一个辅助函数player_t* create_player

player_t* create_player(int rosterNum, char* name) {
player_t* newPlayer = (player_t*) malloc(sizeof(player_t));
newPlayer->rosterNum = rosterNum;
newPlayer->name = (char*) malloc(strlen(name) + 1);
strcpy(newPlayer->name, name);
newPlayer->next = NULL;
newPlayer->previous = NULL;
return newPlayer;
}




jindacz .
还有什么其他有意义的helper function？

其他有意义的辅助函数可以是：

void add_player(team_t* t, player_t* new_player)：用于将新球员添加到队伍中。
void remove_player(team_t* t, int roster_number)：用于删除队伍中的球员。
void print_team(team_t* t)：用于打印队伍中的所有球员的详细信息。
int search_player(team_t* t, int roster_number)：用于搜索队伍中的特定球员，如果找到则返回1，否则返回0。



jindacz .
实现void print_team(team_t* t)
int search_player(team_t* t, int roster_number)

// implementation of void print_team(team_t* t)
void print_team(team_t* t) {
player_t* curr = t->head;
while (curr != NULL) {
printf("Roster number: %d, Name: %s\n", curr->rosterNum, curr->name);
curr = curr->next;
}
}

// implementation of int search_player(team_t* t, int roster_number)
int search_player(team_t* t, int roster_number) {
player_t* curr = t->head;
int pos = 0;
while (curr != NULL) {
if (curr->rosterNum == roster_number) {
return pos;
}
pos++;
curr = curr->next;
}
return -1;
}




jindacz .
除了这些辅助函数，还有什么辅助函数，我只是为了练习，就算没意义也无所谓

其它辅助函数可以考虑：

remove_player: 删除球员节点，并修改 team_t 的 activePlayers 字段。
update_player: 修改球员节点的数据，如名字或更改球员编号。
insert_player: 在球队中插入一名新球员，并更新 team_t 的 activePlayers 字段。
reverse_team: 将整个球队翻转，以便从后向前遍历。
这些函数都可以通过操作链表的结点来实现。




jindacz .
update_player: 修改球员节点的数据，如名字或更改球员编号。
reverse_team: 将整个球队翻转，以便从后向前遍历。
帮我实现

void update_player(player_t* player, int roster_number, char* name){
player->rosterNum = roster_number;
player->name = name;
}

void reverse_team(team_t* t){
player_t* curr = t->head;
player_t* prev = NULL;
player_t* next;
while(curr != NULL){
next = curr->next;
curr->next = prev;
prev = curr;
curr = next;
}
t->head = prev;
}




jindacz .
还有什么有趣的操作辅助函数你能写出

delete_player: 删除某个球员节点。
get_player_at_index: 返回在队伍链表中第n个位置的球员节点。
team_copy: 将一个球队复制到另一个球队。
is_roster_number_unique: 检查给定的编号是否在球队中是唯一的。




jindacz .
team_copy: 将一个球队复制到另一个球队。
is_roster_number_unique: 检查给定的编号是否在球队中是唯一的。

实现这两个方法

Here is the implementation of the two functions:

// Copy an existing team to another team
void team_copy(team_t* source, team_t* dest) {
player_t* curr = source->head;
while (curr != NULL) {
add_player(dest, curr->rosterNum, curr->name);
curr = curr->next;
}
}

// Check if a given roster number is unique in the team
int is_roster_number_unique(team_t* t, int roster_number) {
player_t* curr = t->head;
while (curr != NULL) {
if (curr->rosterNum == roster_number) {
return 0;
}
curr = curr->next;
}
return 1;
}