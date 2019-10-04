#include<stdio.h>
#include<conio.h>
#define max 5
void push();
void pop();
void dis();
int top=-1;
int x[5];
void main()
{
int ch;
clrscr();
while(1)
{
printf("\nSelct the process  which is you wnat to perform\n 1: PUSH\n 2: POP\n 3: DIS\n 4: EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
	push();
	break;
case 2:
	pop();
	break;
case 3:
	dis();
	break;
case 4:
	exit(1);
default:
	printf("\nINVALID INPUT\n");
}
}
}

void push()
{
int item;
if(top==max-1)
{
printf("\nStack is overflow\n");
}
else
{
printf("\nEnter the Nnmber\n");
scanf("%d",&item);
top=top+1;
x[top]=item;
}
}
void pop()
{
if(top==-1)
{
printf("\nStack is underflow\n");
}
else
{
top=top-1;
}
}
void dis()
{
int i;
if(top==-1)
{
printf("\nStack is underflow\n");
}
else
{
for(i=top;i>=0;i--)
{
printf("\n%d\n",x[i]);
}
}
}

