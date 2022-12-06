#include<stdio.h>
typedef struct {
    int row;
    int col;
    int value;
}matrix;
void sparsetranspose(matrix m[],matrix t_m[])
{
int n = m[0].value;
  t_m[0].row = m[0].col;
    t_m[0].col = m[0].row;
    t_m[0].value = m[0].value;
    int k=1;
    if(n>0)
    {
        for(int i=0;i<m[0].col;i++){
            for(int j=0;j<=n;j++){
                if(m[j].col==i){
                    t_m[k].row=m[j].col;
                    t_m[k].col=m[j].row;
                    t_m[k].value=m[j].value;
                    k++;
                }
            }
        }
    }
}
int main()
{
    
    int nonz,r,c;
    printf("Entert the number of non zero elements");
    scanf("%d",&nonz);
    matrix m[nonz+1],t_m[nonz+1];
    m[0].value=nonz;
    printf("Enter the number of row and clumn");
    scanf("%d%d",&m[0].row, &m[0].col);

    printf("Enter the matrix u want");
     printf("\nRows Column Values\n");
    for(int i = 1; i <= nonz; i++){
   
            scanf("%d %d %d\n", &m[i].row, &m[i].col, &m[i].value);
    }
    printf("matrix before transpose:");
     printf("\nRows Column Values\n");
    for(int i=0;i<=nonz;i++){
  
            printf("%d %d %d\n", m[i].row, m[i].col, m[i].value);
    }
        sparsetranspose(m,t_m);
        printf("Sparse matrix representation after transpose\n");
    for (int i = 0; i <= nonz; i++)
        printf("%d %d %d\n", t_m[i].row, t_m[i].col, t_m[i].value);
    
}

