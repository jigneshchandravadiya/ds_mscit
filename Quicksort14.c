
#include<stdio.h>

void quicksort(int a[], int low, int high)
{
    int i, j, pivot, temp;

    if(low<high)
    {
        pivot=a[high];
        i=low-1;

        for(j=low;j<high;j++)
        {
            if(a[j]<pivot)
            {
                i++;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }

        temp=a[i+1];
        a[i+1]=a[high];
        a[high]=temp;

        quicksort(a,low,i);
        quicksort(a,i+2,high);
    }
}

int main()
{
    int a[50], n, i;

    printf("Enter size: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    quicksort(a,0,n-1);

    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}