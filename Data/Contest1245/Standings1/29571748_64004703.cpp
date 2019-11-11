#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

mt19937 gen((uint) chrono::high_resolution_clock::now().time_since_epoch().count());

void solve() {
	int n;
	cin >> n;

	int n1, n2, n3;
	cin >> n3 >> n2 >> n1;

	vector<int> cnt(3);
	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		char c = s[i];

		if (c == 'S') {
			cnt[0]++;
		} else if (c == 'P') {
			cnt[1]++;
		} else {
			cnt[2]++;
		}
	}

	string res;
	int cntWin = 0;

	int take1 = min(n1, cnt[1]);
	int take2 = min(n2, cnt[2]);
	int take3 = min(n3, cnt[0]);

	cntWin += take1 + take2 + take3;

	if (cntWin * 2 >= n) {
		cout << "Yes\n";

		res = string(n, '!');

		for (int i = 0; i < n; i++) {
			if (s[i] == 'P' && take1 > 0) {
				take1--;
				n1--;
				res[i] = 'S';
			} else if (s[i] == 'R' && take2 > 0) {
				take2--;
				n2--;
				res[i] = 'P';
			} else if (s[i] == 'S' && take3 > 0) {
				take3--;
				n3--;
				res[i] = 'R';
			}
		}

		for (int i = 0; i < n; i++) {
			if (res[i] == '!') {
				if (n1 > 0) {
					res[i] = 'S';
					n1--;
				} else if (n2 > 0) {
					res[i] = 'P';
					n2--;
				} else {
					res[i] = 'R';
					n3--;
				}
			}
		}

		cout << res << "\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--) {
		solve();
	}

	return 0;
}