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
	while(k--){
		cin>>n;
		ll a[n],i;
		for(i=0;i<n;i++)
			cin>>a[i];
		map<ll,ll> b;
		for(i=0;i<n;i++)
			b[a[i]]++;
		map<ll,ll>::reverse_iterator rit = b.rbegin(), rjt;
		rjt = rit;
		++rjt;
		ll ans = min(rit->fst, rit->scd);
		if(b.size()==1) {
			cout << ans << '\n';
			continue;
		}
		for(;rjt!=b.rend();rjt++,rit++) {
			rjt->scd += rit->scd;
			ans = max(min(rjt->fst, rjt->scd), ans);
		}
		cout << ans << '\n';
	}
	return 0;
}
