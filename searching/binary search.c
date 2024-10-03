#include <stdio.h>

int binary_search(int* arr,int l,int elem){
    int low = 0,high = l-1;
    int mid = (low+high)/2;
    while(low <=high && arr[mid] != elem){
        if (arr[mid] <elem){
            low = mid+1;
        } else if(arr[mid] > elem){
            high = mid-1;
        }
        mid = (low+high)/2;
    }
    if (arr[mid] == elem){
        return mid;
    } else {
        return -1;
    }

}
// int bsr(int* arr,int low,int high,int elem){
//     if (low > high){
//         return -1;
//     }
//     int mid = (low+high)/2;
//     if (arr[mid] == elem){
//         return mid;
//     } else if (arr[mid] < elem){
//         low = mid + 1;
//     } else if (arr[mid] > elem){
//         high = mid - 1;
//     }
//     return bsr(arr,low,high,elem);
// }

int main(){
    int arr[100];
    int l ;
    printf("==========Binary Search (ravish)==========\nEnter the length of the array (<100) : ");
    scanf("%d",&l);
    printf("\n * Input array should be sorted\n");
    int inp;
    for (int i = 0;i<l;i++){
        printf("Enter element %d : ", (i+1));
        scanf("%d",&inp);
        arr[i] = inp;
    }
    printf("\nEnter element you want to search : ");
    scanf("%d",&inp);
    int res = binary_search(arr,l,inp);
    if (res >=0){
        printf("\nElement %d found at index %d",inp,res);
    } else {
        printf("\nElement %d not found in the array",inp);
    }
    // res = bsr(arr,0,l-1,inp);
    // if (res >=0){
    //     printf("\nElement %d found at index %d",inp,res);
    // } else {
    //     printf("\nElement %d not found in the array",inp);
    // }
    scanf("%d",&inp);
    return 0;
}