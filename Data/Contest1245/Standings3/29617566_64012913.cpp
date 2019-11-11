#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int gcd(int a, int b) {
	if (a == 0) return b;
	else return gcd(b % a, a);
}

void solve() {
	string s;
	cin >> s;
	int q = 0;
	int ptr = 0;
	int n = s.size();
	vector<long long> sz;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << 0 << endl;
			return;
		}
	}
	//cout << "s" << endl;
	while(q < n) {
		if (s[q] != 'u' && s[q] != 'n') {
			q++; continue;
		} else {
			//cout << "q: " << q << endl;
			ptr = q;
			while(ptr < n && s[ptr] == s[q]) ++ptr;
			sz.push_back(ptr - q);
			q = ptr;
		}
	}
	//cout << "s" << endl;
	long long ans = 1;
	for (int i = 0; i < sz.size(); i++) {
		if (sz[i] == 1) continue;
		//cout << "sz: " << sz[i] << endl;
		vector<long long> dplastone(sz[i], 0);
		vector<long long> dplasttwo(sz[i], 0);
		dplastone[0] = 1;
		dplasttwo[1] = 1;
		dplastone[1] = 1;
		for (int j = 2; j < sz[i]; j++) {
			dplastone[j] = dplasttwo[j - 1] + dplastone[j - 1];
			dplastone[j] %= MOD;
			dplasttwo[j] = dplasttwo[j - 2] + dplastone[j - 2];
			dplasttwo[j] %= MOD;
		}
		long long total = dplasttwo[sz[i] - 1] + dplastone[sz[i] - 1];
		//cout << total << endl;
		total %= MOD;
		ans *= total;
		ans %= MOD;
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}