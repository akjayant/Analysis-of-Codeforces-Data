#include <bits/stdc++.h>

int tc, a, b, c, n, A;
std::string s, t;
void solve() {
	std::cin >> n >> a >> b >> c >> s;
	t.resize(n), A = 0;
	for (int i = 0; i < n; ++i) t[i] = ' ';
	for (int i = 0; i < n; ++i)
		if (s[i] == 'S' && a) t[i] = 'R', ++A, --a;
	for (int i = 0; i < n; ++i)
		if (s[i] == 'R' && b) t[i] = 'P', ++A, --b;
	for (int i = 0; i < n; ++i)
		if (s[i] == 'P' && c) t[i] = 'S', ++A, --c;
	if (A * 2 < n) { std::cout << "no" << '\n'; return; }
	std::cout << "yes" << '\n';
	for (int i = 0; i < n; ++i)
		if (t[i] == ' ') {
			if (a) t[i] = 'R', --a;
			else if (b) t[i] = 'P', --b;
			else if (c) t[i] = 'S', --c;
		}
	std::cout << t << '\n';
}
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> tc;
	while (tc--) solve();
	return 0;
}
