#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *leftchild;
    struct node *rightchild;
} node;

struct node *root = NULL;

typedef struct node Node;

void insert()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data : ");
    scanf("%d", &newnode->data);

    newnode->leftchild = NULL;
    newnode->rightchild = NULL;

    if (root == NULL)
        root = newnode;
    else
    {
        struct node *previous, *current;
        current = root;
        while (1)
        {
            if (newnode->data < current->data)
            {
                previous = current;
                current = current->leftchild;
                if (current == NULL)
                {
                    previous->leftchild = newnode;
                    break;
                }
            }
            else if (newnode->data >= current->data)
            {
                previous = current;
                current = current->rightchild;
                if (current == NULL)
                {
                    previous->rightchild = newnode;
                    break;
                }
            }
            else
            {
                printf("Invalid Input\n");
                exit(0);
            }
        }
    }
}

void search()
{
    int key, f = 0;
    printf("Enter the key element to be searched : ");
    scanf("%d", &key);
    struct node *current = root;
    while (current != NULL)
    {
        if (current->data == key)
        {
            f = 1;
            break;
        }

        if (key < current->data)
            current = current->leftchild;

        else if (key > current->data)
            current = current->rightchild;
    }
    if (f)
        printf("Key Element Found !!!\n");
    else
        printf("Key Element NOT found !!!\n");
}
void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->leftchild);
        printf(" %d\t", ptr->data);
        inorder(ptr->rightchild);
    }
}

void preorder(struct node *ptr)
{
    if (ptr)
    {
        printf(" %d\t", ptr->data);
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }
}

void postorder(struct node *ptr)
{
    if (ptr)
    {
        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        printf(" %d\t", ptr->data);
    }
}

struct node *ins(struct node *ptr)
{
    struct node *q = NULL;
    while (ptr->leftchild != NULL)
    {
        q = ptr;
        ptr = ptr->leftchild;
    }
    if (ptr->rightchild != NULL)
        q->leftchild = ptr->rightchild;
    else
        q->leftchild = NULL;
    return (ptr);
}

void delete_node()
{
    printf("Enter node value to delete : ");
    int d, f = 0;
    scanf("%d", &d);

    struct node *current = root;
    struct node *ptr = NULL;

    while (current != NULL)
    {
        if (current->data == d)
        {
            f = 1;
            break;
        }

        if (d < current->data)
        {
            ptr = current;
            current = current->leftchild;
        }
        else if (d > current->data)
        {
            ptr = current;
            current = current->rightchild;
        }
    }

    if (f == 0)
        printf("Element to delete NOT found !!!");
    else
    {
        struct node *t = current;
        if (t->leftchild == NULL && t->rightchild == NULL)
        {
            if (ptr->leftchild == t)
                ptr->leftchild = NULL;
            if (ptr->rightchild == t)
                ptr->rightchild = NULL;
        }
        else if (t->leftchild == NULL)
        {
            if (ptr->leftchild == t)
                ptr->leftchild = t->rightchild;
            if (ptr->rightchild == t)
                ptr->rightchild = t->rightchild;
        }

        else if (t->rightchild == NULL)
        {
            if (ptr->leftchild == t)
                ptr->leftchild = t->leftchild;
            if (ptr->rightchild == t)
                ptr->rightchild = t->leftchild;
        }
        else
        {
            struct node *in = t->rightchild;
            if (in->leftchild == NULL)
            {
                t->data = in->data;
                t->rightchild = in->rightchild;
            }
            else
            {
                in = ins(t->rightchild);
                t->data = in->data;
            }
        }
    }
}

int main()
{
    int ch;
    printf("1.Insert a new node\n");
    printf("2.Inorder Traversal\n");
    printf("3.Preorder Traversal\n");
    printf("4.Postorder Traversal\n");
    printf("5.Delete a node\n6.Search for an Element\n");
    printf("7.Exit\n");
    do
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            printf("Inorder Traversal\n");
            inorder(root);
            break;
        case 3:
            printf("Preorder Traversal\n");
            preorder(root);
            break;
        case 4:
            printf("Postorder Traversal\n");
            postorder(root);
            break;
        case 5:
            delete_node();
            break;
        case 6:
            search();
            break;
        }
    } while (ch != 7);
}
