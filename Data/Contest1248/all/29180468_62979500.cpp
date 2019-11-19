#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll tests; cin >> tests;
	for(ll t=0; t<tests; ++t){
		ll n; cin >> n;
		ll np=0, nd=0, mp=0, md=0;
		for(ll i=0; i<n; ++i){
			ll a; cin >> a;
			if(a & 1) ++nd;
			else ++np;
		}
		ll m; cin >> m;
		for(ll i=0; i<m; ++i){
			ll a; cin >> a;
			if(a & 1) ++md;
			else ++mp;
		}
		cout << ((np*mp) + (nd*md)) << endl;
	}
}
