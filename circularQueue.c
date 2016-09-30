#include <stdio.h>
#define SIZE 10

int QUEUE[SIZE],f=-1,r=-1;
 
void insertElement(int elem) {
    if(isFull()) 
        printf("\nQueue Overflow.\n");
    else {
        if(f==-1)
            f=0;
        r=(r+1) % SIZE;
        QUEUE[r]=elem;
    }
}

int deleteElement() {
    int elem;
    if(isEmpty()) {
        printf("\nQueue Underflow.\n");
        return(-1); 
    }
    else {
        elem=QUEUE[f];
        if(f==r) { 
            f=-1;r=-1;
        }
        else
            f=(f+1) % SIZE;
        return(elem);
    }
}

int isFull() {
    if( (f==r+1) || (f == 0 && r== SIZE-1)) 
        return 1;
    return 0;
}
 
int isEmpty() {
    if(f== -1) 
        return 1;
    return 0;
}

void display() {
    int i;
    if(isEmpty()) printf("\nEmpty Queue\n");
    else {
        printf("Front[%d]->",f);
        for(i=f;i!=r;i=(i+1)%SIZE)
            printf("%d ",QUEUE[i]);
        printf("%d ",QUEUE[i]);
        printf("<-[%d]Rear\n",r);
    }
}

int main() {
    int opn,elem;
    printf("\n  Circular Queue Operations ");
    do {
        printf("\n1 - Insert  2 - Delete  3 - Display  4 - Exit\n");
        printf("Option : ");
        scanf("%d",&opn);
        switch(opn) {
            case 1: 
                printf("Enter the Element :");
                scanf("%d",&elem);
                insertElement(elem); 
                break;
            case 2: elem=deleteElement();
                if( elem != -1)
                    printf("\n%d Deleted. \n",elem);
                break;
            case 3: 
                printf("\nStatus : ");
                display(); 
                break;
            case 4: 
                printf("\nTerminating.\n"); 
                break;
            default: printf("\nInvalid Option.Try Again.\n");
                break;
        }
    }while(opn != 4);
}
