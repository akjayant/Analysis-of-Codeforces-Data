#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1000000007;
ll dps[100100];
ll dpp[100100];

int main(){
	ll n, m; cin >> n >> m;
	dps[1]=2;
	dpp[1]=0;
	for(int i=2; i<=max(n, m); ++i){
		dpp[i]=dps[i-1];
		dps[i]=(dps[i-1] + dpp[i-1])%mod;
	}
	ll ans=(dps[m]+dpp[m]+dps[n]+dpp[n]-2)%mod;
	cout << ans << endl;
}
