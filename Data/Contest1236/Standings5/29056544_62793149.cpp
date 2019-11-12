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
using namespace std;

ll st(ll a,ll b){
    if(!b) return 1;
    if(b%2) return (st(a,b-1)*a)%mods;
    ll e=st(a,b/2);
    return (e*e)%mods;
}

int main() {
	iosync;
	ll n,m;
	cin>>n>>m;
	ll t=st(2,m)-1;
	cout<<st(t,n);
	return 0;
}
