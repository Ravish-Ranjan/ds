#include <stdio.h>
#define max 20

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        swap(&arr[minIndex], &arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("----------Selection Sort ravish----------\n");
    int arr[max],size;
    printf("Enter the size of the arr (<=20) : ");
    scanf("%d",&size);
    if (size>20){
        printf("array size exceeded (>20)");
        return 0;
    }
    for (int i = 0; i < size; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    printf("Unsorted array: ");
    printArray(arr, size);

    selectionSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
