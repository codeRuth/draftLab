#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char STACK[MAX],POSTFIX[MAX],INFIX[MAX];
int top=-1;

void push(char STACK[],char ele);
char pop (char STACK[]);
int  prec(char);


main() {
    char ch,elem;
    int i=0,j=0;
    printf("Enter the INFIX Expression:\n");
    gets(INFIX);
    push(STACK,'#');
    while((ch=INFIX[i++])!='\0') {
        if(ch=='(')
            push(STACK,ch);
        else if(isalnum(ch))
            POSTFIX[j++]=ch;
        else if(ch==')') {
            while(STACK[top]!='(') {
                POSTFIX[j++]=pop(STACK);
            }
            elem=pop(STACK);
        }
        else {
            while(prec(STACK[top]) >= prec(ch))
                POSTFIX[j++] = pop(STACK);
            push(STACK, ch);
        }
    }

    while(STACK[top]!='#') {
        POSTFIX[j++]=pop(STACK);
    }
    POSTFIX[j]!='#';

    printf("The POSTFIX Expression is :\n");
    puts(POSTFIX);
}

void push(char STACK[],char ele) {
    STACK[top++]=ele;
}

char pop(char STACK[]) {
    return STACK[top--];
}


int prec(char ele) {
    switch(ele)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '/':
    case '*':
    case '%':
        return 3;
    case '^':
        return 4;
    default:
        return -1;
    }
}


