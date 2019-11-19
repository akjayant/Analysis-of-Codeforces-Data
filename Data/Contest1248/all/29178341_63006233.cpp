#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define forn(i, n) for(int i=0;i<(n);++i)
#define clr(ar, val) memset(ar, val, sizeof(ar))

using namespace std;

typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<ld, ld> point;

const int MAXN = int(2e5) + 200;
const int INF = int(1e9) + 10;
const long long LINF = 1LL * INF * INF;
const int md = int(1e9) + 7;
const ld eps = 1e-9;
const ld PI = 3.1415926535897932384626433832795l;

int n, ans = -1, l = -1, r = -1;
string s;
vector<int> bal_pref, pref_min, suf_min;


int calc() {
    bal_pref[0] = 0;
    for (int i = 0; i < n; ++i) {
        bal_pref[i + 1] = bal_pref[i] + (s[i] == '(' ? 1 : -1);
    }
    if (bal_pref[n] || (n & 1)) {
        return 0;
    }
    pref_min[0] = 0;
    pref_min[1] = bal_pref[1];
    for (int i = 2; i <= n; ++i) {
        pref_min[i] = min(pref_min[i - 1], bal_pref[i]);
    }
    suf_min[n] = bal_pref[n];
    for (int i = n - 1; i >= 1; --i) {
        suf_min[i] = min(suf_min[i + 1], bal_pref[i]);
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if ((suf_min[i + 1] >= bal_pref[i]) && (bal_pref[n] - bal_pref[i] + pref_min[i] >= 0)) {
            ++cur;
        }
    }
    return cur;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    bal_pref.resize(n + 1);
    pref_min.resize(n + 1);
    suf_min.resize(n + 1);
    cin >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(s[i], s[j]);
            int cur = calc();
            if (cur > ans) {
                ans = cur;
                l = i + 1;
                r = j + 1;
            }
            swap(s[i], s[j]);
        }
    }
    cout << ans << endl;
    cout << l << ' ' << r << endl;
    return 0;
}
