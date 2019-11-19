#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int unions[10000000];
LL n;
vector <LL> soinsu;
int findpa(int k)
{
	if (unions[k] == k)
		return k;
	return unions[k] = findpa(unions[k]);
}
void hap(int a, int b)
{
	unions[findpa(b)] = findpa(a);
}
int main()
{
	scanf("%lld", &n);
	for (int i = 2; (long long int)i*i <= n; i++)
	{
		if (n%i == 0)
		{
			soinsu.push_back(i);
			while (n%i == 0)
			{
				n /= i;
//				printf("//%d//\n", n);
			}
		}
		if (n == 3)
		{
			soinsu.push_back(3);
		}
	}
	if (soinsu.empty())
	{
		printf("%lld", n);
		return 0;
	}
	if (n > 1)
		soinsu.push_back(n);
	int sizz = soinsu.size();
	if (sizz > 1)
	{
		printf("1");
		return 0;
	}
	sort(soinsu.begin(), soinsu.end());
	printf("%lld", soinsu.front());
	return 0;
	int unionsize = soinsu.front();
	for (int i = 1; i <= unionsize; i++)
		unions[i] = i;
	for (int i = 1; i <= unionsize; i++)
	{
		for (int j = 1; j < sizz; j++)
		{
				hap(i, soinsu[j]);
		}
	}
	int dap = 0;
	for (int i = 1; i <= unionsize; i++)
	{
		if (unions[i] == i)
			dap++;
	}
	printf("%d", dap);
}