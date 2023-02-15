#include<stdlib.h>
#include<stdio.h>
struct node{
    int coeff,expo;
    struct node *next;

};
struct node *PHead,*QHead,*RHead;
struct node * ReadPoly(){
struct node *new,*ptr,*head=NULL;
int i,n;
printf("\nenter the number of term u wanr");
scanf("%d",&n);
printf("\nenter the terms in coefficient,exponential format");
for(i=1;i<=n;i++){
new=(struct node *)malloc(sizeof(struct node));
scanf("%d",&new->coeff);
scanf("%d",&new->expo);
new->next=NULL;
if(head==NULL){
    head=new;
    ptr=new;
}
else{
    ptr->next=new;
    ptr=new;
}
}
return(head);
}
struct node * addpoly(){
struct node *p,*q,*head=NULL,*new,*r;
p=PHead;
q=QHead;
while(p!=NULL && q!=NULL){
    if (p->expo == q->expo) {
            new = (struct node *) malloc(sizeof(struct node));
            new->expo = p->expo;
            new->coeff = p->coeff + q->coeff;
            new->next = NULL;
            p = p->next;
            q = q->next;
        
    }
            else  if(p->expo>q->expo){
            new=(struct node *)malloc(sizeof(struct node));
            new->expo=p->expo;
            new->coeff=p->coeff;
            new->next=NULL;
            p=p->next;
 }
          else{
            new=(struct node *)malloc(sizeof(struct node));
            new->expo=q->expo;
            new->coeff=q->coeff;
            new->next=NULL;
            q=q->next;
          }
            if(head==NULL){
                head=new;
                    r=new;
                            }
                    else{
                    r->next=new;
                    r=new;
                    }
                    
                }


    while(p!=NULL){
    
            new=(struct node *)malloc(sizeof(struct node));
            new->expo=p->expo;
            new->coeff=p->coeff;
            new->next=NULL;
            p=p->next;
            if(head==NULL){
                head=new;
                    r=new;
                            }
                    else{
                    r->next=new;
                    r=new;
                    }
                    p=p->next;
}
    while(q!=NULL){
    
            new=(struct node *)malloc(sizeof(struct node));
            new->expo=q->expo;
            new->coeff=q->coeff;
            new->next=NULL;
            q=p->next;
            if(head==NULL){
                head=new;
                    r=new;
                            }
                    else{
                    r->next=new;
                    r=new;
                    }
                    q=q->next;
}
return(head);

}
void DisplayPoly(struct node *head){
struct node *ptr;
if(head==NULL){
    printf("list is empty");
}
else {
    ptr=head;
    while(ptr->next!=NULL){
        printf("%dx^%d",ptr->coeff,ptr->expo);
        ptr=ptr->next;
    }
     printf("%dx^%d",ptr->coeff,ptr->expo);
}
}
void main(){
printf(" the first polynomial :");
PHead=ReadPoly();

printf("Enter the second polynomial :");
QHead=ReadPoly();

printf("Entered the first polynomial :");
DisplayPoly(PHead);

printf("Enter the second polynomial :");
DisplayPoly(QHead);


RHead=addpoly();

printf("result of the polynomial");
DisplayPoly(RHead);

}