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
string S;
int N;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> S;

        int res = N;
        REP(i, N) {
            if (S[i] == '1') {
                res = max(res, 2*max(i+1, N-i));
            }
        }
        cout << res << endl;
    }
}
