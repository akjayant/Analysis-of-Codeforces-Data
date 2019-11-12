#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second
int const INF = 2e9 + 7;

vector<int> g[200004];
vector<int> color(200004);
vector<int> used(200004);
void dfs(int u, int p) {
	if (p == -1) color[u] = 0;
	else color[u] = color[p] ^ 1;
	used[u] = 1;
	for (auto i : g[u]) if (!used[i]) dfs(i, u);
}
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ch = 0;
		int c1 = c;
		int b1 = b;
		int a1 = a;
		while (c > 1 && b > 0) {
			ch += 3;
			c -= 2;
			b -= 1;
		}
		while (b > 1 && a > 0) {
			ch += 3;
			b -= 2;
			a -= 1;
		}
		int ch1 = 0;
		while (b1 > 1 && a1 > 0) {
			ch1 += 3;
			b1 -= 2;
			a1 -= 1;
		}
		while (c1 > 1 && b1 > 0) {
			ch1 += 3;
			c1 -= 2;
			b1 -= 1;
		}
		
		cout << max(ch, ch1) << endl;
	}
}
