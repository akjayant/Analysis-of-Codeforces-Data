#include <stdio.h>
#include <math.h>

long long n;
int a[1000010];

int main(void)
{
	int i, j, sq, ok = 0, p, z = 1;
	long long nn;

	scanf("%lld", &n);
	sq = sqrt(n);
	for (i = 2; i <= sq; i++)
		a[i] = 1;
	for (i = 2; i <= sq; i++)
		if (a[i])
		{
			if (n%i == 0)
			{
				ok = 1;
				p = i;
				break;
			}

			for (j = i * 2; j <= sq; j += i)
				a[j] = 0;
		}
	nn = n;
	while (nn != 1 && z && ok)
	{
		if (nn%p != 0)
			z = 0;
		else
			nn /= p;
	}


	if (!ok)
		printf("%lld", n);
	else if (z)
		printf("%d", p);
	else
		printf("1");

	return 0;
}