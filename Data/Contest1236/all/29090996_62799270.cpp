#include <bits/stdc++.h>
using namespace std;

typedef vector<int> veci;
typedef pair<int, int> pii;
typedef vector<pii> vecii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vecl;
typedef vector<pll> vecll;
#define MOD (1e9 + 7)
#define EPS (1e-9)
#define fi first
#define se second
#define endl '\n'


void solve() {
    int n;
    cin >> n;

    vector<vector<int>> ans(n);
    for (int i=0; i<n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i % 2 == 0) {
                ans[j].push_back(i*n+j+1);
            } else {
                ans[n-1-j].push_back(i*n+j+1);
            }
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " \n"[j==n-1];
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL_TEST
    (void)argc;
    const string strpath = string(argv[0]) + string("-test.in");
    freopen(strpath.c_str(), "r", stdin);
    int tcs;
    cin >> tcs;
    while (tcs-- > 0)
#endif
        solve();
}
