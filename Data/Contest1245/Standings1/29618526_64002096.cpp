#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll dp[Maxn];
char ans[Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	
	cin >> t;
	ll n, a, b, c;
	str s;
	for(int i = 0; i < t; i++){
		cin >> n >> a >> b >> c >> s;
		fill(ans, ans + n, '.');
		ll cnt = n;
		for(int j = 0; j < n; j++){
			//cerr << a << b << c << '\n';
			if(s[j] == 'R' && b){
				ans[j] = 'P';
				b--;
			}
			else if(s[j] == 'S' && a){
				ans[j] = 'R';
				a--;
			}
			else if(s[j] == 'P' && c){
				ans[j] = 'S';
				c--;	
			}
			else {
				ans[j] = '.';
				cnt --;
			}
		}
		if(cnt < (n + 1) / 2) {
			cout << "NO\n";
			continue;
		}
		for(int j = 0; j <n;j++){
			if(ans[j] == '.'){
				if(a) ans[j] = 'R', a--;
				else if(b) ans[j] = 'P', b--;
				else ans[j] = 'S', c--;
			}
		}
		cout << "YES\n";
		for(int j = 0; j <n; j++) cout << ans[j];
		cout << '\n';
	}
	return 0;
}
