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

void print(){
    printf("Queue : NULL");
    struct Node* cur = q->front;
    while(cur != NULL){
        printf("<->%d",cur->value);
        cur = cur->next;
    }
    printf("<->NULL\n");
}

void enqueue(int value){
    struct Node* newNode = createNode(value);
    if (q->front == NULL){
        q->front = newNode;
        q->rear = q->front;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(){
    if (q->front == NULL){
        printf("Underflow\n");
        return -1;
    }
    int temp = q->front->value;
    q->front = q->front->next;
    return temp;
};

int front(){
    if (q->front == NULL){
        printf("Empty queue\n");
        return -1;
    }
    return q->front->value;
};

int rear(){
    if (q->rear == NULL){
        printf("Empty queue\n");
        return -1;
    }
    return q->rear->value;
};

int isEmpty(){
    if (q->front == NULL)
        return 1;
    return 0;
};

int size(){
    if (q->front == NULL)
        return 0;
    struct Node* cur = q->front;
    int count = 0;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }
    return count;
};

int main(){
    q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    print();
    enqueue(10);enqueue(20);print();enqueue(30);enqueue(40);
    print();
    dequeue();dequeue();print();dequeue();dequeue();
    print();
    dequeue();
    enqueue(100);enqueue(200);
    print();
    printf("Front : %d\n",front());
    printf("Rear : %d\n",rear());
    printf("Size : %d\n",size());
    return 0;
};