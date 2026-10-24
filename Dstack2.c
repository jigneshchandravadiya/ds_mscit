
#include<stdio.h>

int main()
{
    int a[10], top1=-1, top2=10, ch, x, i;

    do
    {
        printf("\n1.Push Stack 1");
        printf("\n2.Push Stack 2");
        printf("\n3.delete Stack 1");
        printf("\n4.delete Stack 2");
        printf("\n5.Modify");
        printf("\n6.Display");
        printf("\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                if(top1+1==top2)
                    printf("Overflow");
                else
                {
                    printf("Enter value: ");
                    scanf("%d",&x);
                    a[++top1]=x;
                }
                break;

            case 2:
                if(top1+1==top2)
                    printf("Overflow");
                else
                {
                    printf("Enter value: ");
                    scanf("%d",&x);
                    a[--top2]=x;
                }
                break;

            case 3:
                if(top1==-1)
                    printf("Stack 1 Underflow");
                else
                    printf("Pop = %d",a[top1--]);
                break;

            case 4:
                if(top2==10)
                    printf("Stack 2 Underflow");
                else
                    printf("Pop = %d",a[top2++]);
                break;

            case 5:
                printf("Modify which stack (1 or 2)? ");
                scanf("%d",&x);

                if(x==1)
                {
                    if(top1==-1)
                        printf("Stack 1 Empty");
                    else
                    {
                        printf("Enter new value: ");
                        scanf("%d",&a[top1]);
                    }
                }
                else if(x==2)
                {
                    if(top2==10)
                        printf("Stack 2 Empty");
                    else
                    {
                        printf("Enter new value: ");
                        scanf("%d",&a[top2]);
                    }
                }
                else
                    printf("Wrong choice");
                break;

            case 6:
                printf("Stack 1: ");
                if(top1==-1)
                    printf("Empty");
                else
                    for(i=top1;i>=0;i--)
                        printf("%d ",a[i]);

                printf("\nStack 2: ");
                if(top2==10)
                    printf("Empty");
                else
                    for(i=top2;i<10;i++)
                        printf("%d ",a[i]);
                break;

            case 7:
                printf("Exit");
                break;

            default:
                printf("Wrong choice");
        }
    }
    while(ch!=7);

    return 0;
}