#include <stdio.h>

int search(int* arr,int l,int elem){
    for (int i = 0;i<l;i++){
        if (arr[i] == elem) return i;
    }
    return -1;
}

int main(){
    int arr[100];
    int l ;
    printf("----------Array Search (ravish)----------\nEnter the length of the array (<100) : ");
    scanf("%d",&l);
    int inp;
    for (int i = 0;i<l;i++){
        printf("Enter element %d : ", (i+1));
        scanf("%d",&inp);
        arr[i] = inp;
    }
    printf("\nEnter element you want to search : ");
    scanf("%d",&inp);
    int res = search(arr,l,inp);
    if (res >=0)
        printf("\nElement %d found at index %d",inp,res);
    else
        printf("\nElement %d not found in the array",inp);
    scanf("%d",&inp);
    return 0;
}