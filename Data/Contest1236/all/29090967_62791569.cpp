#include<bits/stdc++.h>
using namespace std;
const int N =1e5+9;
const int mod = 1e9+7;
typedef long long ll;
ll fact[N];
int modpow(ll a,ll b){
	ll res = 1;
	while(b>0){
		if(b&1) res = (res*a)%mod;
		b/=2;
		a = (a*a)%mod;
	}
	return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll ans = modpow(2,m)-1;
    ans = (ans+mod)%mod;
    ans = modpow(ans,n);
	cout<<ans;
	return 0;
}