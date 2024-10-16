#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Queue {
    int arr[MAX];
    int front;
    int rear;
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
        printf("<->%d", q->arr[i]);
        i = (i + 1) % MAX;
    } while (i != (q->rear + 1) % MAX);
    printf("<->NULL\n");
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

void enqueFront(int value) {
    if (size() == MAX) {
        printf("Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
    } else if (q->front == 0) {
        q->front = MAX - 1;
    } else {
        q->front--;
    }
    q->arr[q->front] = value;
}

void enqueRear(int value) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
}

int dequeFront() {
    if (q->front == -1) {
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

int dequeRear() {
    if (size() == 0) {
        printf("Dequeue is empty!\n");
        return -1;
    }
    int res = rear();
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else if (q->rear == 0) {
        q->rear = MAX - 1;
    } else {
        q->rear--;
    }
    return res;
}

int main() {
    printf("----------DeQueue Ravish----------\n");
    q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;

    print();
    enqueRear(10); enqueRear(20); print();
    enqueFront(30); enqueFront(40); print();

    dequeFront(); dequeFront(); print();
    dequeRear(); dequeRear(); print();

    dequeFront();
    enqueRear(100); enqueRear(200); print();

    printf("Front: %d\n", front());
    printf("Rear: %d\n", rear());
    printf("Size: %d\n", size());

    free(q);
    return 0;
}
