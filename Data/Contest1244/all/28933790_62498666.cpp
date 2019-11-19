#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 1;
const long long INF = 2 * 1e18 + 1;
long long c[3][maxn];
vector <long long> g[maxn];
long long curans[maxn];
long long col[maxn];
bool used[maxn];
long long n;
void ERASE() {
    for (long long i = 0; i < n; i++) {
        used[i] = false;
        col[i] = 0;
    }
}
long long tryc(long long v, long long c1, long long c2) {
    col[v] = 3 - c1 - c2;
    used[v] = true;
    //cout << v << "--" << c1 << ", " << c2 << "\n";
    long long C = c[col[v]][v];
    for (long long i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]]) continue;
        long long got = tryc(g[v][i], c2, 3 - c1 - c2);
        C += got;
    }
    return C;
}
int main() {
    /*
    freopen("stdin", "r", stdin);
    freopen("stdout", "w", stdout);
    //*/
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> c[0][i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> c[1][i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> c[2][i];
    }
    for (long long i = 0; i < n - 1; i++) {
        long long s, e;
        cin >> s >> e;
        s--; e--;
        g[s].push_back(e);
        g[e].push_back(s);
    }
    long long St = -1;
    for (long long i = 0; i < n; i++) {
        if (g[i].size() >= 3) {
            cout << "-1";
            return 0;
        }
        if (g[i].size() == 1)
            St = i;
    }
    long long minc = INF;
    for (long long c1 = 0; c1 < 3; c1++) {
        for (long long c2 = 0; c2 < 3; c2++) {
            if (c1 == c2) continue;
            ERASE();
            long long to = g[St][0], to1;
            col[St] = c1;
            used[St] = true;
            col[to] = c2;
            used[to] = true;
            for (long long i = 0; i < g[to].size(); i++) {
                if (g[to][i] != St)
                    to1 = g[to][i];
            }
            //cout << "(" << c[c1][St] + c[c2][to] << ") ";
            long long cost = c[c1][St] + c[c2][to] + tryc(to1, c1, c2);
            //cout << St << " " << to << " " << cost << " " << c1 << " " << c2 << ":  ";
            //for (long long i = 0; i < n; i++) cout << col[i] << " ";
            //cout << "\n";
            if (cost < minc) {
                minc = cost;
                for (long long i = 0; i < n; i++) {
                    curans[i] = col[i];
                }
            }
        }
    }
    if (minc >= INF) {
        cout << "-1";
        return 0;
    }
    cout << minc << "\n";
    for (long long i = 0; i < n; i++) {
        cout << curans[i] + 1 << " ";
    }
}
