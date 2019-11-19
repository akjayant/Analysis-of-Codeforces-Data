#include <bits/stdc++.h>
#define File(_) freopen(#_ ".in", "r", stdin), freopen(#_ ".out", "w", stdout)
#define ALL(x) x.begin(), x.end()
#define mset(a, b) memset(a, b, sizeof a)
#define rep(i, a, b) for(int i(a), i##_END_(b); i <= i##_END_; i++)
#define drep(i, a, b) for(int i(a), i##_END_(b); i >= i##_END_; i--)
using namespace std;
template<class T> inline bool tomax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template<class T> inline bool tomin(T &a, T b) {return b < a ? a = b, 1 : 0;}
typedef long long ll;
typedef double db;

template<class T>
void read(T &a) {
    char c; bool f = false;
    for(c = getchar(); !isdigit(c); c = getchar()) f |= (c == '-');
    for(a = 0; isdigit(c); c = getchar()) a = (a << 1) + (a << 3) + c - '0';
    if(f) a = -a;
}

template<int N, int M, class T> struct Link {
#define erep(k, G, o) for(int k(G.HEAD[o]); k; k = G.NXT[k])
    int HEAD[N], NXT[M], tot; T W[M];
    void add(int x, T w) {NXT[++tot] = HEAD[x]; W[HEAD[x] = tot] = w;}
    T& operator[] (int k) {return W[k];}
};

const int N = 1e5 + 5;

Link<N, N * 2, int> G;

int c[3][N];
int deg[N], vec[N], tot;

void dfs(int o, int f) {
    vec[++tot] = o;
    erep(k, G, o) {
        int v = G[k];
        if(v == f) continue;
        dfs(v, o);
    }
}

int ansc[N];

int main() {
    int n, a, b;
    read(n);
    rep(k, 0, 2) rep(i, 1, n) read(c[k][i]);
    rep(i, 2, n) {
        read(a); read(b);
        deg[a]++; deg[b]++;
        G.add(a, b); G.add(b, a);
    }
    rep(i, 1, n) if(deg[i] > 2) return puts("-1"), 0;
    rep(i, 1, n) if(deg[i] == 1) {
        dfs(i, 0);
        break;
    }
    ll ans = 1e18;
    int col = -1, dir = -1;
    rep(k, 0, 2) rep(d, 1, 2) {
        int t = k;
        ll now = 0;
        rep(i, 1, n) {
            now += c[t][vec[i]];
            t = (t + d) % 3;
        }
        if(tomin(ans, now)) {
            col = k; dir = d;
        }
    }
    cout << ans << endl;
    rep(i, 1, n) {
        ansc[vec[i]] = col;
        col = (col + dir) % 3;
    }
    rep(i, 1, n) printf("%d%c", 1 + ansc[i], " \n"[i == n]);
    return 0;
}
