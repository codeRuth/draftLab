// Design, Develop and Implement a Program for the following operations on 
// Singly Circular Linked List (SCLL) with header nodes
//      a. Represent and Evaluate a Polynomial 
//         P(x,y,z) = 6x^2^y^2^z - 4yz^5 + 3x^3^yz + 2xy^5^z - 2xyz^3
//      b. Find the sum of polynomials POLY1(x,y,z) and POLY2(x,y,z) and store 
//         the result in POLYSUM(x,y,z)
// Support the program with appropriate functions for each of the above operations

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pExponent{
    int expX;
    int expY;
    int expZ;
};
typedef struct pExponent EXPO;

struct node {
    int pCoeff;
    int flag;
    EXPO pExpo;
    struct node *link;
};
typedef struct node POLY;

POLY* getNode() {
    POLY *x;
    x = (POLY*) malloc(sizeof(POLY));
    if(x == NULL) {
        printf("Insufficient Memory\n");
        exit(0);
    }
    return x;
}

void displayPoly(POLY *head) {
    POLY *temp;
    if(head->link == head) {
        printf("Polynomial does not Exist\n");
        return;
    }

    temp = head->link;
    while(temp != head) {
        printf("%d(x^%d y^%d z^%d)", temp->pCoeff, temp->pExpo.expX, 
				     temp->pExpo.expY, temp->pExpo.expZ);
        if(temp->link != head)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

POLY* insertRear(int pCoeff, int expX, int expY, int expZ, POLY *head) {
    POLY *temp, *cur;
    temp = getNode();
    temp->pCoeff = pCoeff;
    temp->pExpo.expX = expX; temp->pExpo.expY = expY; temp->pExpo.expZ = expZ;
    cur = head->link;

    while(cur->link != head) {
        cur = cur->link;
    }
    cur->link = temp; temp->link = head;
    return head;
}

POLY* readPoly(POLY *head) {
    int expX, expY, expZ, pCoeff, n, i;
    printf("\nEnter the Number of Terms: ");
    scanf("%d", &n);
    for(i = 1; i<=n; i++) {
        printf("Enter Coefficient: ");
        scanf("%d", &pCoeff);
        printf("Enter Powers of x, y, z (0 - indicates No Term): \n");
        scanf("%d %d %d", &expX, &expY, &expZ);
        head = insertRear(pCoeff, expX, expY, expZ, head);
    }
    return head;
}

POLY* addPoly(POLY *h1, POLY *h2, POLY *h3) {
    POLY *polyOne, *polyTwo;
    EXPO eOne, eTwo;
    int pCoeffOne, pCoeffTwo, pCoeff;
    polyOne = h1->link;
    while(polyOne != h1) {
        eOne.expX = polyOne->pExpo.expX;
        eOne.expY = polyOne->pExpo.expY;
        eOne.expZ = polyOne->pExpo.expZ;
        pCoeffOne = polyOne->pCoeff;

        polyTwo = h2->link;
        while(polyTwo != h2) {
            eTwo.expX = polyTwo->pExpo.expX;
            eTwo.expY = polyTwo->pExpo.expY;
            eTwo.expZ = polyTwo->pExpo.expZ;
            pCoeffTwo = polyTwo->pCoeff;
            if(	eOne.expX == eTwo.expX &&
		eOne.expY == eTwo.expY && 
		eOne.expZ == eTwo.expZ )
                break;
            polyTwo = polyTwo->link;
        }

        if(polyTwo != h2) {
            pCoeff = pCoeffOne + pCoeffTwo;
            polyTwo->flag = 1;
            if(pCoeff != 0)
                h3 = insertRear(pCoeff, eOne.expX, eOne.expY, eOne.expZ, h3);
        }
        else
            h3 = insertRear(pCoeffOne, eOne.expX, eOne.expY, eOne.expZ, h3);
        polyOne = polyOne->link;
    }
    polyTwo = h2->link;
    while(polyTwo != h2) {
        if(polyTwo->flag == 0)
            h3 = insertRear(polyTwo->pCoeff, polyTwo->pExpo.expX, 
			    polyTwo->pExpo.expY, polyTwo->pExpo.expZ, h3);
        polyTwo = polyTwo->link;
    }
    return h3;
}

void evaluate(POLY *h1) {
    POLY *head; EXPO temp;
    float result = 0.0; head = h1;
    printf("\nEnter x, y, z, terms to evaluate:\n");
    scanf("%d %d %d", &temp.expX, &temp.expY, &temp.expZ);
    while(h1->link != head) {
        result = result + (h1->pCoeff *
                 pow(temp.expX, h1->pExpo.expX) *
                 pow(temp.expY, h1->pExpo.expY) *
                 pow(temp.expZ, h1->pExpo.expZ));
        h1 = h1->link;
    }
    result = result + (h1->pCoeff *
              pow(temp.expX, h1->pExpo.expX) *
              pow(temp.expY, h1->pExpo.expY) *
              pow(temp.expZ, h1->pExpo.expZ));
    printf("\nPolynomial result is: %.0f", result);
}

void main() {
    POLY *h1, *h2, *h3;
    int ch;
    h1 = getNode(); h2 = getNode(); h3 = getNode();
    h1->link = h1; h2->link = h2; h3->link = h3;
    while(1) {
        printf("\n1.Read Polynomial  2.Display  3.Evaluate Polynomial  4.Add Two Polynomials  5.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: h1 = readPoly(h1); break;
            case 2: displayPoly(h1);   break;
            case 3:
                printf("\nEnter Polynomial to Evaluate:");
                h1 = readPoly(h1); displayPoly(h1); evaluate(h1);
                break;
            case 4:
                printf("\nEnter the First Polynomial:  "); h1 = readPoly(h1);
                printf("\nEnter the Second Polynomial: "); h2 = readPoly(h2);
                h3 = addPoly(h1, h2, h3);
                printf("\nFirst Polynomial is: ");  displayPoly(h1);
                printf("\nSecond Polynomial is: "); displayPoly(h2);
                printf("\nSum of the Two Polynomial is: "); displayPoly(h3);
                break;
            case 5: exit(0); break;
            default: printf("\nInvalid Entry");break;
        }
    }
}
