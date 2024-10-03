#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Stack{
    int arr[MAX];
    int top;
};

struct Stack* stack;

void print(){
    printf("Stack : NULL");
    for (int i = 0;i<=stack->top;i++){
        printf("<-%d",stack->arr[i]);
    }
    printf("\n");
}

int peak(){
    if (stack->top == -1){
        printf("Empty stack\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void push(int value){
    if (stack->top == MAX-1){
        printf("Overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}

int pop(){
    if (stack->top == -1){
        printf("Underflow\n");
        return -1;
    }
    int topval = peak();
    stack->top--;
    return topval;
}

int isEmpty(){
    if (stack->top == -1)
        return 1;
    return 0;
}

int size(){
    return stack->top + 1;
}

int main(){
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    print();
    push(10);push(20);print();push(30);push(40);
    print();
    pop();pop();print();pop();pop();
    print();
    pop();
    print();
    push(100);
    print();
    printf("Top element is : %d\n",peak());
    push(200);
    print();
    printf("Size of stack is : %d\n",size());
}