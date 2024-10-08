#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

struct Stack {
    char* arr[MAX];
    int top;
};

struct Stack* stack;

void push(char* value) {
    if (stack->top == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = strdup(value);
}

char* peak() {
    if (stack->top == -1) {
        printf("Empty stack\n");
        return NULL;
    }
    return stack->arr[stack->top];
}

char* pop() {
    if (stack->top == -1) {
        printf("Underflow\n");
        return NULL;
    }
    char* topval = peak();
    stack->top--;
    return topval;
}

int isop(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

void postToPre(char* str, int l) {
    stack->top = -1;
    for (int i = 0; i < l; i++) {
        if (isalpha(str[i])) {
            char operand[2] = {str[i], '\0'};
            push(operand);
        } else if (isop(str[i])) {
            char* op1 = pop();
            char* op2 = pop();
            
            if (op1 == NULL || op2 == NULL) {
                printf("Error: Not enough operands.\n");
                return;
            }
            char result[MAX];
            sprintf(result, "%c%s%s", str[i], op2, op1);
            push(result);
        }
    }
}

int main() {
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;

    printf("1. Infix\n2. Prefix\n3. Postfix\n");
    int from, to;
    printf("Enter the from and to of conversion\nFrom : ");
    scanf("%d", &from);
    printf("To : ");
    scanf("%d", &to);

    char str[30];
    printf("Enter the expression : ");
    scanf("%s", str);
    str[strcspn(str, "\n")] = 0;
    int length = strlen(str);

    postToPre(str, length);

    char* res = peak();
    if (res != NULL) {
        printf("%s\n", res);
    }
    return 0;
}
