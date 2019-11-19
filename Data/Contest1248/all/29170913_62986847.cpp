#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100008;

int n, a[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	ll x=0, y=0, z;
	for (int i = 0; i < n / 2; i++)
		x += a[i];
	for (int i = n / 2; i < n; i++)
		y += a[i];
	z = x * x + y * y;
	printf("%lld\n", z);
}