#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
LL mod = 1e9 + 7;
LL fib[maxn], n, m, ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	LL x, y;
	x = max(n, m);
	y = min(n, m);
	fib[1] = 2;
	fib[2] = 4;
	for (int i = 3; i <= x; ++i)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	cout << (fib[y] + fib[x] - 2) % mod << "\n";
}