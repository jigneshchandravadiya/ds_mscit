
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head=NULL, *newnode, *temp, *prev;
    int ch, x, y;

    do
    {
        printf("\n1.Insert\n2.Delete\n3.Modify\n4.Display\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                newnode=(struct node*)malloc(sizeof(struct node));

                printf("Enter value: ");
                scanf("%d",&newnode->data);

                if(head==NULL)
                {
                    head=newnode;
                    newnode->next=head;
                }
                else
                {
                    temp=head;

                    while(temp->next!=head)
                        temp=temp->next;

                    temp->next=newnode;
                    newnode->next=head;
                }
                break;

            case 2:
                if(head==NULL)
                    printf("List Empty");
                else
                {
                    printf("Enter value to delete: ");
                    scanf("%d",&x);

                    temp=head;
                    prev=NULL;

                    do
                    {
                        if(temp->data==x)
                            break;

                        prev=temp;
                        temp=temp->next;
                    }
                    while(temp!=head);

                    if(temp->data!=x)
                        printf("Value Not Found");
                    else
                    {
                        if(temp==head && head->next==head)
                            head=NULL;
                        else if(temp==head)
                        {
                            while(temp->next!=head)
                                temp=temp->next;

                            temp->next=head->next;
                            temp=head;
                            head=head->next;
                        }
                        else
                            prev->next=temp->next;

                        free(temp);
                        printf("Deleted");
                    }
                }
                break;

            case 3:
                if(head==NULL)
                    printf("List Empty");
                else
                {
                    printf("Enter old value: ");
                    scanf("%d",&x);

                    temp=head;

                    do
                    {
                        if(temp->data==x)
                            break;

                        temp=temp->next;
                    }
                    while(temp!=head);

                    if(temp->data!=x)
                        printf("Value Not Found");
                    else
                    {
                        printf("Enter new value: ");
                        scanf("%d",&y);
                        temp->data=y;
                    }
                }
                break;

            case 4:
                if(head==NULL)
                    printf("List Empty");
                else
                {
                    temp=head;

                    do
                    {
                        printf("%d -> ",temp->data);
                        temp=temp->next;
                    }
                    while(temp!=head);

                    printf("(Back to Head)");
                }
                break;

            case 5:
                printf("Exit");
                break;

            default:
                printf("Wrong Choice");
        }
    }
    while(ch!=5);

    return 0;
}