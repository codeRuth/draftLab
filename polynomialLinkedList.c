#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct poly {
    int c;
    int e;
    struct poly *link;
} POLY;

POLY* createNewNode() {
    POLY *nn=NULL;
    nn = (POLY*) malloc(sizeof(POLY));
    if(nn==NULL) {
        printf("Insufficient Memory !
            ");
        exit(1);
    }
    return(nn);
}

POLY* create() {
    POLY *hn=NULL,*nn=NULL,*cn=NULL;
    int i,n;
    printf("\nEnter number of Terms : ");
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        nn=createNewNode();
        printf("\nEnter Coefficient & Exponent : ");
        scanf("%d %d",&nn->c,&nn->e);

        if(hn==NULL) {
            hn=nn;
            cn=nn;
        }
        else {
            cn->link=nn;
            cn=nn;
        }
        nn->link=hn;
    }
    return(hn);
}

void display(POLY *hn) {
    POLY *cn=NULL;
    cn=hn;
    printf("\nEntered Polynomial is – ");
    do {
        printf("%dx^%d ",cn->c,cn->e);
        if(cn->link != hn) {
            printf(" + ");
        }
        cn=cn->link;
    }
    while(cn!=hn);
}

void evaluate(POLY *hn) {
    POLY *cn=hn;
    int x ,sum =0;
    printf("\n Enter value of x – ");
    scanf("%d",&x);
    do {
        sum=sum+(cn->c*pow(x,cn->e));
        cn=cn->link;
    }
    while(cn!=hn);
    printf("\n Evaluation is- %d",sum);
}

POLY* sameexpo(int c,int e,POLY *h3) {
    POLY *cn=NULL;
    cn=h3;
    if(h3==NULL) {
        return(NULL);
    }

    do {
        if(e==cn->e) {
            cn->c=c+cn->c;
            return(cn);
        }
        cn=cn->link;
    } while(cn!=h3);
    return(NULL);

}

POLY* addlastnode(POLY *nn, POLY *h3, POLY *last) {
    if(h3==NULL)
        h3=nn;
    else
        last->link=nn;

    nn->link=h3;
    return(h3);
}

POLY *addpoly(POLY *h1, POLY *h2) {
    POLY *p=NULL,*q=NULL,*nn=NULL;
    int c,e;
    POLY *h3=NULL;
    POLY *last=NULL;
    p=h1;
    q=h2;
    do {
        nn=createNewNode();
        h3=addlastnode(nn,h3,last);
        last=nn;
        if(p->e==q->e) {
            nn->c=p->c+q->c;
            nn->e=p->e;
            p=p->link;
            q=q->link;
        }
        else if(p->e > q->e) {
            nn->c=p->c;
            nn->e=p->e;
            p=p->link;
        }
        else {
            nn->c=q->c;
            nn->e=q->e;
            q=q->link;
        }
    } while(p->link!=h1 && q->link!=h2);


    while(p!=h1){   
        nn= createNewNode();
        h3=addlastnode(nn,h3,last);
        last=nn;
        nn->c=p->c;
        nn->e=p->e;
        p=p->link;
    }
    while(q!=h2) {
        nn=createNewNode();
        h3=addlastnode(nn,h3,last);
        last=nn;
        nn->c=q->c;
        nn->e=q->e;
        q=q->link;
    }
    return(h3);
}

void main() {
    POLY *hn=NULL, *h1=NULL, *h2=NULL;
    int ch;
    printf("\n—————POLYNOMIAL OPERATION———————");
    do {
        printf("\n\n 1.CREATE \n 2.DISPLAY \n 3.EVALUATE \n 4.ADD \n 5.EXIT");
        printf("\n Enter choice- ");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            hn=create();
            break;
        case 2:
            display(hn);
            break;
        case 3:
            evaluate(hn);
            break;
        case 4:
            h1=create();
            h2=create();
            hn=addpoly(h1,h2);
            display(hn);
            break;
        case 5:
            exit(0);;
        }
    }
    while(ch!=6);
}