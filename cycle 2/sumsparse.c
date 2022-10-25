#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} matrix;

int main()
{

    int s1, s2;
    printf("Enter the number of non zero elements in matrices: ");
    scanf("%d %d", &s1, &s2);

    matrix s_matrix_1[s1];
    printf("Enter the sparse representation of matrix 1: ");
    for (int i = 0; i < s1 + 1; i++)
        scanf("%d %d %d", &s_matrix_1[i].row, &s_matrix_1[i].col, &s_matrix_1[i].value);

    matrix s_matrix_2[s2];
    printf("Enter the sparse representation of matrix 2: ");
    for (int i = 0; i < s2 + 1; i++)
        scanf("%d %d %d", &s_matrix_2[i].row, &s_matrix_2[i].col, &s_matrix_2[i].value);
    // printf("Mat 1\n");
    // for (int i = 0; i <= s_matrix_1[0].value; i++)
    //     printf("%d %d %d\n", s_matrix_1[i].row, s_matrix_1[i].col, s_matrix_1[i].value);
    // printf("Mat 2\n");
    // for (int i = 0; i <= s_matrix_2[0].value; i++)
    //     printf("%d %d %d\n", s_matrix_2[i].row, s_matrix_2[i].col, s_matrix_2[i].value);

    if (s_matrix_1[0].row != s_matrix_2[0].row && s_matrix_1[0].col != s_matrix_2[0].col)
    {
        printf("Matrix dimesions are incompatiable\n");
        return 1;
    }

    matrix s_matrix_sum[s_matrix_1[0].value + s_matrix_2[0].value];

    s_matrix_sum[0].row = s_matrix_1[0].row;
    s_matrix_sum[0].col = s_matrix_1[0].col;

    int z = 1, x = 1, y = 1;

    for (int i = 0; i < s_matrix_1[0].row; i++)
        for (int j = 0; j < s_matrix_1[0].col; j++)
        {
            if (s_matrix_1[x].row == i && s_matrix_1[x].col == j && s_matrix_2[y].row == i && s_matrix_2[y].col == j)
            {
                s_matrix_sum[z].row = i;
                s_matrix_sum[z].col = j;
                s_matrix_sum[z].value = s_matrix_1[x].value + s_matrix_2[y].value;
                x++;
                y++;
                z++;
            }
            else if (s_matrix_1[x].row == i && s_matrix_1[x].col == j)
            {
                s_matrix_sum[z].row = i;
                s_matrix_sum[z].col = j;
                s_matrix_sum[z].value = s_matrix_1[x].value;
                x++;
                z++;
            }
            else if (s_matrix_2[y].row == i && s_matrix_2[y].col == j)
            {
                s_matrix_sum[z].row = i;
                s_matrix_sum[z].col = j;
                s_matrix_sum[z].value = s_matrix_2[y].value;
                y++;
                z++;
            }
        }
    s_matrix_sum[0].value = --z;

    printf("Sum\n");
    for (int i = 0; i <= s_matrix_sum[0].value; i++)
        printf("%d %d %d\n", s_matrix_sum[i].row, s_matrix_sum[i].col, s_matrix_sum[i].value);

    return 0;
}