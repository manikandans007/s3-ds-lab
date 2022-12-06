#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *link;
};
struct node *top;
void display()
{
    struct node *ptr;
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        ptr=top;
        printf("elements are ");
        while(ptr!=NULL){
            printf("%d",ptr->data);
            ptr=ptr->link;
        }
    }

}
void push(int item)
{
   struct node *new;
   new = (struct node *)malloc(sizeof(struct node));
   new->data=item;
   new->link=top;
   top=new;
   display();

} 
 void pop(){
    struct node *temp;
if(top==NULL){
    printf("stack is empty");
}
else{
    temp=top;
    printf("poped elements %d",top->data);
    top=top->link;
    free(temp);
    display();

}
    
 }

 int main(){
int s,item,temp;
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
    scanf("%d",&item);
    push(item);
    break;
    case 2:
    pop();
    break;
    case 3:
    display();
    break;
    
    }
}while(s!=4);

return 0;
 }
