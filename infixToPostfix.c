#include <stdio.h>
#include <ctype.h>
#define MAX 100

typedef struct STACK {
    int data[MAX];
    int top;
} STACK;

int  priority(char);
void initStack(STACK *);
int  empty(STACK *);
int  full(STACK *);
char pop(STACK *);
void push(STACK *,char);
char top(STACK *);

void main() {
    STACK s;
    char x, str[100];
    int token, i;
    initStack(&s);
    printf("Enter 'infix' Expression:");
    scanf("%s", str);
    for(i=0; str[i]!='\0'; i++) {
        token = str[i];
        if(isalnum(token))
            printf("%c",token);
        else if(token == '(')
            push(&s,'(');
        else {
            if(token == ')')
                while((x=pop(&s))!='(')
                    printf("%c",x);
            else {
                while(priority(token) <= priority(top(&s)) && !empty(&s)) {
                    x=pop(&s);
                    printf("%c",x);
                }
                push(&s,token);
            }
        }
    }
    while(!empty(&s)) {
        x=pop(&s);
        printf("%c\n",x);
    }
}
int priority(char x) {
    if(x == '(')
        return(0);
    if(x == '+' || x == '-')
        return(1);
    if(x == '*' || x == '/' || x == '%')
        return(2);
    return(3);
}

void initStack(STACK *s) {
    s->top=-1;
}

int empty(STACK *s) {
    if(s->top==-1)
        return(1);
    else
        return(0);
}

int full(STACK *s) {
    if(s->top==MAX-1)
        return(1);
    else
        return(0);
}

void push(STACK *s,char x) {
    s->top=s->top+1;
    s->data[s->top]=x;
}

char pop(STACK *s) {
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}

char top(STACK * s) {
    return(s->data[s->top]);
}