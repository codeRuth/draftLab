// Design, Develop and Implement a Program in C for the following Stack Applications
// Solving Tower of Hanoi problem with 'n' disks 

#include <stdio.h>
#include <stdlib.h>

int hanoi(int num, char from, char to, char aux);

int main() {
    int num;
    printf("Enter the Number of Disks: ");
    scanf("%d",&num);
    if(num <= 0)
        printf("Enter more than 0 \n");
    else {
        printf("The Sequence Involved is:\n");
        hanoi(num, 'A', 'C', 'B');
    }
    return 0;
}

int hanoi(int num, char from, char to, char aux) {
    if(num == 1) {
        printf("Move Disk 1 from %c to %c \n", from, to);
    }
    else {
        hanoi( num-1, from, aux, to );
        printf("Move Disk %d from %c to %c \n", num, from, to);
        hanoi(num-1, aux, to, from);
    }
}