#include <Stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct Stack{
    struct Node* top;
};

struct Stack* stack;

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

void print(){
    struct Node* cur = stack->top;
    printf("\nStack : NULL");
    while (cur != NULL){
        printf("<-%d",cur->value);
        cur = cur->next;
    }
    printf("\n");
}

void push(int val){
    struct Node* newNode = createNode(val);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(){
    if (stack->top == NULL){
        printf("Underflow\n");
        return -1;
    }
    int temp = stack->top->value;
    stack->top = stack->top->next;
    return temp;
}

int isEmpty(){
    if (stack->top == NULL)
        return 1;
    return 0;
}

int peak(){
    if (stack->top == NULL){
        printf("Empty Stack\n");
        return -1;
    }
    return stack->top->value;
}

int size(){
    if (stack->top == NULL)
        return 0;
    int count = 0;
    struct Node* cur = stack->top;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }
    return count;
}

int main(){
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    print();
    push(10);push(20);push(30);push(40);
    print();
    pop();pop();pop();pop();
    print();
    pop();
    print();
    push(100);
    print();
    printf("Top element is : %d\n",peak());
    push(200);
    print();
    printf("Size of stack is : %d\n",size());

    return 0;
}