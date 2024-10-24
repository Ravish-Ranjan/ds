#include <stdlib.h>
#include <stdio.h>

struct Node{
    int value; struct Node* next;
};

struct Node* head;

void print(){
    struct Node* cur = head;
    while(cur != NULL){
        printf("%d -> ",cur->value);
        cur = cur->next;
    }
    printf("Null\n");
}

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(int value){
    struct Node* newNode = createNode(value);
    struct Node* cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = newNode;
}

void insertStart(int value){
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAt(int value,int at){
    struct Node* newNode = createNode(value);
    struct Node* cur = head;
    if (at == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    for (int i = 1; i < at-1; i++){
        if (cur == NULL){
            printf("Not enough item");
            return;
        }
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}

void insertAfter(int value,int after){
    struct Node* newNode = createNode(value);
    struct Node* cur = head;
    if (cur == NULL) {
        printf("Not engough items\n");
        return;
    }
    while (cur->value != after){
        if (cur->next == NULL){
            printf("No such element found\n");
            return;
        }
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
};

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
};

void update(int old_value,int new_value){
      if (head == NULL) {
        printf("Not enough items\n");
        return;
    }
    struct Node* cur = head;
    while (cur != NULL){
        if (cur->value == old_value) {
            cur->value = new_value;
            return;
        }
        cur = cur->next;
    }
    printf("item not found\n");
    return;  
};

void deleteEnd(){
    if (head == NULL){
        printf("Undeflow\n");
    } else if (head->next == NULL){
        head = NULL;
    } else {
        struct Node* cur = head;
        while(cur->next->next != NULL) cur = cur->next;
        cur->next = NULL;
    }
};

void deleteStart(){
    if (head != NULL){
        head = head->next;
    } else {
        printf("\nUnderflow");
    }
};

void deleteAt(int at){
    if (head == NULL){
        printf("not enough items\n");
        return;
    } else if (at == 1){
        head = head->next;
        return;
    }
    struct Node* cur = head;
    for (int i = 1; i < at-1; i++){
        if (cur->next == NULL){
            printf("Not enough items\n");
            return;
        }
        cur = cur->next;
    }
    if (cur->next == NULL){
        printf("Not enough items\n");
        return;
    }
    cur->next= cur->next->next;
}

void deleteAfter(int val){
    if (head == NULL){
        printf("not enough items\n");
        return;
    }
    struct Node* cur = head;
    while (cur->value != val){
        if (cur->next == NULL){
            printf("no such items found\n");
            return;
        }
        cur = cur->next;
    }
    if (cur->next == NULL){
        printf("not enough items\n");
        return;
    }
    cur->next = cur->next->next;
}


int main(){
    printf("==========Linked List (Ravish)==========\n");
    head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;
    printf("Insert start 10,20\n");
    insertStart(10);print();insertStart(20);print();
    printf("\nInsert end 30,40\n");
    insertEnd(30);print();insertEnd(40);print();
    printf("\nInsert insert at 3nd 50,60\n");
    insertAt(50,2);print();insertAt(60,2);print();
    printf("\nInsert after 40 70,80\n");
    insertAfter(70,40);print();insertAfter(80,40);print();
    printf("\ndelete start\n");
    deleteStart();print();
    printf("\ndelete end\n");
    deleteEnd();print();
    printf("\ndelete at 2\n");
    deleteAt(2);print();
    printf("\ndelete after 10\n");
    deleteAfter(10);print();
    printf("\nupdate 10 to 30\n");
    
    update(10,30);
    
    if (search(10)){
        printf("10 found in list\n");
    } else {
        printf("10 not found in list\n");
    }
    return 0;
}