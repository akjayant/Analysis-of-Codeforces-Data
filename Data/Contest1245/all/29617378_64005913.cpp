#include <bits/stdc++.h>
using namespace std;

int main() {
	constexpr const int mod = 1000000007;
	auto add = [&] (int a, int b) -> int { return a + b < mod ? a + b : a + b - mod; };
	auto mul = [&] (int a, int b) -> int { return 1LL * a * b % mod; };
	constexpr const int maxn = 1 << 17;
	vector<int> fib(maxn);
	fib[0] = fib[1] = 1;
	for (int i = 2; i != maxn; ++i) fib[i] = add(fib[i - 1], fib[i - 2]);
	string s;
	cin >> s;
	if (count(s.begin(), s.end(), 'm') || count(s.begin(), s.end(), 'w')) return cout << 0 << endl, 0;
	s.push_back('a');
	char last = 'a';
	int cnt = 0, ans = 1;
	for (char c : s) {
		if (c == last) {
			++cnt;
		} else {
			if (last == 'u' || last == 'n') ans = mul(ans, fib[cnt]);
			cnt = 1;
			last = c;
		}
	}
	cout << ans << endl;
}
