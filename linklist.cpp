#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
void inserting();
void deletion();
void display();
void exit();
void front();
void end();
void location();
int length();
struct node
{
char nam[30];
int roll;
int prn;
int phone;
char email[30];
char add[30];
struct node* next;	
};
struct node*root;
int count=0;
int main()
{
int ch;
printf("welcome to the student record \n");
while(1)
{
printf("enter the choice of the following choices\n");
printf("\n 1.inserting \n2.deleting \n3. display \n4.length \n 5.exit");
scanf("%d",&ch);
switch(ch)
{
case 1: inserting();
 break;
 case 2: deletion();
  break;
  case 3: display();
  break;
  case 4:length();
  break;
  case 5: exit(0);
  break;
  default:printf("invalid choice");	
}
}
}
void inserting()
{
    int loc;
	printf("enter the elements at what place do you want \n press 1: for front \n press 2: for end \n press 3:any location\n press 4:back \n press 5:main menu");
	scanf("%d",&loc);
    switch(loc)
    {
	case 1: front(); 
    break;
    case 2: end();
    break;
    case 3: location();
    break;
    case 4: inserting();
    break;
    case 5: main();
    break;
    default: printf("invalid choice");
    } 
}
	                void front()
                            {                
                                struct node*temp;
                            temp=(struct node*)malloc(sizeof(struct node));
                            printf("enter the name of the student \n");
                            scanf("%s\n",&temp->nam);
                            printf("enter the roll no \n");
                            scanf("%d\n",&temp->roll);
                            printf("enter the prn no. ");
                            scanf("%d\n",&temp->prn);
                            printf("enter the phone no.");
                            scanf("%d\n",&temp->phone);
                            printf("enter the email");
                            scanf("%s\n",&temp->email);
                            printf("enter the address of the student");
                            scanf("%s\n",&temp->add);
                            if(root==NULL)
                            {
                            	root=temp;
							}
							else
							{
								temp->next=root;
								root=temp;
							}
                            }
            void end()
                       {
                    	struct node*temp;
                            temp=(struct node*)malloc(sizeof(struct node));
                            printf("enter the name of the student \n");
                            scanf("%s",&temp->nam);
                            printf("enter the roll no \n");
                            scanf("%d",&temp->roll);
                            printf("enter the prn no. ");
                            scanf("%d",&temp->prn);
                            printf("enter the phone no.");
                            scanf("%d",&temp->phone);
                            printf("enter the email");
                            scanf("%s",&temp->email);
                            printf("enter the address of the student");
                            scanf("%s",&temp->add);
                            temp->next=NULL;
                        if(root==NULL)
                                {
                            	 root=temp;
		   }
		else
		  { 
		struct node*p;
		p=root;
		while(p->next!=NULL)
	 {
		p=p->next;
			  }
		 p->next=temp;
		}	    
		   }
		   void location()
		  {   
		struct node*temp,*p;
		 int loc,i=1,len;
		                
                           	printf("enter the location");
                           	scanf("%d",&loc);
                           	len=length();
                           	if(loc>len)
                           	{
                           	printf("invalid location\n");
                           	printf("currently list is of size %d node\n",len);
		   }
		else
		{
		p=root;
		while(i<loc)
		{
		p=p->next;
		i++;
		}
		temp=(struct node*)malloc(sizeof(struct node));
                            printf("enter the name of the student \n");
                            scanf("%s",&temp->nam);
                            printf("enter the roll no \n");
                            scanf("%d",&temp->roll);
                            printf("enter the prn no. ");
                            scanf("%d",&temp->prn);
                            printf("enter the phone no.");
                            scanf("%d",&temp->phone);
                            printf("enter the email");
                            scanf("%s",&temp->email);
                            printf("enter the address of the student");
                            scanf("%s",&temp->add);
                            temp->next=p->next;
                            p->next=temp;
}		
}
int length()
  {
		        	struct node *temp;
		            	temp=root;
		            	while(temp!=NULL)
		            	{
		           	count++;
		            	temp=temp->next;
			}
												printf("\n total length of list is=%d",count);
                                                return 0;												
												}
void deletion()
{
	int locat;
	printf("please enter the location at which do you want to delete the elements.\n ");
	struct node* temp;
	printf("\n *** A.press 1 for deleting element at front \n ***B.press any number less then length of list for deleting it.\n");
	scanf("%d",locat);
	if(locat>count)
	{
		printf("invalid location\n");
	}
	else if (locat==1)
	{
	temp=root;
	root=temp->next;
	temp->next=NULL;
	free(temp);
	}
else
{
struct node*p=root,*q;
int r;
while(r<locat-1)
{
p=p->next;
r++;	
}
	q=p->next;
	p->next=q->next;
	q->next=NULL;
	free(q);
}
printf("element deleted successfully.");
}
void display()
{
struct node*temp;
temp=root;
if(temp==NULL)
{
	printf("\n there is no node in list \n please enter the node in the list\n");
}
else 
{
	while(temp!=NULL)
	{
		printf("%c->",temp->nam);
		printf("%d->",temp->roll);
		printf("%d->",temp->prn);
		printf("%d->",temp->phone);
		printf("%c->",temp->email);
		printf("%c->",temp->add);
	temp=temp->next;
	}
}
}
void exit()
{
	printf("press enter the to to exit");
}
