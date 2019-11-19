#pragma GCC optimize("2,Ofast,inline")
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 10;

template <typename T> T read(T &x) {
	int f = 0;
	register char c = getchar();
	while (c > '9' || c < '0') f |= (c == '-'), c = getchar();
	for (x = 0; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + (c ^ 48);
	if (f) x = -x;
	return x;
}

int n;
char s[N];

void solve() {
	read(n);
	scanf("%s", s + 1);
	int ans = 0;
	ans = n;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '1') {
			int d = max(i, n - i + 1);
			ans = max(ans, d * 2);
		}
	}
	cout << ans << endl;
}

int main() {
	int T; read(T);
	while (T--) solve();
	return 0;
}
