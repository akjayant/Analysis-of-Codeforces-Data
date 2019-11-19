#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const int MOD  = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> pii;

void solve(){
	int n;
	cin >> n;

	vector<int> v(n);


	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());


	ll g2 = 0;
	for (int i = 0; i < n / 2; i++) {
		g2 += v[i];
	}

	sum -= g2;
	cout << (sum * sum) + (g2 * g2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}