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

void enqueue(int value) {
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

int dequeue() {
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

int main() {
    printf("----------Queue Arr Ravish----------\n");
    q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;

    print();
    enqueue(10); enqueue(20); print();
    enqueue(30); enqueue(40); print();

    dequeue(); dequeue(); print();
    dequeue(); dequeue(); print();

    dequeue();
    enqueue(100); enqueue(200); print();

    printf("Front: %d\n", front());
    printf("Rear: %d\n", rear());
    printf("Size: %d\n", size());

    free(q);
    return 0;
}
