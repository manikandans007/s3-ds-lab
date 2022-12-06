#include<stdio.h>
#define max_size 100
int a[100],front=-1,rear=-1,s,c,size;
void enqueue(int data)
{
    if(rear==size-1)
        printf("queue is overflow");
        else if(rear==-1)
        {
            front++;
            rear++;
            a[rear]=data;
            
        }
        else{
            rear++;
            a[rear]=data;
        }
    

} 
 void dequeue(){
if(front==-1)
        printf("Queue is empty");
        else if(front==rear)
        {
         
            printf("Deleted element is %d",a[front]);
            front=-1;
            rear=-1;
            }
            else{
                printf("Deleted item %d.",a[front]);
                front++;
            }
    
 }
void display()
{
if(front==-1)
printf("Queeue is empty");
else{
printf("stack elements are:");
  for(int i=front;i<=rear;i++)
        {
            printf("%d\n",a[i]);
        }
}
}
 int main(){
    
printf("entert the size of array");
scanf("%d",&size);
do{
printf("select the operation you want to perform");
printf("\n 1.Enqueue");
printf("\n 2.Dequeue");
printf("\n 3.Display");
printf("\n 4.Exit\n");
scanf("%d",&s);

    switch(s){
    case 1:
    printf("\nEnter the element you want to push");
    scanf("%d",&c);
    enqueue(c);
    break;
    case 2:
    dequeue();
    break;
    case 3:
    display();
    break;
    
    }
}while(s<4);

return 0;
 }
