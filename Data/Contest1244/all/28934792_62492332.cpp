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

int n, k;

int next(int idx) {
    return (idx + 1) % n;
}

int prev(int idx) {
    return (idx - 1 + n) % n;
}

char flip(char c) {
    return c == 'W' ? 'B' : 'W';
}

void solve() {
    cin>>n>>k;
    string s;
    cin>>s;
    int pos = 0;
    vector<pii> diffBlocks;
    vector<bool> fixed(n);
    bool anyFixed = false;
    forn(i, 0, n) {
        if (s[prev(i)] == s[i] || s[next(i)] == s[i]) {
            fixed[i] = true;
            anyFixed = true;
        }

    }

    if (!anyFixed) {
        if (k % 2) {
            forn(i, 0, n) {
                s[i] = flip(s[i]);
            }
        }
        cout << s << endl;
        return;
    }

    for(int i = 0; i < n; ++i) {
        if (!fixed[i]) {
            int l = i, r = i;
            fixed[i] = true;
            while(!fixed[next(r)]) {
                r = next(r);
                fixed[r] = true;
            }
            while(!fixed[prev(l)]) {
                l = prev(l);
                fixed[l] = true;
            }
            int len = (r >= l) ? r - l + 1 : (n - l + r + 1);
//            cerr<<len<<endl;
            int it = 0;
            char lColor = s[prev(l)];
            char rColor = s[next(r)];
            int endForL = (l + (len + 1) / 2) % n; // check
            while (l != endForL) {
                if (it < k) {
                    s[l] = lColor;
                    s[r] = rColor;
                } else {
                    bool needChange = k % 2;
                    if (needChange) {
                        s[l] = flip(s[l]);
                        if (l!=r)
                            s[r] = flip(s[r]);
                    }
                }
                l = next(l);
                r = prev(r);
                it++;
            }
        }
    }

    cout << s << endl;
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
