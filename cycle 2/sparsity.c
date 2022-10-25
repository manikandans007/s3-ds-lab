#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} matrix;

int main()
{
    matrix s_matrix[100];
    int m, n;

    printf("Enter the number of rows and coloumns: ");
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    int number_of_non_zero_elements = 0;
    s_matrix[0].row = m;
    s_matrix[0].col = n;
    for (int i = 0, z = 1; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                number_of_non_zero_elements++;
                s_matrix[z].row = i;
                s_matrix[z].col = j;
                s_matrix[z].value = matrix[i][j];
                z++;
            }
        }
    s_matrix[0].value = number_of_non_zero_elements;

    float sparsity = (float)(s_matrix[0].row * s_matrix[0].col - s_matrix[0].value) / (s_matrix[0].row * s_matrix[0].col);
    printf("Sparsity = %0.3f\n", sparsity);

    printf("Sparse matrix representation\n");
    for (int i = 0; i <= number_of_non_zero_elements; i++)
        printf("%d %d %d\n", s_matrix[i].row, s_matrix[i].col, s_matrix[i].value);

  
}