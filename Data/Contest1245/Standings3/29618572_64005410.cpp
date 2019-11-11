#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;


int main() {
	int64_t a, b,n, t, q, w, ra,pa,sa,rb,pb,sb;
	cin >> t;
	for (int ii = 0; ii < t; ++ii) {
		cin >> n;
		cin >> ra >> pa >> sa;
		rb = 0;
		pb = 0;
		sb = 0;
		w = 0;
		vector<char> xx(n);
		vector<char> yy(n);
		for ( int i = 0; i < n; ++i) {
			cin >> xx[i];
			if (xx[i] == 'R') {
				rb++;
				if (pa > 0) {
					pa--;
					yy[i] = 'P';
					++w;
				}
			} else if (xx[i] == 'P') {
				if (sa > 0) {
					sa--;
					yy[i] = 'S';
					++w;
				}
				pb++;
			} else if (xx[i] == 'S') {
				if (ra > 0) {
					ra--;
					yy[i] = 'R';
					++w;
				}
				sb++;
			}
		}
		if ((n + 1)/ 2 <= w) {
			cout << "YES" << '\n';
			for (int i = 0; i < n; ++i) {
				if (yy[i] != 0) {
					cout << yy[i];
				} else if (pa > 0) {
					pa--;
					cout <<'P';
				} else if (sa > 0) {
					sa--;
					cout <<'S';
				} else if (ra > 0) {
					ra--;
					cout <<'R';
				}
			}
			cout <<'\n';

		} else {
			cout << "NO\n";
		}
	}

}