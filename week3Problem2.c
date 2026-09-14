#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calPoints(char** operations, int operationsSize) {
    int* stack = (int*)malloc(operationsSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < operationsSize; i++) {
        char* op = operations[i];

        if (strcmp(op, "+") == 0) {
            // sum of last two scores
            int sum = stack[top] + stack[top - 1];
            stack[++top] = sum;
        } else if (strcmp(op, "D") == 0) {
            // double the last score
            int doubled = stack[top] * 2;
            stack[++top] = doubled;
        } else if (strcmp(op, "C") == 0) {
            // remove the last score
            top--;
        } else {
            // it's a number, push it
            stack[++top] = atoi(op);
        }
    }

    int total = 0;
    for (int i = 0; i <= top; i++) {
        total += stack[i];
    }

    free(stack);
    return total;
}

int main() {
    char* ops1[] = {"5", "2", "C", "D", "+"};
    printf("Result: %d\n", calPoints(ops1, 5)); // Expected: 30

    char* ops2[] = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    printf("Result: %d\n", calPoints(ops2, 8)); // Expected: 27

    char* ops3[] = {"1"};
    printf("Result: %d\n", calPoints(ops3, 1)); // Expected: 1

    return 0;
}