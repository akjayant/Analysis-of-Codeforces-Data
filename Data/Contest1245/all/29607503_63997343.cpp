#include <bits/stdc++.h>

using namespace std;

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )

int rd() {
	int x = 0;
	char c = nc();
	while (c < 48) {
		c = nc();
	}
	while (c > 47) {
		x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
	}
	return x;
}

int main() {
	int T = rd();
	while (T -- ) {
		int x = rd(), y = rd();
		if (__gcd(x, y) != 1) {
			puts("Infinite");
		}
		else {
			puts("Finite");
		}
	}
	return 0;
}