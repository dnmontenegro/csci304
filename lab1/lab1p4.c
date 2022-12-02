/*
This program includes an implementation of a linked list. It takes in input from the console and reads it as strings. Uppercase words get inserted at the beginning of the linked list and lowercase words at the end.
If a word already exists in the linked list then the word in the list is deleted and no word is inserted. After all input is read then the elements of the linked list are printed out. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Node for the linked list. data stores a string, next points to the next node in the linked list.
struct Node
{
    char *data;
    struct Node *next;
};
// struct that contains head pointer. head points to first node of linked list.
struct Linkedlist
{
    struct Node *head;
};
//inserts a node at the beginning of the linked list
void insertAtBeginning(struct Linkedlist* LL, char ele[]) 
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node)); // make new node pointer
    int len = strlen(ele);
    char *newData = (char*) malloc(sizeof(char) * (len + 1)); // make new node pointer
    strcpy(newData, ele);
    // assign values to node
    new->data = newData;
    new->next = LL->head;
    LL->head = new;
}
//inserts a node at the end of the linked list
void insertAtTheEnd(struct Linkedlist* LL, char ele[])
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node)); // make new node pointer
    int len = strlen(ele);
    char *newData = (char*) malloc(sizeof(char) * (len + 1)); // make new node pointer
    strcpy(newData, ele);
    // assign values to node
    new->data = newData;
    //if list is empty, point head to new node
    if(LL->head == NULL) {    
        LL->head = new;
    }
    // iterate through list. Once last node is reached, add new node to end and update next pointer
    else {
        struct Node *p = LL->head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = new;
    }
}
//removes a node from the linked list
void deleteNode(struct Linkedlist* LL, char ele[]) {
    //if list is empty, return
    if(LL->head == NULL) {
        return;
    }
    struct Node *p = LL->head;
    //check if first node is desired node, if it is then free the memory
    if(strcmp(p->data, ele) == 0) {    
        LL->head = p->next; //update head pointer
        free(p->data);
        free(p);
        return;
    }
    //iterate through list, comparing each node's string with desired string. If found, free that node's memory
    while(p->next != NULL) {
        if(strcmp(p->next->data, ele) == 0) {
            struct Node *temp = p->next;
            p->next = p->next->next; //update next pointer
            free(temp->data);
            free(temp);
            return;
        }
        p = p->next;
    }
    return;
}
//checks if a node exists in the linked list
int findNode(struct Linkedlist LL, char ele[]) 
{
    //if list empty, return
    if(LL.head == NULL) {
        return 0;
    }
    struct Node *p = LL.head;
    //iterate through list, if node's string matches desired string then return 1
    while(p != NULL) {
        if(strcmp(p->data, ele) == 0) {
            return 1;
        }
        p = p->next;
    }
    return 0; //no match so return 0
}
//prints the data in the linked list
void displayLinkedList(struct Linkedlist LL)
{
    printf("The list:- "); 
    struct Node *p = LL.head;
    //iterate through list, printing each node's data value
    while(p->next != NULL) {
        printf("%s, ", p->data);
        p = p->next;
    }
    printf("%s\n", p->data); //print last value and add new line
}
int main(int argc, char* argv[])
{
    struct Linkedlist list;
    list.head = NULL;
    struct Linkedlist *p_list = &list; //make pointer to list to pass into functions
    //loop througg all elements of the input
    if(argc == 1){
        printf("ERROR: The program must read at least an argument. \n");
        return (EXIT_SUCCESS);
    }
    for(int i=1; i<argc; i++) {
        //check if element already exists in list, if so delete the node that contains the element
        if(findNode(list, argv[i]) == 1) {
            deleteNode(p_list, argv[i]);
            continue;
        }
        //otherwise add element to list according to first letter being uppercase or lowercase
        char *check = argv[i];
        if(check[0] >= 'A' && check[0] <= 'Z') {
            insertAtBeginning(p_list, argv[i]);
        }
        else {
            insertAtTheEnd(p_list, argv[i]);
        }
    }
    displayLinkedList(list);
    return (EXIT_SUCCESS);
}
