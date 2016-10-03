#include <stdio.h>
#include <math.h>
typedef struct poly {
    int c;
    int e;
    struct poly *link;
} POLY;

POLY* createnewnode()
{
    POLY *nn=NULL;
    nn=(POLY*)malloc(sizeof(POLY));
    if(nn==NULL) {
        printf("\n Insufficient Memory ! ");
        exit(1);
    }
    return(nn);
}

POLY* create() {
    POLY *hn=NULL,*nn=NULL,*cn=NULL;
    int i,n;
    printf("\n Enter how many terms- ");
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        nn=createnewnode();
        printf("\n Enter coefficient & exponent – ");
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

void display(POLY *hn)
{
    POLY *cn=NULL;
    cn=hn;
    printf("\n entered polynomial is – ");
    do
    {
        printf(” %dx^%d ",cn->c,cn->e);
        if(cn->link != hn)
        {
            printf(” + ");
        }
        cn=cn->link;
    }
    while(cn!=hn);
}

void evaluate(POLY *hn)
{
    POLY *cn=hn;
    int x ,sum =0;
    printf("\n Enter value of x – ");
    scanf("%d”,&x);
    do
    {
        sum=sum+(cn->c*pow(x,cn->e));
        cn=cn->link;
    }
    while(cn!=hn);
    printf("\n Evaluation is- %d”,sum);
}

POLY* sameexpo(int c,int e,POLY *h3)
{
    POLY *cn=NULL;
    cn=h3;
    if(h3==NULL)
    {
        return(NULL);
    }

    do
    {
        if(e==cn->e)
        {
            cn->c=c+cn->c;
            return(cn);
        }
        cn=cn->link;
    } while(cn!=h3);
    return(NULL);

}

POLY* addlastnode(POLY *nn,POLY *h3,POLY *last)
{
    if(h3==NULL)
    {
        h3=nn;

    }
    else
    {
        last->link=nn;

    }
    nn->link=h3;
    return(h3);
}

POLY* multipoly(POLY *h1,POLY *h2)
{
    POLY *p=NULL,*q=NULL,*nn=NULL;
    int c=0,e=0;
    POLY *h3=NULL;
    POLY *last=NULL;
    p=h1;
    q=h2;
    do
    {
        do
        {
            c=p->c*q->c;
            e=p->e+q->e;
            nn=sameexpo(c,e,h3);
            if(nn!=NULL)
            {
                nn->c=nn->c +c;
            }
            else
            {
                nn=createnewnode();
                h3=addlastnode(nn,h3,last);
                last=nn;
                nn->c=c;
                nn->e=e;
            }
            q=q->link;
        } while(q!=h2);
        p=p->link;
    } while(p!=h1);
    return(h3);
}

POLY *addpoly(POLY *h1, POLY *h2)
{
    POLY *p=NULL,*q=NULL,*nn=NULL;
    int c,e;
    POLY *h3=NULL;
    POLY *last=NULL;
    p=h1;
    q=h2;
    do
    {
        nn=createnewnode();
        h3=addlastnode(nn,h3,last);
        last=nn;
        if(p->e==q->e)
        {
            nn->c=p->c+q->c;
            nn->e=p->e;
            p=p->link;
            q=q->link;
        }
        else if(p->e > q->e)
        {
            nn->c=p->c;
            nn->e=p->e;
            p=p->link;
        }
        else
        {
            nn->c=q->c;
            nn->e=q->e;
            q=q->link;
        }
    } while(p->link!=h1 && q->link!=h2);

//end while

    while(p!=h1)
    {   nn= createnewnode();
        h3=addlastnode(nn,h3,last);
        last=nn;
        nn->c=p->c;
        nn->e=p->e;
        p=p->link;
    }
    while(q!=h2)
    {
        nn=createnewnode();
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
        printf("\n\n 1.CREATE \n 2.DISPLAY \n 3.EVALUATE \n 4.MULTIPLY \n 5.ADD \n 6.EXIT");
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
            hn=multipoly(h1,h2);
            display(hn);
            break;
        case 5:
            h1=create();
            h2=create();
            hn=addpoly(h1,h2);
            display(hn);
            break;
        case 6:
            exit(0);;
        }
    }
    while(ch!=6);
}