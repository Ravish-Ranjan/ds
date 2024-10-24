#include <stdio.h>

void deleteElement(int arr[], int *n, int index) {
    if (index < 0 || index >= *n) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[100], n, index;
    printf("----------Deletion Array Ravish\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter arr[%d] : ",i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the index of the element to delete: ");
    scanf("%d", &index);
    deleteElement(arr, &n, index);
    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}