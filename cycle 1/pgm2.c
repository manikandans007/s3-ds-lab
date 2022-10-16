#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int l[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &l[i]);

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (l[j + 1] < l[j])
            {
                int temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            }

    int sum = 0;
    float median = (float)(n % 2 == 0) ? (l[n / 2 - 1] + l[n / 2]) / 2.0 : l[n / 2];
    int mode = l[0], count = 0, max_count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += l[i];
        for (int j = 0; j < n; j++)
        {
            if (l[j] == l[i])
                count++;
        }
        if (count > max_count)
        {
            mode = l[i];
            max_count = count;
        }
        count = 0;
    }
    float mean = (float)sum / n;

    printf("Mean: %0.1f\n", mean);
    printf("Median: %0.1f\n", median);
    printf("Mode: %d\n", mode);
}
