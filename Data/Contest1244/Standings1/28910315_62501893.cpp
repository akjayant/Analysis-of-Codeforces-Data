#include <algorithm>
// #include <cassert>
#include <cctype>
// #include <cmath>
#include <cstdio>
// #include <cstdlib>
#include <cstring>
// #include <ctime>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define fir first
#define sec second
#define pb push_back
#define pch putchar
#define rg register
#define SZ(_) (int)_.size()
#define SORT(_) std::sort(_.begin(), _.end())
#define LB(_, __) std::lower_bound(_.begin(), _.end(), __)
#define UB(_, __) std::upper_bound(_.begin(), _.end(), __)
#ifdef DEBUG
	#define debug(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
	#define debug(format, ...) 0
#endif

typedef long long LL;
typedef double DB;
typedef std::pair<DB, DB> Pdd;
typedef std::pair<int, int> Pii;
typedef std::pair<LL, int> Pli;
typedef std::pair<int, LL> Pil;
typedef std::pair<LL, LL> Pll;
typedef std::vector<int> Vi;
typedef std::vector<LL> Vl;
typedef std::map<int, int> Mii;
typedef std::map<LL, int> Mli;
typedef std::map<int, LL> Mil;
typedef std::map<LL, LL> Mll;
typedef std::set<int> Si;
typedef std::set<LL> Sl;

const int kInf = 0x3f3f3f3f, kMod = 1e9 + 7;
const LL kInf64 = 0x3f3f3f3f3f3f3f3f;
// const double kPie = acos(-1), kEps = 1e-9;

/* NOTICE! The default mod number is 1e9 + 7 ! */

typedef long long LL;

const int kMaxn = 1000010;

int a[kMaxn], b[kMaxn];
LL k, ggg;
int n;

int main(){
	scanf("%d%lld", &n, &k);
	ggg = k;
	for(int i = 1; i <= n; i++) {
		a[i] = b[i] = i;
	}
	k -= 1ll * n * (n + 1) >> 1;
	if (k < 0) { puts("-1"); return 0; }
	int i = 1, j = n;
	for (; i < j && k >= j - i; ++i, --j) {
		k -= j - i;
		std::swap(b[i], b[j]);
	}
	if (k && i < j) {
		std::swap(b[i], b[i + k]);
		k = 0;
	}
	printf("%lld\n", ggg - k);
	for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
	pch('\n');
	for (int i = 1; i <= n; ++i) printf("%d ", b[i]);
	pch('\n');
	return 0;
}
