#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <map>
#include <bitset>
#include <queue>
#include <functional>  
#include <numeric>      
#include <assert.h>

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piii;
typedef pair<pll, ll>plll;
typedef pair<int, ll>pil;

ll MOD = 1000 * 1000 * 1000 + 7;

ll f(int cur, string &s, vll &dp) {
	if (cur >= s.size()) return  1;
	if (s[cur] == 'm' || s[cur] == 'w') return 0;

	if (dp[cur] != -1) return dp[cur];
	ll ans = 0;

	if (cur + 1 < s.size() && s[cur] == 'u' && s[cur + 1] == 'u') {
		ll keep = f(cur + 1, s, dp);
		ll change = f(cur + 2, s, dp);
		ans = (keep + change) % MOD;
	}
	else if (cur + 1 < s.size() && s[cur] == 'n' && s[cur + 1] == 'n') {
		ll keep = f(cur + 1, s, dp);
		ll change = f(cur + 2, s, dp);
		ans = (keep + change) % MOD;
	}
	else {
		ans = f(cur + 1, s, dp);
	}
	return dp[cur] = ans % MOD;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	string s;
	cin >> s;

	vll dp((int)s.size() + 1, -1);

	cout << f(0, s, dp) << "\n";
}