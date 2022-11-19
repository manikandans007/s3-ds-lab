#include <stdio.h>
#include <stdlib.h>
int top=-1,size;
 typedef struct{
    int key;
}element;
void getsize(element a[])
{
    printf("enter the size of array");
    scanf("%d",&size);
    int top2=size;
}
void push1(element a[]){
    int top2=size;
    if(top== top2-1)
    {
        printf("overflow");
        printf("\n");
    }
    else
    {
        printf("enter the element");
        scanf("%d",&a[top+1].key);
        top++;
        printf("\n");
    }
}
void push2(element a[]){
    int top2=size;
    if(top== top2-1)
    {
        printf("overflow");
        printf("\n");
    }
    else
    {
        printf("enter the element");
        scanf("%d",&a[top2--].key);
        top2--;
        printf("\n");
    }
}
void pop1(element a[]){
    if(top==-1){
        printf("underflow");
        printf("\n");
    }
    else{
        printf("the popped element is %d",a[top].key);
        printf("\n");
        top--;
    }
}
void pop2(element a[]){
    int top2=size;
    if(top==top2){
        printf("underflow");
        printf("\n");
    }
    else{
        printf("the popped element is %d",a[top2].key);
        printf("\n");
        top2--;
    }
}
void display1(element a[]){
    int i;
    printf("the elements of stack are \n");
    for(i=top;i>0;i--)
    {
        printf(" %d",a[i].key);
    }
    printf("\n");
}
void display2(element a[]){
    int top2=size;
    int i;
    printf("the elements of stack-2 are \n");
    for(i=top2;i<size;i++)
    {
        printf("%d",a[i].key);
    }
}
void main(){
    int ch,size,c,choice;
    element a[100];
    getsize(a);
    printf("enter the choice \n1:stack-1 \n2:stack-2 \n3:stop\n");
    scanf("%d",&choice);
    if(choice==1){
        while(1){
            printf("enter the choice \n 1->push \n 2->pop \n 3->display  \n 4->end \n");
            scanf("%d",&ch);
            if(ch==1){
                push1(a);
            }
            else if(ch==2){
                pop1(a);
            }
            else if(ch==3){
                display1(a);
            }
            else if(ch==4){
                break;
           }
            else{
                printf("invalid choice");
           }
       }
   }
   printf("enter the choice \n1:stack-1 \n2:stack-2 \n3:stop\n");
   scanf("%d",&choice);
    if(choice==2){
       while(1){
           printf("enter the choice \n 1->push \n 2->pop \n 3->display  \n 4->end \n");
           scanf("%d",&c);
            if(c==1){
                push2(a);
            }
            else if(c==2){
                pop2(a);
            }
            else if(c==3){
                display2(a);
            }
            else if(c==4){
                break;
           }
            else{
                printf("invalid choice");
           }
       }
   }
   else if(choice==3){
       exit(0);
   }
}
