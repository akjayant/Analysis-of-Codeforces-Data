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

const ll N = 1e5+5;
ll t, a, b, c;

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--){
		cin>>a>>b>>c;
		ll ans = 0;
		for (ll i = 0; i <= b; i++){
			ll tmp = 0;
			if (2*i <= c){
				tmp += 3*i;
			}
			else{
				tmp += 3*(c/2);
			}
			ll t = b-i;
			if (t/2 >= a){
				tmp += 3*a;
			}
			else{
				tmp += 3*(t/2);
			}
			ans = max(ans, tmp);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}