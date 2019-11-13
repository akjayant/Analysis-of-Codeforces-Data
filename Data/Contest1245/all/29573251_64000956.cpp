#include <bits/stdc++.h>

/*
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fs first
#define sc second
#define getfiles ifstream cin("input.txt"); ofstream cout("output.txt");
#define endl '\n'
#define con continue
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

const int INF = 2000000005;
const ll BIG_INF = 2000000000000000005;
const int mod = 1000000007;
const int P = 31;
const ld PI = 3.141592653589793238462643;
const double eps = 1e-9;

using namespace std;

vector< pair<int, int> > dir = {
    {
        -1, 0
    },
    {
        0, 1
    },
    {
        1, 0
    },
    {
        0, -1
    }
};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

mt19937 rng(1999999973);

signed main() {
    fast_io;

    int t;
    cin >> t;
    while(t--) {
        int n, a, b, c, r = 0, p = 0, s = 0, sr = 0, sp = 0, ss = 0;
        string pos;
        cin >> n >> a >> b >> c >> pos;

        for (int i = 0; i < pos.size(); i++) {
            if (pos[i] == 'R')
                r++;
            if (pos[i] == 'P')
                p++;
            if (pos[i] == 'S')
                s++;
        }

        sr = max(0, a - s);
        sp = max(0, b - r);
        ss = max(0, c - p);

        a -= sr;
        b -= sp;
        c -= ss;

        int wn = 0;

        string ans;
        for (int i = 0; i < n; i++) {
            if (pos[i] == 'R') {
                if (b != 0) {
                    ans.pb('P');
                    b--;
                    wn++;
                    continue;
                }
                if (sr != 0) {
                    ans.pb('R');
                    sr--;
                    continue;
                }
                if (sp != 0) {
                    ans.pb('P');
                    sp--;
                    continue;
                }
                if (ss != 0) {
                    ans.pb('S');
                    ss--;
                    continue;
                }
            }
            if (pos[i] == 'P') {
                if (c != 0) {
                    ans.pb('S');
                    c--;
                    wn++;
                    continue;
                }
                if (sr != 0) {
                    ans.pb('R');
                    sr--;
                    continue;
                }
                if (sp != 0) {
                    ans.pb('P');
                    sp--;
                    continue;
                }
                if (ss != 0) {
                    ans.pb('S');
                    ss--;
                    continue;
                }
            }
            if (pos[i] == 'S') {
                if (a != 0) {
                    ans.pb('R');
                    a--;
                    wn++;
                    continue;
                }
                if (sr != 0) {
                    ans.pb('R');
                    sr--;
                    continue;
                }
                if (sp != 0) {
                    ans.pb('P');
                    sp--;
                    continue;
                }
                if (ss != 0) {
                    ans.pb('S');
                    ss--;
                    continue;
                }
            }
        }
        if (wn >= (n + 1) / 2) {
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
