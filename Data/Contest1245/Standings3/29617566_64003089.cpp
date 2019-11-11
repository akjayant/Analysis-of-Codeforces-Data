#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	else return gcd(b % a, a);
}

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	string s;
	cin >> s;
	vector<char> t(s.size(), 'A');
	int won = 0;
	for (int i = 0; i < n; i++) {
		if (a == 0) break;
		if (s[i] == 'S') {
			t[i] = 'R';
			won++;
			a--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (b == 0) break;
		if (s[i] == 'R') {
			t[i] = 'P';
			--b;
			won++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (c == 0) break;
		if (s[i] == 'P') {
			--c;
			won++;
			t[i] = 'S';
		}
	}
	if (won < (n + 1) / 2) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		if (t[i] == 'A') {
			if (a > 0) {
				t[i] = 'R';
				a--;
			} else {
				if (b > 0) {
					t[i] = 'P';
					--b;
				} else {
					if (c > 0) {
						t[i] = 'S';
						--c;
					}
				}
			}
		} 
		cout << t[i];
	}
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}