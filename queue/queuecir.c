#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

struct Queue* q;

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(){
    if (q->front == NULL) return 1;
    return 0;
};

void print(){
    printf("Queue : ");
    struct Node* cur = q->front;
    if (cur == NULL){
        printf("<->NULL\n");
        return;
    }
    while(cur->next != q->front){
        printf("<->%d",cur->value);
        cur = cur->next;
    }
    printf("<->%d<->LOOP\n",cur->value);
}

void enque(int value){
    struct Node* newNode = createNode(value);
    if (isEmpty()){
        q->front = newNode;
        q->front->next = q->front;
        q->rear = q->front;
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int deque(){
    if (isEmpty()){
        printf("Underflow\n");
        return -1;
    }
    int temp = q->front->value;
    if (q->front == q->rear){
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->rear->next = q->rear->next->next;
        q->front = q->rear->next->next;
    }
    return temp;
};

int front(){
    if (isEmpty()){
        printf("Empty queue\n");
        return -1;
    }
    return q->front->value;
};

int rear(){
    if (isEmpty()){
        printf("Empty queue\n");
        return -1;
    }
    return q->rear->value;
};

int size(){
    if (q->front == NULL)
        return 0;
    struct Node* cur = q->front;
    int count = 1;
    while(cur->next != q->front){
        count++;
        cur = cur->next;
    }
    return count;
};

int main(){
    printf("----------Queue Cir LL (ravish)----------\n");
    q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    print();
    printf("\nenqueue 10,20\n");
    enque(10);enque(20);print();
    printf("\nenqueue 30,40\n");
    enque(30);enque(40);print();
    printf("\ndequeue twice\n");
    deque();deque();print();
    printf("\ndequeue twice\n");
    deque();deque();print();
    printf("\ndequeue\n");
    deque();
    printf("\nenqueue 100,200\n");
    enque(100);enque(200);print();
    printf("Front : %d\n",front());
    printf("Rear : %d\n",rear());
    printf("Size : %d\n",size());
    return 0;
};