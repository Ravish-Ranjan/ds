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

int peak(){
    if (stack->top == NULL){
        printf("Empty Stack\n");
        return -1;
    }
    return stack->top->value;
}

int pop(){
    if (stack->top == NULL){
        printf("Underflow\n");
        return -1;
    }
    int temp = peak();
    stack->top = stack->top->next;
    return temp;
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
    printf("----------Stack LL (ravish)----------\n");
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    print();
    printf("\npushing 10,20");
    push(10);push(20);print();
    printf("pushing 30,40");
    push(30);push(40);print();
    printf("popping twice");
    pop();pop();print();
    printf("popping twice");
    pop();pop();print();
    printf("popping");
    pop();print();
    printf("popping");
    push(100);
    print();
    printf("Top element is : %d\n",peak());
    push(200);
    print();
    printf("Size of stack is : %d\n",size());

    return 0;
}