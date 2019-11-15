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
	ll n;
	cin>>n;
	vector<vector<ll>> c(n,vector<ll>(n));
	ll k=1;
	fr(j,0,n){
	    if(j%2){
            for(ll i=n-1;i>=0;i--){
                c[i][j]=k;
                k++;
            }
	    } else {
	        fr(i,0,n){
                c[i][j]=k;
                k++;
            }
	    }
	}
	fr(i,0,n){
	    prv(c[i]);
	}
	return 0;
}
