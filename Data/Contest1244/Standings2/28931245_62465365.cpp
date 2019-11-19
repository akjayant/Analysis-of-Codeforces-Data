#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>

void solve() {
	#define int ll
	int n;
	cin >> n;
	string s;
	cin >> s;
	int max = n;
	int left = -1, right = -1;
	for (int i = 0; i < n; ++i) {
		if (left == -1 && s[i] == '1')
			left = i;
		if (s[i] == '1')
			right = i;
	}
	if (left != -1) {
		max = std::max(max, (right - left + 1) * 2 + std::max(left, n - right - 1) * 2);
	}
	cout << max << endl;
}

signed main() {
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}	
}