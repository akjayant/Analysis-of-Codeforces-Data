#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define L long long
#define MP make_pair
#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPR(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a, b) for(int i = b - 1; i >= a; --i)
#define EB emplace_back
#define ST first
#define ND second
#define S size()
#define RS resize

using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using PI = pair<int, int>;
using VPI = vector<PI>;
using VVPI = vector<VPI>;
using VL = vector<L>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VC = vector<char>;
using VVC = vector<VC>;

VVI g;
VVL c;
VL wyn;
VVL kol;

void dfs(int v, int p, L c1, L c2, int nr)
{
    if ((c1 == 0 && c2 == 1) || (c1 == 1 && c2 == 0))
    {
        kol[v][nr] = 2;
        wyn[nr] += c[v][2];
    }
    if ((c1 == 0 && c2 == 2) || (c1 == 2 && c2 == 0))
    {
        kol[v][nr] = 1;
        wyn[nr] += c[v][1];
    }
    if ((c1 == 1 && c2 == 2) || (c1 == 2 && c2 == 1))
    {
        kol[v][nr] = 0;
        wyn[nr] += c[v][0];
    }
    for (int u : g[v])
        if (u != p)
        {
            if (c1 == 0 && c2 == 1)
                dfs(u, v, c2, 2, nr);
            if (c1 == 1 && c2 == 0)
                dfs(u, v, c2, 2, nr);
            if (c1 == 0 && c2 == 2)
                dfs(u, v, c2, 1, nr);
            if (c1 == 2 && c2 == 0)
                dfs(u, v, c2, 1, nr);
            if (c1 == 1 && c2 == 2)
                dfs(u, v, c2, 0, nr);
            if (c1 == 2 && c2 == 1)
                dfs(u, v, c2, 0, nr);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    g.RS(n);
    c.RS(n, VL(3));
    kol.RS(n, VL(6));
    wyn.RS(6);
    REP(i, n)
        cin >> c[i][0];
    REP(i, n)
        cin >> c[i][1];
    REP(i, n)
        cin >> c[i][2];
    REP(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].EB(b);
        g[b].EB(a);
    }
    REP(i, n)
        if (int(g[i].S) > 2)
        {
            cout << -1;
            return 0;
        }
    int s = -1;
    REP(i, n)
        if (int(g[i].S) == 1)
        {
             s = i;
             break;
        }
    dfs(s, -1, 2, 1, 0);
    dfs(s, -1, 1, 2, 1);
    dfs(s, -1, 2, 0, 2);
    dfs(s, -1, 0, 2, 3);
    dfs(s, -1, 0, 1, 4);
    dfs(s, -1, 1, 0, 5);
    pair<L, L> odp = MP(10000000000000000, -1);
    REP(i, 6)
        if (wyn[i] < odp.ST)
            odp = MP(wyn[i], i);
    cout << odp.ST << endl;
    REP(i, n)
        cout << kol[i][odp.ND] + 1 << ' ';
    return 0;
}

// clang++ -std=c++11 -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wfloat-equal -fsanitize=address,undefined -D_GLIBCXX_DEBUG -DDEBUG -ggdb con1.cpp -o a
