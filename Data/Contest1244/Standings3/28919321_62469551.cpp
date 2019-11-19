// IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9, MOD = INF + 7;

/////////////////////////////////////////////////////////////////////

const int N = 3e5 + 5;

int MAIN() {
	int n; cin >> n;
	int ans = n;
	for(int i = 1; i <= n; i++) {
		char c; cin >> c;
		if (c == '1') ans = max(ans, max(2 * i, 2 * (n - i + 1)));
	}
	cout << ans << endl;
}

int main() {

	sync;
	
	int t; cin >> t;
	while(t--) MAIN();

  	return 0;
}
