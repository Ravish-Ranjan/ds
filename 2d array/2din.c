#include <stdio.h>
int main(){
    int arr[10][10],row,col;
    printf("----------2d insertion ravish----------\n");
    printf("Enter no. of rows : ");
    scanf("%d",&row);
    printf("Enter no. of cols : ");
    scanf("%d",&col);

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("Enter arr[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
    
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
    return 0;
}