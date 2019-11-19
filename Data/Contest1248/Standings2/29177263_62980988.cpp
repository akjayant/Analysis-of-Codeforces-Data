#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+7;
int a[N];
int main()
{
	int n;
	ll s1 = 0, s2 = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		s1 += a[i];
	}
	sort(a+1, a+1+n);
	for(int i = 1; i <= (n>>1); i++)
	{
		s2 += a[i];
	}
	printf("%lld\n", s2*s2+(s1-s2)*(s1-s2));
	return 0;
}
