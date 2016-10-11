// Design, Develop and Implement a Program in C for the following operations on
// Singly Linked List of Student Data with the fields: USN, Name, Branch, Sem, PhNo
//        a. Create a SLL of N Students Data by using front insertion.
//        b. Display the status of SLL and count the number of nodes in it
//        c. Perform Insertion and Deletion at End of SLL
//        d. Perform Insertion and Deletion at Front of SLL
//        e. Demonstrate how this SLL can be used as STACK and QUEUE
//        f. Exit

#include <stdio.h>
#include <stdlib.h>

struct data {
    char   USN[200];
    char   studentName[20];
    char   branchName[20];
    int    currentSem;
    double phoneNumber;
};
typedef struct data DATA;

struct node {
    DATA data;
    struct node *link;
};
typedef struct node* NODE;

NODE first = NULL;
int count = 0;

NODE createNode() {
    DATA sample;
    printf("\nEnter Student Details: \n");
    printf("USN           : "); scanf("%s" , sample.USN);
    printf("Student Name  : "); scanf("%s" , sample.studentName);
    printf("Branch        : "); scanf("%s" , sample.branchName);
    printf("Semester      : "); scanf("%d" , &sample.currentSem);
    printf("Phone Number  : "); scanf("%lf", &sample.phoneNumber);

    NODE studentNode;
    studentNode = (NODE) malloc(sizeof(struct node));
    if(studentNode == NULL) {
        printf("\nMemory not Available.");
        exit(0);
    }

    studentNode->data = sample; count++;
    return studentNode;
}

NODE insertAtFront() {
    NODE temp; 
    temp = createNode();
    if(first == NULL) {
        temp->link = NULL;
        return temp;
    }
    temp->link = first;
    return temp;
}

NODE deleteAtFront() {
    NODE temp;
    if(first == NULL) {
        printf("\nLinked List is Empty");
        return NULL;
    }
    if(first->link == NULL) {
        printf("\nThe Student USN: %s Deleted.", first->data.USN);
        count--;
        free(first);
        return NULL;
    }
    temp = first; first = first->link;
    printf("\nThe Student USN: %s Deleted.", temp->data.USN);
    count--; free(temp);
    return first;
}

NODE insertAtEnd() {
    NODE cur, temp;
    temp = createNode(); temp->link = NULL;
    if(first == NULL) {
        return temp;
    }
    if(first->link == NULL) {
        first->link = temp;
        return first;
    }
    cur = first;
    while(cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE deleteAtEnd() {
    NODE cur, prev;
    if(first == NULL) {
        printf("\nLinked List Empty.");
        return NULL;
    }
    if(first->link == NULL) {
        printf("\nThe Student USN: %s Deleted.", first->data.USN);
        free(first); count--;
        return NULL;
    }
    prev = NULL; cur = first;
    while(cur->link!=NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("\nThe Student USN: %s Deleted.", cur->data.USN);
    free(cur); 
    prev->link = NULL; count--;
    return first;
}

void displayStatus() {
    NODE cur;
    int nodeNo = 1; 
    cur = first;
    printf("\nThe Contents of SLL: \n");
    printf("\nSl. No.   USN         Name      Branch    Semester Phone No. \n");
    if(cur == NULL)
        printf("\nNo Contents in SLL. \n");
    while(cur!=NULL) {
        printf("%-10d", nodeNo);
        printf("%-12s", cur->data.USN);
        printf("%-10s", cur->data.studentName);
        printf("%-10s", cur->data.branchName);
        printf("%-10d", cur->data.currentSem);
        printf("%.0lf\t", cur->data.phoneNumber);
        cur = cur->link; nodeNo++;
    }
    printf("\nNo of Student Nodes is %d \n", count);
}

void stackDemoUsingSLL() {
    int ch;
    printf("\n------------Stack Demo using SLL------------");
    while(1) {
        printf("\n1:Push operation  2:Pop operation  3:Display  4:Exit \n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: first = insertAtFront(); break;
            case 2: first = deleteAtFront(); break;
            case 3: displayStatus();         break;
            case 4: return;
            default: return;
        }
    }
}

void main() {
    int ch, i, n;
    while(1) {
        printf("\n---------------MENU----------------");
        printf("\nEnter your choice for SLL operation \n");
        printf("\n1: Create Student Node.");
        printf("\n2: Display Status.");
        printf("\n3: Insert At End.");
        printf("\n4: Delete At End.");
        printf("\n5: Stack Demo using SLL.");
        printf("\n6: Exit. \n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch) {
            case 1 :
                printf("\nEnter the No. of Students: "); scanf("%d", &n);
                for(i=1; i<=n; i++)
                    first = insertAtFront();
                break;
            case 2: displayStatus();       break;
            case 3: first = insertAtEnd(); break;
            case 4: first = deleteAtEnd(); break;
            case 5: stackDemoUsingSLL();   break;
            case 6: exit(0);
            default: printf("\nPlease Enter the Valid Choice");
        }
    }
}
