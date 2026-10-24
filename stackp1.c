#include<stdio.h>

int main()
{
    int s[5], top=-1, ch, x, i;

    do
    {
        printf("\n1.Push\n2.delete\n3.Peep\n4.Modify\n5.Display\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                if(top==4)
                    printf("Overflow");
                else
                {
                    printf("Enter value: ");
                    scanf("%d",&x);
                    top++;
                    s[top]=x;
                }
                break;

            case 2:
                if(top==-1)
                    printf("Underflow");
                else
                {
                    printf("delete = %d",s[top]);
                    top--;
                }
                break;

            case 3:
                if(top==-1)
                    printf("Empty");
                else
                    printf("Peep = %d",s[top]);
                break;

            case 4:
                if(top==-1)
                    printf("Empty");
                else
                {
                    printf("Enter new value: ");
                    scanf("%d",&s[top]);
                }
                break;

            case 5:
                for(i=top;i>=0;i--)
                    printf("%d ",s[i]);
                break;

            case 6:
                printf("Exit");
                break;

            default:
                printf("Wrong choice");
        }
    }
    while(ch!=6);

    return 0;
}