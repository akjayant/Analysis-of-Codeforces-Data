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
		int n;
		cin >> n;
		int mx1 = 0, mx2 = 0;
		for (int i = 0; i < n; ++i) {
			char c;
			cin >> c;
			if (c == '1') {
				mx1 = max(mx1, i + 1);
				mx2 = max(mx2, n - i);
			}
		}
		cout << max(n, max(mx1, mx2) * 2) << '\n';
	}
	return 0;
}