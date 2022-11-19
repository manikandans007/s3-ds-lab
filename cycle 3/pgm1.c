#include<stdio.h>
#include<stdlib.h>
int stack[100],a,n,x,m,top;
void push(void);
void pop(void);
void display(void);
int main()
{
top=-1;
printf("Enter the size of stack:");
scanf("%d",&n);
printf("--------stack operations using array------");
printf("\n------------------------------------------");
printf("\n\t1.push \n\t2.pop \n\t3.display \n\t4.exit");
do{
printf("\nenter your choice");
scanf("%d",&a);
switch(a)
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
printf("\nenter the valid number b/w 1-4");
}
}

}while(a!=4);
return 0;
}
void push()
{
if(top>=n-1)
{
printf("stack is underflow");
}
else{
printf("enter the element to be pushed");
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
printf("\nThe popped elements is %d",stack[top]);
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





