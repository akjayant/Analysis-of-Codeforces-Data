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
    int t;
    cin>>t;
    forn(i, 0, t) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = n;
        int l=-1, r=-1;
        forn(j, 0, n) {
            if (s[j] == '1') {
                if (l == -1) l=j;
                r = j;
            }
        }
//        cerr<<l<<' '<<r<<endl;
        if (l != -1) {
            ans = max(ans, 2 * (r+1));
            ans = max(ans, 2 * (n-l));
        }
        cout <<ans <<endl;
    }
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
