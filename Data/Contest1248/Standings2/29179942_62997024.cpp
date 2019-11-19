#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;
ll mod = 1e9+7;

ll f(ll n){
	if(n==1) return 2;
	if(n==2) return 4;
	ll e11=1,e00=1,e01=1,e10=1;
	for(ll j = 3; j <= n; j++){
	ll ne11=e01, ne00=e10, ne01=(e10+e00)%mod, ne10=(e01+e11)%mod;
		e11=ne11;e00=ne00;e01=ne01;e10=ne10;
	}
	return (e11+e00+e01+e10)%mod;
}

main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	bool ok = (n*m>0);
	if(!ok){
		cout<<0;
		return 0;
	}
	ll a1 = f(n);
	ll b1 = f(m);
	ll dv = -2;
	cout<<((a1 + b1 + dv)%mod + mod)%mod;
}
