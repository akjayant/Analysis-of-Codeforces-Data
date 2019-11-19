#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	long long x = 0LL, y = 0LL;
	int i = 1;
	for(; i <= (n) / 2; i ++)
	{
		y += a[i];
	}
	for(; i <= n; i ++)
	{
		x += a[i]; 
	}
	printf("%lld\n", x * x + y * y);
	return 0;
}