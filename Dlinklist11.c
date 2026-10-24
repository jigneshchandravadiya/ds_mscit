
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

int main()
{
    struct node *head=NULL, *newnode, *temp;
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

                newnode->next=NULL;
                newnode->prev=NULL;

                if(head==NULL)
                    head=newnode;
                else
                {
                    temp=head;

                    while(temp->next!=NULL)
                        temp=temp->next;

                    temp->next=newnode;
                    newnode->prev=temp;
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

                    while(temp!=NULL && temp->data!=x)
                        temp=temp->next;

                    if(temp==NULL)
                        printf("Value Not Found");
                    else
                    {
                        if(temp->prev!=NULL)
                            temp->prev->next=temp->next;
                        else
                            head=temp->next;

                        if(temp->next!=NULL)
                            temp->next->prev=temp->prev;

                        free(temp);
                        printf("Deleted");
                    }
                }
                break;

            case 3:
                printf("Enter old value: ");
                scanf("%d",&x);

                temp=head;

                while(temp!=NULL && temp->data!=x)
                    temp=temp->next;

                if(temp==NULL)
                    printf("Value Not Found");
                else
                {
                    printf("Enter new value: ");
                    scanf("%d",&y);
                    temp->data=y;
                }
                break;

            case 4:
                if(head==NULL)
                    printf("List Empty");
                else
                {
                    temp=head;

                    while(temp!=NULL)
                    {
                        printf("%d <-> ",temp->data);
                        temp=temp->next;
                    }

                    printf("NULL");
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