#include<stdio.h>

void dismantle(int a[], int lb, int ub);
void ms(int a[], int lb, int mid, int ub);

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

    dismantle(a, 0, n - 1);

    printf("The sorted array is as follows: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void dismantle(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        dismantle(a, lb, mid);
        dismantle(a, mid + 1, ub);
        ms(a, lb, mid, ub);
    }
}

void ms(int a[], int lb, int mid, int ub)
{
    int b[ub - lb + 1];
    int i = lb, j = mid + 1, k = 0;

    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        { 
            b[k++] = a[i++]; 
        }
        else
        { 
            b[k++] = a[j++]; 
        }
    }

    while (i <= mid)
    {
        b[k++] = a[i++];
    }

    while (j <= ub)
    {
        b[k++] = a[j++];
    }
    
    for (int x = 0; x < ub - lb + 1; x++)
    {
        a[lb + x] = b[x];
    }
}