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

const int MAXN = 1e5 + 10;
ll a[MAXN];
int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	ll all = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		all += a[i];
	}
	sort(a, a + n);
	ll t1 = 0;
	for (int i = 0; i < n / 2; i++) {
		t1 += a[i];
	}
	cout << t1 * t1 + (all - t1)*(all - t1) << endl;
}
/*
3
1 3 2
2
0 3
1
1

*/