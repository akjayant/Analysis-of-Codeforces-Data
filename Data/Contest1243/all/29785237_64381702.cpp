#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define vll vector<ll>

using namespace std;

const ll N = 3e5+100;
const ll MOD = 1e9+7;

int main()
{

	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin>> n;
		ll a[n+1];
		for(int i =1;i<=n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		ll ans= 0;
		for(int i =1;i<=n;i++)
		{
			ans = max(ans,  min(a[i],n-i+1));
		}
		cout << ans << endl;
	}
	
	return 0;
}