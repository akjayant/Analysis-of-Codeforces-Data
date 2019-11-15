#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int const maxn = 101010;
int const mod = 1e9 + 7;

ll fib[maxn];

void init() {
	fib[0] = 1;
	fib[1] = 1;

	for (int i = 2; i < maxn; i++) fib[i] = (fib[i-1] + fib[i-2]) % mod;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	init();

	string s;
	cin >> s;

	int n = s.size();
	
	ll ans = 1;
	bool ok = (count(s.begin(), s.end(), 'm') == 0) and
	          (count(s.begin(), s.end(), 'w') == 0);
	
	if (!ok) {
		cout << 0 << "\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (s[i] != 'u' and s[i] != 'n') continue;

		int cnt = 1;
		while (i+1 < n and s[i+1] == s[i]) cnt++, i++;

		ans = ans*fib[cnt]%mod;
	}

	cout << ans << "\n";
}