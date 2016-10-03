/*-------------------------------------------------------------------------------------------------
Program    : Represent polynomial using circular linked list & write a menu
                     driven program to perform Addition,Multiplication & Evaluation.
Created By : JABIR DAUD PATHAN
Branch     : COMPUTER ENGINEERING
----------------------------------------------------------------------------------------------------*/

/*--------------------<<  Header File  >>---------------------*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<math.h>

/*-----<< Global Declaration of Structure and Functions  >>-------*/

typedef struct node
{
    int expo,coef;
    struct node *next;
} node;

node * insert(node *,int,int);
node * create();
node * add(node *p1,node *p2);
node * multi(node *p1,node *p2);
int eval(node *p1);
void display(node *head);

/*--------------<< function defination for insert >>---------------*/

node *insert(node*head,int expo1,int coef1)
{
    node *p,*q;
    p=(node *)malloc(sizeof(node));
    p->expo=expo1;
    p->coef=coef1;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        head->next=head;
        return(head);
    }
    if(expo1>head->expo)
    {
        p->next=head->next;
        head->next=p;
        head=p;
        return(head);
    }
    if(expo1==head->expo)
    {
        head->coef=head->coef+coef1;
        return(head);
    }
    q=head;
    while(q->next!=head&&expo1>=q->next->expo)
        q=q->next;
    if(p->expo==q->expo)
        q->coef=q->coef+coef1;
    else
    {
        p->next=q->next;
        q->next=p;
    }
    return(head);
}

/*---------<< function defination for create poly >>-------------*/

node *create()
{
    int n,i,expo1,coef1;
    node *head=NULL;
    printf("\n\nEnter no of terms of polynomial==>");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\n\nEnter coef & expo==>");
        scanf("%d%d",&coef1,&expo1);
        head=insert(head,expo1,coef1);
    }
    return(head);
}

/*------------<< function defination for add poly >>-------------*/

node *add(node *p1,node *p2)
{
    node *p;
    node *head=NULL;
    printf("\n\n\nAddition of polynomial==>");
    p=p1->next;
    do
    {
        head=insert(head,p->expo,p->coef);
        p=p->next;
    } while(p!=p1->next);
    p=p2->next;
    do
    {
        head=insert(head,p->expo,p->coef);
        p=p->next;
    } while(p!=p2->next);
    return(head);
}

/*---------<< function defination for multiply poly >>------------*/

node *multi(node *p1,node *p2)
{
    node *head1,*head2;
    node *head=NULL;
    printf("\n\n\nMultiplication of polynomial==>");
    head2=p2->next;
    do
    {
        head1=p1->next;
        do
        {
            head=insert(head,head1->expo+head2->expo,head1->coef*head2->coef);
            head1=head1->next;
        } while(head1!=p1->next);
        head2=head2->next;
    } while(head2!=p2->next);
    return(head);
}

/*--------<< function defination for evaluate poly >>--------------*/

int eval(node *head)
{
    node *p;
    int x,ans=0;
    printf("\n\nEnter the value of x=");
    scanf("%d",&x);
    p=head->next;
    do
    {
        ans=ans+p->coef*pow(x,p->expo);
        p=p->next;
    } while(p!=head->next);
    return(ans);
}

/*----------<< function defination for display poly >>------------*/

void display(node *head)
{
    node *p,*q;
    int n=0;
    q=head->next;
    p=head->next;
    do
    {
        n++;
        q=q->next;
    } while(q!=head->next);
    printf("\n\n\tThe polynomial is==>");
    do
    {
        if(n-1)
        {
            printf("%dx^(%d) + ",p->coef,p->expo);
            p=p->next;
        }
        else
        {
            printf(" %dx^(%d)",p->coef,p->expo);
            p=p->next;
        }
        n--;
    } while(p!=head->next);
}

/*------------<<  Main Function Start  >>---------------*/

void main()
{
    char ans;
    int a,x,ch;
    node *p1,*p2,*p3;
    p1=p2=p3=NULL;
    do
    {
        clrscr();
        printf("\n\t----------------<<  MENU  >>---------------");
        printf("\n\tPolynomial Operations :");
        printf(" 1.Add");
        printf("\n\t\t\t\t2.Multiply");
        printf("\n\t\t\t\t3.Evaluate");
        printf("\n\t\t\t\t4.Exit");
        printf("\n\t---------------------------------------------------");
        printf("\n\n\n\tEnter your choice==>");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1 :
            p1=create();
            display(p1);
            p2=create();
            display(p2);
            p3=add(p1,p2);
            display(p3);
            break;
        case 2 :
            p1=create();
            display(p1);
            p2=create();
            display(p2);
            p3=multi(p1,p2);
            display(p3);
            break;
        case 3 :
            p1=create();
            display(p1);
            a=eval(p1);
            printf("\n\nValue of polynomial=%d",a);
            break;
        case 4 :
            exit(0);
            break;
        default :
            printf("\n\n\tinvalid choice");
            break;

        }
        printf("\n\n\nDo you want to continue(Y/N)?==>");
        ans=getch();
    } while(ans=='Y'||ans=='y');
    getch();
}
/*------------<< End of Main Function >>---------------*/