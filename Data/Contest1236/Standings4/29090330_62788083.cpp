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

ll fast_pow(ll val, ll k){
	if(k==0) return 1;
	if(k%2==0){
		ll ans = fast_pow(val,k/2);
		return (ans*ans)%mod;
	}else{
		ll ans = fast_pow(val,k-1);
		return (ans*val)%mod;
	}
}

main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	cout<<fast_pow(((fast_pow(2,m)-1)%mod+mod)%mod,n); 
}

