#include <stdio.h>

int main() {
    int n;

    // Input size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate running sum
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i] + arr[i - 1];
    }

    // Print running sum
    printf("Running sum: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
