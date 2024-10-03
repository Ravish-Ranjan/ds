#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

void print(){
    struct Node* cur = head;
    printf("Null");
    while(cur != NULL){
        printf(" <-%d->",cur->value);
        cur = cur->next;
    }
    printf(" Null\n");
}

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertStart(int value){
    struct Node* newNode = createNode(value);
    newNode->next = head;
    if (newNode->next == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    head = newNode;
}

void insertEnd(int value){
    struct Node* newNode = createNode(value);
    if (head == NULL){
        head = newNode;
        return;
    }
    struct Node* cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->prev = cur;
}

void deleteStart(){
    if(head == NULL){
        printf("\nUnderflow");
        return;
    } 
    struct Node* next = head->next;
    head = head->next;
    if (next != NULL)
        next->prev = NULL;
}

void deleteEnd(){
    if (head == NULL){
        printf("\nUnderflow");
        return;
    }
    if (head->next == NULL){
        head = NULL;
        return;
    }
    struct Node* cur = head;
    while(cur->next != NULL)
        cur = cur->next;
    struct Node* prev = cur->prev;
    if (prev != NULL)
        prev->next = NULL;
}

int main(){
    printf("==========Doubly Linked List (Ravish)=========\n");
    head = createNode(10);
    print();
    insertStart(20);
    print();
    insertEnd(30);
    print();
    deleteStart();
    print();
    deleteEnd();
    print();
    return 0;
}