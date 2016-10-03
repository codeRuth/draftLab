#include <stdio.h>
#include <stdlib.h>
struct data {
	double SSN;
	char   *name;
	char   *deptName;
	char   *designationName;
	double totalSalary;
	double phoneNumber;
};
typedef struct data DATA;

struct NODE {
    DATA data;
    struct NODE* next;
    struct NODE* prev;
};
struct NODE* head;

struct NODE* getNewNode(DATA x) {
    struct NODE* newNode = (struct NODE*) malloc(sizeof(struct NODE));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(DATA x) {
    struct NODE* newNode = getNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(DATA x) {
    struct NODE* temp = head;
    struct NODE* newNode = getNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList() {
    struct NODE* temp = head;
    printf("SSN\tEmployee Name\tDepartment\tDesignation\tTotal Salary\tPhone Number\n");
    while(temp != NULL) {
        printf("%.0f   ", &temp->data.SSN);
        printf("%s     ", temp->data.name);
        printf("%s     ", temp->data.deptName);
        printf("%s     ", temp->data.designationName);
        printf("%.0f   ", &temp->data.totalSalary);
        printf("%.0f   ", &temp->data.phoneNumber);
        printf("\n");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    DATA sample;
    char choice;

    while(1) {
        printf("Enter Employee Records.\n\n");
        printf("SSN : ");scanf("%lf", &sample.SSN);
        printf("Employee Name : ");scanf("%s",  &sample.name);
        printf("Department    : ");scanf("%s",  &sample.deptName);
        printf("Designation   : ");scanf("%s",  &sample.designationName);
        printf("Total Salary  : ");scanf("%lf", &sample.totalSalary);
        printf("Phone Number  : ");scanf("%lf", &sample.phoneNumber);
        insertAtTail(sample);
        printf("Do You want to continue ? (Y/N) :\n");scanf("%s", &choice);
        if(choice=='Y'||choice == 'y') 
            continue;
        else if(choice=='N'||choice == 'n')
            break;
    }
    printList();
}
