#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class NODE
{
    public:
    int info;
    class NODE *left;
    class NODE *right;
};

class bintree
{
   NODE *root;
    public:
            bintree()
            {
                root=NULL;
            }
            void Inorder(NODE* );
            void Preorder(NODE* );
            void Postorder(NODE* );
            NODE* Insert();
            void Display();
};

 /* To traverse a non-empty binary search tree in in-order (symmetric), perform the following operations recursively at each node:
    1. Traverse the left sub-tree.
    2. Visit the root.
    3. Traverse the right sub-tree. */


void bintree::Inorder(NODE *p)
{
     if(p!=NULL)
     {
             Inorder(p->left);
             cout<<p->info<<" ";
             Inorder(p->right);
     } 
}

/*To traverse a non-empty binary search tree in pre-order, perform the following operations recursively at each node  
 1. Visit the root.
 2. Traverse the left sub-tree.
 3. Traverse the right sub-tree. */

void bintree::Preorder(NODE *p)
{
     if(p!=NULL)
     {
             cout<<p->info<<" ";
             Preorder(p->left);
             Preorder(p->right);
     } 
}

/*To traverse a non-empty binary search tree in post-order, perform the following operations recursively at each node:
 1. Traverse the left sub-tree.
 2. Traverse the right sub-tree.
 3. Visit the root. */

void bintree::Postorder(NODE *p)
{
     if(p!=NULL)
     {
             Postorder(p->left);
             Postorder(p->right);
             cout<<p->info<<" ";
     } 
}
NODE* bintree::Insert()
{

NODE *newnode;
     newnode=(NODE *)malloc(sizeof(NODE));
     newnode->left=newnode->right=NULL;
     cout<<"\n\n\tEnter an Element to Insert: ";
     cin>>newnode->info;
     if(root==NULL)
             root=newnode;
     else
     {
             NODE *p,*q;
             p=root;
             while(p!=NULL)
             {
                     q=p;
                     if(newnode->info>p->info)
                             p=p->right;
                     else
                             p=p->left;
             } 
             if(newnode->info>q->info)
                     q->right=newnode;
              else
                     q->left=newnode;
        }
}
void bintree::Display()
{
 int x;
 if(root==NULL)
                    cout<<"\n\n\tNo Nodes in the Tree";
     else
         {
          while(1){
          cout<<"\n\tEnter your choice:\n\t1.Preorder\n\t2.Inorder\n\t3.Postorder\n\t4.Exit: ";
          cin>>x;
          switch(x)
          {
                 case 1:
                             cout<<"\n\n\tPreorder Traversal :";
                             Preorder(root);
                             break;
                 case 2:
                             cout<<"\n\n\tInorder Traversal :";
                             Inorder(root);
                             break;
                 case 3:
                             cout<<"\n\n\tPostorder Traversal :";
                             Postorder(root);
                             break;
                 case 4:
                             exit(0);
                 default:cout<<"Enter proper choice:";
          }
     }
     }
}

int main()
{
     int choice;
 bintree obj;

     while(1)
     {
     cout<<"\n\n\n\t1.Insert\n\t2.Display\n\t3.Exit";
             cout<<"\n\tEnter Your Choice: ";
             cin>>choice;
             switch(choice)
             {
                     case 1: obj.Insert(); break;
                     case 2: obj.Display(); break;
                     case 3: exit(0);
                     default: cout<<"\n\n\tEnter Proper Choice:";
              }
     } 
 return 0;
}