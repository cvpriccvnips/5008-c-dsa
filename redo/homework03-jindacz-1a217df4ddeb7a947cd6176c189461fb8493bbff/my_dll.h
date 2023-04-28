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
	int activePlayers;  // count keeps track of how many active players are on the Team.
	player_t* head;		// head points to the first player node in our DLL.
    player_t* tail;     //tail points to the last player node in our DLL.
} team_t;

// Creates a Team 
// Returns a pointer to a newly created Team.
// The Team should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The Team fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
team_t* create_team(){
	// Modify the body of this function as needed.
	team_t* myTeam = (team_t*)malloc(sizeof(team_t));
	if (myTeam == NULL){
		return NULL;
	}
	myTeam->activePlayers = 0;
	myTeam->head = NULL;
	myTeam->tail = NULL;
	return myTeam; // Note: This line is a 'filler' so the code compiles.
}

// helper function to find position
player_t* find_position(team_t* t, int pos){
	player_t* cur = t->head;
	
	for (int i=0; i<pos; i++) {
		cur = cur->next;
	}
	return cur;
}

// helper to create player
player_t* create_player(int roster, char* name) {
    player_t* newNode = (player_t*)malloc(sizeof(player_t));
	if (newNode == NULL) {
		return 0;
	}
	newNode->rosterNum = roster;
	newNode->name = (char*)malloc(strlen(name) + 1);
	if (newNode->name == NULL){
		free(newNode);
		return 0;
	}
	strcpy(newNode->name, name);
	return newNode;
}

// push a new player to the front of the DLL ( before the first player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new player)
// (i.e. the memory allocation for a new player failed).
int team_push_front(team_t* t, int roster, char* name){
	if (t == NULL || name == NULL){
		return -1;
	}
	player_t* newNode = create_player(roster, name);

	newNode->next = t->head;
	newNode->previous = NULL;
	if (t->head != NULL) {
		t->head->previous = newNode;
	} 
	t->head = newNode;
	
	if (t->tail == NULL){
		t->tail = newNode;
	}
	t->activePlayers += 1;

    return 1; // Note: This line is a 'filler' so the code compiles.
}

// push a new player to the end of the team DLL (after the last player in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new player)
// (i.e. the memory allocation for a new player failed).
int team_push_back(team_t* t, int roster, char* name){
	if (t == NULL || name == NULL) {
		return -1;
	}
	player_t* newNode = create_player(roster, name);

	newNode->next = NULL;
	newNode->previous = t->tail;
	if (t->tail != NULL) {
		t->tail->next = newNode;
	} 
	t->tail = newNode;

	if (t->head == NULL) {
		t->head = newNode;
	}
	t->activePlayers += 1;

	return 1; // Note: This line is a 'filler' so the code compiles.
}

// Returns the first player in the DLL and also removes it from the team.
// Returns NULL if the Team is NULL. 
// Returns NULL on failure, i.e. there is no one to pop from the team.
// Assume roster numbers are always greater than zero
player_t* team_pop_front(team_t* t){
	if (t == NULL || t->activePlayers == 0) {
		return NULL;
	}
	player_t* front = t->head;
	t->head = front->next;

	if (t->head != NULL) {
		t->head->previous = NULL;
	} else {
		t->tail = NULL;
	}
	t->activePlayers -= 1;
	// when you pop, consider resetting the pointers in the returned node to NULL before you return it, so that you're not giving away pointers to inside your list
	front->next = NULL;
	front->previous = NULL;

	return front; // Note: This line is a 'filler' so the code compiles.
}

// Returns the last player in the Team, and also removes it from the list.
// Returns NULL if the Team is NULL. 
// Returns NULL on failure, i.e. there is no one to pop from the Team.
// Assume roster numbers are always greater than zero
player_t* team_pop_back(team_t* t){
	if (t == NULL || t->activePlayers == 0){
		return NULL;
	}
	player_t* back = t->tail;
	t->tail = back->previous;

	if (t->tail != NULL) {
		t->tail->next = NULL;
	} else {
		t->head = NULL;
	}
	t->activePlayers -= 1;
	
	return back; // Note: This line is a 'filler' so the code compiles.
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
	if (t == NULL) {
		return -1;
	}
	if (pos < 0 || pos > t->activePlayers || name == NULL) {
		return 0;
	}

	if (pos == 0) {
		team_push_front(t, roster, name);
	}

	if (pos == t->activePlayers) {
		team_push_back(t, roster, name);
		return 1;
	}

	player_t* newNode = (player_t*)malloc(sizeof(player_t));
	if (newNode == NULL) {
		return 0;
	}
	newNode->rosterNum = roster;
	newNode->name = (char*)malloc(strlen(name) + 1);
	if (newNode->name == NULL){
		free(newNode);
		return 0;
	}
	strcpy(newNode->name, name);

	player_t* cur = find_position(t, pos);

	newNode->next = cur;
	newNode->previous = cur->previous;
	cur->previous = newNode;
	if (newNode->previous != NULL){
		newNode->previous->next = newNode;
	} else {
		t->head = newNode;
	}
	t->activePlayers += 1;
	return 1;
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
	if (t == NULL) {
		return -1;
	}
	if (pos < 0 || pos >= t->activePlayers) {
		return 0;
	}
	player_t* cur = t->head;
	int i;
	for (i = 0; i < pos; i += 1){
		cur = cur->next;
	}
	
	return cur->rosterNum; // Note: This line is a 'filler' so the code compiles.
}

