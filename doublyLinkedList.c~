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

struct NODE* getNewNode(DATA *x) {
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = *x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(DATA *x) {
    struct NODE* newNode = getNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void insertAtTail(DATA *x) {
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
    while(temp != NULL) {
        printf("%.0f ",temp->data.SSN);
        printf("%s ",temp->data.name);
        printf("%s ",temp->data.deptName);
        printf("%s ",temp->data.designationName);
        printf("%.0f ",temp->data.totalSalary);
        printf("%.0f ",temp->data.phoneNumber);
        printf("\n");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    while (1) {
        DATA *sample = (DATA*) malloc(sizeof(DATA));
        printf("Enter Employee Details :\n");
        
        printf("SSN :\n");scanf("%lf", sample->SSN);
        printf("Name :\n");fgets(sample->name, sizeof(char*), stdin);
        printf("Department Name :\n");gets(sample->deptName);
        printf("Designation : :\n");scanf("%s", sample->designationName);
        printf("Total Salary :\n");scanf("%lf", sample->totalSalary);
        printf("Phone Number : \n");scanf("%lf", sample->phoneNumber);

        insertAtTail(sample);
        free(sample);
        printf("Do you want to Continue (Y/N)?\n");

        if(getchar() == 'Y')
            continue;
        else
            break;
    }
    
    // insertAtTail(sample);
    // insertAtHead(sample);
    // insertAtTail(sample);

    printList();
}