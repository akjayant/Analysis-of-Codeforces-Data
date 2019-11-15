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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piii;
typedef pair<pll, ll>plll;
typedef pair<int, ll>pil;

ll MOD = 1000000000LL + 7;



ll powe(ll x, ll p) {
	if (p == 0) return 1;
	ll w = powe((x * x) % MOD, p / 2);
	if (p & 1) w = (w * x) % MOD;
	return w;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m;
	cin >> n >> m;

	ll ans = powe(2, m) - 1;
	ans = powe(ans, n);
	if (ans < 0) ans += MOD;
	cout << ans << "\n";
}
