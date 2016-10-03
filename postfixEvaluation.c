#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define max 100

float st[max];
int top=-1;

void push(float st[],float val);
float pop(float st[]);
float postEval(char exp[]);

int main() {
    char exp[100];
    float val;
    printf("Enter 'postfix' Expression:\n");
    gets(exp);
    val = postEval(exp);
    printf("The Value of the 'postfix' Expression is: %.0f\n",val);
}

void push(float st[],float val) {
    top++;
    st[top]=val;

}

float pop(float st[]) {
    float val;
    val=st[top];
    top--;
    return val;

}

float postEval(char exp[]) {
    float value,op1,op2;
    int i=0;
    while(exp[i]!='\0') {
        if(isdigit(exp[i])) {
            push(st,(exp[i]-'0'));
        }
        else {
            op2=pop(st);
            op1=pop(st);
            switch(exp[i]) {
            case '+':
                value= op1+op2;
                break;
            case '-':
                value= op1-op2;
                break;
            case '*':
                value= op1*op2;
                break;
            case '/':
                value= op1/op2;
                break;
            case '%':
                value= (int)op1%(int)op2;
                break;
            case '^':
                value=pow((int)op1,(int)op2);
                break;
            default:
                value= 0;
                break;
            }
            push(st,value);
        }
        i++;
    }
    return pop(st);
}
