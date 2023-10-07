#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    int arr[] = {2, 5, 7, 12, 16, 23, 38, 45, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    int result = binarySearch(arr, n, target);

    if (result != -1)
        printf("\n%d found at index %d.\n", target, result);
    else
        printf("\n%d not found in the array.\n", target);

    return 0;
}
