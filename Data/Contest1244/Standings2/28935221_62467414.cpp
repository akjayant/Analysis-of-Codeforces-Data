#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#define R register
#define ll long long
using namespace std;
const int N = 1100;

int t, n;
char s[N];

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
		read(n), scanf("%s", s + 1);
		int ans = n, minD = n;
		for (R int i = 1; i <= n; ++i)
			ans += s[i] - '0';
		for (R int i = 1; i <= n; ++i)
			if (s[i] - '0')
				minD = min(minD, i - 1);
		for (R int i = n; i; --i)
			if (s[i] - '0')
				minD = min(minD, n - i);
		ans = max(ans, 2 * (n - minD));
		cout << ans << endl;
	}
	return 0;
}
