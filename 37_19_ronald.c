#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++s->top] = value;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char operator) {
    if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack operatorStack;
    initialize(&operatorStack);
    int infixLen = strlen(infix);
    int j = 0;

    for (int i = 0; i < infixLen; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (isOperator(ch)) {
            while (!isEmpty(&operatorStack) && precedence(operatorStack.stack[operatorStack.top]) >= precedence(ch)) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, ch);
        } else if (ch == '(') {
            push(&operatorStack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.stack[operatorStack.top] != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            pop(&operatorStack);  // Pop the '('
        }
    }

    while (!isEmpty(&operatorStack)) {
        postfix[j++] = pop(&operatorStack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}