#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second
int const INF = 2e9 + 7;
int mod = 1e9 + 7;
vector<int> g[200004];
vector<int> color(200004);
vector<int> used(200004);
int bp(int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (bp(a, n - 1) * a)%mod;
	else {
		int b = (bp(a, n / 2))%mod;
		return (b * b)%mod;
	}
}
signed main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	cout << bp((bp(2, m) - 1), n);
}
