#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head,*node;
struct node* create(int value){
node = (struct node *)malloc(sizeof(struct node));
node->data = value;
node->next = NULL;
return (node);
}
void display()
{
if(head == NULL)
printf("Circular Linked list is Empty.");
else {
ptr = head;
printf("\nCIRCULAR LINKED LIST : ");
while(ptr->next!=head)
{
printf("%i",ptr->data);
ptr = ptr->next;
}
printf("%i",ptr->data);
}
printf("\n");
}
void insert_begin(int value){
new = create(value);
if(head == NULL){
new->link=new;
head=new;
}
else{
ptr=head;
while(ptr->next!=head)
ptr=ptr->next;
new->next=head;
head=new;
ptr->next=head;
}
display();
}
void insert_end(int value)
{
node = create(value);
if(head == NULL) {
nre->link=new;
head=new;

}
else {
ptr=head;
while(ptr->next!=head)
ptr=ptr->next;
ptr->next=new;
new->next=head;
}
display();
}
void insert_after(int prev,int value){
node = create(value);
if(head==NULL)
printf("search key not found insertion not possible");

display();
}
void delete(int val){
struct node *prev,*curr,*ptr,*temp;
if(head == NULL)
printf("List is Empty.");
else if(head->next==head) {
if(head->link==head){
    temp=head;
    head=NULL;
    free(temp);
}
else{
printf("Search data not found.Deletion is not possible");
}
}
else if(head->data==key){
    temp=ptr=head;
    while(ptr->next!=head)
    ptr=ptr->next;
    head=head-next;
    ptr->link=head;
    free(temp);            
    
}
else
display();
}
void main(){
int opt,key,x;
do{


printf("\t__Menu__\n");
printf("1.Insert node at beginning of the list\n2.Insert node after a particular node in the list\n3.Insert node at the end of the list\n4.Delete a node containing a particular item\n5.Display\n6.Exit\n");

printf("Enter choice: ");
scanf("%i",&opt);

switch(opt){
case 1:printf("Enter the node value to be inserted : ");

scanf("%i",&x);
insert_begin(x);
break;
case 2:printf("Enter node value to be inserted : ");
scanf("%i",&x);
printf("Enter node value after which new node is to be inserted : ");
scanf("%i",&key);
insert_after(key,x);
break;
case 3:printf("Enter the node value to be inserted : ");
scanf("%i",&x);
insert_end(x);
break;
case 4:printf("Enter node value to be deleted : ");
scanf("%i",&key);
delete(key);
break;
case 5:display();
break;
case 6:printf("EXIT…");
break;
}
}while(op!=7)
}