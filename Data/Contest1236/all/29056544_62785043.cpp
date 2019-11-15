#include <bits/stdc++.h>
#define ll long long
#define db long double
#define prl(c) cout<<(c)<<"\n"
#define al(fu) (fu).begin(), (fu).end()
#define alr(fu) (fu).rbegin(), (fu).rend()
#define fr(i,l,n) for(unsigned int i=l;i<(unsigned int)n;i++)
#define mod 998244353
#define mods 1000000007
#define pi 3.14159265359
#define br cout<<"\n"
#define prv(v) fr(qz,0,v.size()) cout<<(v)[qz]<<' '; br
#define iosync ios::sync_with_stdio(0)
using namespace std;

int main() {
	iosync;
	ll t;
	cin>>t;
	fr(h,0,t){
	    ll a[3];
	    fr(i,0,3) cin>>a[i];
	    ll c=min(a[1],a[2]/2);
	    a[1]-=c;
	    prl(c*3+min(a[1]/2,a[0])*3);
	}
	return 0;
}
