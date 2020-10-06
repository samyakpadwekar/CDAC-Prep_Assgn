#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[10];
    int price;
} book;

void merge(book arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /*temp arrays */
    book L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].price >= R[j].price) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// l is lower bound,r is upper bound,m is middle element
void mergeSort(book arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(book A[], int size)
{
    int i;
    printf("ID Bookname Price\n");
    for (i = 0; i < size; i++)
     {
        printf("%d ",A[i].id);
        printf("  %s ",A[i].name);
        printf("   %d ",A[i].price);
        printf("\n");
     }
    printf("\n");
}

int main(void)
{
    book b1[10] = {
        {5, "Bookf", 100},
        {4, "Bookc", 130},
        {8, "Booka", 120},
        {6, "Booke", 160},
        {0, "Bookg",110},
        {1, "Bookd", 170},
        {7, "Booki", 140},
        {9, "Bookb", 190},
        {2, "Bookh", 150},
        {3, "Bookj",180}};
    int i;

    printf("Array of 10 books:\n");
    printArray(b1, 10);

    mergeSort(b1, 0, 9);

    printf("In descending order of price after merge sort:\n");
    printArray(b1, 10);

    return (0);
}
