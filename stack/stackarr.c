#include <stdio.h>
#include <stdlib.h>

#define MAX 5

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

int size(){
    return stack->top + 1;
}

int peak(){
    if (size() == 0){
        printf("Empty stack\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void push(int value){
    if (size() == MAX){
        printf("Overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}

int pop(){
    if (size() == 0){
        printf("Underflow\n");
        return -1;
    }
    int topval = peak();
    stack->top--;
    return topval;
}

int isEmpty(){
    if (size() == 0) return 1;
    return 0;
}

int main(){
    printf("----------Stack Arr (ravish)----------\n");
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    print();
    printf("pushing 10,20\n");
    push(10);push(20);print();
    printf("\npushing 30,40\n");
    push(30);push(40);print();
    printf("\npopping twice\n");
    pop();pop();print();
    printf("\npopping twice\n");
    pop();pop();print();
    printf("\npopping\n");
    pop();
    printf("\npushing 10,20\n");
    push(10);push(20);
    printf("\npushing 30,40\n");
    push(30);push(40);
    printf("\npushing 50,60\n");
    push(50);push(60);
    printf("Top element is : %d\n",peak());
    print();
    printf("Size of stack is : %d\n",size());
}