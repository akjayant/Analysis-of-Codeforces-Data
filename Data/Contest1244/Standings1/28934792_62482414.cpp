#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <map>
#include <cstdlib>
#include <sstream>
#include <queue>
#include <stack>
#include <cassert>
#include <deque>
#include <list>
#include <set>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define mp(x, y) make_pair(x, y)
#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define pr(x) printf("%d ", x)
#define nl() printf("\n")
#define forn(i, a, b) for(int i=a; i<b; ++i)
#define ford(i, a, b) for(int i=b-1; i>=a; --i)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
#define X first
#define Y second
#define sqr(x) 1ll*(x)*(x)
#define pb push_back

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vint = vector<int>;
using v2int = vector<vint>;
using vll = vector<ll>;
using ld = long double;
using pld = pair<ld, ld>;


void solve() {
    int n;
    ll k;
    cin>>n>>k;
    map<int, int> cnt;
    forn(i, 0, n) {
        int a;
        cin>>a;
        cnt[a]++;
    }
    while(cnt.size() > 1 && (k >= cnt.begin()->second || k >= cnt.rbegin()->second)) {
        int cntMin = cnt.begin()->second;
        int cntMax = cnt.rbegin()->second;
        if (cntMin <= cntMax) {
            int minVal = cnt.begin()->first;
            int nextVal = next(cnt.begin())->first;
            ll need = 1ll * (nextVal - minVal) * cntMin;
            if (need <= k) {
                k -= need;
                cnt[nextVal] += cntMin;
                cnt.erase(minVal);
            } else {
                ll can = k / cntMin;
                cnt[minVal + can] += cntMin;
                k -= can * cntMin;
                cnt.erase(minVal);
            }
        } else {
            int maxVal = cnt.rbegin()->first;
            int prevVal = next(cnt.rbegin())->first;
            ll need = 1ll * (maxVal - prevVal) * cntMax;
            if (need <= k) {
                k -= need;
                cnt[prevVal] += cntMax;
                cnt.erase(maxVal);
            } else {
                ll can = k / cntMax;
                cnt[maxVal - can] += cntMax;
                k -= can * cntMax;
                cnt.erase(maxVal);
            }
        }
    }
    cout << cnt.rbegin()->first - cnt.begin()->first<<endl;
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    //    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    fprintf(stderr, "Time: %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}
