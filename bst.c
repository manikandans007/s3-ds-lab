#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *leftchild;
    struct node *rightchild;
};

typedef struct node Node;
Node *root = NULL;

void insert() {
    Node *newnode = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->leftchild = NULL;
    newnode->rightchild = NULL;

    if (root == NULL) {
        root = newnode;
    } else {
        Node *current = root;
        Node *parent;

        while (1) {
            parent = current;
            if (newnode->data < current->data) {
                current = current->leftchild;
                if (current == NULL) {
                    parent->leftchild = newnode;
                    return;
                }
            } else if (newnode->data > current->data) {
                current = current->rightchild;
                if (current == NULL) {
                    parent->rightchild = newnode;
                    return;
                }
            } else {
                printf("Invalid input\n");
                free(newnode);
                return;
            }
        }
    }
}

void inorder(Node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->leftchild);
        printf("%d ", ptr->data);
        inorder(ptr->rightchild);
    }
}

void preorder(Node *ptr) {
    if (ptr != NULL) {
        printf("%d ", ptr->data);
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }
}

void postorder(Node *ptr) {
    if (ptr != NULL) {
        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        printf("%d ", ptr->data);
    }
}

Node *search(int data) {
    Node *current = root;

    while (current != NULL) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->leftchild;
        } else {
            current = current->rightchild;
        }
    }

    return NULL;
}

Node *findMin(Node *ptr) {
    while (ptr->leftchild != NULL) {
        ptr = ptr->leftchild;
    }

    return ptr;
}

void delete(int data) {
    Node *current = root;
    Node *parent = NULL;
    while (current != NULL) {
        if (data == current->data) {
            break;
        } else if (data < current->data) {
            parent = current;
            current = current->leftchild;
        } else {
            parent = current;
            current = current->rightchild;
        }
    }

    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    // Case 1: Node has no children
    if (current->leftchild == NULL && current->rightchild == NULL) {
        if (parent == NULL) {
            root = NULL;
        } else if (current == parent->leftchild) {
            parent->leftchild = NULL;
        } else {
            parent->rightchild = NULL;
        }

        free(current);
    }
    // Case 2: Node has one child
    else if (current->leftchild == NULL) {
        if (parent == NULL) {
            root = current->rightchild;
        } else if (current == parent->leftchild) {
            parent->leftchild = current->rightchild;
        }
    }
}
void main(){
int ch,data1,data2;
printf("\n---- Menu ----");
printf("\n1.Insert a new node");
printf("\n2.Inorder Traversal");
printf("\n3.Preorder Traversal");
printf("\n4.Postorder Traversal"); 
printf("\n5.Delete a node");
printf("\n6.Search for an Element");
printf("\n7.Exit\n");
do{
printf("\nEnter your choice : ");
scanf("%d",&ch);
switch(ch){
case 1:insert();
break;
case 2:inorder(root);
break;
case 3:preorder(root);
break;
case 4:postorder(root);
break;
case 5:
printf("enter the value you want to delete");
scanf("%d",&data1);
delete(data1);

break;

case 6:
printf("enter the value you want to search");
scanf("%d",&data2);
search(data2);
break;
}
}while(ch != 7);
}
