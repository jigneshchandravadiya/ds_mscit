
#include<stdio.h>

int main()
{
    int q[5], front=-1, rear=-1, ch, x, i;

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                if((rear+1)%5==front)
                    printf("Overflow");
                else
                {
                    printf("Enter value: ");
                    scanf("%d",&x);

                    if(front==-1)
                        front=0;

                    rear=(rear+1)%5;
                    q[rear]=x;
                }
                break;

            case 2:
                if(front==-1)
                    printf("Underflow");
                else
                {
                    printf("Deleted: %d",q[front]);

                    if(front==rear)
                        front=rear=-1;
                    else
                        front=(front+1)%5;
                }
                break;

            case 3:
                if(front==-1)
                    printf("Queue Empty");
                else
                {
                    i=front;

                    while(1)
                    {
                        printf("%d ",q[i]);

                        if(i==rear)
                            break;

                        i=(i+1)%5;
                    }
                }
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