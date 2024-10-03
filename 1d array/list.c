#include <stdio.h>

#define max 100

void traverse(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int arr[], int *size, int elem, int at) {
    if (*size >= max || at < 0 || at > *size) {
        printf("Insertion failed.\n");
        return;
    }
    for (int i = *size; i > at; i--)
        arr[i] = arr[i - 1];
    arr[at] = elem;
    (*size)++;
}

void deleteElement(int arr[], int *size, int at) {
    if (*size == 0 || at < 0 || at >= *size) {
        printf("Deletion failed.\n");
        return;
    }
    for (int i = at; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
}

int main() {
    int arr[max], size = 0, choice, elem, position;

    while (1) {
        printf("Ravish\nMenu:\n1. Insert\t2. Delete\n3. Display\t4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Element: "); scanf("%d", &elem);
                printf("Position (0 to %d): ", size); scanf("%d", &position);
                insertElement(arr, &size, elem, position);
                break;
            case 2:
                printf("Position to delete (0 to %d): ", size - 1); scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 3:
                printf("Array: "); traverse(arr, size);
                break;
            case 4: return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