// Removes the player at position pos starting at 0 ( 0 being the first item )
// Returns NULL if the list is NULL
// Returns NULL on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
// Otherwise returns the roster number of the player removed.
player_t* team_list_remove(team_t* t, int pos){
	if (t == NULL) {
		return NULL;
	}
	// if pos = t->activePlayers is invalid, since pos start from 0
	if (pos < 0 || pos >= t->activePlayers) {
		return NULL;
	}

	player_t* cur = find_position(t, pos);

	if (cur->previous != NULL) {
		cur->previous->next = cur->next;
	} else {
		t->head = cur->next;
	}

	if (cur->next != NULL) {
		cur->next->previous = cur->previous;
	} else {
		t->tail = cur->previous;
	}
	
	t->activePlayers -= 1;
	return cur; // Note: This line is a 'filler' so the code compiles.
}

// Team Size
// Returns -1 if the Team is NULL.
// Queries the current size of a team
int team_size(team_t* t){
	if (t == NULL){
		return -1;
	}
	
	return t->activePlayers; // Note: This line is a 'filler' so the code compiles.
}

// BONUS function - not required for HW
// no extra credit is given for this function
// Team DLL Sort
// sorts the team by roster number, putting the players in order
// with the smallest roster number at the head of the list, 
// in ascending order
// only work on this if you're all done with everything else tested!!
void team_sort(team_t* t){
	player_t* curr = t->head;
	player_t* minNode;
	player_t* temp = (player_t*)malloc(sizeof(player_t));

	while (curr->next != NULL) {
		minNode = curr;
		for (player_t* i = curr->next; i != NULL; i=i->next) {
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
		free(temp);
	}
}

// Free Team DLL
// Removes a Team and all of its players (...and their names!!...) from memory.
// This should be called before the program terminates.
void free_team(team_t* t){
	if (t == NULL) {
		return;
	}
	player_t* cur = t->head;
	while (cur != NULL){
		player_t* nxt = cur->next;
		if (cur->name != NULL){
			free(cur->name);
		}
		free(cur);
		cur = nxt;
	}
	free(t);
}

// Team DLL Empty
// Check if the team is empty
// Returns -1 if the team is NULL.
// Returns 1 if true (The team is completely empty)
// Returns 0 if false (the team DLL has at least one player enqueued)
int team_empty(team_t* t){
	if (t == NULL) {
		return -1;
	}
	if (t->activePlayers == 0){
		return 1;
	} else {
		return 0;
	}
}


// helper to print team
void print_team(team_t* t) {
	player_t* cur = t->head;
	while (cur != NULL){
		printf("Roster number: %d, Name: %s\n", cur->rosterNum, cur->name);
		cur = cur->next;
	}
}

// helper to search player
int search_player(team_t* t, int roster_number) {
	player_t* cur = t->head;
	int pos = 0;
	while (cur != NULL) {
		if (cur->rosterNum == roster_number) {
			return pos;
		}
		pos += 1;
		cur = cur->next;
	}
	return -1;
}

void update_player(player_t* player, int rosterNum, char* name) {
	player->rosterNum = rosterNum;
	player->name = name;
}

void reverse_team(team_t* t) {
	player_t* cur = t->head;
	player_t* pre = NULL;
	player_t* nxt;

	while (cur != NULL) {
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}
	t->head = pre;
}

void team_copy(team_t* source, team_t* dest) {
	player_t* cur = source->head;
	while (cur != NULL) {
		team_push_back(dest, cur->rosterNum, cur->name);
		cur = cur->next;
	}
}

// Check if a given roster number is unique in the team
int is_roster_unique(team_t* t, int roster_number) {
	player_t* cur = t->head;
	while (cur != NULL) {
		if (cur->rosterNum == roster_number) {
			return 0;
		}
		cur = cur->next;
	}
	return 1;
}

#endif
