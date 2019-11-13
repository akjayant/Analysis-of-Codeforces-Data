#include <bits/stdc++.h>
using namespace std;

typedef vector<int> veci;
typedef pair<int, int> pii;
typedef vector<pii> vecii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vecl;
typedef vector<pll> vecll;
#define EPS (1e-9)
#define MOD (1e9 + 7)
#define fi first
#define se second
#define endl '\n'

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int cnt = 0;
    while (b>=1 && c>=2) {
        b -= 1;
        c -= 2;
        cnt += 3;
    }
    while (a>=1 && b>=2) {
        a -= 1;
        b -= 2;
        cnt += 3;
    }

    cout << cnt << endl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL_TEST
    (void)argc;
    const string strpath = string(argv[0]) + string("-test.in");
    freopen(strpath.c_str(), "r", stdin);
#endif
    int tcs;
    cin >> tcs;
    while (tcs-- > 0)
    solve();
}
