// Design, Develop and Implement a Program for the following Stack Applications
//      a. Evaluation of Suffix expression with : 
//	   Single digit Operands and operators: +, -, *, /, %, ^
//      b. Solving Tower of Hanoi problem with n disks

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

float STACK[MAX];
int top = -1;

void  push(float[], float);
float pop(float[]);
float postEval(char[]);

int main() {
    char inpExp[100];
    printf("Enter 'postfix' Expression: ");
    gets(inpExp);
    printf("The Value of the 'postfix' Expression is: %.0f\n", postEval(inpExp));
}

void push(float STACK[],float val) {
    STACK[++top] = val;
}

float pop(float STACK[]) {
    return STACK[top--];
}

float postEval(char exp[]) {
    float value, op1, op2;
    int i = 0;
    while(exp[i] != '\0') {
        if(isdigit(exp[i]))
            push(STACK, (exp[i]-'0'));
        else {
            op2 = pop(STACK), op1 = pop(STACK);
            switch(exp[i]) {
                case '+': value = op1 + op2; break;
                case '-': value = op1 - op2; break;
                case '*': value = op1 * op2; break;
                case '/':
                    if(op2 == 0) {
                        printf("Divide by 0 Error.");
                        return;
                    }
                    else
                        value = op1 / op2;
                    break;
                case '%': value = (int)op1 % (int)op2;     break;
                case '^': value = pow((int)op1, (int)op2); break;
                default: value = 0;
            }
            push(STACK, value);
        } i++;
    }
    return pop(STACK);
}
