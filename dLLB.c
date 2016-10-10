#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

NODE createEmployeeNode() {
    DATA sample;
    printf("Enter Employee Details: \n");
    printf("SSN           : ");scanf("%lf", &sample.SSN);
    printf("Employee Name : ");scanf("%s ", sample.empName);
    printf("Department    : ");scanf("%s ", sample.deptName);
    printf("Designation   : ");scanf("%s ", sample.designationName);
    printf("Total Salary  : ");scanf("%lf", &sample.totalSalary);
    printf("Phone Number  : ");scanf("%lf", &sample.phoneNumber);
    //scanf("%s %s %s %s %d %ld",SSN,empName,deptName,designationName,&totalSalary,&phoneNumber);
    NODE employeeNode;
    employeeNode = (NODE) malloc(sizeof(struct NODE));
    if(employeeNode== NULL) {
        printf("\nOut of Memory.");
        exit(0);
    }
    employeeNode->prev = NULL;
    employeeNode->next = NULL;
    employeeNode->data = sample;
//    strcpy(employeeNode->SSN, SSN);
//    strcpy(employeeNode->empName, empName);
//    strcpy(employeeNode->deptName, deptName);
//    strcpy(employeeNode->designationName, designationName);
//    employeeNode->totalSalary = totalSalary;
//    employeeNode->phoneNumber = phoneNumber;
    count++;
    return employeeNode;
}
NODE insertAtFront()
{
    NODE temp;
    temp = createEmployeeNode();
    if(first == NULL)
    {
        return temp;
    }
    temp->next = first;
    first->prev = temp;
    return temp;
}
NODE deleteAtFront()
{
    NODE temp;
    if(first == NULL)
    {
        printf("\nDoubly Linked List is empty");
        return NULL;
    }
    if(first->next== NULL)
    {
        printf("\nThe employee node with the SSN:%s is deleted", first->SSN);
        free(first);
        count--;
        return NULL;
    }
    temp = first;
    first = first->next;
    temp->next = NULL;
    first->prev = NULL;
    printf("\nThe employee node with the SSN:%s is deleted", temp->SSN);
    free(temp);
    count--;
    return first;
}

NODE insertAtEnd()
{
    NODE cur, temp;
    temp = createEmployeeNode();
    if(first == NULL)
    {
        return temp;
    }
    cur = first;
    while(cur->next!=NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
    return first;
}
NODE deleteAtEnd()
{
    NODE prev, cur;
    if(first == NULL)
    {
        printf("\nDoubly Linked List is empty");
        return NULL;
    }
    if(first->next == NULL)
    {
        printf("\nThe employee node with the SSN:%s is deleted", first->SSN);
        free(first);
        count--;
        return NULL;
    }
    prev = NULL;
    cur = first;
    while(cur->next!=NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    cur->prev = NULL;
    printf("\nThe employee node with the SSN:%s is deleted", cur->SSN);
    free(cur);
    prev->next = NULL;
    count--;
    return first;
}
void displayStatus()
{
    NODE cur;
    int nodeno=1;
    cur = first;

    if(cur == NULL)
        printf("\nNo Contents to display in DLL");
    while(cur!=NULL)
    {
        printf("\nENode:%d|| SSN:%s| Name:%s| Department:%s| Designation:%s|                                                 Salary:%d| Phone no:%ld", nodeno, cur->SSN, cur->empName, cur->deptName,                                               cur->designationName, cur->totalSalary, cur->phoneNumber);
        cur = cur->next;
        nodeno++;
    }
    printf("\nNo of employee nodes is %d",count);
}

void doubleEndedQueueDemo()
{
    int ch;
    while(1)
    {
        printf("\nDemo Double Ended Queue Operation");
        printf("\n1:InsertQueueFront \n2: DeleteQueueFront \n3:InsertQueueRear                                                  \n4:DeleteQueueRear \n5:DisplayStatus \n6: Exit \n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                first = insertAtFront();
                break;
            case 2:
                first = deleteAtFront();
                break;
            case 3:
                first = insertAtEnd();
                break;
            case 4:
                first = deleteAtEnd();
                break;
            case 5:
                displayStatus();
                break;
            default :
                return;
        }
    }
}
void main()
{
    int ch, i, n;
    while(1)
    {
        printf("\n\n~~~Menu~~~");
        printf("\n1:Create DLL of Employee Nodes");
        printf("\n2:DisplayStatus");
        printf("\n3:InsertAtEnd");
        printf("\n4:DeleteAtEnd");
        printf("\n5:InsertAtFront");
        printf("\n6:DeleteAtFront");
        printf("\n7:Double Ended Queue Demo using DLL");
        printf("\n8:Exit \n");
        printf("\nPlease enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 :
                printf("\nEnter the no of Employees:   ");
                scanf("%d", &n);
                for(i=1; i<=n; i++)
                    first = insertAtEnd();
                break;
            case 2:
                displayStatus();
                break;
            case 3:
                first = insertAtEnd();
                break;
            case 4:
                first = deleteAtEnd();
                break;
            case 5:
                first = insertAtFront();
                break;
            case 6:
                first = deleteAtFront();
                break;
            case 7:
                doubleEndedQueueDemo();
                break;
            case 8 :
                exit(0);
            default:
                printf("\nPlease Enter the valid choice");
        }
    }
}