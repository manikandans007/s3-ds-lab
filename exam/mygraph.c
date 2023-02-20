#include<stdio.h>
#include<stdlib.h>
#define max 20
int vis[20],top=-1,front=-1,rear=-1,s,n,item,a[max][max],q[max],stack[max];

int delete();
void bfs(int s,int n);
void dfs(int s,int n);
void add(int item);
void push(int item);
int pop();

void bfs(int s,int n)
{
    int p,i,j;
    add(s);
    vis[s]=1;
    p=delete();
    if(p!=0){
        printf("%d",p);
    }
    while(p!=0){
        for(i=1;i<=n;i++){
            if(a[p][i]!=0 && vis[i]==0){
            add(i);
            vis[i]=1;
        }
        }
        p=delete();
        if(p!=0){
            printf("%d",p);
        }

    }
    for(i=1;i<=n;i++)
        if(vis[i]==0)
            bfs(i,n);
        
    
    }

void add(int item){
    if(rear==19){
        printf("queue is full");
    }
    else 
    {
        if(rear==-1)
    {
        q[++rear]=item;
        front++;
    }
    else{
         q[++rear]=item;
    }
}
}
int delete(){
    int k;
 if((front>rear)||(front==-1)){
    return(0);
}
 else{
    k=q[front++];
    return(k);
 }
}
void dfs(int s,int n)
{
    int p,i,j;
    push(s);
    vis[s]=1;
    p=pop();
    if(p!=0){
        printf("%d",p);
    }
    while(p!=0){
        for(i=1;i<=n;i++){
            if(a[p][i]!=0 && vis[i]==0)
            push(i);
            vis[i]=1;
        }
        p=pop();
        if(p!=0){
            printf("%d",p);
        }

    }
    for(i=1;i<=n;i++)
        if(vis[i]==0)
            dfs(i,n);
        
    
    }

void push(int item){
    if(top==19){
        printf("stack is full");
    }
    else 
    {
          stack[++top]=item;   
   
}
}
int pop(){
    int k;
 if(top==-1){
    return(0);
}
 else{
    k=stack[top--];
    return(k);
 }
}
void main(){
int ch,n,s,i,j,k,p;
char dummy,c;
printf("enter the number of vertex");
scanf("%d",&n);
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
    printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 : ",i,j);
scanf("%d",&a[i][j]);
}
}
printf("THE ADJACENCY MATRIX IS : \n");
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
printf("%d ",a[i][j]);
}
printf("\n");
}
do{
for(i=1;i<=n;i++)
vis[i]=0;
printf("\n__MENU__");
printf("\n1.BFS");
printf("\n2.DFS");
printf("\nENTER YOUR CHOICE : ");
scanf("%d",&ch);
printf("ENTER THE SOURCE VERTEX : ");
scanf("%d",&s);
switch(ch){
case 1:bfs(s,n);
break;
case 2:
dfs(s,n);
break;
}
printf("\nDO U WANT TO CONTINUE(Y/N) ? ");
scanf("%c",&dummy);
scanf("%c",&c);
}while((c=='y')||(c=='Y'));
}