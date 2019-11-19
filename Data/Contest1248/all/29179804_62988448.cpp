#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=1e5+10;

ll f[N], n, m;

int main() {
	f[1]=1;
	f[2]=2;
	for(int i=3; i<=100000; i++) {
		f[i]=f[i-1]+f[i-2];
		f[i]%=mod;
	}
	cin>>n>>m;
	ll ans=(f[n]+f[m]-1+mod)*2%mod;
	cout<<ans<<endl;
	return 0;
}
