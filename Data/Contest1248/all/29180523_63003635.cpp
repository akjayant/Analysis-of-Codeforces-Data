#include <bits/stdc++.h>
#define pi acos(-1.0)
#define ll long long
#define lf double
#define ull unsigned long long
#define esp 1e-9
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define Pair pair<ll, ll>
#define It set<ll>::iterator
    
using namespace std;

const ll N = 1e5+5, mod = 1e9+7;
ll n, m;

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	ll col[N], row[N], tmp[N];
	col[1] = 2; col[2] = 4;
	tmp[1] = 0; tmp[2] = 2;
	row[1] = 0; row[2] = 2;
	for (ll i = 3; i <= max(n, m); i++){
		col[i] = (col[i-1]+col[i-2])%mod;
		tmp[i] = (tmp[i-1]+tmp[i-2])%mod;
		row[i] = (row[i-1]+tmp[i])%mod;
	}
	cout<<(col[n]%mod+row[m]%mod)%mod<<endl;
	
	return 0;
}