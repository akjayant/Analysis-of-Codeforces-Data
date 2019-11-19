#include <bits/stdc++.h>
#define mem(sx, sy) memset(sx, sy, sizeof(sx))
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-8;
const double PI = acos(-1.0);
const ll llINF = 0x3f3f3f3f3f3f3f3f;
const double INF = 1e9;
using namespace std;
#define pa pair<int, int>
// const int maxn = 1e6+5;



int main() {
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n;
		ll ji0 = 0, ji1 = 0, ou0 = 0, ou1 = 0;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			if (t & 1) ji0++;
			else ou0++;
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			int t;
			cin >> t;
			if (t & 1) ji1++;
			else ou1++;
		}

		cout << ji1 * ji0 + ou0 * ou1 << endl;
	}

}
/*
3
1 3 2
2
0 3
1
1

*/