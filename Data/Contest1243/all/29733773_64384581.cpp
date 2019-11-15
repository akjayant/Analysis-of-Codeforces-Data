#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vec vector
#define psb push_back
#define ppb pop_back
#define mkp make_pair
#define fst first
#define scd second
#define ins insert
#define psf push_front
#define ppf pop_front
using namespace std;
ll modExp(ll a, ll b, ll c) {
	a %= c;
	ll ans = 1;
	for(; b; b >>= 1) {
		if(b & 1){
			ans *= a;
			ans %= c;
		}
		a *= a;
		a %= c;
	}
	return ans;
}
int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll k,n;
	cin>>k;
	string s,t;
	while(k--){
		cin>>n>>s>>t;
		ll i;
		vec<pair<ll,ll> > a;
		for(i=0;i<n;i++){
			if(s[i]!=t[i]){
				a.psb({s[i],t[i]});
			}
		}
		if(a.size()!=2 || a[0]!=a[1]){
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
		}
	}
	return 0;
}
