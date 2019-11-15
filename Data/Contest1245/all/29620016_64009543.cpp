#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int, int> pii;

const long long MOD = 1000 * 1000 * 1000 + 7;
const int MAXL = 100 * 1000;

long long ans = 1;
long long a[MAXL + 1];
string s;

void prePro();
long long f(char c, int cnt);

int main() {
	ios::sync_with_stdio(false);
	prePro();
	cin >> s;
	char c = s[0];
	int cnt = 1;
	for (int i = 1; i <= s.size(); i++) {
		if (i == s.size() || s[i] != c) {
			ans = ans * f(c, cnt) % MOD;
			if (i != s.size())
				c = s[i];
			cnt = 1;
		}
		else
			cnt++;
	}
	cout << ans << endl;
}
long long f(char c, int cnt) {
	if (c == 'w' || c == 'm')
		return 0;
	if (c != 'u' && c != 'n')
		return 1;
	return a[cnt];
	
}
void prePro() {
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= MAXL; i++)
		a[i] = (a[i - 1] + a[i - 2]) % MOD;
}
