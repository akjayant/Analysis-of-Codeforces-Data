#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin >> n;
	ll ans = n;
	for(ll i=2; i*i<=n; i++)
	{
		if(n%i == 0)
		{
			ans = __gcd(ans, n/i);
			ans = __gcd(ans, i);
		}
	}
	cout << ans << endl;
}