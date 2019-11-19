#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void gcd(LL a, LL b, LL& d, LL&x, LL& y) {
	if (!b) { d = a; x = 1; y = 0; }
	else { gcd(b, a%b, d, y, x); y -= x * (a / b); }
}

LL modFunc(LL a, LL b, LL n, LL &d) {
	LL x, y;
	gcd(a, n, d, x, y);
	if (b % d) return -1;
	x *= (b / d);
	x = (x%n + n) % n;
	x = x % (n/d);
	return x;
}

int work() {
    LL w, d, n, p, x, y, g;
    cin >> n >> p >> w >> d;
    //if (!p) { cout << "0 0 " << n << endl; return 0; }

    y = modFunc(d, p%w, w, g);
    //cout << y << endl << g << endl;

    //if (y < 0 || (p-d*y) < 0) { cout << -1 << endl; return 0; }
    x = (p-d*y) / w;
    if (x < 0 || y < 0 || x + y > n) { cout << -1 << endl; return 0; }
    cout << x << " " << y << " " << n-x-y << endl;
    return 0;
}

int main() {
    //while (1)
    work();
    return 0;
}

