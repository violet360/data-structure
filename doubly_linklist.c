#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
struct Node *head;

void insert_beg(int x)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
        if(head!=NULL)
        {
            temp->next = head;
            head->prev = temp;
        }
        head = temp;
}

void print()
{
    struct Node *temp = head;
    printf("\n  LIST IS  \n");
    while(temp!=NULL)
    {
        printf("%d", temp->data);
        temp =  temp->next;
    }
    printf("\n");
}
void reverse(){
    struct Node *temp = head;
    if(temp==NULL)
        return;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("\n REVERSE LIST IS");
    while(temp!=NULL)
    {
        printf("%d", temp->data);
        temp = temp->prev;
    }
    printf("\n");

}
int main()
{
    int n,x;
    head = NULL;
    printf("enter the total number of elements");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf(" \n  enter the data  \n");
        scanf("%d",&x);
        insert_beg(x);

    }
    reverse();
    return 0;
}