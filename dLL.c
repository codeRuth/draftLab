#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct data {
    double SSN;
    char   name[20];
    char   deptName[10];
    char   designationName[10];
    double totalSalary;
    double phoneNumber;
};
typedef struct data DATA;

struct NODE {
    DATA data;
    struct NODE *next;
    struct NODE *prev;
};

struct NODE *head = NULL;
struct NODE *last = NULL;
struct NODE *current = NULL;

bool isEmpty() {
    return head == NULL;
}

int length() {
    int length = 0;
    struct NODE *current;
    for(current = head; current != NULL; current = current->next) {
        length++;
    }
    return length;
}

void displayForward() {
    struct NODE *ptr = last;
    printf("SSN\tEmployee Name\tDepartment\tDesignation\tTotal Salary\tPhone Number\n");
    while(ptr != NULL) {
        printf("%.0lf   ", ptr->data.SSN);
        printf("%s      ", ptr->data.name);
        printf("%s      ", ptr->data.deptName);
        printf("%s      ", ptr->data.designationName);
        printf("%.0lf   ", ptr->data.totalSalary);
        printf("%.0lf   ", ptr->data.phoneNumber);
        printf("(%s) ", ptr->data.name);
        ptr = ptr->prev;
    }
}

void displayBackward() {
    struct NODE *ptr = last;
    printf("\n[ ");
    while(ptr != NULL) {
        printf("(%s) ", ptr->data.name);
        ptr = ptr ->prev;
        printf(" ");
    }
    printf(" ]");
}

void insertFirst(DATA data) {
    struct NODE *link = (struct NODE*) malloc(sizeof(struct NODE));
    link->data = data;

    if(isEmpty()) {
        last = link;
    } else {
        head->prev = link;
    }
    link->next = head;
    head = link;
}

void insertLast(DATA data) {
    struct NODE *link = (struct NODE*) malloc(sizeof(struct NODE));
    link->data = data;

    if(isEmpty()) {
        last = link;
    } else {
        last->next = link;
        link->prev = last;
    }
    last = link;
}

struct NODE* deleteFirst() {
    struct NODE *tempLink = head;
    if(head->next == NULL) {
        last = NULL;
    } else {
        head->next->prev = NULL;
    }
    head = head->next;
    return tempLink;
}

struct NODE* deleteLast() {
    struct NODE *tempLink = last;
    if(head->next == NULL) {
        head = NULL;
    } else {
        last->prev->next = NULL;
    }
    last = last->prev;
    return tempLink;
}

int main() {
    DATA sample;
    int option, i, n;

//    data.SSN = 321355153;
//    data.name = "Ruthvik";
//    data.deptName = "IT";
//    data.designationName = "Manager";
//    data.totalSalary = 500000;
//    data.phoneNumber = 8970464490;
    option = 1;
    switch(option) {
        case 1:
            printf("Enter no. Of Employee's :");
            scanf("%d", &n);
            for (i = 0; i < n; ++i) {
                printf("Enter Employee Records.\n\n");
                printf("SSN : ");           scanf("%lf", &sample.SSN);
                printf("Employee Name : "); scanf("%s",  sample.name);
                printf("Department    : "); scanf("%s",  sample.deptName);
                printf("Designation   : "); scanf("%s",  sample.designationName);
                printf("Total Salary  : "); scanf("%lf", &sample.totalSalary);
                printf("Phone Number  : "); scanf("%lf", &sample.phoneNumber);
                insertLast(sample);
            }
        case 2:
        case 3:
        case 4:
        case 5:;
    }

//    insertFirst(1,data);
//    insertFirst(2,data);
//    insertFirst(3,data);
//    insertFirst(4,data);
//    insertFirst(5,data);
//    insertFirst(6,data);

    //printf("\nList (First to Last): ");
    displayForward();
//
//    printf("\n");
//    printf("\nList (Last to first): ");
//    displayBackward();
//
//    printf("\nList , after deleting first record: ");
//    deleteFirst();
//    displayForward();
//
//    printf("\nList , after deleting last record: ");
//    deleteLast();
//    displayForward();
//    displayForward();
}

