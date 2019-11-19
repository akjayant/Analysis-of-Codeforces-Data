#include <bits/stdc++.h>
#define ll long long
#define db long double
#define prl(c) cout<<(c)<<"\n"
#define al(fu) (fu).begin(), (fu).end()
#define alr(fu) (fu).rbegin(), (fu).rend()
#define fr(i,l,n) for(ll i=l;i<(ll)n;i++)
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
	fr(d,0,t){
	ll a[5];
	fr(i,0,5) cin>>a[i];
	ll r=(a[0]-1)/a[2]+1,k=(a[1]-1)/a[3]+1;
	if(r+k>a[4]) prl(-1);
	else{
        cout<<r<<' '<<k;br;
	}
	}
	return 0;
}
