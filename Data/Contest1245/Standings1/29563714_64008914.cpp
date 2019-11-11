#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000;
const int MD = 1000000007;
string s;
int n;
int f[MAX_N + 9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'm' || s[i] == 'w') {
			cout << "0\n";
			return 0;
		}
	}
	f[0] = 1 % MD;
	f[1] = 1 % MD;
	for(int i = 2; i <= n; i++) {
		f[i] = f[i - 1];
		if(s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')) {
			f[i] = (f[i] + f[i - 2]) % MD;
		}
	}
	cout << f[n] << "\n";
	return 0;
}