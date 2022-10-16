#include <stdio.h>

int main()
{
    int n1, n2;
    printf("Enter the number of elements in set 1: ");
    scanf("%d", &n1);
    int s1[n1];
    printf("Enter the elements of set 1: ");
    for (int i = 0; i < n1; i++)
        scanf("%d", &s1[i]);
    printf("Enter the number of elements in set 2: ");
    scanf("%d", &n2);
    int s2[n2];
    printf("Enter the elements of set 2: ");
    for (int i = 0; i < n2; i++)
        scanf("%d", &s2[i]);

    int n = (n1 > n2) ? n1 : n2;
    int s[n];

    int x = 0;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            if (s1[i] == s2[j])
            {
                int already_exists = 0;
                for (int k = 0; k < n; k++)
                    if (s[k] == s1[i])
                        already_exists = 1;
                if (!already_exists)
                {
                    s[x] = s1[i];
                    x++;
                }
            }

    printf("Intersection is: ");
    for (int i = 0; i < x; i++)
        printf("%d ", s[i]);
    printf("\n");

    return 0;
}
