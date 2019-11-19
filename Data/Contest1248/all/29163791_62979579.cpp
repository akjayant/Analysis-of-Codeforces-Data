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
	ll t;
	cin>>t;
	fr(h,0,t){
        ll n,m,la=0,lb=0,ra=0,rb=0,q;
        cin>>n;
        fr(i,0,n){
            cin>>q;
            if(q%2) la++;
            else ra++;
        }
        cin>>m;
        fr(i,0,m){
            cin>>q;
            if(q%2) lb++;
            else rb++;
        }
        cout<<la*lb+ra*rb<<'\n';
    }
	return 0;
}
