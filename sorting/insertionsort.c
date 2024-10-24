#include <stdio.h>
#define max 20

void insertionSort(int arr[],int l){
    int key,i;
    for (int j = 1; j < l; j++){
        key = arr[j];
        i = j-1;
        while (i>=0 && arr[i] > key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

int main(){
    printf("----------Insertion Sort Ravish----------\n");
    int arr[max],l;
    printf("Enter size of array (<=20): ");
    scanf("%d",&l);
    if (l > 20){
        printf("Size exceeding\n");
    } else {
        for (int i = 0;i<l;i++){
            printf("Enter %dth element : ",i+1);
            scanf("%d",&arr[i]);
        }
        printf("\nArray before insertion sort : \n");
        for (int i = 0;i<l;i++)
            printf("%d ",arr[i]);
        insertionSort(arr,l);
        printf("\nArray after insertion sort : \n");
        for (int i = 0;i<l;i++)
            printf("%d ",arr[i]);
    }
    return 0;
}