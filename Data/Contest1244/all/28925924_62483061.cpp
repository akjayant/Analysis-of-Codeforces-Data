/*
 * (c) fushar (Ashar Fuadi)
*/

#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, _n = n; i < _n; i++)
#define FOR(i, a, b) for (int i = a, _b = b; i <= _b; i++)
#define FORD(i, b, a) for (int i = b, _a = a; i >= _a; i--)
#define RESET(c, v) memset(c, v, sizeof c)

using namespace std;
using ll = long long;

/***********************************************************/

ll N, P, W, D;

int main() {
    cin >> N >> P >> W >> D;

    ll wins = P/W;
    REP(i, W+1) {
        if (wins < 0) {
            break;
        }

        ll rem = P - wins*W;
        if (rem % D == 0) {
            ll draws = rem/D;
            if (wins + draws <= N) {
                cout << wins << " " <<  draws << " " << (N - wins - draws) << endl;
                return 0;
            }
        }

        wins--;
    }

    cout << -1 << endl;
}
