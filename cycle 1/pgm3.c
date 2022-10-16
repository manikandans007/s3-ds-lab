#include <stdio.h>

int main()
{
    char str[100];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    int freq[256];
    for (int i = 0; i < 256; i++)
        freq[i] = 0;

    for (int i = 0; str[i] != '\0'; i++)
        freq[str[i]]++;

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] == 0)
            continue;
        if (i == '\n')
            continue;
        printf("'%c' - %d\n", i, freq[i]);
    }

    return 0;
}
