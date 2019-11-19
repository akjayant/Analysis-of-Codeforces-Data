#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define maxn 100111
#define ll long long 
#define ull unsigned long long 
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

ull a[maxn];

int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n;
	while(cin>>n){
		ull t2 = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			t2 += a[i];
		}
		sort(a,a+n);
		int cnt = n/2;
		ull t1 = 0;
		for(int i=0;i<cnt;i++){
			t1 += a[i];
		}
		t2 -= t1;

		cout<<t1*t1+t2*t2<<endl;
	}
	return 0;
}