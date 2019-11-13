#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;
const int N = 1e5 + 3;

string s;
queue<int> q;
long long f[N];
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> s;
	f[0] = f[1] = 1;
	int cnt = 0;
	int n = (int) s.size();
	s.push_back('*');
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << "0\n";
			return 0;
		}
	}
	int i = 0;
	for (; true; ) {
		while (s[i] == 'u') {
			++cnt;
			++i;
		}
		if (cnt) {
			
			q.push(cnt);
			cnt = 0;
		}

		while (s[i] == 'n') {
			++cnt;
			++i;
		}
		if (cnt) {
			q.push(cnt);
			cnt = 0;
		}
		if (s[i] != '*' && s[i] != 'u' && s[i] != 'n') ++i;
		if (s[i] == '*') break;
	}
	long long ans = 1;
	for (int i = 2; i <= n; ++i) f[i] = (f[i - 1] + f[i - 2]) % M;
	while (! q.empty()) {
		int x = q.front();
		q.pop();
		ans = (ans * f[x]) % M;
	}
	cout << ans << '\n';
	return 0;
}
