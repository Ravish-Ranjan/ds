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
    else if (cursor->next == cursor){
        printf("%d -> LOOP\n",cursor->value);
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
    while(cur->next != cursor)
        cur = cur->next;
    newNode->next = cur->next;
    cur->next = newNode;
    cursor = newNode;
}

void insertEnd(int value){
    struct Node* newNode = createNode(value);
    if (cursor == NULL){
        newNode->next = newNode;
        cursor = newNode;
        return;
    }
    struct Node* cur = cursor;
    while(cur->next != cursor)
        cur = cur->next;
    newNode->next = cur->next;
    cur->next = newNode;
}

int deleteCursor(){
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
    while (cur->next != cursor)
        cur = cur->next;
    int ret = cur->next->value;
    cur->next = cur->next->next;
    cursor = cur->next;
    return ret;
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
    while (cur->next->next != cursor)
        cur = cur->next;
    int ret = cur->next->value;
    cur->next = cur->next->next;
    return ret;
}

int main(){
    cursor = NULL;
    print();
    insertCursor(10);insertCursor(20);print();insertCursor(30);insertCursor(40);
    print();
    return 0;
}