#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int n, fib[maxn];
string s;
ll ans;

int main(){
	fib[0] = fib[1] = 1;
	for (int i = 2; i < maxn; ++i)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	ans = 1;
	cin >> s; 
	n = s.size();
	for (int i = 0; i < n; )
		if (s[i] == 'n' || s[i] == 'u') {
			int pos = i + 1;
			while (pos < n && s[pos] == s[pos - 1])
				pos++;
			ans = ans * fib[pos - i] % mod;
			i = pos;
		}
		else if (s[i] == 'm' || s[i] == 'w')
			return cout << "0\n", 0;
		else
			i++;
	cout << ans << '\n';
	return 0;
}
