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
int N;
int A, B, C;
string D;

char E[105];

void win(int r, int p, int s) {
    cout << "YES" << endl;

    REP(i, N) E[i] = 0;
    REP(i, N) {
        if (D[i] == 'R' && r) {
            E[i] = 'P';
            r--;
            B--;
        } else if (D[i] == 'P' && p) {
            E[i] = 'S';
            p--;
            C--;
        } else if (D[i] == 'S' && s) {
            E[i] = 'R';
            s--;
            A--;
        }
    }

    REP(i, N) {
        if (E[i]) continue;
        if (A) {
            E[i] = 'R';
            A--;
        } else if (B) {
            E[i] = 'P';
            B--;
        } else {
            E[i] = 'S';
            C--;
        }
    }

    E[N] = 0;
    cout << string(E) << endl;
}

void solve() {
    cin >> N;
    cin >> A >> B >> C;
    cin >> D;

    bool can = false;
    int M = (N+1) / 2;

    int P = 0, R = 0, S = 0;
    REP(i, N) {
        if (D[i] == 'P') P++;
        else if (D[i] == 'R') R++;
        else S++;
    }

    REP(p, M+1) REP(r, M-p+1) {
        int s = M-p-r;

        if (r > R || p > P || s > S) continue;

        if (B >= r && C >= p && A >= s) {
            win(r, p, s);
            can = true;
            break;
        }
    }
    if (!can) {
        cout << "NO" << endl;
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
