#include <iostream>
#include <map>
#include <vector>
#include <cassert>

using namespace std;

int64_t mult(int64_t a, int64_t b, int64_t mod) {
	return a * b % mod;
}

int64_t deg(int64_t a, int64_t b, int64_t mod) {
	if (mod == 1) return 0;
	int64_t res = 1;
	int64_t deg = a;
	while (b) {
		if (b & 1) res = mult(res, deg, mod);
		deg = mult(deg, deg, mod);
		b /= 2;
	}
	return res;
}

int64_t gcd(int64_t a, int64_t b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int64_t n, p, w, d;
	cin >> n >> p >> w >> d;
	if (p % gcd(w, d) != 0) {
		cout << -1 << endl;
		return 0;
	}
	int64_t allgcd = gcd(w, d);
	w /= allgcd; p /= allgcd; d /= allgcd;
	int64_t wm = w % d;
	int64_t pm = p % d;
	int64_t x0 = -1;
	for (int64_t i = 0; i < d; ++i) {
		if (i * wm % d == pm) {
			x0 = i;
			break;
		}
	}
	if (x0 == -1) {
		cout << -1 << endl;
		return 0;
	}
	assert((p - w * x0) % d == 0);
	int64_t y0 = (p - w * x0) / d;
	int64_t t;
	if (y0 < 0) {
		t = -((-y0) / w + ((-y0) % w != 0));
	} else {
		t = y0 / w;
	}
	int64_t resx = x0 + t * d;
	int64_t resy = y0 - w * t;
	if (resx + resy > n || resx < 0) {
		cout << -1 << endl;
		return 0;
	}
	assert(y0 >= 0);
	cout << resx << ' ' << resy << ' ' << n - resx - resy << endl;
	return 0;
}