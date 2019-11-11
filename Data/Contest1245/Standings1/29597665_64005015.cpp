#include <bits/stdc++.h>

const int mod = 1000000007, N = 100005;
typedef long long LL;

int n, f[N];
std::string s;
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> s; s = s + '#', n = s.size();
	if (s.find_first_of("wm") != std::string::npos)
	{ std::cout << 0 << '\n'; return 0; }
	f[0] = 1, f[1] = 1;
	for (int i = 2; i <= n; ++i) {
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	}
	int _u = 0, _n = 0, ans = 1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'u') ++_u; else ans = (LL) ans * f[_u] % mod, _u = 0;
		if (s[i] == 'n') ++_n; else ans = (LL) ans * f[_n] % mod, _n = 0;
	}
	std::cout << ans << '\n';
	return 0;
}