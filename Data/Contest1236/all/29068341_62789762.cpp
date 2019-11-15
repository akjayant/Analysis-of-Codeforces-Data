
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fr, to)    for (int i = fr; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int mod = 1e9 + 7;
num n, m;

num inline qpow(num a, num p) {
	num res = 1;
	for (; p; p >>= 1) {
		if (p & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
	}
	return res;
}

int main() {
	cin >> n >> m;
	cout << qpow(qpow(2, m) - 1, n) << ln;
}
