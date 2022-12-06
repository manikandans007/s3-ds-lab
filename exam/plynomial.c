#include<stdio.h>
typedef struct
{
int coff;
int expo;
}polynomial; 
int main()
{
int size1,size2;

printf("enter the size of polynomial1&2");
scanf("%d %d",&size1,&size2);
polynomial p1[size1],p2[size2],sum[size1+size2];
printf("enter the 1st polynomial you want:");
for(int i=0;i<size1;i++)
scanf("%d%d",&p1[i].coff, &p1[i].expo);
printf("enter the 2st polynomial you want:");
for(int i=0;i<size2;i++)
scanf("%d %d",&p2[i].coff, &p2[i].expo);
printf("\n");
printf("entered the 1st polynomial :");
for(int i=0;i<size1;i++)
printf("%dX^%d+", p1[i].coff, p1[i].expo);
printf("\n");
printf("entered the 2st polynomial :");
for(int i=0;i<size2;i++)
printf("%dX^%d+", p2[i].coff, p2[i].expo);
printf("\n");


int i=0,j=0,z=0;
while(i<size1 && j<size2)
	{
if(p1[i].expo>p2[j].expo)
{
sum[z].expo=p1[i].expo;
sum[z].coff=p1[i].coff;
i++;
z++;
	}
if(p1[i].expo<p2[j].expo)
{
sum[z].expo=p2[j].expo;
sum[z].coff=p2[j].coff;
j++;
z++;
	}
if(p1[i].expo==p2[j].expo)
{
sum[z].expo=p1[i].expo;
sum[z].coff=p1[i].coff+p2[j].coff;
i++;
z++;
j++;
}
}

    while (i < size1)
    {
        sum[z].expo = p1[i].expo;
        sum[z].coff = p1[i].coff;
        i++;
        z++;
    }
    while (j < size2)
    {
        sum[z].expo = p2[j].expo;
        sum[z].coff = p2[j].coff;
        j++;
        z++;
    }

printf("sum of two polynomial is:");
for(i=0;i<z;i++)
	{
        printf("%dx^%d ", sum[i].coff, sum[i].expo);
    printf("\n");
	}
}

