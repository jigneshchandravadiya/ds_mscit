
#include<stdio.h>

int main()
{
    int q[5], front=-1, rear=-1, ch, x, i;

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Modify\n4.Display\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                if(rear==4)
                    printf("Queue Overflow");
                else
                {
                    printf("Enter process: ");
                    scanf("%d",&x);

                    if(front==-1)
                        front=0;

                    q[++rear]=x;
                }
                break;

            case 2:
                if(front==-1)
                    printf("Queue Underflow");
                else
                {
                    printf("Deleted process: %d",q[front++]);

                    if(front>rear)
                        front=rear=-1;
                }
                break;

            case 3:
                if(front==-1)
                    printf("Queue Empty");
                else
                {
                    printf("Enter new process: ");
                    scanf("%d",&q[front]);
                }
                break;

            case 4:
                if(front==-1)
                    printf("Queue Empty");
                else
                    for(i=front;i<=rear;i++)
                        printf("%d ",q[i]);
                break;

            case 5:
                printf("Exit");
                break;

            default:
                printf("Wrong choice");
        }
    }
    while(ch!=5);

    return 0;
}