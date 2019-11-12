#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define se second
#define fi first
#define pb push_back
#define eb emplace_back
#define mk make_pair

#define N 1000007 //10e6 +7

ll fexp(ll a, int x, ll mod){		// Fast exponenciation returns a^x % mod
	if(x==0)return 1ll;
	if(x%2==0){
		ll y=fexp(a, x/2, mod);
		return (y*y)%mod;
	}
	return (a*fexp(a, x-1, mod))%mod;
}

int main(){
	ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll h = fexp(2, m, 1000000007) -1;
	cout << fexp(h, n, 1000000007) << endl;
}