#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;      // main stack values
    int* minData;   // parallel stack tracking min at each level
    int top;        // index of top element
    int capacity;   // allocated size
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 100;  // initial capacity, will grow if needed
    obj->data = (int*)malloc(obj->capacity * sizeof(int));
    obj->minData = (int*)malloc(obj->capacity * sizeof(int));
    obj->top = -1;
    return obj;
}

// helper to grow arrays if we run out of space
void minStackResizeIfNeeded(MinStack* obj) {
    if (obj->top + 1 >= obj->capacity) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, obj->capacity * sizeof(int));
        obj->minData = (int*)realloc(obj->minData, obj->capacity * sizeof(int));
    }
}

void minStackPush(MinStack* obj, int val) {
    minStackResizeIfNeeded(obj);
    obj->top++;
    obj->data[obj->top] = val;

    if (obj->top == 0) {
        obj->minData[obj->top] = val; // first element, it's the min
    } else {
        int prevMin = obj->minData[obj->top - 1];
        obj->minData[obj->top] = (val < prevMin) ? val : prevMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minData[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->minData);
    free(obj);
}

int main() {
    MinStack* obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    printf("Min: %d\n", minStackGetMin(obj)); // Expected: -3
    minStackPop(obj);
    printf("Top: %d\n", minStackTop(obj));    // Expected: 0
    printf("Min: %d\n", minStackGetMin(obj)); // Expected: -2

    minStackFree(obj);
    return 0;
}