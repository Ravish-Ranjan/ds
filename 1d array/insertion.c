#include <stdio.h>
int main(){
    int arr[15],size;
    printf("----------Insertion Arr ravish----------\nEnter length of arr : ");
    scanf("%d",&size);
    for (int i = 0; i < size; i++){
        printf("Enter arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    printf("Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}