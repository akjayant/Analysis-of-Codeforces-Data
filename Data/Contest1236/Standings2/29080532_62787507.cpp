#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll pot(ll a, int b)
{
	ll ans = 1;
	for(int i = 1; i <= b; i <<= 1)
	{
		if(b&i)
			ans = (ans*a)%MOD;
		a = (a*a)%MOD;
	}
	return ans;
}

main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%lld\n", pot(pot(2, m)-1, n));
	return 0;
}