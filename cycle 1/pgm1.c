#include <stdio.h>
#include <string.h>

void rotate(int a[], int n, int d, int cr)
{
	if (cr == 0)
		return;
	int x, res[n];
	switch (d)
	{
	case 'l':
		x = n - cr;
		while (x <= 0)
			x += n;
		break;
	case 'r':
		x = cr;
		while (x >= (n - 1))
			x -= n;
		break;
	}
	for (int i = 0; i < n; i++, x++)
	{
		res[x] = a[i];
		if (x >= (n - 1))
			x -= n;
	}
	memcpy(a, res, sizeof(res));
}

int main()
{
	int n;
	char d;
	int cr;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter the elements: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Enter the direction to rotate (l or r): ");
	scanf(" %c", &d);

	printf("Enter the count of rotation");
	scanf("%d", &cr);

	rotate(a, n, d, cr);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
