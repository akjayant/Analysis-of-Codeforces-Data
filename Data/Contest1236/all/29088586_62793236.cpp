#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll M = 1e9 + 7;
ll exp(ll n, ll m){
	ll ans = 1;
	while(m){
		if(m&1){
			ans = (ans*n)%M;
		}
		n = (n*n)%M;
		m = m >> 1;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll n, m;
	cin>>n>>m;
	cout<<exp(exp(2, m) - 1, n)<<endl;
	return 0;
}