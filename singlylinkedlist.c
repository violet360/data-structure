#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *first=NULL, *current=NULL;

struct node * create_node()
{
    struct node *t;
    t=(struct node *)malloc (sizeof(struct node));
    t->next = NULL;
    return t;
}

void add_last(int n)
{
    struct node *temp;
    temp = create_node();
    temp->data = n;

    if(first==NULL)
        first=current=temp;
    else
    {
        current->next=temp;
        current=temp;
    }
}

void add_first(int n)
{
    struct node *temp;
    temp = create_node();
    temp->data = n;

    if(first==NULL)
        first=current=temp;
    else
    {
        temp->next=first;
        first=temp;
    }
}

void add_pos(int n)
{
    int i=0,pos;
    struct node *temp,*x,*y;
    temp = create_node();
    temp->data = n;
    x=first;

    printf("enter the position:\n");
    scanf("%d",&pos);

    while(i<pos-1)
    {   
        y=x;
        x=x->next;
        i++;
    }
        y->next=temp;
        temp->next=x;

}

void display()
{
    struct node *temp;
    temp = first;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void del_pos(int n)
{
    struct node *t,*x;
    int i=1;

    if(n==1)
    {
        t=first;
        first=t->next;
        free(t);
    }   
    else
    {   
        t=first;
        while(i<n-1)
        {
            t=t->next;
            i++;
        }
        x=t->next;
        t->next=x->next;

        if(t->next == NULL)
        {
            current =t;
        }
        free(x);
    }

}

void del_before(int n)
{
    struct node *t,*x;
    int i=1;

    if(n==1)
    {
        printf("invalid deletion\n");
    }
    if(n==2)
    {
        t=first;
        first=t->next;
        free(t);
    }   
    else
    {   
        t=first;
        while(i<n-2)
        {
            t=t->next;
            i++;
        }
        x=t->next;
        t->next=x->next;

        if(t->next == NULL)
        {
            current =t;
        }
        free(x);
    }
}

void del_after(int n)
{
    struct node *t,*x;
    int i=1;

    if(n==0)
    {
        t=first;
        first=t->next;
        free(t);
    }   
    else
    {   
        t=first;
        while(i<n)
        {
            t=t->next;
            i++;
        }
        x=t->next;
        t->next=x->next;

        if(t->next == NULL)
        {
            current =t;
        }
        free(x);
}

void main()
{
    int choice,n;

    while(1)
    {   
        printf("\n1. Insert an element at last");
        printf("\n2. Insert an element at front");
        printf("\n3. Insert an element at specific position");
        printf("\n4. Display the list");
        printf("\n5. Delete at specific position");
        printf("\n6. Delete an element before specific position");
        printf("\n7. Delete an element before specific position");
        printf("\n8.Exit\n");

        printf("enter your choice:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("enter element to be inserted\n");
                scanf("%d",&n);
                add_last(n);
                break;

            case 2:
                printf("enter element to be inserted\n");
                scanf("%d",&n);
                add_first(n);
                break;

            case 3:
                printf("enter element to be inserted\n");
                scanf("%d",&n);
                add_pos(n);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("enter position to be deleted\n");
                scanf("%d",&n);
                del_pos(n);
                break;

            case 6:
                printf("enter position\n");
                scanf("%d",&n);
                del_before(n);
                break;

            case 7:
                printf("enter position\n");
                scanf("%d",&n);
                del_after(n);
                break;

            case 8:
                exit(0);
            
        }

    }
}
