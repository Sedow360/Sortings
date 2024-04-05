#include<stdio.h>

int partition(int* a, int lb, int ub);
void quick(int* a, int lb, int ub);

int partition(int* a, int lb, int ub)   //for partitioning the array around the "pivot" element
{
    int pivot = a[lb];   //setting the pivot to be the last first element of any array
    int start = lb;
    int end = ub;

    while (start < end) 
    {
        while (a[start] <= pivot) 
        {
            start++;
        }
        while (a[end] > pivot) 
        {
            end--;
        }
        if (start < end) 
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    a[lb] = a[end];//fixating the position of pivot at the correct position in the array
    a[end] = pivot;//such that, elements on its left are <pivot and elements on its right are >pivot
    return end;
}

void quick(int* a, int lb, int ub)   //for the actual quick sort
{
    if (lb < ub) 
    {
        int loc = partition(a, lb, ub);
        quick(a, lb, loc - 1);   //calling recursing for sorting the left sub array of the pivot
        quick(a, loc + 1, ub);   //for the right sub array
    }
}

int main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++) 
    {
        printf("Enter the value for index no. %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    quick(a, 0, n - 1);

    printf("The sorted array is as follows: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", a[i]);
    }
    return 0;
}