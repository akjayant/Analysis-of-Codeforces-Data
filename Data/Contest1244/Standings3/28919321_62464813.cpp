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

int main() {

	sync;
	
	int t; cin >> t;
	while(t--) {
		int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
		pii ans = make_pair(-1, -1);
		for(int i = 0; i <= a; i++) for(int j = 0; j <= b; j++) {
			if (i + j <= k && i * c >= a && j * d >= b) ans = make_pair(i, j);
		}
		if (ans.first != -1) cout << ans.first << ends << ans.second << endl;
		else cout << -1 << endl;
	}

  	return 0;
}
