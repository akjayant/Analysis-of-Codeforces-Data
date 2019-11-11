#include <cstdio>

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main(void) {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		string s;
		cin >> s;
		int cnt = 0;
		vector<char> res(n);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'S') {
				if (a > 0) {
					a--;
					cnt++;
					res[i] = 'R';
				}
			} else if (s[i] == 'R') {
				if (b > 0) {
					b--;
					cnt++;
					res[i] = 'P';
				}
			} else {
				if (c > 0) {
					c--;
					cnt++;
					res[i] = 'S';
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (res[i] == 0) {
				if (a > 0) {
					a--;
					res[i] = 'R';
				} else if (b > 0) {
					b--;
					res[i] = 'P';
				} else if (c > 0) {
					c--;
					res[i] = 'S';
				}
			}
		}
		if (cnt * 2 >= n) {
			cout << "YES" << endl;
			for (char ch : res) cout << ch;
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
		
	}

	return 0;
}