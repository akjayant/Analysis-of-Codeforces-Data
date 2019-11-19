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

	ll n;
	cin >>n;

	ll g = n;
	for(ll i =2;i<=sqrt(n);i++)
	{
		if(n % i == 0)
		{
			ll x = n/i;
			g = __gcd(g,x);
			g = __gcd(g,i);
		}
	}
	
	cout <<g << endl;

	return 0;
}