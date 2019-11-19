/*Bismillahir Rahmanir Rahim*///{
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long; using ld = long double;
const ll llinf = (1ll<<61)-1;
const double eps = 1e-6, ldeps = 1e-9;
struct Dbg {
static constexpr auto &os = cout;   // replace by cerr in interactive.
template<class C> static auto dud(C *x)->decltype(os << *x, 0);
template<class C> static char dud(...);
template<class C> typename enable_if<sizeof dud<C>(0)!=1, Dbg&>::type operator<<(const C &x) { os << x; return *this; }
template<class C> Dbg &dump(C b, C e) {
    *this << "\n[";
    int cur = 0;
    for (C i = b; i!=e and cur<26; i++, cur++) *this << ", "+2*(i==b) << *i;
    return *this << ']';
}
template<class C> typename enable_if<sizeof dud<C>(0)==1, Dbg&>::type operator<<(const C &x) {
    return dump(begin(x), end(x));
}
template<class C, size_t X> typename enable_if<sizeof(C)!=1, Dbg&>::type operator <<(C (&x)[X]) {
    return dump(begin(x), end(x));
}
template<class B, class C> Dbg &operator <<(const pair<B, C> &x) {
    return *this << '{' << x.first << ", " << x.second << '}';
}
template<class C, size_t Y> struct TP {
    void operator()(Dbg& os, const C &t) { TP<C, Y-1>()(os, t); os << ", " << get<Y-1>(t); }
};
template<class C> struct TP<C, 1> { void operator()(Dbg& os, const C &t) { os << get<0>(t); } };
template<class... C> Dbg& operator<<(const tuple<C...> &t) {
    os << '{', TP<decltype(t), sizeof...(C)>()(*this, t); return *this << '}';
}
Dbg &operator<<(ostream&(*x)(std::ostream&)) { os << x; return *this; }
} dbg;
void err(istringstream *iss) { delete iss; }
template<class C, class... Args> void err(istringstream *iss, const C &val, const Args &... args) {
    string name; *iss >> name; if (name.back()==',') name.pop_back();
    dbg << name << " = " << val << "; ", err(iss, args ...);
}
#define bug(args...) dbg << __LINE__ << ": ", err(new istringstream(string(#args)), args), dbg << endl
#define sl(a) int(strlen(a))
#define sz(a) int(a.size())
int T, Q, cn;//}
const int inf = 1000000007, mxn = 100005;


class DSU//{
{
    vector<int> dsupar, siz;
public:
    int cntDSU;

    void reset() {
        int sz = int(dsupar.size());
        for (int i = 0; i<sz; i++) dsupar[i] = i, siz[i] = 1;
    }

    DSU(int N, int noOfSets = -1) {
        dsupar.resize(N+5), siz.resize(N+5);
        reset();
        cntDSU = noOfSets==-1 ? N : noOfSets;
    }

    int find(int x) {
        return dsupar[x]==x ? x : dsupar[x] = find(dsupar[x]);
    }

    void union_(int u, int v) {
        if ((u = find(u))==(v = find(v))) return;
        if (siz[u]<siz[v]) swap(u, v);
        dsupar[v] = u, siz[u] += siz[v], siz[v] = 0;
        cntDSU--;
    }
};//}


int n, m, deg[mxn], shits[mxn], si, id[mxn];
list<int> g[mxn];
bool mnc[mxn], fuk[1005][1005];

signed main() { ios::sync_with_stdio(0); cin.tie(NULL); cout.precision(11);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    int mn = inf, mv = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i]<mn) mv = i, mn = deg[mv];
    }
    DSU dsu(n, n);
    for (auto &v : g[mv]) {
        mnc[v] = 1, shits[++si] = v, id[v] = si;
    }
    int notshit = 0;
    for (int i = 1; i <= n; i++) {
        if (!mnc[i]) dsu.union_(mv, i), notshit++;
    }
    for (int i = 1; i <= si; i++) {
        int u = id[shits[i]];
        assert(i==u);
        int cnt = 0;
        for (auto &v : g[shits[i]]) {
            if (mnc[v]) fuk[u][id[v]] = fuk[id[v]][u] = 1;
            else cnt++;
        }
        if (cnt<notshit) dsu.union_(mv, shits[i]);
    }
    for (int i = 1; i <= si; i++) {
        for (int j = i+1; j <= si; j++) {
            if (!fuk[i][j]) dsu.union_(shits[i], shits[j]);
        }
    }
    cout << dsu.cntDSU-1 << '\n';
}