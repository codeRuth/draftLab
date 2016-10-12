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
typedef struct node NODE;

NODE* getNode() {
    NODE *x;
    x = (NODE*) malloc(sizeof(NODE));
    if(x == NULL) {
        printf("Insufficient Memory\n");
        exit(0);
    }
    return x;
}

void display(NODE *head) {
    NODE *temp;
    if(head->link == head) {
        printf("Polynomial does not Exist\n");
        return;
    }
    temp = head->link;
    printf("\n");
    while(temp != head) {
        printf("%d x^%d y^%d z^%d", temp->pCoeff, temp->pExpo.expX, temp->pExpo.expY, temp->pExpo.expZ);
        if(temp->link != head)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

NODE* insertRear(int pCoeff, int expX, int expY, int expZ, NODE *head) {
    NODE *temp, *cur;
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

NODE* readPoly(NODE *head) {
    int expX, expY, expZ, pCoeff, ch;
    do {
        printf("\nEnter Coefficient: ");
        scanf("%d", &pCoeff);
        printf("\nEnter Powers of x, y, z (0 - indicate No Term): ");
        scanf("%d %d %d", &expX, &expY, &expZ);
        head = insertRear(pCoeff, expX, expY, expZ, head);
        printf("\nIf you wish to continue press 1 otherwise 0: ");
        scanf("%d", &ch);
    } while(ch != 0);
    return head;
}

NODE* addPoly(NODE *h1, NODE *h2, NODE *h3) {
    NODE *polyOne, *polyTwo;
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
            if(eOne.expX == eTwo.expX && eOne.expY == eTwo.expY && eOne.expZ == eTwo.expZ)
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
            h3 = insertRear(polyTwo->pCoeff, polyTwo->pExpo.expX, polyTwo->pExpo.expY, polyTwo->pExpo.expZ, h3);
        polyTwo = polyTwo->link;
    }
    return h3;
}

void evaluate(NODE *h1) {
    NODE *head; EXPO temp;
    float result = 0.0; head = h1;
    printf("\nEnter x, y, z, terms to evaluate:\n");
    scanf("%d %d %d", &temp.expX, &temp.expY, &temp.expZ);
    while(h1->link != head) {
        result = result +
                ( h1->pCoeff *
                    pow(temp.expX, h1->pExpo.expX) *
                    pow(temp.expY, h1->pExpo.expY) *
                    pow(temp.expZ, h1->pExpo.expZ)
                );
        h1 = h1->link;
    }
    result = result +
             ( h1->pCoeff *
               pow(temp.expX, h1->pExpo.expX) *
               pow(temp.expY, h1->pExpo.expY) *
               pow(temp.expZ, h1->pExpo.expZ)
             );
    printf("\nPolynomial result is: %.)f", result);
}

void main() {
    NODE *h1, *h2, *h3;
    int ch;
    h1 = getNode(); h2 = getNode(); h3 = getNode();
    h1->link = h1; h2->link = h2; h3->link = h3;
    while(1) {
        printf("\n1.Read Polynomial  2.Display  3.Evaluate Polynomial  4.Add Two Polynomials  5.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: h1 = readPoly(h1); break;
            case 2: display(h1);       break;
            case 3:
                printf("\nEnter Polynomial to Evaluate:\n");
                h1 = readPoly(h1); display(h1); evaluate(h1);
                break;
            case 4:
                printf("\nEnter the First Polynomial:  "); h1 = readPoly(h1);
                printf("\nEnter the Second Polynomial: "); h2 = readPoly(h2);
                h3 = addPoly(h1, h2, h3);
                printf("\nFirst Polynomial is: ");  display(h1);
                printf("\nSecond Polynomial is: "); display(h2);
                printf("\nSum of the Two Polynomial is: "); display(h3);
                break;
            case 5: exit(0); break;
            default: printf("\nInvalid Entry");break;
        }
    }
}