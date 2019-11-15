#include <bits/stdc++.h>

#define sz(a) int(a.size())
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
int res [100'010];
int dp (int id) {
	if (!id) return 1;
	if (res[id] != -1) return res[id];
	int w = dp(id-1);
	if (id > 1) w += dp(id-2);
	if (w >= MOD) w -= MOD;
	return res[id] = w;
}

int main() {
	memset(res, -1, sizeof(res));
	string s;
	cin >> s;
	int n = sz(s);
	char l = 'q';
	int c = 0;
	s += "L";

	ll ans = 1;
	for (char x : s) {
		if (x == 'w' || x == 'm') {
			puts("0");
			return 0;
		}
		if (x == l) c++;
		else {
			if (l == 'u' || l == 'n') ans = (ans*dp(c))%MOD;
			c = 1;
			l = x;
		}
	}
	cout << ans << endl;
}
