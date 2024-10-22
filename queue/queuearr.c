#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Queue* q;

int size(){
    if (q->front == -1) return 0;
    return q->rear - q->front + 1;
}

int isFull() {
    return size() == MAX;
}

int isEmpty() {
    return size() == 0;
}

int front(){
    if (q->front == -1) return -1;
    return q->items[q->front];
}

int rear(){
    if (q->front == -1) return -1;
    return q->items[q->rear];
}

void enque(int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int deque() {
    int value;
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        for (int i = 0; i < q->rear; i++){
            q->items[i] = q->items[i+1];
        }
        q->rear--;
    }
}

void print() {
    printf("Queue : ");
    if (q->front != -1){
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    }
    printf("\n");
}

int main() {
    printf("----------Queue Arr Ravish----------\n");
    q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    print();enque(10);enque(20);enque(30);enque(40);enque(50);
    print();enque(60);
    deque();print();deque();print();deque();print();
    enque(60);enque(70);
    print();
    
    return 0;
}
