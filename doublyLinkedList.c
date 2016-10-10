// Design, Develop and Implement a Program for the following Operations on
// Doubly Linked List (DLL) of Employee Data with the fields:
// SSN, Name, Dept, Designation, Sal, PhNo
//        a. Create a DLL of N Employees Data by using end insertion.
//        b. Display the status of DLL and count the number of nodes in it
//        c. Perform Insertion and Deletion at End of DLL
//        d. Perform Insertion and Deletion at Front of DLL
//        e. Demonstrate how this DLL can be used as Double Ended Queue
//        f. Exit

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data {
    double SSN;
    char   empName[20];
    char   deptName[10];
    char   designationName[10];
    double totalSalary;
    double phoneNumber;
};
typedef struct data DATA;

struct NODE  {
    DATA data;
    struct NODE *prev;
    struct NODE *next;
};
typedef struct NODE* NODE;

NODE first = NULL;
int count = 0;

NODE createNode() {
    DATA sample;

    printf("\nEnter Employee Details: \n");
    printf("SSN           : ");scanf("%lf", &sample.SSN);
    printf("Employee Name : ");scanf("%s" , sample.empName);
    printf("Department    : ");scanf("%s" , sample.deptName);
    printf("Designation   : ");scanf("%s" , sample.designationName);
    printf("Total Salary  : ");scanf("%lf", &sample.totalSalary);
    printf("Phone Number  : ");scanf("%lf", &sample.phoneNumber);

    NODE employeeNode;
    employeeNode = (NODE) malloc(sizeof(struct NODE));
    if(employeeNode== NULL) {
        printf("\nOut of Memory.");
        exit(0);
    }
    employeeNode->prev = NULL;
    employeeNode->next = NULL;
    employeeNode->data = sample;
    count++;
    return employeeNode;
}

NODE insertAtFront() {
    NODE temp;
    temp = createNode();
    if(first == NULL) {
        return temp;
    }
    temp->next = first;
    first->prev = temp;
    return temp;
}

NODE deleteAtFront() {
    NODE temp;

    if(first == NULL) {
        printf("\nDLL Empty");
        return NULL;
    }
    if(first->next== NULL) {
        printf("\nEmployee SSN: %.0f Deleted\n", first->data.SSN);
        free(first);
        count--;
        return NULL;
    }
    temp = first; first = first->next; temp->next = NULL;
    first->prev = NULL;
    printf("\nEmployee SSN: %.0f Deleted\n", temp->data.SSN);
    free(temp); count--;
    return first;
}

NODE insertAtEnd() {
    NODE cur, temp;
    temp = createNode();
    if(first == NULL) {
        return temp;
    }
    cur = first;
    while(cur->next!=NULL) {
        cur = cur->next;
    }
    cur->next = temp; temp->prev = cur;
    return first;
}

NODE deleteAtEnd() {
    NODE prev, cur;
    if(first == NULL) {
        printf("\nDLL Empty");
        return NULL;
    }
    if(first->next == NULL) {
        printf("\nEmployee SSN: %.0f Deleted\n", first->data.SSN);
        free(first);
        count--;
        return NULL;
    }
    prev = NULL; cur = first;
    while(cur->next!=NULL) {
        prev = cur;
        cur = cur->next;
    }
    cur->prev = NULL;
    printf("\nEmployee SSN: %.0f Deleted\n", cur->data.SSN);
    free(cur); prev->next = NULL; count--;
    return first;
}

void displayStatus() {
    NODE cur; int nodeNo=1; cur = first;
    printf("\nSl. No.\tSSN\tName\tDepartment\tDesignation\tSalary\tPhone No.\n");
    if(cur == NULL)
        printf("\nNo Contents to Display.");
    while(cur!=NULL) {
        printf("%.0f\t", cur->data.SSN);
        printf("%s\t"  , cur->data.empName);
        printf("%s\t"  , cur->data.deptName);
        printf("%s\t"  , cur->data.designationName);
        printf("%.0f\t", cur->data.totalSalary);
        printf("%.0f\t", cur->data.phoneNumber);
        printf("\n");
        cur = cur->next;
        nodeNo++;
    }
    printf("\nNo. of Employee Records %d\n", count);
}

void doubleEndedQueueDemo() {
    int ch;
    while(1) {
        printf("\nDeQueue Demo.\n");
        printf("1: Insert Front  ");
        printf("2: Delete Front  ");
        printf("3: Insert Rear  ");
        printf("4: Delete Rear  ");
        printf("5: Display  ");
        printf("6: Exit\n");
        printf("Enter your Choice :");
        scanf("%d", &ch);
        switch(ch) {
            case 1: first = insertAtFront(); break;
            case 2: first = deleteAtFront(); break;
            case 3: first = insertAtEnd();   break;
            case 4: first = deleteAtEnd();   break;
            case 5: displayStatus();         break;
            default : return;
        }
    }
}

void main() {
    int ch, i, n;
    while(1) {
        printf("\n1: Create Employee Node.");
        printf("\n2: Display Status.");
        printf("\n3: Insert At End.");
        printf("\n4: Delete At End.");
        printf("\n5: Insert At Front.");
        printf("\n6: Delete At Front.");
        printf("\n7: DEQUEUE Demo.");
        printf("\n8: Exit. \n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1 :
                printf("\nEnter the No of Employees: ");
                scanf("%d", &n);
                for(i=1; i<=n; i++)
                    first = insertAtEnd();
                break;
            case 2: displayStatus();         break;
            case 3: first = insertAtEnd();   break;
            case 4: first = deleteAtEnd();   break;
            case 5: first = insertAtFront(); break;
            case 6: first = deleteAtFront(); break;
            case 7: doubleEndedQueueDemo();  break;
            case 8: exit(0);
            default: printf("\nPlease Enter the valid choice");
        }
    }
}
