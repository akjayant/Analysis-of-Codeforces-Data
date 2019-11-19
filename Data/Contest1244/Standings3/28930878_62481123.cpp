#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define maxn 1005
#define line; printf("========");
#define endl '\n'
int main() {
	std::ios::sync_with_stdio(false);
//	int n, m;
//	int a, c, b, d;
	ll n, p, w, d;
	cin>>n>>p>>w>>d;
	if(n*w < p) {
		cout<<"-1"<<endl;
		return 0;
	}
	if(p%w==0) {
		ll k = p/w;
		cout<<k<<" "<<0<<" "<<n-k<<endl;
		return 0;
	}
	if(p%d==0 && p/d <= n) {
		ll k = p/d;
		cout<<0<<" "<<k<<" "<<n-k<<endl;
		return 0;
	}
	if(p==0) {
		cout<<0<<" "<<0<<" "<<n<<endl;
		return 0;
	}
	bool f = 1;
	for(ll i = 1; i <= w-1; i++) {
		ll h = p-i*d;
		if(h < 0) {
			break;
		}
		if(h%w==0) {
			ll k = h/w;
			if(k+i <= n) {
				cout<<k<<" "<<i<<" "<<n-(k+i)<<endl;
				return 0;
			}
		}
	}
	for(ll i = 1; i <= d-1; i++) {
		ll h = p-i*w;
		if(h < 0) {
			break;
		}
		if(h%d==0) {
			ll k = h/d;
			if(k+i <= n) {
				cout<<i<<" "<<k<<" "<<n-(k+i)<<endl;
				return 0;
			}
		}
	}
	cout<<"-1"<<endl;


	return 0;
}