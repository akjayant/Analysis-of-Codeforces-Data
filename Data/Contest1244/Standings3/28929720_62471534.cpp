#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

template <typename Tp>
inline void read(Tp &x) {
    x = 0;
    bool f = true; char ch = getchar();
    for ( ; ch < '0' || ch > '9'; ch = getchar()) f ^= ch == '-';
    for ( ; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch ^ 48);
    x = f ? x : -x;
}

std::string s;
int n, ans, tmp;

inline void init() {
    read(n);
    std::cin >> s;
}

inline void solve() {
    ans = 0, tmp = 0;
    for (int i = 0; i < n; ++i) 
		if (s[i] == '1') ans = std::max(ans, std::max(i + 1, n - i)), tmp = 1;
}

int main() {
    int T;
    read(T);
    while (T--) {
        init();
        solve();
		printf("%d\n", std::max(n, tmp * 2 * std::max(ans, n - ans + 1)));
	}
	return 0;
}