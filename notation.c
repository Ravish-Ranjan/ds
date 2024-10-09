#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

struct Stack {
    char* arr[MAX];
    int top;
};

void push(char* value,struct Stack* stack) {
    if (stack->top == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = strdup(value);
}

char* peak(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Empty stack\n");
        return NULL;
    }
    return stack->arr[stack->top];
}

char* pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Underflow\n");
        return NULL;
    }
    char* topval = peak(stack);
    stack->top--;
    return topval;
}

int isop(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

void postToPre(char* str,int l,struct Stack* stack) {
    stack->top = -1;
    for (int i = 0; i < l; i++) {
        if (isalpha(str[i])) {
            char operand[2] = {str[i], '\0'};
            push(operand,stack);
        } else if (isop(str[i])) {
            char* op1 = pop(stack);
            char* op2 = pop(stack);
            
            if (op1 == NULL || op2 == NULL) {
                printf("Error: Not enough operands.\n");
                return;
            }
            char result[MAX];
            sprintf(result, "%c%s%s", str[i], op2, op1);
            push(result,stack);
        }
    }
}

void preToPost(char* str,int l,struct Stack* stack) {
    stack->top = -1;
    for (int i = l-1; i >= 0; i--) {
        if (isalpha(str[i])) {
            char operand[2] = {str[i], '\0'};
            push(operand,stack);
        } else if (isop(str[i])) {
            char* op1 = pop(stack);
            char* op2 = pop(stack);
            
            if (op1 == NULL || op2 == NULL) {
                printf("Error: Not enough operands.\n");
                return;
            }
            char result[MAX];
            sprintf(result, "%s%s%c", op1, op2, str[i]);
            push(result,stack);
        }
    }
}

void preToIn(char* str,int l,struct Stack* stack){
    stack->top = -1;
    for (int i = l-1; i >= 0; i--) {
        if (isalpha(str[i])){
            char operand[2] = {str[i], '\0'};
            push(operand,stack);
        } else if (isop(str[i])) {
            char* op1 = pop(stack);
            char* op2 = pop(stack);
            
            if (op1 == NULL || op2 == NULL) {
                printf("Error: Not enough operands.\n");
                return;
            }
            char result[MAX];
            sprintf(result, "(%s%c%s)", op1, str[i], op2);
            push(result,stack);
        }
    }
}

void postToIn(char* str,int l,struct Stack* stack){
    stack->top = -1;
    for (int i = 0;i < l;i++) {
        if (isalpha(str[i])){
            char operand[2] = {str[i], '\0'};
            push(operand,stack);
        } else if (isop(str[i])){
            char* op1 = pop(stack);
            char* op2 = pop(stack);
            
            if (op1 == NULL || op2 == NULL) {
                printf("Error: Not enough operands.\n");
                return;
            }
            char result[MAX];
            sprintf(result, "(%s%c%s)", op2, str[i], op1);
            push(result,stack);
        }
    }
}

void reverse(char* str, int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void inToPost(char* str,int l,struct Stack* stack,struct Stack* op){
    stack->top = -1;
    op->top = -1;

    for (int i = 0; i < l; i++) {
        if (isalpha(str[i])) {
            char operand[2] = {str[i], '\0'};
            push(operand, stack);
        } else if (str[i] == '(') {
            char operator[2] = {str[i], '\0'};
            push(operator, op);
        } else if (str[i] == ')') {
            while (op->top != -1 && *(op->arr[op->top]) != '(') {
                char* oper = pop(op);
                char* op1 = pop(stack);
                char* op2 = pop(stack);
                
                char result[MAX];
                sprintf(result, "%s%s%s", op2, op1, oper);
                push(result, stack);
            }
            pop(op);
        } else if (isop(str[i])) {
            while (op->top != -1 && prec(str[i]) <= prec(*(op->arr[op->top]))) {
                char* oper = pop(op);
                char* op1 = pop(stack);
                char* op2 = pop(stack);
                
                char result[MAX];
                sprintf(result, "%s%s%s", op2, op1, oper);
                push(result, stack);
            }
            char operator[2] = {str[i], '\0'};
            push(operator, op);
        }
    }

    while (op->top != -1) {
        char* oper = pop(op);
        char* op1 = pop(stack);
        char* op2 = pop(stack);
        
        char result[MAX];
        sprintf(result, "%s%s%s", op2, op1, oper);
        push(result, stack);
    }
}

void inToPre(char* str,int l,struct Stack* stack,struct Stack* op){
    stack->top = -1;
    op->top = -1;
    reverse(str,l);
    for (int i = 0; i < l; i++) {
        if (str[i] == ')'){
            str[i] = '(';
        } else if (str[i] == '('){
            str[i] = ')';
        }
    }
    inToPost(str,l,stack,op);
    char* res = peak(stack);
    reverse(res,strlen(res));
    push(res,stack);
    reverse(str,l);
    for (int i = 0; i < l; i++) {
        if (str[i] == ')'){
            str[i] = '(';
        } else if (str[i] == '('){
            str[i] = ')';
        }
    }
}

int main() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;

    struct Stack* opstack = (struct Stack*)malloc(sizeof(struct Stack));
    opstack->top = -1;
    printf("----------Notation ravish----------\n");
    printf("1. Infix\n2. Prefix\n3. Postfix\n");
    int from, to;
    printf("Enter the from and to of conversion\nFrom : ");
    scanf("%d", &from);
    printf("To : ");
    scanf("%d", &to);
    char* choice[3] = {"Infix","Prefix","Postfix"};

    char str[30];
    printf("Enter the expression : ");
    scanf("%s", str);
    str[strcspn(str, "\n")] = 0;
    int length = strlen(str);

    if (from < 1 || from > 3 || to < 0 || to > 3) {
        printf("\nWrong choice");
        return 0;
    }
    char* res;
    if (from == to){
        printf("\n%s : %s\n%s : %s",choice[from-1],str,choice[to-1],str);
    } else if (from == 1 && to == 2) {
        inToPre(str,length,stack,opstack);
        res = peak(stack);
        if (res != NULL){
            printf("\n%s : %s\n%s : %s",choice[from-1],str,choice[to-1],res);
        }
    } else if (from == 1 && to == 3) {
        inToPost(str,length,stack,opstack);
        res = peak(stack);
        if (res != NULL){
            printf("\n%s : %s\n%s : %s",choice[from-1],str,choice[to-1],res);
        }
    } else if (from == 2 && to == 1) {
        preToIn(str,length,stack);
        res = peak(stack);
        if (res != NULL){
            printf("\n%s : %s\n%s : %s",choice[from-1],str,choice[to-1],res);
        }
    } else if (from == 2 && to == 3) {
        preToPost(str,length,stack);
        res = peak(stack);
        if (res != NULL){
            printf("\n%s : %s\n%s : %s",choice[from-1],str,choice[to-1],res);
        }
    } else if (from == 3 && to == 1) {
        postToIn(str,length,stack);
        res = peak(stack);
        if (res != NULL){
            printf("\n%s : %s\n%s : %s",choice[from-1],str,choice[to-1],res);
        }
    } else if (from == 3 && to == 2) {
        postToPre(str,length,stack);
        res = peak(stack);
        if (res != NULL){
            printf("\n%s : %s\n%s : %s",choice[from-1],str,choice[to-1],res);
        }
    }
    free(stack);
    free(opstack);
    return 0;
}
