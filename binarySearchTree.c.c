//Design, Develop and Implement a menu driven Program in C for the following operations on
//Binary Search Tree (BST) of Integers
//      a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
//      b. Traverse the BST in In-Order, Pre-Order and Post-Order
//      c. Search the BST for a given element (KEY) and report the appropriate message
//      d. Delete an element(ELEM) from BST
//      e. Exit

#include<stdio.h>
#include<stdlib.h>

struct BST  {
    int data;
    struct BST *lchild;
    struct BST *rchild;
};
typedef struct BST * NODE;

NODE getNode() {
    NODE temp;
    temp = (NODE) malloc(sizeof(struct BST));
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

void insert(NODE, NODE);
void inOrder(NODE);
void preOrder(NODE);
void postOrder(NODE);
void search(NODE, int);

void insert(NODE root, NODE newnode) {
    if (newnode->data < root->data) {
        if (root->lchild == NULL)
            root->lchild = newnode;
        else
            insert(root->lchild, newnode);
    }
    if (newnode->data > root->data) {
        if (root->rchild == NULL)
            root->rchild = newnode;
        else
            insert(root->rchild, newnode);
    }
}

void search(NODE root, int key) {
    NODE cur;
    if(root == NULL) {
        printf("\nBST is empty."); return;
    }
    cur = root;
    while (cur != NULL) {
        if (cur->data == key) {
            printf("\nElement %d is found in BST", cur->data);
            return;
        }
        if (key < cur->data)
            cur = cur->lchild;
        else
            cur = cur->rchild;
    }
    printf("\nElement %d is not found in the BST", key);
}

void inOrder(NODE root) {
    if(root != NULL) {
        inOrder(root->lchild);
        printf("%d ", root->data);
        inOrder(root->rchild);
    }
}

void preOrder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void postOrder(NODE root) {
    if (root != NULL) {
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%d ", root->data);
    }
}


void main() {
    int ch, key, val, i, n;
    NODE root = NULL, newNode;
    while(1) {
        printf("\n---BINARY SEARCH TREE---");
        printf("\n1. Create a BST.");
        printf("\n2. Search.");
        printf("\n3. BST Traversals.");
        printf("\n4. Exit.");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("\nEnter the number of elements: "); scanf("%d", &n);
                for(i=1; i<=n; i++) {
                    newnode = getNode();
                    printf("\nEnter The value: "); scanf("%d", &val);
                    newnode->data = val;
                    if (root == NULL)
                        root = newnode;
                    else
                        insert(root, newnode);
                }
                break;
            case 2:
                printf("\nEnter Element to be Searched: "); scanf("%d", &key);
                search(root, key);
                break;
            case 3:
                if (root == NULL)
                    printf("\nTree Is Not Created");
                else {
                    printf("\nThe Pre-Order Display : ");
                    preOrder(root);
                    printf("\nThe In-Order Display  : ");
                    inOrder(root);
                    printf("\nThe Post-Order Display : ");
                    postOrder(root);
                }
                break;
            case 4: exit(0);
        }
    }
}
