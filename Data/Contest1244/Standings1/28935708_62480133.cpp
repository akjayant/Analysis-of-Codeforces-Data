#include <bits/stdc++.h>

using namespace std;

#define MS(a, b) memset(a, b, sizeof(a))
#define REP(a, b, c) for (register int a = b, _n = c; a <= _n; ++a)
#define DREP(a, b, c) for (register int a = b, _n = c; a >= _n; --a)
#define FOR(a, b, c) for (register int a = b, _n = c; a < _n; ++a)
#define EREP(a, b) for (register int a = head[b]; a; a = edge[a].nxt)
#define LL long long

inline int rd () {
    int x = 0; bool f = 0; char IO = getchar();
    while ((IO < '0' || IO > '9') && IO != '-') IO = getchar();
    if (IO == '-') IO = getchar(), f = 1;
    while (IO >= '0' && IO <= '9') x = (x << 3) + (x << 1) + (IO ^ 48), IO = getchar();
    return f ? -x : x;
}

const int SIZE = 100005;

int n;

int deg[SIZE];

int head[SIZE], ecnt;
struct Edge {
    int v, nxt;
} edge[SIZE << 1];
void Add_Edge (int u, int v) {
    ++ecnt;
    edge[ecnt].v = v;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt;
}

int c[4][SIZE];

int s[SIZE];

int tmp[SIZE];
int Ans[SIZE];
LL ans = -1;

int main () {
    n = rd();

    REP (j, 1, 3)
        REP (i, 1, n)
            c[j][i] = rd();

    int Mx = 0;
    FOR (i, 1, n) {
        int u = rd(), v = rd();
        ++deg[u], ++deg[v];
        Mx = max(Mx, max(deg[u], deg[v]));
        Add_Edge(u, v);
        Add_Edge(v, u);
    }

    if (Mx > 2) {
        puts("-1");
        return 0;
    }

    int cnt = 0;
    REP (i, 1, n) if (deg[i] == 1) {
        s[++cnt] = i;
        break;
    }

    s[0] = -1;
    while (cnt < n) {
        int u = s[cnt];
        EREP (i, u) {
            Edge& e = edge[i];
            if (e.v == s[cnt - 1]) continue;
            s[++cnt] = e.v;
            break;
        }
    }

    REP (i, 1, 3) REP (j, 1, 3) if (i != j) {
        tmp[s[1]] = i, tmp[s[2]] = j;
        LL tot = c[i][s[1]] + c[j][s[2]];
        int l1 = i, l2 = j, t;
        //cout << l1 << " " << l2 << endl;
        REP (x, 3, n) {
            tot += c[l1 ^ l2][s[x]];
            tmp[s[x]] = l1 ^ l2;
            t = l2;
            l2 = l1 ^ l2;
            l1 = t;
        }
        if (ans == -1 || ans > tot) {
            ans = tot;
            REP (x, 1, n)
                Ans[x] = tmp[x];
        }
    }

    printf ("%lld\n", ans);
    REP (i, 1, n) printf ("%d ", Ans[i]);

    return 0;
}
