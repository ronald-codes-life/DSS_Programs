#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for stack
struct Stack {
    int top;
    int* items;
};

// Create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->items = (int*)malloc(sizeof(int) * capacity);
    return stack;
}

// Check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an item onto the stack
void push(struct Stack* stack, int item) {
    stack->items[++stack->top] = item;
}

// Pop an item from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return -1; // Return -1 if the stack is empty
}

// Evaluate an arithmetic expression
int evaluateExpression(char* expression) {
    struct Stack* stack = createStack(strlen(expression));

    for (int i = 0; expression[i]; i++) {
        if (expression[i] == ' ')
            continue; // Skip spaces

        if (expression[i] >= '0' && expression[i] <= '9') {
            // Read and push operands onto the stack
            int operand = 0;
            while (expression[i] >= '0' && expression[i] <= '9') {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            push(stack, operand);
            i--;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // Pop the top two operands and apply the operator
            int operand1 = pop(stack);
            int operand2 = pop(stack);

            switch (expression[i]) {
                case '+':
                    push(stack, operand2 + operand1);
                    break;
                case '-':
                    push(stack, operand2 - operand1);
                    break;
                case '*':
                    push(stack, operand2 * operand1);
                    break;
                case '/':
                    if (operand1 != 0)
                        push(stack, operand2 / operand1);
                    else {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    break;
            }
        }
    }

    // The result should be at the top of the stack
    return pop(stack);
}

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove the newline character if present
    int len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}
