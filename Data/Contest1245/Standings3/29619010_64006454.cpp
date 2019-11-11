#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll ((ll) 1e18 + 10)

#define endl '\n'
#define fi first
#define se second
#define pb emplace_back
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr<<#x<<": "<<(x)<<'\n'
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a)-1; i >= (b); i--)

const int N = 100010;
int n, cur['z'+1];
ll dp[N];
string s;

ll f() {
	if (s[0] == 'w') return 0;
	if (s[0] == 'm') return 0;
	cur[s[0]]++;
	ll ans=1;
	rep(i, 1, n) {
		if (s[i] == 'w') return 0;
		if (s[i] == 'm') return 0;
		if (s[i] != s[i-1]) {
			ans = ans*dp[cur['u']]%mod;
			ans = ans*dp[cur['n']]%mod;
			cur['u']=cur['n']=0;
		}
		cur[s[i]]++;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> s; s.push_back('z'); n=sz(s);
	dp[0]=dp[1]=1;
	rep(i, 2, n) dp[i] = (dp[i-1] + dp[i-2])%mod;
	cout << f() << endl;
}
