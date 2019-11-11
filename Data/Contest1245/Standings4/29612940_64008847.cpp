#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define ff first
#define ss second
#define sz(vv) (int) vv.size()
#define all(a) a.begin(), a.end()
#define lb lower_bound
#define ub upper_bound
#define _ << " " <<

//#define int ll

void solve() {
    int n, r, p, s;
    cin >> n >> r >> p >> s;
    string v;
    cin >> v;
    int cnt = 0;
    int r0, p0, s0;
    r0 = 0; p0 = 0; s0 = 0;
    string ans;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 'R') {
            ++r0;
        }
        if (v[i] == 'P') {
            ++p0;
        }
        if (v[i] == 'S') {
            ++s0;
        }
    }
    string ost = "";
    cnt = min(r0, p) + min(p0, s) + min(s0, r);
    //cout << r0 _ p0 _ s0 _ cnt << endl;
    if (cnt < (n + 1) / 2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (p > r0) {
        for (int i = 0; i < p - r0; ++i) {
            ost.push_back('P');
        }
    }
    if (r > s0) {
        for (int i = 0; i < r - s0; ++i) {
            ost.push_back('R');
        }
    }
    if (s > p0) {
        for (int i = 0; i < s - p0; ++i) {
            ost.push_back('S');
        }
    }
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 'P') {
            if (s > 0) {
                cout << "S";
                --s;
            }
            else {
                cout << ost[j];
                ++j;
            }
        }
        if (v[i] == 'R') {
            if (p > 0) {
                cout << "P";
                --p;
            }
            else {
                cout << ost[j];
                ++j;
            }
        }
        if (v[i] == 'S') {
            if (r > 0) {
                cout << "R";
                --r;
            }
            else {
                cout << ost[j];
                ++j;
            }
        }
    }
    cout << endl;
}

signed main() {
///#define TASK ""
#if !defined(LOCAL) && defined(TASK)
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
    return 0;
}

