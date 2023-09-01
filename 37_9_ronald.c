#include <stdio.h>
int main() {
    int size, i, j, count = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
        printf("Enter array elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
               }
        }
    }
    printf("Total duplicate elements: %d\n", count);
}