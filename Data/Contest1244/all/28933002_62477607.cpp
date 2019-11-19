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
	ll n;
	cin>>n;
	vector<vector<ll>> c(3,vector<ll>(n)),w(n);
	fr(j,0,3) fr(i,0,n){
	    cin>>c[j][i];
	}
	fr(i,0,n-1){
	    ll g,q;
	    cin>>g>>q;
	    w[g-1].push_back(q-1);
	    w[q-1].push_back(g-1);
	}
	int b=0,boss;
	fr(i,0,n){
	    if(w[i].size()<2) boss=i;
	    if(w[i].size()>2) b=1;
	}
	if(b){
        cout<<-1;
        return 0;
	}
	vector<vector<ll>> k(6);
	k[0].resize(3);
	fr(i,1,3) k[0][i]=k[0][i-1]+1;
	fr(i,1,6){
	    k[i]=k[i-1];
	    next_permutation(al(k[i]));
	}
	vector<ll> e(n);
	vector<bool> be(n);
	e[0]=boss;
	if(n>1) e[1]=w[boss][0];
	be[boss]=1;
	fr(i,1,n){
	    be[e[i]]=1;
	    for(ll g:w[e[i]]) if(!be[g]) e[i+1]=g;
	}
	ll cr=0,cv=0;
	fr(i,0,n) cr+=c[k[0][i%3]][e[i]];
	fr(j,1,6){
	    ll cd=0;
	    fr(i,0,n) cd+=c[k[j][i%3]][e[i]];
	    if(cd<cr){
            cr=cd;
            cv=j;
	    }
	}
	vector<ll> o(n);
	fr(i,0,n) o[e[i]]=k[cv][i%3]+1;
	prl(cr);
	prv(o);
	return 0;
}
