#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

int a[5],top=0;
void push();
void pop();
void display();
void main()
{
    system("cls");
  int i;
  while(1)
        {
            printf("\t1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choise..\n");
            scanf("%d",&i);
            switch(i)
            {
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Invalid choise..\1");
            }
        }
 getch();
}
void push()
{
  if(top==5)
  {
        printf("Stack overflow");
  }
  else
  {
      top++;
      printf("Enter data : ");
      scanf("%d",&a[top]);
      printf("/nOperation successful..");
  }
};
void pop()
{
  if(top==0)
  {
        printf("\nStack underflow");
  }
  else
  {
    printf("\n%d is successfully removed...",a[top]);
    top--;
  }
};
void display()
{
    if(top==0)
  {
        printf("\nStack underflow");
  }
  else
  {
    for(int q=0;q<=top;q++)
    {
        printf("\n%d",a[q]);
    }
  }
};
