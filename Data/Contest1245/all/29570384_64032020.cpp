#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (int)a; i <= (int)b; ++i)
#define FORD(i, a, b) for (int i = (int)a; i >= (int)b; --i)
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define Debug(x) cerr << #x << " = " << x << '\n';
#define HERE cerr << "HERE\n\n";
#define X first
#define Y second
#define pb push_back
#define FASTER { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;
#include <iostream>
#include <vector>
#include <algorithm> // H�m sort
using namespace std;


struct edge {
    int u, v;
    int64_t w;
};

bool cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}

int const N = 2e3 + 5;
int n;
ii Pos[N];
int c[N];
int k[N];

int cha[N], hang[N];


int find(int u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}


bool join(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v]=u;
    return true;
}

int main() {
    FASTER
    cin >> n;
    vector <edge> Edges;
    FOR(i, 1, n) cin >> Pos[i].X >> Pos[i].Y;
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 1, n) cin >> k[i];
    FOR(i, 1, n){
        edge tmp;
        tmp.u = 0;
        tmp.v = i;
        tmp.w = c[i];
        Edges.pb(tmp);
    }
    FOR(i, 1, n) FOR(j, i + 1, n){
        int64_t val = (int64_t)(abs(Pos[i].X - Pos[j].X) + abs(Pos[i].Y - Pos[j].Y)) * (int64_t)(k[i] + k[j]);
        edge tmp;
        tmp.u = i;
        tmp.v = j;
        tmp.w = val;
        Edges.pb(tmp);
    }

    sort(Edges.begin(), Edges.end(), cmp);

    for (int i=1; i<=n; i++) {
        cha[i] = i;
        hang[i] = 0;
    }

    int64_t mst_weight = 0;
    vector <int> station;
    vector <ii> ways;

    for (edge &e: Edges) {
        if (join(e.u, e.v)) {
            mst_weight += e.w;
            if (e.u == 0) station.push_back(e.v);
            else ways.pb(ii(e.u, e.v));
        }
    }

    cout << mst_weight << '\n';
    cout << station.size() << '\n';
    REP(i, station.size()) cout << station[i] << ' ';
    cout << '\n' << ways.size() << '\n';
    REP(i, ways.size()) cout << ways[i].X << ' ' << ways[i].Y << '\n';
    return 0;
}
