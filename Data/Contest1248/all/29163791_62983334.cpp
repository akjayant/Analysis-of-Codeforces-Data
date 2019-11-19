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
	ll n;
	cin>>n;
	vector<ll> a(n);
	fr(i,0,n) cin>>a[i];
	sort(al(a));
	ll l=0,r=0;
	fr(i,0,n/2) l+=a[i];
	fr(i,n/2,n) r+=a[i];
	cout<<l*l+r*r;
	return 0;
}
