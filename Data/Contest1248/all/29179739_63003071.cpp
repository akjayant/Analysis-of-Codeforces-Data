#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxV = 90010;
const int maxN = 1e5+10;
const int MOD = 1e9+7;
const ll INF = 1000000000000000010LL;
const ll inf = 1e9+10;

ll a[maxN];
int cnt[maxN];
int b[maxN];
vector<int> v;
vector<int> s;

ll power(ll x,ll p)
{
	if(p == 0)
	{
		return 1;
	}
	ll t = power(x,p/2);
	t = t*t%MOD;
	if(p%2 == 1)
	{
		t = (t*x)%MOD;
	}
	return t;
}
ll C(ll n,ll m)
{
	ll X = a[n]*power(a[m],MOD-2)%MOD*power(a[n-m],MOD-2)%MOD;
	return X;
}
int main() {
	ll n,m;
	scanf("%lld%lld",&n,&m);
	a[0] = 1;
	for(int i=1;i<=100000;i++)
	{
		a[i] = (a[i-1])*i%MOD;
	}
	ll ans1 = 0;
	for(int x=1;x<=n/2;x++)
	{
		ans1 = (ans1+C(n-x,x))%MOD;
	}
	ans1 = (2*ans1)%MOD;
	ll ans2 = 0;
	for(int y=1;y<=m/2;y++)
	{
		ans2 = (ans2+C(m-y,y))%MOD;
	}
	ans2 = (2*ans2)%MOD;
	ll ans = (2 + ans1 + ans2)%MOD;
	cout<<ans<<endl;
    return 0;
}