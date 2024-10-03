#include <stdlib.h>
#include <stdio.h>

// * structure for a node
struct Node{
    int value;
    struct Node* next;
};

struct Node* head;

// * function to print linked list
void print(){
    struct Node* cur = head;
    while(cur != NULL){
        printf("%d -> ",cur->value);
        cur = cur->next;
    }
    printf("Null\n");
}

// * function to create new node and return it
struct Node* createNode(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// * function to insert new node at end 
void insertEnd(int value){
    struct Node* newNode = createNode(value);
    struct Node* cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = newNode;
}

// * function to insert new node in start
void insertStart(int value){
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// * function to insert new node at given position 
// void insertAt(struct Node* head,int value,int at){

// };

// * function to insert new node after given value
// void insertAfter(struct Node* head,int value,int after){

// };

// * function to search a node by value
// int search(struct Node* head,int value){

// };

// * function to update a node's value
// void update(struct Node* head,int old_value,int new_value){
    
// };

// * function to delete a node by given value
// void deleteEnd;

// * function to delete the head node
void deleteStart(){
    if (head != NULL){
        head = head->next;
    } else {
        printf("\nUnderflow : no element to delete");
    }
};

// * function to delete node at given position
// void deleteAt;

// * function to delete node after given value
// void deleteAfter;


int main(){
    printf("==========Linked List (Ravish)==========\n");
    head = createNode(10);
    print();
    insertEnd(20);
    print();
    insertStart(0);
    print();
    deleteStart();
    print();
    return 0;
}