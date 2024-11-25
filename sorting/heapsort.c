#include <stdio.h>
#define max 20

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int size,int i){
    int lar = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l<size && arr[l]>arr[lar])
        lar = l;
    
    if (r<size && arr[r]>arr[lar])
        lar = r;

    if (lar != i){
        swap(&arr[i],&arr[lar]);
        heapify(arr,size,lar);
    }
}

void heapsort(int arr[],int size){
    for (int i = size/2-1 ;i>=0 ;i--)
        heapify(arr,size,i);
    
    for (int i = size-1 ;i>0 ;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
    
}

void print(int arr[],int size){
    for (int i = 0; i < size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    printf("----------Heap Sort ravish----------\n");
    int arr[max],size;
    printf("Enter the size of the array (<=20): ");
    scanf("%d",&size);
    if (size > max){
        printf("array size exceeded\n");
    } else {
        for (int i = 0; i < size; i++){
            printf("arr[%d] : ",i);
            scanf("%d",&arr[i]);
        }
        printf("Before sorting : ");
        print(arr,size);
        heapsort(arr,size);
        printf("After sorting : ");
        print(arr,size);
    }
    return 0;
}