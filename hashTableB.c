#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Employee {
    int  SSN;
    char empName[20];
    char nDept[10];
};
typedef struct Employee EMP;

EMP hashTable[MAX]; int a[MAX];

int createTable(int num) {
    int key;
    key = num % 100;
    return key;
}

int getEmp(EMP hashTable[], int key) {
    printf("Enter Employee Details : \n");
    printf("ID: ");   scanf("%d", &hashTable[key].SSN);
    printf("Name: "); scanf("%s", hashTable[key].empName);
    printf("Department: "); scanf("%s", hashTable[key].nDept);
    return key;
}

void displayTable() {
    int i, ch;
    mark:
    printf("\n1.Display All\n2.Filtered Display\n3.Exit");
    printf("\nEnter your Choice: "); scanf("%d", &ch);
    switch(ch) {
        case 1:
            printf("\nThe Hash Table :\n");
            printf("\nKey\tSSN\tEmpName\tDepartment");
            for(i=0; i<MAX; i++)
                printf("\n%d\t%d\t%s\t%s", i, hashTable[i].SSN, hashTable[i].empName, hashTable[i].nDept);
            goto mark;
        case 2:
            printf("\nThe Hash Table :\n");
            printf("\nKey\tSSN\tEmpName\tDepartment");
            for(i=0; i<MAX; i++)
                if(a[i] != -1) {
                    printf("\n%d\t%d\t%s\t%s", i, hashTable[i].SSN, hashTable[i].empName, hashTable[i].nDept);
                    continue;
                }
            goto mark;
        case 3:
            exit(0);
        default: printf("Enter Correct Option"); goto mark;
    }
}

void linearProbe(int key, int num) {
    int flag, i, count = 0; flag = 0;
    if(a[key] == -1) {
        a[key] = getEmp(hashTable, key);
    }
    else {
        printf("\nCollision Detected...!!!\n");
        i = 0;
        while(i < MAX) {
            if (a[i] != -1)
                count++;
            else
                i++;
        }
        printf("Collision avoided successfully using LINEAR PROBING\n");
        if(count == MAX) {
            printf("\n Hash table is full");
            displayTable(hashTable);
            exit(1);
        }
        for(i=key; i<MAX; i++)
            if(a[i] == -1) {
                a[i] = num; flag = 1;
                break;
            }
        i = 0;
        while((i < key) && (flag == 0)) {
            if(a[i] == -1) {
                a[i] = num; flag=1;
                break;
            } i++;
        }
    }
}
void main() {
    int num, key, i;
    int ans = 1;
    printf("\n - Hash Table Demo - ");
    for (i=0; i < MAX; i++) {
        a[i] = -1;
    }
    do {
        printf("\nEnter Index: "); scanf("%d", &num);
        key = createTable(num); linearProbe(key,num);
        printf("\nDo you wish to continue? (1/0): "); scanf("%d",&ans);
    } while(ans);
    displayTable(hashTable);
}

