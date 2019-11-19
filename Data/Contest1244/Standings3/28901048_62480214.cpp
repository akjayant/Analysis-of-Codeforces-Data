#include <bits/stdc++.h>
#define f first
#define s second
#define push push_back
#define pop pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
// #define Bubibu
// #pragma GCC optimize("O3")
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 1e5 + 1, INF = 1e9;
 
// mt19937 rnd(0);

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef Bubibu	
	freopen("out.txt", "w", stdout); 
	freopen("in.txt", "r", stdin);
	#endif
	ll n, p, w, d;
	cin >> n >> p >> w >> d;
	for (ll y = 0; y <= n && d * y <= p && y < 10000000; ++y) {
		if ((p - d * y) % w) {
			continue;
		}
		ll x = (p - d * y) / w;
		if (x + y <= n) {
			cout << x << ' ' << y << ' ' << n - x - y;
			return 0;
		}
	}
	cout << -1;
	return 0;
}