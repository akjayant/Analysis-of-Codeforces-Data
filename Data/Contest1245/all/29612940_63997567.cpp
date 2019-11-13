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

int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return (a + b);
    }
    else {
        return gcd(b, a % b);
    }
}

void solve() {
    int a, b;
    cin >> a >> b;
    //cout << gcd(a, b) << endl;
    if (gcd(a, b) == 1) {
        cout << "Finite" << endl;
    }
    else {
        cout << "Infinite" << endl;
    }
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

