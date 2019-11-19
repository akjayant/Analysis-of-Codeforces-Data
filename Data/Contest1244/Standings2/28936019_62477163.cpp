#define Hello the_cruel_world!
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#include<climits>
#include<deque>
#include<functional>
#include<numeric>
#define lowbit(x) ((x) & (-(x)))
#define FRIN freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\1.in", "r", stdin)
#define FROUT freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\1.out", "w", stdout)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define outd(x) printf("%d\n", x)
#define outld(x) printf("%lld\n", x)
#define outu(x) printf("%u\n", x)
#define memset0(arr) memset(arr, 0, sizeof(arr))
#define il inline
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 1e5;
const ll INF = 0x7fffffffffffffff;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const double Pi = acos(-1.0);
il int read_int() {
	char c;
	int ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
il ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
il ll quick_pow(ll base, ll index, ll p) {
	ll res = 1;
	while (index) {
		if (index & 1)res = res * base % p;
		base = base * base % p;
		index >>= 1;
	}
	return res;
}
int du[maxn + 5], n;
int c[maxn + 5][3], cnt;
vector<int> g[maxn + 5];
ll res = INF;
int s, ans[maxn + 5];
void DFS(int u, int parent, int c1, int c2, int cnt, ll& sum) {
	if (cnt % 3 == 1)sum += c[u][c1];
	else if (cnt % 3 == 2)sum += c[u][c2];
	else if (cnt % 3 == 0) {
		for (int i = 1; i <= 3; ++i)if (i != c1 && i != c2)sum += c[u][i];
	}
	for (auto v : g[u]) {
		if (v == parent)continue;
		DFS(v, u, c1, c2, cnt + 1, sum);
	}
}
void Color_it(int u, int parent, int c1, int c2, int cnt) {
	if (cnt % 3 == 1)ans[u] = c1;
	else if (cnt % 3 == 2)ans[u] = c2;
	else if (cnt % 3 == 0) {
		for (int i = 1; i <= 3; ++i)if (i != c1 && i != c2)ans[u] = i;
	}
	for (auto v : g[u]) {
		if (v == parent)continue;
		Color_it(v, u, c1, c2, cnt + 1);
	}
}
pii cres;
int main()
{
	n = read_int();
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= n; ++j)
			c[j][i] = read_int();
	for (int i = 1, u, v; i < n; ++i) {
		u = read_int(), v = read_int();
		g[u].push_back(v), g[v].push_back(u);
		++du[u], ++du[v];
		if (du[u] == 3)++cnt;
		if (du[v] == 3)++cnt;
	}
	if (cnt) {
		outd(-1);
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		if (du[i] == 1) {
			s = i;
			break;
		}
	}
	ll sum = 0;
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j) {
			if (i == j)continue;
			sum = 0;
			DFS(s, s, i, j, 1, sum);
			if (res > sum) {
				res = sum;
				cres = pii(i, j);
			}
		}
	Color_it(s, s, cres.first, cres.second, 1);
	outld(res);
	for (int i = 1; i <= n; ++i)printf("%d%c", ans[i], " \n"[i == n]);
	//system("pause");
	return 0;
}