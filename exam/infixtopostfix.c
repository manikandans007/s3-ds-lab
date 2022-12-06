#include <stdio.h>
//declare global variables.
char infix[20],p[20];
char stack[20];
int top=-1,top1=-1;
//precedence fun..
int precedence(char c){
    switch(c){
        case '+':
        case '-':   return 1;
        
        
        case '*':
        case '/':   return 2;
        
        
        case '^':   return 3;
        
    }
}
//infix to postfix fun..
void infix_to_postfix(){
    int i=0;
    int j=0;
    char x,y;
    while(infix[i]!='\0')
    {
        if(isdigit(infix[i]))  //if it is a operand.
            p[j++]=infix[i];
        else if(infix[i]=='(')  //if it is open paranthesis.
            stack[++top]=infix[i];
        else if(infix[i]==')'){//if it is a close paranthesis.
            while(stack[top]!='(')
                p[j++]=stack[top--];
            
            top--;
        }
        else{ //if it is a operator.
             x=infix[i];
             y=stack[top];
            if(top==-1 || y=='(' || precedence(y)>precedence(x)){
                stack[++top]=infix[i];
            }else{
                while(y!='(' && top!=-1 && precedence(x)<=precedence(y)){
                    p[j++]=stack[top--];
                    y=stack[top];
                }
                stack[++top]=x;
                
            }
            
        }
        i++;
    }
    while(top!=-1)
        p[j++]=stack[top--];
        p[j]='\0';
        printf("Postfix expression is %s",p);
    
}


void main() {
    printf("Enter the infix expression:");
    gets(infix);
    infix_to_postfix();

}