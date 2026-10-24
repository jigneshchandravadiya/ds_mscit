
#include<stdio.h>

int main()
{
    int q[5], p[5], n=0, ch, x, pr, i, j, temp;

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                if(n==5)
                    printf("Overflow");
                else
                {
                    printf("Enter value: ");
                    scanf("%d",&x);
                    printf("Enter priority: ");
                    scanf("%d",&pr);

                    q[n]=x;
                    p[n]=pr;
                    n++;
                }
                break;

            case 2:
                if(n==0)
                    printf("Underflow");
                else
                {
                    j=0;

                    for(i=1;i<n;i++)
                        if(p[i]<p[j])
                            j=i;

                    printf("Deleted: %d",q[j]);

                    for(i=j;i<n-1;i++)
                    {
                        q[i]=q[i+1];
                        p[i]=p[i+1];
                    }

                    n--;
                }
                break;

            case 3:
                if(n==0)
                    printf("Queue Empty");
                else
                    for(i=0;i<n;i++)
                        printf("\nValue=%d Priority=%d",q[i],p[i]);
                break;

            case 4:
                printf("Exit");
                break;

            default:
                printf("Wrong choice");
        }
    }
    while(ch!=4);

    return 0;
}