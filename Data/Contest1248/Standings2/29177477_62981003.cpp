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
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.rbegin(), a.rend());
	int ct1 = 0;
	for (int i = 0; i*2 < n; i++) {
		ct1 += a[i];
	}
	cout << ct1 * ct1 + (sum - ct1) * (sum - ct1) << endl;
}
