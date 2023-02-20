#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
   
    struct node *next;
};
struct node *rear,*front;
void display(){
    struct node *ptr;
    if(front==NULL){
        printf("Queue is empty");
    }
    else{
        ptr=front;
        while(ptr!=NULL){
            printf("%d",ptr->data);
            ptr=ptr->next;
        }
    }
}
void enqueue(int item){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data=item;
    new->next=NULL;
    if(front==NULL){
        front=rear=new;
    }
else {
    rear->next=new;
    rear=new;
}
}
void dequeue(){
   
     struct node *temp;
     if(front==NULL){
        
        printf("queue is empty");
    }
    else if(front==rear){
      
        temp=front;
        front=rear=0;
        free(temp);
        display();
    }
    else{
            
        temp=front;
        front=front->next;
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
    enqueue(item);
    break;
    case 2:
    dequeue();
    break;
    case 3:
    display();
    break;
    
    }
}while(s<4);

 }

    





























