#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define print(x, text) cout << text << " = " << x << endl;
#define printv(x, text) cout << text << " = "; for (auto e : x) cout << e << ' '; cout << endl;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for (int tt = 0; tt < t; ++tt) {
        int n, m;
        cin >> n;

        int nep = 0, chp = 0, p, q, neq = 0, chq = 0;
        for (int i = 0; i < n; ++i) {
            cin >> p;
            if (p % 2 == 0) chp++;
            else nep++;
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> q;
            if (q % 2 == 0) chq++;
            else neq++;
        }

        ll ans = (ll) neq * (ll) nep + (ll) chp * (ll) chq;
        cout << ans << endl;
    }
}
