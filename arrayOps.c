#include <stdio.h>
#include <stdlib.h>
int a[20], b[20], c[40];
int m, n, p, val, i, j, pos, temp;

void createArray();
void displayElements();
void insertElement();
void deleteElement();

int main() {
    int choice;
    do {
        printf("\n1.Create\n");
        printf("2.Display\n");
        printf("3.Insert\n");
        printf("4.Delete\n");
        printf("5.Exit\n");
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
            exit(0);
        default:
            printf("Invalid choice.");
        }
    } while (1);
    return 0;
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
    printf("The Array Elements are:\n");
    for (i = 0; i < n; i++) {
        printf("[%d]  ", i);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf(" %d   ", a[i]);
    }
}

void insertElement() {
    printf("Enter the Position for the Element: ");
    scanf("%d", &pos);
    printf("Enter the Element to be Inserted: ");
    scanf("%d", &val);
    for (i = n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    a[pos] = val;
    n = n + 1;
}

void deleteElement() {
    printf("Enter the Position for the Element: ");
    scanf("%d", &pos);
    val = a[pos];
    for (i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n = n-1;
    printf("The Deleted Element is : %d", val);
}