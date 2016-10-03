#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define max 100

float st[max];
int top=-1; 

void push(float st[],float val);
float pop(float st[]);
float posteval(char exp[]);

main()
{
 char exp[100];
 float val;
 printf("enter any postfix expression:\n");
 gets(exp);
 val=posteval(exp);
 printf("the value of the postfix expression is %f\n",val);
}

void push(float st[],float val)
{
  top++;
  st[top]=val;
 
}

float pop(float st[])
{ 
  float val;
  val=st[top];
  top--;
  return val;
 
}

float posteval(char exp[])
{
 float value,op1,op2;
 int i=0;
 while(exp[i]!='\0')
 {
  if(isdigit(exp[i]))
  {
   push(st,(exp[i]-'0'));
  }
  else
  {
   op2=pop(st);
   op1=pop(st);
   switch(exp[i])
   {
    case '+': value= op1+op2;
              break;
    case '-': value= op1-op2;
              break;
    case '*': value= op1*op2;
              break;
    case '/': value= op1/op2;
              break;
    case '%': value= (int)op1%(int)op2;
              break;
    case '^': value=pow((int)op1,(int)op2);
              break;
    default:  value= 0;
              break;
  }
  push(st,value);
 }
 i++;
 } 
 return pop(st);
} 
