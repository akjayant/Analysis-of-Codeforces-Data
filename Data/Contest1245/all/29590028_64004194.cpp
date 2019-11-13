//besmellah
#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1e5 + 10, mod = 1e9 + 7;
long long fib[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < maxn; i ++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	string s;
	cin >> s;
	long long ans = 1;
	int u = 0, n = 0;
	for (int i = 0; i < s.size(); i ++){
		if (s[i] != 'n'){
			ans *= fib[n];
			n = 0;
		}
		else{
			n ++;
		}
		if (s[i] != 'u'){
			ans *= fib[u];
			u = 0;
		}
		else{
			u ++;
		}
		ans %= mod;
		if (s[i] == 'm' || s[i] == 'w')
			ans *= 0;
	}
	ans = ans * fib[n] % mod * fib[u] % mod;
	cout << ans;
}
