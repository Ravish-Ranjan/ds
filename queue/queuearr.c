#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Queue{
    int arr[MAX];
    int front;
    int rear;
};

struct Queue* q;

void print(){
    printf("Queue : NULL");
    if (q->front != -1){
        for (int i = q->front;i<q->rear+1;i++){
            printf("<->%d",q->arr[i]);
        }
    }
    printf("<->NULL\n");
}

int size(){
    return q->rear + 1;
}

int front(){
    if (q->front != -1)
        return q->arr[q->front];
    return -1;
}

int rear(){
    if (q->rear != -1)
        return q->arr[q->rear];
    return -1;
}

void enqueue(int value){
    if (q->rear == MAX-1){
        printf("Overflow\n");
        return;
    }
    if(q->front == -1)
        q->front++;
    q->rear++;
    q->arr[q->rear] = value;
}

int dequeue(){
    if (q->front == -1){
        printf("Underflow\n");
        return -1;
    }
    int temp = front();
    for(int i=q->front+1;i<q->rear+1;i++){
        q->arr[i-1] = q->arr[i];
    }
    q->rear--;
    if (q->rear == -1)
        q->front = -1;
    return temp;
}

int main(){
    printf("----------Queue Arr (ravish)----------\n");
    q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
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
}