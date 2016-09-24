#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int STACK[MAX], top = -1;

void push(int);
int pop();
void peep();
void display();
void checkPalindrome();

int main()
{
    int choice, item;
    while(1){
			printf("\n1.Push\n");
			printf("2.Pop\n");
			printf("3.Display\n");
			printf("4.Check Palindrome\n");
			printf("5.Exit\n");
			printf("\nEnter your choice: ");
			scanf("%d", &choice);
			switch (choice) {
				case 1:
					printf("Enter the element to be inserted: ");
					scanf("%d", &item);
				    push(item);
				    break;
				case 2:
					printf("%d Popped.", pop());
				    break;
				case 3:
				    display();
				    break;
				case 4:
				    checkPalindrome();
				    break;
				case 5:
				    exit(0);
				    break;
				default:
				    printf("\nInvalid choice:\n");
				    break;
			}
    }
    return 0;
}

void push(int item) {
    if (top == (MAX - 1)) {
		printf("\nSTACK Overflow:");
    } else {
		STACK[++top] = item;
    }
}

int pop() {
	int item;
    if (top == -1) {
		printf("STACK Underflow:");
		item = -1;
    } else {
		item = STACK[top--];
    }
    return item;
}

void display() {
    int i;
    if (top == -1) {
		printf("\nSTACK is Empty:");
    } else {
		for (i = top; i >= 0; i--) {
		    printf("%d\n", STACK[i]);
		}
    }
}

void checkPalindrome() {
	int TEMP[MAX], flag=1;
	for (int i=0;i<(top-1);i++) {
		TEMP[i]=pop();
	}
	for (int i=0;i<(top-1);i++) {
		if(STACK[i]==TEMP[i]) {
			flag=0;
		}
		else
			flag=1;
	}
	if(flag == 1) {
		printf("Not a Palindrome\n");
	} else {
		printf("It is a Palindrome\n");
	}
}
