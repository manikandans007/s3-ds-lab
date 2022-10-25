#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} matrix;

void sparseTranspose(matrix m[], matrix t_m[])
{

    int n = m[0].value;
    t_m[0].row = m[0].col;
    t_m[0].col = m[0].row;
    t_m[0].value = m[0].value;

    int current_t = 1;
    if (n > 0)
    {
        current_t = 1;
        for (int i = 0; i < m[0].col; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (m[j].col == i)
                {
                    t_m[current_t].row = m[j].col;
                    t_m[current_t].col = m[j].row;
                    t_m[current_t].value = m[j].value;
                    current_t++;
                }
            }
        }
    }
}

int main()
{
    int size;
    printf("Enter the number of non zero elements: ");
    scanf("%d", &size);

    matrix m[size + 1], t_m[size + 1];
    m[0].value = size;

    printf("Enter the number of rows and coloumns: ");
    scanf("%d %d", &m[0].row, &m[0].col);

    printf("Enter the sparse matrix representation: ");
    for (int i = 1; i <= size; i++)
        scanf("%d %d %d", &m[i].row, &m[i].col, &m[i].value);

    printf("Sparse matrix representation before transpose\n");
    for (int i = 0; i <= size; i++)
        printf("%d %d %d\n", m[i].row, m[i].col, m[i].value);

    sparseTranspose(m, t_m);

    printf("Sparse matrix representation after transpose\n");
    for (int i = 0; i <= size; i++)
        printf("%d %d %d\n", t_m[i].row, t_m[i].col, t_m[i].value);
}