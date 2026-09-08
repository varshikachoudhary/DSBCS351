#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int k = 0;

    // Move all non-zero elements to the front
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[k] = nums[i];
            k++;
        }
    }

    // Fill the remaining positions with zero
    while (k < numsSize) {
        nums[k] = 0;
        k++;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, numsSize);

    printf("Output: ");

    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
