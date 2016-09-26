#include <stdio.h>
#include <stdlib.h>

int hanoi(int num,char from,char to,char aux);

main() {
    int num;
    printf("Enter the Number of Disks:\n");
    scanf("%d",&num);
    if(num<=0)
        printf("Enter more than 0 \n");
    else {
        printf("The Sequence Involved is:\n");
        hanoi(num,'A','C','B');
    }
}

int hanoi(int num,char from,char to,char aux) {
    if(num==1) {
        printf("Moving Disk 1 from %c to %c \n",from,to);
    }
    else {
        hanoi(num-1,from,aux,to);

        printf("Moving Disk %d from %c to %c \n",num,from,to);

        hanoi(num-1,aux,to,from);
    }
}