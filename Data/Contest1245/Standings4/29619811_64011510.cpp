#include <bits/stdc++.h>
#define pi acos(-1.0)
#define ll long long
#define lf double
#define ull unsigned long long
#define esp 1e-9
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define Pair pair<ll, ll>
#define It map<ll, ll>::iterator
#define CLR(x, a) memset(x, a, sizeof(x))
    
using namespace std;

const ll N = 1e3+5;
ll t, n, a, b, c;
char str[N], ans[N];

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--){
		cin>>n>>a>>b>>c;
		ll ta = 0, tb = 0, tc = 0;
		for (ll i = 1; i <= n; i++){
			cin>>str[i]; ans[i] = '0';
			if (str[i] == 'R') ta++;
			if (str[i] == 'P') tb++;
			if (str[i] == 'S') tc++;
		} 
		ll tmp = (n&1 ? n/2+1 : n/2);
		if (min(a, tc)+min(b, ta)+min(c, tb) >= tmp){
			cout<<"YES"<<'\n';
			ll tta = min(a, tc), ttb = min(b, ta), ttc = min(c, tb);
			for (ll i = 1; i <= n; i++){
				if (str[i]=='R' && ttb){
					ttb--, ans[i] = 'P';
				} 
				else if (str[i]=='P' && ttc){
					ttc--, ans[i] = 'S';
				} 
				else if (str[i]=='S' && tta){
					tta--, ans[i] = 'R';
				} 
			}
			tta = a-min(a, tc), ttb = b-min(b, ta), ttc = c-min(c, tb);
			for (ll i = 1; i <= n; i++){
				if (ans[i] == '0'){
					if (tta){
						tta--, ans[i] = 'R';
					} 
					else if (ttb){
						ttb--, ans[i] = 'P';
					} 
					else if (ttc){
						ttc--, ans[i] = 'S';
					} 	
				}
			}
			for (ll i = 1; i <= n; i++){
				cout<<ans[i];
			}
			cout<<'\n';
		}
		else{
			cout<<"NO"<<'\n';
		}
	}
	
	return 0;
}