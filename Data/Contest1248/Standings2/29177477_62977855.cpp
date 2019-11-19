#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second
int const INF = 2e8 + 7;
int mod = 1e9 + 7;
vector<int> g[200004];
vector<int> color(200004);
struct point {
	int x, y;
};
bool comp1(point p1, point p2) {
	if (p1.x == p2.x) return p1.y < p2.y;
	return p1.x < p2.x;
}
bool comp2(point p1, point p2) {
	if (p1.y == p2.y) return p1.x < p2.x;
	return p1.y < p2.y;
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int n1 = 0, c1 = 0, n2 = 0, c2 = 0; 
		int ch;
		for (int i = 0; i < n; i++) {
			cin >> ch;
			if (ch % 2) n1++;
			else c1++;
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> ch;
			if (ch % 2) n2++;
			else c2++;
		}
		cout << c1 * c2 + n1 * n2 << endl;
	}
}
