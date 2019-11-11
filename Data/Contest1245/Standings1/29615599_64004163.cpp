#include <bits/stdc++.h>
using namespace std;



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		string s;
		cin >> s;
		int r[3] = {0, 0, 0};
		for (auto ch : s) {
			if (ch == 'R') r[0] += 1;
			if (ch == 'P') r[1] += 1;
			if (ch == 'S') r[2] += 1;
		}
		int ans = min(a, r[2]) + min(b, r[0]) + min(c, r[1]);
		//cout << ans << endl;
		if (ans >= (n + 1)/2) {
			cout << "YES" << endl;
			int t1 = min(r[2], a);
			int n1 = a - t1;
			int t2 = min(r[0], b);
			int n2 = b - t2;		
			int t3 = min(r[1], c);
			int n3 = c - t3;
			for (auto ch : s) {
				if (ch == 'R') {
					if (t2 > 0) {
						cout << "P";
						t2 -= 1;
					} else {
						if (n1 > 0) n1 -= 1, cout << "R";
						else n3 -= 1, cout << "S";
					}
				}
				if (ch == 'P') {
					if (t3 > 0) {
						cout << "S";
						t3 -= 1;
					} else {
						if (n1 > 0) n1 -= 1, cout << "R";
						else n2 -= 1, cout << "P";
					}
				}
				if (ch == 'S') {
					if (t1 > 0) {
						cout << "R";
						t1 -= 1;
					} else {
						if (n2 > 0) n2 -= 1, cout << "P";
						else n3 -= 1, cout << "S";
					}
				}
			}
			cout << endl;
		} else cout << "NO" << endl;
	}
	return 0;
}