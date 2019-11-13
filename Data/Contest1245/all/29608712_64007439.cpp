#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 1e9+7;

ll dp[100010];
string s;

int main() {
	fast;

	cin >> s;

	dp[0] = dp[1] = 1;
	for(int i=2; i<=s.size(); i++) {
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] %= Mod;
	}

	ll ans = 1;

	for(int i=0; i<s.size(); ) {
		if(s[i] == 'm' || s[i] == 'w') {
			cout << 0;
			return 0;
		}
		if(s[i] != 'u' && s[i] != 'n') {
			i++;
			continue;
		}

		int t = i;
		while(t < s.size() && s[t] == 'u') t++;
		ans *= dp[t-i];
		ans %= Mod;

		i = t;
		while(t < s.size() && s[t] == 'n') t++;
		ans *= dp[t-i];
		ans %= Mod;

		i = t;
	}

	cout << ans;
}