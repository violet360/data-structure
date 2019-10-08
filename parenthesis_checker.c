#include <stdio.h>
#include <string.h>
#include "char_stack.h"
#define MAX 50

int main()
{
    char exp[MAX],temp;
    int i;
    int flag = 1; //assuming that the expression is valid

    printf("enter expression\n");
    gets(exp);


    for( i = 0; i < strlen(exp); i++)
    {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            push(exp[i]);
        }

        else if (exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(tos==-1)
            {
                flag = 0;
                break;
            }

            else
            {

                temp = pop();

                if(exp[i]==')' && (temp=='[' || temp=='{'))
                   { flag = 0;
                    break;}
                if(exp[i]==']' && (temp=='{' || temp=='('))
                   { flag = 0;
                    break;}
                if(exp[i]=='}' && (temp=='(' || temp=='['))
                   { flag = 0;
                    break;}
            }

        }
    }

    if (tos >=0)
        flag=0;

    if (flag == 1)
        printf("\n valid expression\n");

    else
        printf(" invalid expression\n");

    return 0;
}
