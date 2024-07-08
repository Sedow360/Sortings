#include<stdio.h>
#include<stdlib.h>

void counting(int* a, int l);

int main()
{
    int n; printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    counting(a, n);

    printf("The sorted arrsy is as follows:\n");
    for (int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

void counting(int* a, int l)
{
    int max=a[0];
    for (int i=1; i<l; i++)
    {
        if (a[i]>max) {max=a[i];}
    }

    int t[max+1];

    for (int i=0; i<=max; i++)  //counts the appearances
    {
        t[i]=0;
        for (int j=0; j<l; j++)
        {
            if (a[j]==i)
            {
                t[i]++;
            }
        }
    }

    int i=0;

    while (i<l)
    {
        for (int j=0; j<=max; j++)
        {
            while (t[j]--)
            {
                a[i]=j;
                i++;
            }
        }
    }
}