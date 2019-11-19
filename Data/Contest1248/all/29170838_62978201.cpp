#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define maxn 100111
#define ll long long 
const ll mod = 1e9+7;

ll qpow(ll a,ll n){
	ll ret = 1LL;
	while(n){
		ret = n&1LL?ret*a%mod:ret;
		n >>= 1;
		a = a*a%mod;
	}
	return ret;
}

int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int T;
	int n,m;
	cin>>T;
	while(T--){
		cin>>n;
		ll t1,t2,t3,t4;
		t1 = t2 = t3 = t4 = 0;
		for(int i=0,x;i<n;i++){
			cin>>x;
			t1 += x&1?1:0;
			t2 += x&1?0:1;
		}
		cin>>m;
		for(int i=0,x;i<m;i++){
			cin>>x;
			t3 += x&1?1:0;
			t4 += x&1?0:1;
		}
		ll ans = t1*t3+t2*t4;
		cout<<ans<<endl;
	}

	return 0;
}