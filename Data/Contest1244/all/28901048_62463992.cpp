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
	int t;
	cin >> t;
	for (;t;--t) {
		int a, b, c, d, k;
		cin >> a >> b >>c >> d >> k;
		if ((a + c - 1) / c + (b + d - 1) / d <= k) 
			cout << (a + c - 1) / c << ' ' << (b + d - 1) / d << '\n';
		else 
			cout << "-1\n";
	}
	return 0;
}