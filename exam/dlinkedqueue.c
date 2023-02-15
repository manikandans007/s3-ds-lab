#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next,*prev;
};
struct node *head=NULL, *tail=NULL;
struct node * createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof (struct node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    
    return (newNode);
}
void createCredential(){
    head = createNode(0);
    tail = createNode(0);
    head->next=tail;
    tail->prev=head;
}

void EnqueueAtfront(int data)
{
   struct node *newNode, *temp;
   newNode = createNode(data); 
   temp = head->next;
   head->next=newNode;
   newNode->prev=head;
   newNode->next=temp;
   temp->prev=newNode;
}
void  EnqueueAtend(int data)
{
   struct node *newNode, *temp;
   newNode = createNode(data); 
   temp = tail->prev;
   tail->prev=newNode;
    newNode->next=tail;
   newNode->prev=temp;
  
   temp->next=newNode;
}
void DequeueAtFront(){
    struct node *temp;
    
if(head->next==tail){
    printf("queue emprty");
}
else{
temp = head->next;
head->next=temp->next;
temp->next->prev=head;
free(temp);
}
}
void DequeueAtRear(){
    struct node *temp;
    
if(tail->prev==head){
    printf("queue emprty");
}
else{
temp =tail->prev;
tail->prev=temp->prev;
temp->prev->next=tail;
free(temp);
}
}
void display()
{
    struct node *temp;
    temp=head;
    if(head->next==tail){
        printf("stack is empty");
    }
    else{
        temp=head->next;
        while(temp->next!=NULL){
            printf("\nelements are:%d",temp->data);
            temp=temp->next;
        }
  printf("\n");

}
}
 

int main(){
int s,data;
createCredential();
do{
printf("\nselect the operation you want to perform");
printf("\n 1.enqueueatfront");
printf("\n 2.enqueueatrear");
printf("\n 3.dequeue at front");
printf("\n 4.dequeue at rear");
printf("\n 5.Display");
printf("\n 6.Exit\n");
scanf("%d",&s);

    switch(s){
    case 1:
    printf("\nEnter the element you want to push");
    scanf("%d",&data);
    EnqueueAtfront(data);
    break;
     case 2:
    printf("\nEnter the element you want to push");
    scanf("%d",&data);
    EnqueueAtend(data);
    break;
    case 3:
    DequeueAtFront();
    break;
     case 4:
    DequeueAtRear();
    break;
    case 5:
    display();
    break;
    case 6:
    printf("Exit...");
    exit(0);
    
    }
}while(s<6);

return 0;
 }
