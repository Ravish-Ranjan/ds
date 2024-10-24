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
    printf("insert start 10\n");
    insertStart(10);print();
    printf("insert start 10\n");
    insertStart(10);print();
    printf("insert start 20\n");
    insertStart(20);print();
    printf("insert start 20\n");
    insertStart(20);print();
    printf("insert end 30\n");
    insertEnd(30);print();
    printf("insert end 30\n");
    insertEnd(30);print();
    printf("insert end 40\n");
    insertEnd(40);print();
    printf("insert end 40\n");
    insertEnd(40);print();
    printf("delete start\n");
    deleteStart();print();
    printf("delete start\n");
    deleteStart();print();
    printf("delete end\n");
    deleteEnd();print();
    printf("delete end\n");
    deleteEnd();print();
    printf("searching 30\n");
    if (search(30)){
        printf("30 found in linked list\n");
    } else {
        printf("30 not found in linked list\n");
    }
    return 0;
}