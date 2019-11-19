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
	    ll n;
	    cin>>n;
	    string s;
	    cin>>s;
	    vector<ll> l;
	    fr(i,0,n){
	        if(s[i]=='1') l.push_back(i);
	    }
	    if(l.empty()) prl(n);
	    else if(l.size()==1) prl(max((l[0]+1)*2,(n-l[0])*2));
	    else prl(max((l.back()+1)*2,(n-l[0])*2));
	}
	return 0;
}
