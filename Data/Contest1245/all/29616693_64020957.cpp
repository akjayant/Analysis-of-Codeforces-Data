#include<bits/stdc++.h>
#define ALL(X)        X.begin(),X.end()
#define FOR(I,A,B)    for(int I = A; (I) <= (B); (I)++)
#define FORW(I,A,B)   for(int I = A; (I) < (B);  (I)++)
#define FORD(I,A,B)   for(int I = A; (I) >= (B); (I)--)
#define CLEAR(X)      memset(X,0,sizeof(X))
#define SIZE(X)       int(X.size())
#define CONTAINS(A,X) (A.find(X) != A.end())
#define PB            push_back
#define MP            make_pair
#define X             first
#define Y             second
using namespace std;

typedef signed long long slong;
typedef long double ldouble;
const slong INF = 1000000100;
const ldouble EPS = 1e-9;


struct find_union {
    vector<int> S;
    vector<slong> M;

    find_union(int n, vector<slong> _M) : S(n), M(_M) {
        FORW(i,0,n) S[i] = i;
    }

    int find(int a) {
        return S[a] == a ? a : (S[a] = find(S[a]));
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if (M[a] < M[b]) {
            S[b] = a;
        } else {
            S[a] = b;
        }
        return true;
    }
};

const int MAXN = 2020;
int N;
slong X[MAXN];
slong Y[MAXN];
slong K[MAXN];
slong C[MAXN];

void read_data() {
    scanf("%d", &N);
    FORW(i,0,N) scanf("%lld %lld", X+i, Y+i);
    FORW(i,0,N) scanf("%lld", C+i);
    FORW(i,0,N) scanf("%lld", K+i);
}

slong weight(int i, int j) {
    slong dist = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
    return dist * (K[i] + K[j]);
}

void solve() {
    find_union F(N, vector<slong>(C, C+N));
    vector<tuple<slong, int, int>> E;
    FORW(i,0,N) FORW(j,i+1,N) E.PB(make_tuple(weight(i, j), i, j));
    sort(ALL(E));
    slong edge_w = 0;
    vector<pair<int, int>> built_e;
    for (auto e: E) {
        slong w;
        int i, j;
        tie(w, i, j) = e;
        if (F.find(i) == F.find(j)) continue;
        slong m = max(F.M[F.find(i)], F.M[F.find(j)]);
        if (w <= m) {
            built_e.PB(MP(i, j));
            F.unite(i, j);
            edge_w += w;
            continue;
        }
    }

    slong node_w = 0;
    set<int> built;
    FORW(i,0,N) {
        int x = F.find(i);
        if (CONTAINS(built, x)) continue;
        built.insert(x);
        node_w += F.M[x];
    }

//    cout << "DEBUG: edge_w=" << edge_w << " node_w=" << node_w << endl;
    slong r = edge_w + node_w;
    cout << r << endl;
    cout << SIZE(built) << endl;
    for (int x: built) cout << x+1 << " ";
    cout << endl;
    cout << SIZE(built_e) << endl;
    for (auto e: built_e) {
        cout << e.X+1 << " " << e.Y+1 << endl;
    }

}

int main() {
    read_data();
    solve();
}
