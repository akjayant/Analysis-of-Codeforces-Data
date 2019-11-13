#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;

ll f[N];
char s[N];

int main()
{
	ios::sync_with_stdio(false);
	cin >> (s + 1);
	f[1] = 1ll; f[2] = 2ll;
	for (int i = 3; i < N; i++)f[i] = (f[i - 2] + f[i - 1]) % mod;
	int n = strlen(s + 1);
	ll res = 1;
	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'm' || s[i] == 'w')flag = 1;
		int tmp = 1;
		if (s[i] == 'n') {
			while (i + 1 <= n && s[i] == 'n' && s[i] == s[i + 1]) {
				tmp++;
				i++;
			}
			res = (res * f[tmp]) % mod;
		} else if (s[i] == 'u') {
			while (i + 1 <= n && s[i] == 'u' && s[i] == s[i + 1]) {
				tmp++;
				i++;
			}
			res = (res * f[tmp]) % mod;
		}
	}
	if (!flag)cout << res << endl;
	else cout << 0 << endl;
	return 0;
}