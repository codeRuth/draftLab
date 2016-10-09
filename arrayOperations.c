// Design, Develop and Implement a menu driven Program in C for the following Array operations
//      a. Creating an Array of N Integer Elements
//      b. Display of Array Elements with Suitable Headings
//      c. Inserting an Element (ELEM) at a given valid Position (POS)
//      d. Deleting an Element at a given valid Position(POS)
//      e. Exit.
// Support the program with functions for each of the above operations.

#include <stdio.h>
#include <stdlib.h>

int a[20], val, i, j, pos, temp, n;

void createArray();
void displayElements();
void insertElement();
void deleteElement();

int main() {
    int choice;
    do {
        printf("\n1.Create  2.Display  3.Insert  4.Delete  5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            createArray();
            break;
        case 2:
            displayElements();
            break;
        case 3:
            insertElement();
            break;
        case 4:
            deleteElement();
            break;
        case 5:
            printf("Exiting.\n");
            exit(0);
        default:
            printf("Invalid choice.");
        }
    } while (1);
}

void createArray() {
    printf("Enter vlaue of 'n':");
    scanf("%d", &n);
    printf("Enter %d Elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void displayElements() {
    int i;
    printf("\nThe Array Elements are:\n");
    for (i = 0; i < n; i++) {
        printf("[%d]  ", i);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf(" %d   ", a[i]);
    }
    printf("\n");
}

void insertElement() {
    printf("Enter the Position for the Element: ");
    scanf("%d", &pos);
    printf("Enter the Element to be Inserted: ");
    scanf("%d", &val);
    for (i = n-1; i >= pos; i--) {
        a[i+1] = a[i];
    }
    a[pos] = val;
    n = n+1;
}

void deleteElement() {
    printf("Enter the Position for the Element: ");
    scanf("%d", &pos);
    val = a[pos];
    for (i = pos; i < n-1; i++) {
        a[i] = a[i+1];
    }
    n = n-1;
    printf("The Deleted Element is : %d", val);
}
