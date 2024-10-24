#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct Queue {
    int arr[MAX];
    int front,rear;
};

struct Queue* q;

void print() {
    printf("Queue: ");
    if (q->front == -1) {
        printf("NULL\n");
        return;
    }
    int i = q->front;
    do {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    } while (i != (q->rear + 1) % MAX);
    printf("\n");
}

int size() {
    if (q->front == -1) return 0;
    return (q->rear - q->front + MAX) % MAX + 1;
}

int front() {
    if (q->front != -1) return q->arr[q->front];
    return -1;
}

int rear() {
    if (q->rear != -1) return q->arr[q->rear];
    return -1;
}

int isEmpty(){
    return size() == 0;
}

int isFull(){
    return size() == MAX;
}

void enque(int value) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
}

int deque() {
    if (isEmpty()) {
        printf("Underflow\n");
        return -1;
    }
    int temp = front();
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return temp;
}

int main() {
    printf("----------Queue Arr Ravish----------\n");
    q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;

    print();
    printf("\nenqueue 10,20\n");
    enque(10); enque(20); print();
    printf("\nenqueue 40,50\n");
    enque(30); enque(40); print();

    printf("\ndequeue twice\n");
    deque(); deque(); print();
    printf("\ndequeue twice\n");
    deque(); deque(); print();

    printf("\ndequeue\n");
    deque();
    printf("\nenqueue 100,200\n");
    enque(100); enque(200); print();

    printf("Front: %d\n", front());
    printf("Rear: %d\n", rear());
    printf("Size: %d\n", size());

    free(q);
    return 0;
}
