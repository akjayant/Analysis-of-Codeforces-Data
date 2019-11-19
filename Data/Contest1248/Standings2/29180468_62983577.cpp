#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l[100100];

int main(){
	ll n; cin >> n;
	for(ll i=0; i<n; ++i){
		cin >> l[i];
	}
	sort(l, l+n);
	ll sumv=0, sumh=0;
	for(ll i=0; i<n/2; ++i){
		sumv+=l[i];
	}
	for(ll i=n/2; i<n; ++i){
		sumh+=l[i];
	}
	cout << ((sumv*sumv) + (sumh*sumh)) << endl;
}
