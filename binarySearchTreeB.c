#include <stdio.h>
#include <stdlib.h>
struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST NODE;
NODE *node;

NODE* createTree(NODE *node, int data) {
    if (node == NULL) {
        NODE *temp;
        temp = (NODE*) malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < (node->data)) {
        node->left = createTree(node->left, data);
    }
    else if (data > node->data) {
        node -> right = createTree(node->right, data);
    }
    return node;
}

NODE* searchNode(NODE *node, int data) {
    if(node == NULL)
        printf("Element not Found\n");
    else if(data < node->data) {
        node->left = searchNode(node->left, data);
    }
    else if(data > node->data) {
        node->right = searchNode(node->right, data);
    }
    else
        printf("Element Found : %d\n", node->data);
    return node;
}

void inOrder(NODE *node) {
    if(node != NULL) {
        inOrder(node->left);
        printf("%d   ", node->data);
        inOrder(node->right);
    }
}

void preOrder(NODE *node) {
    if(node != NULL) {
        printf("%d   ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(NODE *node) {
    if(node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d   ", node->data);
    }
}

NODE* findMin(NODE *node) {
    if(node==NULL) {
        return NULL;
    }
    if(node->left)
        return findMin(node->left);
    else
        return node;
}

NODE* deleteNode(NODE *node, int data) {
    NODE *temp;
    if(node == NULL) {
        printf("Element not Found.\n");
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
            node -> right = deleteNode(node->right,temp->data);
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
    int data, ch, i, n, dis;
    NODE *root = NULL;
    while (1) {
        printf("\n1.Create Tree.");
        printf("\n2.Search Element.");
        printf("\n3.Delete Element.");
        printf("\n4.Display.");
        printf("\n5.Exit.");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the Value of 'n': " ); scanf("%d", &n);
                printf("Enter Node Data: " );
                for(i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = createTree(root, data);
                }
                break;
            case 2:
                printf("\nEnter the Element to Search: ");
                scanf("%d", &data);
                root = searchNode(root, data);
                break;
            case 3:
                printf("\nEnter the Element to Delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 4:
                printf("\nIn-Order Traversal:   "); inOrder(root);
                printf("\nPre-Order Traversal:  "); preOrder(root);
                printf("\nPost-Order Traversal: "); postOrder(root);
                printf("\n");
                break;
            case 5: exit(0);
            default: printf("Wrong Option.\n");
                break;
        }
    }
}