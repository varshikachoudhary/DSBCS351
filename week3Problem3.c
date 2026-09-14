#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Result array, same size as nums1
    int* result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    // Map to store "next greater element" for each value in nums2.
    // Since constraints usually say values are up to 10^4 and unique,
    // we can use an array as a simple hashmap (value -> next greater).
    int* map = (int*)malloc(100001 * sizeof(int));
    for (int i = 0; i < 100001; i++) {
        map[i] = -1;
    }

    // Stack to hold indices/values from nums2 while finding next greater element
    int* stack = (int*)malloc(nums2Size * sizeof(int));
    int top = -1;

    // Traverse nums2, use monotonic decreasing stack
    for (int i = 0; i < nums2Size; i++) {
        while (top != -1 && stack[top] < nums2[i]) {
            map[stack[top]] = nums2[i]; // found next greater for stack[top]
            top--;
        }
        stack[++top] = nums2[i];
    }
    // Anything left in the stack has no next greater element (-1 by default)

    // Build result for nums1 using the map
    for (int i = 0; i < nums1Size; i++) {
        result[i] = map[nums1[i]];
    }

    free(map);
    free(stack);
    return result;
}

int main() {
    int nums1_1[] = {4, 1, 2};
    int nums2_1[] = {1, 3, 4, 2};
    int returnSize1;
    int* res1 = nextGreaterElement(nums1_1, 3, nums2_1, 4, &returnSize1);
    printf("Result 1: ");
    for (int i = 0; i < returnSize1; i++) printf("%d ", res1[i]);
    printf("\n"); // Expected: 3 3 4 -1... wait check below
    free(res1);

    int nums1_2[] = {2, 4};
    int nums2_2[] = {1, 2, 3, 4};
    int returnSize2;
    int* res2 = nextGreaterElement(nums1_2, 2, nums2_2, 4, &returnSize2);
    printf("Result 2: ");
    for (int i = 0; i < returnSize2; i++) printf("%d ", res2[i]);
    printf("\n"); // Expected: 3 -1
    free(res2);

    return 0;
}