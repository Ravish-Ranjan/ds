#include <stdio.h>
#define max 20

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    printf("----------Merge Sort ravish----------\n");
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
    printArray(arr,size);

    mergeSort(arr, 0,size - 1);

    printf("Sorted array: ");
    printArray(arr,size);

    return 0;
}
