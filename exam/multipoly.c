#include <stdio.h>
#include <stdlib.h>

struct node {
    int coefficient;
    int exponent;
    struct node *next;
};

struct node *create_node(int coefficient, int exponent) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->coefficient = coefficient;
    new_node->exponent = exponent;
    new_node->next = NULL;
    return new_node;
}

struct node *add_node(struct node *list, int coefficient, int exponent) {
    struct node *new_node = create_node(coefficient, exponent);
    if (list == NULL) {
        return new_node;
    } else {
        struct node *curr = list;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
        return list;
    }
}

struct node *polynomial_multiplication(struct node *p1, struct node *p2) {
    struct node *result = NULL;
    struct node *curr1 = p1;
    while (curr1 != NULL) {
        struct node *curr2 = p2;
        while (curr2 != NULL) {
            int coefficient = curr1->coefficient * curr2->coefficient;
            int exponent = curr1->exponent + curr2->exponent;
            result = add_node(result, coefficient, exponent);
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    struct node*temp1,*temp2,*prev;
            temp1=result;
    while(temp1 != NULL && temp1->next != NULL)
        {
         temp2 = temp1;
         while(temp2->next!=NULL)
         {
         if(temp1->exponent == temp2->next->exponent)
         {
         temp1->coefficient = temp1->coefficient + temp2->next->coefficient;
         
         temp2->next = temp2->next->next;
        temp2=temp2->next; 
         }
         else
         temp2 = temp2->next;
         }
         temp1 = temp1->next;
         }
         return result;
}

void print_polynomial(struct node *list) {
    struct node *curr = list;
    while (curr != NULL) {
        printf("%dx^%d ", curr->coefficient, curr->exponent);
        curr = curr->next;
        if (curr != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {int i,t1,t2,x,y;
    struct node *p1 = NULL;
   printf("Enter the no of terms of first polynomial");
   scanf("%d",&t1);
    printf("Enter the terms of first polynomial");
   for(i=0;i<t1;i++){
       scanf("%d%d",&x,&y);
       p1=add_node(p1,x,y);
   }

    struct node *p2 = NULL;
    printf("Enter the no of terms of second polynomial");
   scanf("%d",&t1);
    printf("Enter the terms of second polynomial");
   for(i=0;i<t1;i++){
       scanf("%d%d",&x,&y);
       p2=add_node(p2,x,y);
   }
    

    struct node *result = polynomial_multiplication(p1, p2);
    printf("The product polynomial is : \n");
    print_polynomial(result);

    return 0;
}