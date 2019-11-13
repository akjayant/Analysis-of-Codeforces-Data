// 巨菜的ACMer-Happy233

#include <bits/stdc++.h>

using namespace std;

//-----
typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define pw(x) (1ll << (x))
#define bt(x, k) (((x) >> k) & 1)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i, l, r) for(int i=(l);i<(r);++i)
#define per(i, l, r) for(int i=(r)-1;i>=(l);--i)
#define mst(t, v, n) memset(t, v, sizeof(decltype(*(t))) * (n))
#define sf(x) scanf("%d", &(x))
#ifndef ACM_LOCAL
#pragma GCC optimize(2)
#define endl '\n'
#endif

const int N = 100005;
char a[N], b[N];

void solve() {
    int n, c[3];
    cin >> n;
    rep(i, 0, 3) cin >> c[i];
    cin >> a;
    int ans = 0;
    int d = 0;
    for (int i = 0; i < n - d; i++) {
        char ch = a[i];
        int k;
        if (ch == 'R') {
            k = 1;
        } else if (ch == 'P') {
            k = 2;
        } else {
            k = 0;
        }
        if (c[k]) {
            ans++;
            c[k]--;
            b[i] = "RPS"[k];
        } else {
            b[i] = '*';
        }
    }
    if (ans * 2 >= n) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            if (b[i] == '*') {
                for (int k = 0; k < 3; k++) {
                    if (c[k]) {
                        c[k]--;
                        b[i] = "RPS"[k];
                        break;
                    }
                }
            }
        }
        b[n] = '\0';
        cout << b << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
#ifdef ACM_LOCAL
    freopen("./data/std.in", "r", stdin);
    // freopen("./data/std.out", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif

#ifdef ACM_LOCAL
    auto start = clock();
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
#ifdef ACM_LOCAL
    auto end = clock();
    cerr << "Run Time: " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
#endif
    return 0;
}