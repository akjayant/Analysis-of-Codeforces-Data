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

int T;
int A, B, C, D, K;

int main() {
    cin >> T;
    while (T--) {
        cin >> A >> B >> C >> D >> K;
        int a = (A + C - 1) / C;
        int b = (B + D - 1) / D;
        if (a + b <= K) {
            cout << a << " " << b << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
