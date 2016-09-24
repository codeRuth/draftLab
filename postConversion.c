#include <stdio.h>
#include <stdlib.h>
int top = -1, length, iinf = 0, ipostf = 0;
int precd(char);
char pop();
void inf_to_postf(char[], char[]);
void push(char);
char infix[20], postf[20], stk[20], sym;

int main() {
    printf("\nConversion of infix to postfix expression");
    printf("\nEnter the infix expression to be converted:");
    gets(infix);
    inf_to_postf(infix, postf);
    printf("\nEntered  infix expression is:%s ", infix);
    printf("\nConverted  infix to postfix expression is : %s \n", postf);
}

void inf_to_postf(char infix[], char postf[]) {
    char temp;
    push('#');
    while (infix[iinf] != '\0') {
        sym = infix[iinf];
        switch (sym) {

        case '(':
            push(sym);
            break;
        case ')':
            temp = pop();
            while (sym != '(') {
                postf[ipostf++] = temp;
                temp = pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (precd(stk[top]) >= precd(sym)) {
                temp = pop();
                postf[ipostf++] = temp;
            }
            push(sym);
            break;
        default:
            postf[ipostf++] = sym;
        }
        iinf++;
    }
    while (top > 0) {

        temp = pop();
        postf[ipostf++] = temp;
    }
}

void push(char x) {
    stk[++top] = x;
}

char pop() {
    int x;
    x = stk[top];
    top--;
    return x;
}