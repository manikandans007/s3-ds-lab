#include<stdio.h>
#include<math.h>
typedef struct
{
int coff;
int expo;
}polynomial; 
int main()
{
int size1,c,result = 0;

printf("enter the size of polynomial");
scanf("%d",&size1);
polynomial p1[size1];
printf("enter he  polynomial you wantt:");
for(int i=0;i<size1;i++)
scanf("%d %d",&p1[i].coff, &p1[i].expo);
printf("entered polynomial");
for(int i=0;i<size1;i++)
printf("%dx^%d+",p1[i].coff,p1[i].expo);
printf("enter the value of x you want");
scanf("%d",&c);
for(int i=0;i<size1;i++)
     result += p1[i].coff * pow(c, p1[i].expo);
    printf("the sum of polynomial is %d ",result);

}
