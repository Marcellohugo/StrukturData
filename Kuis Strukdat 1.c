#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top == MAX-1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    int i, j;
    char c, temp;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (is_operator(c)) {
            while (top != -1 && is_operator(stack[top]) && precedence(stack[top]) >= precedence(c)) {
                temp = pop();
                postfix[j++] = temp;
            }
            push(c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                temp = pop();
                postfix[j++] = temp;
            }
            if (top == -1) {
                printf("Invalid infix expression\n");
                exit(1);
            }
            pop();
        }
    }
    while (top != -1 && is_operator(stack[top])) {
        temp = pop();
        postfix[j++] = temp;
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix_to_postfix(infix, postfix);
    printf("The corresponding postfix expression is: %s\n", postfix);
    return 0;
}