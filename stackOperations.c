// Design, Develop and Implement a menu driven Program in C for the following operations on
// STACK of Integers (Array Implementation of Stack with maximum size MAX)
//      a. Push an Element on to Stack
//      b. Pop an Element from Stack
//      c. Demonstrate how Stack can be used to check Palindrome
//      d. Demonstrate Overflow and Underflow situations on Stack
//      e. Display the status of Stack
//      f. Exit
// Support the program with appropriate functions for each of the above operations

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int STACK[MAX], top = -1;

int push(int);
int  pop();
void display();
void checkPalindrome();

int main() {
    int choice, item;
    while(1) {
        printf("\n1.Push  2.Pop  3.Display  4.Check Palindrome  5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
	    printf("\n");
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                push(item);
                if(item == -1)
		            printf("%d pushed to STACK\n", item);
                break;
            case 2:
                printf("%d Popped.\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                checkPalindrome();
                exit(0);
            case 5:
    	    	printf("Exiting.\n");
                exit(0);
            default:
                printf("\nInvalid choice:\n");
        }
    }
}

int push(int item) {
    if (top == (MAX - 1)) {
        printf("\nSTACK Overflow.");
        return -1;
    }
    else
        STACK[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("STACK Underflow.");
        return -1;
    } else
        return STACK[top--];
}

void display() {
    int i;
    if (top == -1)
        printf("\nSTACK is Empty.");
    else
        for (i = top; i >= 0; i--)
            printf("[%d]\n", STACK[i]);
}

void checkPalindrome() {
    int *TEMP, flag=1, i;
    TEMP = STACK;

    for (i = 0; i < (top-1); i++)
        if(TEMP[i] == pop())
            flag = 0;
        else
            flag = 1; 

    if(flag == 1)
        printf("Not a Palindrome\n");
    else
        printf("It is a Palindrome\n");
}
