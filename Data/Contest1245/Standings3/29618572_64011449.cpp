#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <string>

using namespace std;


int main() {
	int64_t a, b,n, t, q, w, ra,pa,sa,rb,pb,sb;
	string s;
	int64_t pp = 1000000007;
	cin >> s;
	vector<int64_t> f(111111);
	f[1] = 1;
	f[2] = 2;
	f[3] = 3;
	int64_t res = 1;
	for (int i = 4; i < f.size(); ++i) {
		f[i] = (f[i - 1] + f[i - 2]) % pp;
	}
	int64_t cn, cu;
	cn = 0;
	cu = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'n') {
			if (cu > 0) {
				res = (res * f[cu]) % pp;
				cu = 0;
			}
			cu = 0;
			cn++;
		} else if (s[i] == 'u') {
			if (cn > 0) {
				res = (res * f[cn]) % pp;
				cn = 0;
			}
			cn = 0;
			cu++;
		} else if ((s[i] == 'w') || (s[i] == 'm')) {
			cout << 0;
			return 0;
		} else {
			if (cn > 0) {
				res = (res * f[cn]) % pp;
				cn = 0;
			}
			cn = 0;
			if (cu > 0) {
				res = (res * f[cu]) % pp;
				cu = 0;
			}
			cn = 0;
		}
	}
	if (cn > 0) {
		res = (res * f[cn]) % pp;
		cn = 0;
	}
	cn = 0;
	if (cu > 0) {
		res = (res * f[cu]) % pp;
		cu = 0;
	}
	cn = 0;
	cout << res;

}