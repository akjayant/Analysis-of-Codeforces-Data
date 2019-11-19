#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 998244353;
const int N = 100010;
int n, cnt[N]; ll m;
ll a[N], p[N], ans, flag = 0; int lp;

template<typename T> void gi(T &x) {
	x = 0; register char c = getchar(), pre = 0;
	for(; c < '0' || c > '9'; pre = c, c = getchar());
	for(; c >= '0' && c <= '9'; c = getchar()) x = x * 10ll + (c ^ 48);
	if(pre == '-') x = -x;
}
int main() {
	gi(n), gi(m); rep(i, 1, n) gi(a[i]), p[++lp] = a[i];
	sort(p + 1, p + lp + 1), lp = unique(p + 1, p + lp + 1) - p - 1;
	rep(i, 1, n) ++cnt[lower_bound(p + 1, p + lp + 1, a[i]) - p];
	int l = 1, r = lp;
	for(; l < r && m;) {
		if(cnt[l] < cnt[r]) {
			if(m >= 1ll * cnt[l] * (p[l + 1] - p[l])) {
				m -= 1ll * cnt[l] * (p[l + 1] - p[l]), cnt[l + 1] += cnt[l], ++l;
			}
			else { flag = m / cnt[l]; break; }
		}
		else {
			if(m >= 1ll * cnt[r] * (p[r] - p[r - 1])) {
				m -= 1ll * cnt[r] * (p[r] - p[r - 1]), cnt[r - 1] += cnt[r], --r;
			}
			else { flag = m / cnt[r]; break; }
		}
//		rep(i, 1, n) printf("%d ", cnt[i]); puts("");
	}
	printf("%lld\n", p[r] - p[l] - flag);
	return 0;
}