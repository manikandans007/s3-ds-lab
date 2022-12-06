#include<stdio.h>
#include<math.h>
typedef struct{
    int row;
    int col;
    int value;
}matrix;
int main()
{
matrix s_matrix[100];
int m,n;
printf("Enter the number of row and column");
scanf("%d %d",&m,&n);
int matrix[m][n];
    printf("enter the elements u want");
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    scanf("%d",&matrix[i][j]);
int nonz= 0;    
s_matrix[0].row = m;
s_matrix[0].col = n;
       for (int i = 0,z=1; i < m; i++)
        for(int j=0;j<n;j++)
        {
    if(matrix[i][j] != 0 )
        {
    nonz++;
    s_matrix[z].row=i;
    s_matrix[z].col=j;
    s_matrix[z].value=matrix[i][j];
    z++;
    

    }
    }
s_matrix[0].value=nonz;
 float sparsity =(float)(s_matrix[0].row * s_matrix[0].col- s_matrix[0].value) / (s_matrix[0].row * s_matrix[0].col);
    printf("Sparsity = %0.3f\n", sparsity);
printf("\nSparse matrix representation\n");
    for (int i = 0; i <= nonz; i++)
        printf("%d %d %d\n",s_matrix[i].row,s_matrix[i].col,s_matrix[i].value);
}











