#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define fill(space,a) memset(space,a,sizeof(space))
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);
#define MOD 1000000007
ll fib[100005];
int main()
{
	optimize();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	string s;
	cin >> s;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << 0 << endl;
			exit(0);
		}
	}
	ll ans = 1LL;
	ll u = 0LL, n = 0LL;
	fib[0] = 1LL;
	fib[1] = 1LL;
	for (int i = 2; i < 100005; i++) {
		fib[i] = fib[i - 2] + fib[i - 1];
		fib[i] %= (ll)(MOD);
	}
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'u') {
			u++;
			if (n > 0LL) {
				ans = ans * fib[n];
				ans %= (ll)(MOD);
				n = 0LL;
			}
		}
		else if (s[i] == 'n') {
			n++;
			if (u > 0LL) {
				ans = ans * (fib[u]);
				ans %= (ll)(MOD);
				u = 0LL;
			}
		}
		else {
			if (u > 0LL) {
				ans = ans * (fib[u]);
				ans %= (ll)(MOD);
				u = 0LL;
			}
			else if (n > 0LL) {
				ans = ans * fib[n];
				ans %= (ll)(MOD);
				n = 0LL;
			}
		}
	}
	if (u > 0LL) {
		ans = ans * (fib[u]);
		ans %= (ll)(MOD);
		u = 0LL;
	}
	else if (n > 0LL) {
		ans = ans * fib[n];
		ans %= (ll)(MOD);
		n = 0LL;
	}
	cout << ans << endl;

	return 0;
}