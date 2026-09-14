#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc(n + 1);
    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            // push opening bracket
            stack[++top] = c;
        } else {
            // closing bracket: check if stack is empty first
            if (top == -1) {
                free(stack);
                return false;
            }

            char t = stack[top];
            if ((c == ')' && t == '(') ||
                (c == '}' && t == '{') ||
                (c == ']' && t == '[')) {
                top--; // matched, pop
            } else {
                free(stack);
                return false;
            }
        }
    }

    bool result = (top == -1); // stack must be empty at the end
    free(stack);
    return result;
}

int main() {
    char s1[] = "()[]{}";
    char s2[] = "(]";
    char s3[] = "{[]}";

    printf("%s -> %s\n", s1, isValid(s1) ? "true" : "false");
    printf("%s -> %s\n", s2, isValid(s2) ? "true" : "false");
    printf("%s -> %s\n", s3, isValid(s3) ? "true" : "false");

    return 0;
}