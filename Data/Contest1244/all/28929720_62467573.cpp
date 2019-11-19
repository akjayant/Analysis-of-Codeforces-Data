#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

template <typename Tp>
inline void read(Tp &x) {
    x = 0;
    bool f = true; char ch = getchar();
    for ( ; ch < '0' || ch > '9'; ch = getchar()) f ^= ch == '-';
    for ( ; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch ^ 48);
    x = f ? x : -x;
}

int main() {
	int T;
	read(T);
	while (T--) {
		int a, b, c, d, k;
		read(a), read(b), read(c), read(d), read(k);
		int x = !(a % c) ? a / c : a / c + 1, y = !(b % d) ? b / d : b / d + 1;
		if (x + y > k) printf("-1\n");
		else printf("%d %d\n", x, k - x); 
	}
	return 0;
}
