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
#include <deque>

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

LL n, k, x;
std::deque<Pll> que;
Mll cnt;

int main() {
	scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		cnt[x]++;
	}
    for (auto v : cnt) que.pb({v.fir,v.sec});
    while (k > 0) {
        if(SZ(que) == 1) break;
        Pll bbb = que.back(), fff = que.front();
        if (fff.sec < bbb.sec) {
            que.pop_front();
            Pll cur = que.front();
            LL mdzz = (cur.fir - fff.fir) * fff.sec;
            if (mdzz > k) {
                LL steps = k / fff.sec;
                fff.fir += steps;
                que.push_front(fff);
                break;
            } else {
                que.front().sec += fff.sec;
                k -= mdzz;
            }
        } else {
            que.pop_back();
            Pll cur = que.back();
            LL mdzz = (bbb.fir - cur.fir) * bbb.sec;
            if (mdzz > k) {
                LL steps = k / bbb.sec;
                bbb.fir -= steps;
                que.pb(bbb);
                break;
            } else {
                k -= mdzz;
                que.back().sec += bbb.sec;
            }
        }
    }
    printf("%lld\n", que.back().fir - que.front().fir);
    return 0;
}
