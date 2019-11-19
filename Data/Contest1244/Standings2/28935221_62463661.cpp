#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#define R register
#define ll long long
using namespace std;

int t, a, b, c, d, k; 

template <class T> inline void read(T &x) {
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

int main() {
	read(t);
	while (t--) {
		read(a), read(b), read(c), read(d), read(k);
		int x = (a - 1) / c + 1, y = (b - 1) / d + 1;
		if (x + y <= k)
			printf("%d %d\n", x, y);
		else
			printf("-1\n");
	}
	return 0;
}
