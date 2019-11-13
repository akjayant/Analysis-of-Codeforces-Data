#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define mkp make_pair
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<62);
const int inf=(1<<30);
const int nmax=1e5+50;
const ll mod=1e9+7;
using namespace std;
ll n,m,x;
ll pw(ll x,ll p)
{
	ll ans=1;
	while(p)
	{
		if(p&1LL)ans=(ans*x)%mod;
		x=(x*x)%mod;
		p>>=1LL;
	}
	return ans;
}
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>n>>m;
	x=(pw(2,m)-1+mod)%mod;
	x=pw(x,n);
	cout<<x<<endl;
	return 0;
}
