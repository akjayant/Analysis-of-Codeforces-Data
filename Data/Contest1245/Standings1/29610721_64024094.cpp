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

const int MAXN = 2005;
const ll oo = 100000000000000000LL;

int N;
ll X[MAXN], Y[MAXN];
ll W[MAXN][MAXN];
ll K[MAXN];

ll C[MAXN], E[MAXN];
bool used[MAXN];

int main() {
    cin >> N;
    REP(i, N) cin >> X[i] >> Y[i];
    REP(i, N) {
        ll c;
        cin >> c;
        W[i][N] = W[N][i] = c;
    }
    REP(i, N) cin >> K[i];

    REP(i, N) REP(j, N) {
        W[i][j] = (abs(X[i]-X[j]) + abs(Y[i]-Y[j])) * (K[i] + K[j]);
    }

    REP(i, N+1) C[i] = oo;
    C[N] = 0;

    ll res = 0;
    vector<int> stations;
    vector<pair<int, int>> edges;

    REP(i, N+1) {
        int u = -1;
        REP(v, N+1) {
            if (used[v]) continue;
            if (u == -1 || C[v] < C[u]) {
                u = v;
            }
        }

        used[u] = true;

        REP(v, N+1) {
            if (u == v || used[v]) continue;
            if (C[v] > W[u][v]) {
                C[v] = W[u][v];
                E[v] = u;
            }
        }

        if (u == N) continue;

        res += C[u];
        if (E[u] == N) {
            stations.push_back(u+1);
        } else {
            edges.push_back(make_pair(u+1, E[u]+1));
        }
    }

    cout << res << endl;
    cout << stations.size() << endl;
    REP(i, stations.size()) {
        if (i) cout << " ";
        cout << stations[i];
    }
    cout << endl;
    cout << edges.size() << endl;
    REP(i, edges.size()) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }
    cout << endl;
}
