#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define mp make_pair
#ifndef MY
    #define endl '\n'
#endif
//#define int long long
#define sz(x) (int)x.size()

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair < int, int > pii;

ostream & operator << (ostream & out, vector < int > & lst) {
    for (auto a : lst)
        out << a << ' ';
    out << endl;
    return out;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i <= b; i++) {
        int j = b - i;
        int f = min(i, c / 2) * 3;
        int s = min(a, j / 2) * 3;
        ans = max(ans, f + s);
    }
    cout << ans << endl;
}

signed main() {
#ifdef MY
    freopen("f.in", "r", stdin);
    //freopen("f.out", "w", stdout);
#endif // MY
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
