#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char opstk[max],postfix[max],infix[max];
int top=-1;

void push(char opstk[],char symb);
int pop(char opstk[]);
int isop(char y);
int in_op_prec(char c);
int stk_prec(char stk);
int infixtopostfix(char infix[]);

main()
{
    printf("enter the infix expression:\n");
    gets(infix);
    infixtopostfix(infix);
    printf("the postfix expression is :\n");
    puts(postfix);
}

void push(char opstk[],char symb)
{
    if(top==max-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        top++;
        opstk[top]=symb;
    }
}

int pop(char opstk[])
{
    char symb;
    if(top==-1)
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        symb=opstk[top];
        top--;
        return symb;
    }
}

int isop(char y) {
    if((y=='+')||(y=='-')||(y=='/')||(y=='%')||(y=='*')||(y=='^')||(y=='(')||(y==')'))
        return 1;
    else
        return 0;
}

int in_op_prec(char c)
{
    switch(c)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '/':
    case '*':
    case '%':
        return 3;
        break;
    case '^':
        return 5;
        break;
    case '(':
        return 7;
        break;
    default:
        return -1;
        break;
    }
}

int stk_prec(char stk)
{
    switch(stk)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '/':
    case '*':
    case '%':
        return 4;
        break;
    case '^':
        return 6;
        break;
    case '(':
        return 0;
        break;
    default:
        return -1;
        break;
    }
}

int infixtopostfix(char infix[])
{
    int i=0,j=0;
    push(opstk,'(');
    while(infix[i]!='\0')
    {
        if(isop(infix[i])==0)
            postfix[j++]=infix[i];
        else if(infix[i]=='(')
            push(opstk,'(');
        else if(infix[i]==')')
        {
            while(opstk[top]!='(')
            {
                postfix[j++]=pop(opstk);
            }
            pop(opstk);
        }
        else if(isop(infix[i])==1)
        {
            if(in_op_prec(infix[i])>=stk_prec(opstk[top]))
            {
                push(opstk,infix[i]);
            }
            else
            {
                while(in_op_prec(infix[i])<=stk_prec(opstk[top]))
                {
                    postfix[j++]=pop(opstk);
                }
            }
        }

        i++;
    }
    push(opstk,')');
    postfix[j]='\0';
}

