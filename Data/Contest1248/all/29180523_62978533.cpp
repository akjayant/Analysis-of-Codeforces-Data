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
ll t, n, m, p;

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while (t--){
    	cin>>n;
    	ll a = 0, b = 0;
    	for (ll i = 1; i <= n; i++){
    		cin>>p;
    		if (p & 1){
    			a++;
			}
			else{
				b++;
			}
		}
		ll ans = 0;
		cin>>m;
    	for (ll i = 1; i <= m; i++){
    		cin>>p;
    		if (p & 1){
    			ans += a;
			}
			else{
				ans += b;
			}
		}
		cout<<ans<<endl;
	}
    
    return 0;
}