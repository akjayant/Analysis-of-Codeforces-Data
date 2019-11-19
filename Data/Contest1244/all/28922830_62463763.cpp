#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = a / c;
		if (a % c != 0) x++;
		int y = b / d;
		if (b % d != 0) y++;
		if (x + y <= k) {
			cout << x << ' ' << y << endl;
		} else {
			cout << -1 << endl;
		}
	}
}