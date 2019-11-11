#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const LL mod = 1e9 + 7;
using namespace std;
LL fib[maxn], ans = 1;
bool f = false;
string str;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= str.size(); ++i)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	int st = -1;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'm' || str[i] == 'w')
			f = true;
		if (st == -1 && (str[i] == 'u' || str[i] == 'n')) {
			st = i;
		}
		else if (st != -1 && str[i] != str[st]) {
			ans = ans * fib[i - st] % mod;
			st = -1;
			if (st == -1 && (str[i] == 'u' || str[i] == 'n')) {
				st = i;
			}
		}
	}
	if (st != -1)
		ans = ans * fib[str.size() - st] % mod;
	cout << (f ? 0 : ans) << endl;
}