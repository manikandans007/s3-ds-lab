#include <stdio.h>
#include <stdlib.h>
int stack[100],a,n,x,m,top,ntop=0,s;
void push(void);
void pop(void);
void display(void);
void push1(void);
void pop1(void);
void display1(void);
int main()
{
    top = -1;
    ntop = n - top;
    printf("Enter the size of stack :");
    scanf("%d", &n);
    printf("choose the stack you want");
    printf("\n\t1.stack-1 \n\t2.stack-2 \n\t3.exit");
    scanf("%d", &s);
    if (s == 1)
    {
        printf("--------choose opertion u want to perform in stack-1------");
        printf("\n------------------------------------------");
        printf("\n\t1.push \n\t2.pop \n\t3.display \n\t4.exit");
        do{
            printf("\nenter your choice :");
            scanf("%d", &a);
            switch (a)
            {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("Exit Status ");
                break;
            }
            default:
            {
                printf("\nenter the valid number b/w 1-4 :");
            }
            }
    }while(a!=4);
    return 0;
    }
}
   /* else if (s == 2)
    {
         printf("--------choose opertion u want to perform in stack-2------");
        printf("\n---------------------------------------------------------");
        printf("\n\t1.push \n\t2.pop \n\t3.display \n\t4.exit");
        
    
            printf("\nenter your choice :");
            scanf("%d", &a);
            switch (a)
            {
            case 1:
            {
                push1();
                break;
            }
            case 2:
            {
                pop1();
                break;
            }
            case 3:
            {
                display1();
                break;
            }
            case 4:
            {
                printf("Exit Status ");
                break;
            }
            default:
            {
                printf("\nenter the valid number b/w 1-4 :");
            }
            }

    
    }
    else if(s==3)
    {
        
    }
    else{
        printf("enter correct value between 1-3");
    }
}*/
    
void push()
{
if(top>=n-1)
{
printf("stack is underflow");
}
else{
printf("enter the element to be pushed :");
scanf("%d",&x);
top++;
stack[top]=x;
}
}
void pop(){
if(top<=-1){
printf("The  stack is underflow ");
top--;
}
else
{
printf("\nThe popped elements is :%d",stack[top]);
        top--;
}
}
void display()
{
if(top>=0)
	{
   
        printf("\n The elements in STACK \n");
        for(int i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        
    }
    else
    {
        printf("\n The STACK is empty");
    }

}
/*
void push1()
{
    if (ntop >= n - 1)
    {
        printf("stack is underflow");
    }
    else
    {
        printf("enter the element to be pushed :");
        scanf("%d", &x);
        ntop++;
        stack[ntop] = x;
    }
}
void pop1()
{
    if (ntop <= -1)
    {
        printf("The  stack is underflow ");
        top--;
    }
    else
    {
        printf("\nThe popped elements is :%d", stack[ntop]);
        ntop--;
    }
}
void display1()
{
    if (ntop >= 0)
    {

        printf("\n The elements in STACK \n");
        for (int i = ntop; i >= 0; i--)
            printf("\n%d", stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
*/



