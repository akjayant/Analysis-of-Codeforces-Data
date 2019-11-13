/**
 * author:  apikdech
 * created: 01.11.2019 22:01:58
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;

ll fibo[N];

void pre() {
	fibo[0] = 1;
	fibo[1] = 1;
	fibo[2] = 2;
	for (int i = 3; i < N; i++) {
		fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
	}
}

int main() {
	pre();
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	vector<int> v;
	char last = s[0];
	int cnt = 0;
	ll ans = 1;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'm' || s[i] == 'w') ans = 0;
		if (s[i] == last) cnt++;
		else {
			if (last == 'u' || last == 'n') v.push_back(cnt);
			cnt = 1;
			last = s[i];
		}
	}
	if (last == 'u' || last == 'n') v.push_back(cnt);
	for (int it : v) {
		// cout << it << "\n";
		ans = ans * fibo[it] % MOD;
	}
	cout << ans << "\n";
	return 0;
}
