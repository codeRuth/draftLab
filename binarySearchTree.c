//Design, Develop and Implement a Program in C for the following operations on
//Binary Search Tree (BST) of Integers
//      a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
//      b. Traverse the BST in In-Order, Pre-Order and Post-Order
//      c. Search the BST for a element (KEY) and report the appropriate message
//      d. Delete an element(ELEM) from BST
//      e. Exit

#include <stdio.h>
#include <stdlib.h>

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

void insert(NODE root, NODE newNode) {
    if (newNode->data < root->data) {
        if (root->lchild == NULL)
            root->lchild = newNode;
        else
            insert(root->lchild, newNode);
    }
    if (newNode->data > root->data) {
        if (root->rchild == NULL)
            root->rchild = newNode;
        else
            insert(root->rchild, newNode);
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
            printf("Element %d is found in BST\n", cur->data);
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

NODE* findMin(NODE *node) {
    if(node == NULL) {
        return NULL;
    }
    if(node->left)
        return findMin(node->left);
    else
        return node;
}

NODE* deleteNode(NODE *node, int data)
{
    NODE *temp;
    if(node == NULL) {
        printf("\nElement Not Found.");
    }
    else if(data < node->data) {
        node->left = deleteNode(node->left, data);
    }
    else if(data > node->data) {
        node->right = deleteNode(node->right, data);
    }
    else {
        if(node->right && node->left) {
            temp = findMin(node->right);
            node -> data = temp->data;
            node -> right = del(node->right, temp->data);
        }
        else {
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp);
        }
    }
    return node;
}

void main() {
    int ch, key, val, i, n;
    NODE root = NULL, newNode, temp;
    while(1) {
        printf("\n---BINARY SEARCH TREE---");
        printf("\n1. Create a BST.");
        printf("\n2. Search.");
        printf("\n3. BST Traversal.");
        printf("\n4. Delete Item.");
        printf("\n5. Exit.");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("\nEnter the number of elements: "); scanf("%d", &n);
                for(i=1; i<=n; i++) {
                    newNode = getNode();
                    printf("Enter The value: "); scanf("%d", &val);
                    newNode->data = val;
                    if (root == NULL)
                        root = newNode;
                    else
                        insert(root, newNode);
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
                    printf("\nThe Pre-Order Display  : ");
                    preOrder(root);
                    printf("\nThe In-Order Display   : ");
                    inOrder(root);
                    printf("\nThe Post-Order Display : ");
                    postOrder(root);
                    printf("\n");
                }
                break;
            case 4: printf("Enter Item to be Deleted.");
                    scanf("%d", data);
                    temp = deleteNode(root, data);
                    printf("%d Deleted.", temp->data);
                break;
            case 5:exit(0);
        }
    }
}
