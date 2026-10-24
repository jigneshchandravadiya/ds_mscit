
#include<stdio.h>

int main()
{
    int q[5], front=-1, rear=-1, ch, x, i;

    do
    {
        printf("\n1.Insert Front\n2.Insert Rear");
        printf("\n3.Delete Front\n4.Delete Rear");
        printf("\n5.Modify\n6.Display\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                if(front==0)
                    printf("Overflow");
                else
                {
                    printf("Enter value: ");
                    scanf("%d",&x);

                    if(front==-1)
                        front=rear=0;
                    else
                        front--;

                    q[front]=x;
                }
                break;

            case 2:
                if(rear==4)
                    printf("Overflow");
                else
                {
                    printf("Enter value: ");
                    scanf("%d",&x);

                    if(front==-1)
                        front=rear=0;
                    else
                        rear++;

                    q[rear]=x;
                }
                break;

            case 3:
                if(front==-1)
                    printf("Underflow");
                else
                {
                    printf("Deleted: %d",q[front]);

                    if(front==rear)
                        front=rear=-1;
                    else
                        front++;
                }
                break;

            case 4:
                if(rear==-1)
                    printf("Underflow");
                else
                {
                    printf("Deleted: %d",q[rear]);

                    if(front==rear)
                        front=rear=-1;
                    else
                        rear--;
                }
                break;

            case 5:
                if(front==-1)
                    printf("Queue Empty");
                else
                {
                    printf("Enter new value: ");
                    scanf("%d",&q[front]);
                    printf("Modified");
                }
                break;

            case 6:
                if(front==-1)
                    printf("Queue Empty");
                else
                    for(i=front;i<=rear;i++)
                        printf("%d ",q[i]);
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