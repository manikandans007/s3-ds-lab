#include <stdio.h>

typedef struct
{
    int coeff;
    int expo;
} polynomial;

int main()
{
    int size1, size2;
    printf("Enter the size of both polynomials: ");
    scanf("%d %d", &size1, &size2);
    polynomial p1[size1], p2[size2], sum[size1 + size2];

    printf("Enter the coefficient and power of the polynomial 1 in descending order:\n");
    printf("For example, 3x^2+2x+1 can be entered as 3 2  2 1  1 0\n");
    for (int i = 0; i < size1; i++)
        scanf("%d %d", &p1[i].coeff, &p1[i].expo);
    printf("Enter the coefficient and power of the polynomial 2 in descending order:\n");
    printf("For example, 3x^2+2x+1 can be entered as 3 2  2 1  1 0\n");
    for (int i = 0; i < size2; i++)
        scanf("%d %d", &p2[i].coeff, &p2[i].expo);

    printf("Polynomial 1\n");
    for (int i = 0; i < size1; i++)
        printf("%dx^%d ", p1[i].coeff, p1[i].expo);
    printf("\n");
    printf("Polynomial 2\n");
    for (int i = 0; i < size2; i++)
        printf("%dx^%d ", p2[i].coeff, p2[i].expo);
    printf("\n");

    int i = 0, j = 0, z = 0;
    while (i < size1 && j < size2)
    {
        if (p1[i].expo > p2[j].expo)
        {
            sum[z].expo = p1[i].expo;
            sum[z].coeff = p1[i].coeff;
            i++;
            z++;
        }
        else if (p1[i].expo < p2[j].expo)
        {
            sum[z].expo = p2[j].expo;
            sum[z].coeff = p2[j].coeff;
            j++;
            z++;
        }
        else
        {
            sum[z].expo = p1[i].expo;
            sum[z].coeff = p1[i].coeff + p2[j].coeff;
            z++;
            i++;
            j++;
        }
    }
    while (i < size1)
    {
        sum[z].expo = p1[i].expo;
        sum[z].coeff = p1[i].coeff;
        i++;
        z++;
    }
    while (j < size2)
    {
        sum[z].expo = p2[j].expo;
        sum[z].coeff = p2[j].coeff;
        j++;
        z++;
    }

    printf("Sum\n");
    for (int i = 0; i < z; i++)
        printf("%dx^%d ", sum[i].coeff, sum[i].expo);
    printf("\n");

    return 0;
}