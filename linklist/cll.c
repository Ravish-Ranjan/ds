#include <stdlib.h>
#include <stdio.h>

struct Node{
    int value;
    struct Node* next;
};

struct Node* cursor;

void print(){
    if (cursor == NULL){
        printf("NULL");
        return;
    }
    else if (cursor->next == cursor){
        printf("%d -> ",cursor->value);
        return;
    }
    struct Node* cur = cursor;
    while(cur->next != cursor){
        printf("%d -> ",cur->value);
        cur = cur->next;
    }
    printf("LOOP\n");
}

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertStart(int value){
    struct Node* newNode = createNode(value);
    if (cursor == NULL){
        newNode->next = newNode;
        cursor = newNode;
    }
    struct Node* cur = cursor;
    while(cur->next != cursor)
        cur = cur->next;
    cur->next = newNode;
    newNode->next = cursor;
    cursor = newNode;
}

int main(){
    cursor = createNode(10);
    insertStart(20);
    print();
}