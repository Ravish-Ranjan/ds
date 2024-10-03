#include <stdio.h>
#include <stdlib.h>

void print2(int arr[][20], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

// void print(int *arr, int l)
// {
//     for (int i = 0; i < l; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int *flat_rm(int arr[][20], int m, int n)
// {
//     int *ret = (int *)malloc(m * n * sizeof(int));
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             ret[n * i + j] = arr[i][j];
//         }
//     }
//     return ret;
// }

// int *flat_cm(int arr[][20], int m, int n)
// {
//     int *ret = (int *)malloc(m * n * sizeof(int));
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             ret[m * j + i] = arr[i][j];
//         }
//     }
//     return ret;
// }

void linear_search(int arr[][20], int m, int n, int elem)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == elem)
            {
                printf("\nElement %d found at row : %d col : %d", elem, i + 1, j + 1);
                return;
            }
        }
    }
    printf("\nElement %d not found", elem);
    return;
}

void binary_search(int arr[][20], int elem, int m, int n)
{
    int start = 0;
    int mid, row, col, value;
    int end = m * n - 1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        row = mid / n;
        col = mid % n;
        value = arr[row][col];

        if (value == elem)        {
            printf("\nElement %d found at row : %d col : %d", elem, row + 1, col + 1);
            return;
        }
        if (value > elem)
            end = mid - 1;
        else
            start = mid + 1;
    }
    printf("\nElement %d not found", elem);
    return;
}

int main()
{
    int arr[20][20];
    int m, n;
    printf("========2d array (ravish)========\n");
    printf("Enter no. of rows (<20) : ");
    scanf("%d", &m);

    printf("Enter no. of cols (<20) : ");
    scanf("%d", &n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element at %d:row %d:col : ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n=====Your 2D array is=====\n");
    print2(arr, m, n);

    // int *ret_rm = flat_rm(arr, m, n);
    // printf("\nMapping your array from 2d to 1d (row major)\n");
    // print(ret_rm, m * n);
    // free(ret_rm);

    // int *ret_cm = flat_cm(arr, m, n);
    // printf("\nMapping your array from 2d to 1d (row major)\n");
    // print(ret_cm, m * n);
    // free(ret_cm);

    int ret;
    printf("\nEnter the element you want to search (linear search) : ");
    scanf("%d", &ret);
    linear_search(arr, m, n, ret);

    printf("\n\nEnter the element you want to search (binary search) : ");
    scanf("%d", &ret);
    binary_search(arr, ret, m, n);

    return 0;
}