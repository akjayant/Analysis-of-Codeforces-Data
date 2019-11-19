#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

const int N = 1e5 + 777;
int a[N];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	long long mi = 0, mx = 0;
	for (int i = n, j = 1; i >= j; --i, ++j)
	{
		if (i == j) mx += a[i];
		else {
			mx += a[i];
			mi += a[j];
		}
	}
	printf("%lld\n", mi * mi + mx * mx);
}