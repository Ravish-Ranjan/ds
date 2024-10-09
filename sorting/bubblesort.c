#include <stdio.h>
#define MAX 20

void bubbleSort(int* arr,int l){
    for (int i = 0;i < l;i++){
        for (int j = 0;j < l-1;j++){
            if (arr[j] > arr[j+1]){
                arr[j] = arr[j] ^ arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^ arr[j+1];
            }
        }
    }
}

int main(){
    printf("----------Bubble Sort ravish----------\n");
    int arr[MAX];
    int size;
    printf("Enter the size of the array (<=20): ");
    scanf("%d",&size);
    for (int i = 0;i < size;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nBefore bubble sort : ");
    for (int i = 0;i < size;i++){
        printf("%d ",arr[i]);
    }

    bubbleSort(arr,size);
    
    printf("\nAfter bubble sort : ");
    for (int i = 0;i < size;i++){
        printf("%d ",arr[i]);
    }
    return 0; 
}