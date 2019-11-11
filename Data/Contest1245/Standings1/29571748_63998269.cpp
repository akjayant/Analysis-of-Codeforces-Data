#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

mt19937 gen((uint) chrono::high_resolution_clock::now().time_since_epoch().count());

void solve() {
	int a, b;
	cin >> a >> b;

	if (a > b) {
		swap(a, b);
	}

	vector<char> ok(b);

	for (int i = 0; i < b; i++) {
		ok[a * i % b] = 1;
	}

	for (int i = 0; i < b; i++) {
		if (!ok[i]) {
			cout << "Infinite\n";
			return;
		}
	}

	cout << "Finite\n";
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