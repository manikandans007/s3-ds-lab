#include<stdio.h>
#define max_size 100
int stack[max_size],top=-1;
void push(int data)
{
    if(top==max_size-1)
        printf("Stack is overflow");
        else 
        {
            stack[++top]=data;
            
        }
    

} 
 void pop(){
if(top==-1)
        printf("Stack is underflow");
        else 
        {
          int  d=stack[top--];
            printf("Deleted element is %d",d);
            
        }
    
 }
void display()
{
if(top==-1)
printf("stack is emplty");
else{
printf("stack elements are:");
  for(int i=0;i<=top;i++)
        {
            printf("%d\n",stack[i]);
        }
}
}
 int main(){
int s,c;
do{
printf("select the operation you want to perform");
printf("\n 1.push");
printf("\n 2.pop");
printf("\n 1.Display");
printf("\n 1.Exit\n");
scanf("%d",&s);

    switch(s){
    case 1:
    printf("\nEnter the element you want to push");
    scanf("%d",&c);
    push(c);
    break;
    case 2:
    pop();
    break;
    case 3:
    display();
    break;
    
    }
}while(s<4);

return 0;
 }
