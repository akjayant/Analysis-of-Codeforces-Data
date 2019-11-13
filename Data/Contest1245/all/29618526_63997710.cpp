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

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	cin >> s;
	ll n = s.size();
	for(auto x : s) if(x == 'w' || x == 'm') return cout << 0, 0; 
	dp[0] = 1;
	dp[1] = 1;
	s = '!' + s;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1];
		if(s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')) dp[i] += dp[i - 2];
		dp[i] %= Mod;
	}
	cout << dp[n];
	return 0;
}
