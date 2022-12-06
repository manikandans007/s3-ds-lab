#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *link;
};
struct node *front,*rear;
void display()
{
    struct node *ptr;
    if(front==NULL){
        printf("stack is empty");
    }
    else{
        ptr=front;
        printf("elements are ");
        while(ptr!=NULL){
            printf("%d",ptr->data);
            ptr=ptr->link;
        }
    }

}
void Enqueue(int item)
{
   struct node *new;
   new = (struct node *)malloc(sizeof(struct node));
   new->data=item;
   new->link=NULL;
   if(front==NULL){
    front=rear=new;
   }
   else{
    rear->link=new;
    rear=new;
   }
   display();

} 
 void Dequeue(){
    struct node *temp;
if(front==NULL){
    printf("queue is empty");
}
else if(front==rear)
{
    temp=front;
    
    front=rear=NULL;
    free(temp);
    display();

}
else{
    temp=front;
    front=front->link;
    free(temp);
    display();
}
    
 }

void main(){
int s,item,temp;
do{
printf("select the operation you want to perform");
printf("\n 1.enqueue");
printf("\n 2.dequeue");
printf("\n 1.Display");
printf("\n 1.Exit\n");
scanf("%d",&s);

    switch(s){
    case 1:
    printf("\nEnter the element you want to push");
    scanf("%d",&item);
    Enqueue(item);
    break;
    case 2:
    Dequeue();
    break;
    case 3:
    display();
    break;
    
    }
}while(s<4);

return 0;
 }
