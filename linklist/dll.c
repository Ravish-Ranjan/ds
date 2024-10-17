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
    if (head != NULL){
        newNode->next = head;
        head->prev = newNode;
    }
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
    head = next;
    if (head != NULL) head->prev = NULL;
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
    while(cur->next->next != NULL) cur = cur->next;
    cur->next = NULL;
}

int search(int value){
    if (head == NULL) {
        printf("Not enough items\n");
        return 0;
    }
    struct Node* cur = head;
    while (cur != NULL){
        if (cur->value == value) return 1;
        cur = cur->next;
    }
    return 0;
}

int main(){
    printf("==========Doubly Linked List (Ravish)=========\n");
    head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;
    insertStart(10);insertStart(20);
    print();
    insertEnd(30);insertEnd(40);
    print();
    deleteStart();print();
    deleteEnd();print();
    if (search(30)){
        printf("30 found in linked list\n");
    } else {
        printf("30 not found in linked list\n");
    }
    return 0;
}