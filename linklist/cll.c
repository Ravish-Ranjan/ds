#include <stdlib.h>
#include <stdio.h>

struct Node{
    int value;
    struct Node* next;
};

struct Node* cursor;

void print(){
    if (cursor == NULL){
        printf("NULL\n");
        return;
    }
    struct Node* cur = cursor;
    while(cur->next != cursor){
        printf("%d -> ",cur->value);
        cur = cur->next;
    }
    printf("%d -> ",cur->value);
    printf("LOOP\n");
}

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertCursor(int value){
    struct Node* newNode = createNode(value);
    if (cursor == NULL){
        newNode->next = newNode;
        cursor = newNode;
        return;
    }
    struct Node* cur = cursor;
    while(cur->next != cursor) cur = cur->next;
    newNode->next = cur->next;
    cur->next = newNode;
    cursor = newNode;
}

void insertEnd(int value){
    insertCursor(value);
    cursor = cursor->next;
}

int deleteEnd(){
    if (cursor == NULL){
        printf("Undeflow\n");
        return -1;
    }
    if (cursor->next == cursor){
        int ret = cursor->value;
        cursor = NULL;
        return ret;
    }
    struct Node* cur = cursor;
    while (cur->next->next != cursor) cur = cur->next;
    int ret = cur->next->value;
    cur->next = cur->next->next;
    return ret;
}

int deleteCursor(){
    if (cursor == NULL){
        printf("Undelflow\n");
        return -1;
    }
    cursor = cursor->next;
    return deleteEnd();
}

int search(int val){
    if (cursor == NULL){
        printf("not enough items\n");
        return -1;
    }
    struct Node* cur = cursor;
    while (cur->next != cursor){
        if (cur->value == val) return 1;
    }
    if (cur->value == val) return 1;
    return 0;
}

int main(){
    printf("----------Circular LL (DIVYASNSH)----------\n");
    cursor = NULL;
    print();
    insertCursor(10);insertCursor(20);print();
    insertEnd(30);insertEnd(40);print();
    deleteCursor();deleteCursor();print();
    deleteEnd();deleteEnd();print();
    insertCursor(10);
    if (search(20)){
        printf("20 found in linked list\n");
    } else {
        printf("20 not found in linked list\n");
    }
    return 0;
}