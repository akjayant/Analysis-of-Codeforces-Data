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
#define CLR(x, a) memset(x, a, sizeof(x))
    
using namespace std;

const ll N = 1e3+5, mod = 1e9+7;
ll n, ans[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	ll cnt = 1;
	for (ll i = 1; i <= n; i++){
		if (i & 1){
			for (ll j = 1; j <= n; j++){
				ans[j][i] = cnt++;
			}
		}
		else{
			for (ll j = n; j >= 1; j--){
				ans[j][i] = cnt++;
			}
		}
	}
	for (ll i = 1; i <= n; i++){
		for (ll j = 1; j <= n; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}