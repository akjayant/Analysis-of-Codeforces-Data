#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
ll f[MAXN];
void init() {
	f[0] = f[1] = 1;
	for (int i = 2; i < MAXN; i++) f[i] = (f[i - 1] + f[i - 2]) % MOD;
}
int main() {
	init();
	string str;
	cin >> str;
	int m = 0, w = 0;
	for (auto it : str) {
		if (it == 'm') m++;
		if (it == 'w') w++;
	}
	if (m + w != 0) {
		cout << 0 << endl;
		return 0;
	}
	else {
		ll ret = 1;
		int con = 1; char conch = str[0];
		for (int i = 1; i < int(str.length()); i++) {
			// cout << conch << endl;
			if (str[i] == str[i - 1]) {
				con++;
			}
			else {
				if (conch == 'u' || conch == 'n') {
					ret *= f[con];
					ret %= MOD;
				}

				con = 1; conch = str[i];
			}
		}

		if (conch == 'u' || conch == 'n') {
			ret *= f[con];
			ret %= MOD;
		}
		cout << ret << endl;
	}
}

/*
2 5
2 3 0
SSSSS
*/