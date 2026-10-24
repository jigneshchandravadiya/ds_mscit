
#include<stdio.h>

void heap(int a[], int n, int i)
{
    int largest=i, l=2*i+1, r=2*i+2, t;

    if(l<n && a[l]>a[largest])
        largest=l;

    if(r<n && a[r]>a[largest])
        largest=r;

    if(largest!=i)
    {
        t=a[i];
        a[i]=a[largest];
        a[largest]=t;

        heap(a,n,largest);
    }
}

int main()
{
    int a[20], n, i, t;

    printf("Enter size: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=n/2-1;i>=0;i--)
        heap(a,n,i);

    for(i=n-1;i>0;i--)
    {
        t=a[0];
        a[0]=a[i];
        a[i]=t;

        heap(a,i,0);
    }

    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}