#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<cstdio>
#include<cmath>
#include<set>
#include<algorithm>
#include<vector>
#define inf 0x3f3f3f3f
#define PI acos(-1)
#define eps 1e-6
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	ll n;
	cin>>n;
	ll ans=n;
	for (ll i=2;i*i<=n;i++)
	{
		if (n%i==0)
		{
			ans=gcd(ans,i);
			ans=gcd(ans,n/i);
		}
	}
	cout<<ans;
    return 0;
}

