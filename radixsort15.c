
#include<stdio.h>

int main()
{
    int a[50], b[10][50], c[10]={0};
    int n, i, j, k, max=0, exp=1, d;

    printf("Enter size: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>max)
            max=a[i];
    }

    while(max/exp>0)
    {
        for(i=0;i<10;i++)
            c[i]=0;

        for(i=0;i<n;i++)
        {
            d=(a[i]/exp)%10;
            b[d][c[d]++]=a[i];
        }

        k=0;

        for(i=0;i<10;i++)
            for(j=0;j<c[i];j++)
                a[k++]=b[i][j];

        exp=exp*10;
    }

    printf("Sorted array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}