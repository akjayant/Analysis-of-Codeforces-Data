/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>
#include <climits>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const ll inf = 1e9;
const int mod = 1e9+7;

class UnionFind {
private:
    vi p, rank;
public:
    UnionFind(int n) {
        p.assign(n, 0); rank.assign(n, 0);
        REP(i, 0, n) p[i] = i;
    }
    int findSet(int i) {
        return (i == p[i] ? i : (p[i] = findSet(p[i])));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int n;
ii xy[2010];
int c[2010];
int k[2010];
struct tp {
    ll cost;
    int conn_type;
    int a, b;
    tp(ll cost_, int conn_type_, int a_, int b_) {
        cost = cost_;
        conn_type = conn_type_;
        a = a_;
        b = b_;
    }
};

bool cmp(tp& a, tp& b) {
    return a.cost < b.cost;
}

void solve() {
    vector<tp> e;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            ll ct = 1LL * (1LL * k[i] + k[j]) * (1LL * abs(xy[i].first - xy[j].first) + abs(xy[i].second - xy[j].second));
            e.push_back(tp(ct, 1, i, j));
        }
    }
    for(int i=1; i<=n; i++) {
        e.push_back(tp(c[i], 0, i, 0));
    }
    sort(e.begin(), e.end(), cmp);
    UnionFind uf(n+1);
    ll ans = 0;
    vii wires;
    vi built;
    REP(i, 0, e.size()) {
        tp tmp_tp = e[i];
        if(!uf.isSameSet(tmp_tp.a, tmp_tp.b)) {
            uf.unionSet(tmp_tp.a, tmp_tp.b);
            ans += tmp_tp.cost;
            if(tmp_tp.conn_type == 0) {
                built.push_back(tmp_tp.a);
            } else {
                wires.push_back(ii(tmp_tp.a, tmp_tp.b));
            }
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", (int)built.size());
    REP(i, 0, built.size()) {
        if(i) printf(" ");
        printf("%d", built[i]);
    }
    printf("\n%d\n", (int)wires.size());
    REP(i, 0, wires.size()) {
        printf("%d %d\n", wires[i].first, wires[i].second);
    }
}

int main() {
    int t, kase = 0;
    // scanf("%d", &t);
    t = 1;
    while(t--) {
        scanf("%d", &n);
        REP(i, 1, n+1) {
            scanf("%d%d", &xy[i].first, &xy[i].second);
        }
        REP(i, 1, n+1) scanf("%d", &c[i]);
        REP(i, 1, n+1) scanf("%d", &k[i]);
        //printf("Case #%d: %lld\n", ++kase, solve());
        solve();
    }
	return 0;
}
