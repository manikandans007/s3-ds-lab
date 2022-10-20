#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the number of binary numbers: ");
    scanf("%d", &n);
    int bin[n][4];
    printf("Enter numbers\n");
    for (int i = 0; i <n; i++)
    {
        scanf("%d %d %d %d", &bin[i][0], &bin[i][1], &bin[i][2], &bin[i][3]);
    }
    for (int i = 0; i <n; i++)
    {
        printf("Entered binary numbers are :%d\t%d\t%d\t%d",bin[i][0],bin[i][1],bin[i][2],bin[i][3]);
    }
    for (int i = 0; i < n; i++)
    {
        int hex_value = bin[i][0] * pow(2, 3) + bin[i][1] * pow(2, 2) + bin[i][2] * pow(2, 1) + bin[i][3] * pow(2, 0);
        if (hex_value <= 9)
        {
            printf("Hexadecimal of given number is: %d\t", hex_value);
        }
        else
        {
            hex_value += (65 - 9 - 1);//ascii value of a=65
            printf("\nHexadecimal of given number is: %c\t", hex_value);
        }
    }

    return 0;
}
