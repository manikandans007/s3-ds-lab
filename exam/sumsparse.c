#include<stdio.h>
typedef struct {
    int row;
    int col;
    int value;
}matrix;

int main(){
    int s1,s2,s3,d;
    printf("enter the no of non zero elements of matrix1&2:");
    scanf("%d %d",&s1,&s2);
    printf("enter the matrix1 elements u wants");
    matrix sparse1[s1];
    
    printf("Row Column Value");
    for(int i = 1;i<=s1;i++){
        
        scanf("%d %d %d",&sparse1[i].row, &sparse1[i].col, &sparse1[i].value);
    }
     printf("enter the matrix2 elements u wants");
    matrix sparse2[s2];
    printf("Row Column Value");
    for(int i = 1;i<=s2;i++){
        
        scanf("%d %d %d",&sparse2[i].row, &sparse2[i].col, &sparse2[i].value);
    }
     matrix sparseSum[100];
   sparseSum[0].row = sparse1[0].row;
    sparseSum[0].col = sparse1[0].col;
    int i = 1, j = 1, k = 1;
    while (i < s1 && j <s2)
    {
        if (sparse1[i].row == sparse2[j].row && sparse1[i].col == sparse2[j].col) 
        {
            sparseSum[k].row = sparse1[i].row;
            sparseSum[k].col = sparse1[i].col;
            sparseSum[k].value = sparse1[i].value + sparse2[j].value;
            i++;
            j++;
        }
        else if (sparse1[i].row == sparse2[j].row) 
        {
            sparseSum[k].row = sparse1[i].row;
            if (sparse1[i].col < sparse2[j].col && i < s1)
            {
                sparseSum[k].col = sparse1[i].col;
                sparseSum[k].value = sparse1[i].value;
                i++;
            }
            else 
            {
                sparseSum[k].col = sparse2[j].col;
                sparseSum[k].value = sparse2[j].value;
                j++;
            }
        }
        else 
        {
            if (sparse1[i].row < sparse2[j].row) 
            {
                sparseSum[k].row = sparse1[i].row;
                sparseSum[k].col = sparse1[i].col;
                sparseSum[k].value = sparse1[i].value;
                i++;
            }
            else 
            {
                sparseSum[k].row = sparse2[j].row;
                sparseSum[k].col = sparse2[j].col;
                sparseSum[k].value = sparse2[j].value;
                j++;
            }
        }
        k++;
    }
    while (i < s1) 
    {
        sparseSum[k].row = sparse1[i].row;
        sparseSum[k].col = sparse1[i].col;
        sparseSum[k].value = sparse1[i].value;
        k++;
        i++;
    }
    while (j < s2) 
    {
        sparseSum[k].row = sparse2[j].row;
        sparseSum[k].col = sparse2[j].col;
        sparseSum[k].value = sparse2[j].value;
        k++;
        j++;
    }
    s3 = k;
    sparseSum[0].value = k - 1;
    printf("Sum\n");
    for (int i = 0; i <= sparseSum[0].value; i++)
        printf("%d %d %d\n", sparseSum[i].row, sparseSum[i].col, sparseSum[i].value);

    return 0;
}

    

