#include <cstdio>
#include <iostream>
typedef long long ll;
const ll mod=1e9+7;
using namespace std;

ll quick_mod(ll a,ll b) {
	ll ans=1,res=a;
	while(b){
		if(b&1) ans=ans*res%mod;
		res=res*res%mod;
		b>>=1;
	}
	return ans%mod;
}

ll n,m,t;

int main() {
	cin >> n >> m;
	t=(quick_mod(2LL,m)-1LL+mod)%mod;
	cout << quick_mod(t,n) << endl;
	return 0;
}