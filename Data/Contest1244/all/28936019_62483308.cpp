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
const int INF = 0x7fffffff;
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
map<ll, int> mp;
int n;
ll k;
int main()
{
	n = read_int(), k = read_ll();
	for (int i = 1, x; i <= n; ++i) {
		x = read_int();
		++mp[x];
	}
	while (k && mp.size() > 1) {
		pair<ll, int> small = *mp.begin(), big = *mp.rbegin();
		if (k < small.second && k < big.second)break;
		if (small.second < big.second) {
			pair<ll, int> nxt = *(mp.upper_bound(small.first));
			ll v = nxt.first, s = nxt.second;
			ll diff = v - small.first;
			ll sum = diff * small.second;
			if (sum <= k) {
				k -= sum;
				mp[v] += small.second;
				mp.erase(small.first);
			}
			else {
				ll u = k / small.second;
				mp[small.first + u] = small.second;
				k -= small.second * u;
				mp.erase(small.first);
			}
		}
		else {
			pair<ll, int> nxt = *(--(mp.find(big.first)));
			ll v = nxt.first, s = nxt.second;
			ll diff = big.first - v;
			ll sum = diff * big.second;
			if (sum <= k) {
				k -= sum;
				mp[v] += big.second;
				mp.erase(big.first);
			}
			else {
				ll u = k / big.second;
				mp[big.first - u] = big.second;
				k -= big.second * u;
				mp.erase(big.first);
			}
		}
	}
	ll small = mp.begin()->first, big = mp.rbegin()->first;
	outld(big - small);
	//system("pause");
	return 0;
}