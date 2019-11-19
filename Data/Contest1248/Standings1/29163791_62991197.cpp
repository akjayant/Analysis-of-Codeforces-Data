#include <bits/stdc++.h>
#define ll long long
#define db long double
#define prl(c) cout<<(c)<<"\n"
#define al(fu) (fu).begin(), (fu).end()
#define alr(fu) (fu).rbegin(), (fu).rend()
#define fr(i,l,n) for(ll i=l;i<(ll)n;i++)
#define mod 998244353LL
#define mods 1000000007LL
#define pi 3.14159265359
#define br cout<<"\n"
#define prv(v) fr(qz,0,v.size()) cout<<(v)[qz]<<' '; br
#define iosync ios::sync_with_stdio(0)
#define pump(a,b) push_back(make_pair(a,b))

using namespace std;
int main() {
	iosync;
	ll n,m;
	cin>>n>>m;
	vector<ll> a(2);
	a[0]=2;
	a[1]=4;
	fr(i,2,max(n,m)) a.push_back((a[i-1]+a[i-2])%mods);
	ll c=(a[n-1]+a[m-1]-2)%mods;
	if(c<0) c+=mods;
	cout<<c;
	return 0;
}
