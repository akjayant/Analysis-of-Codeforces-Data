//#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>
using namespace std;
//@起動時
struct initon {
    initon() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout.setf(ios::fixed);
        cout.precision(16);
        srand((unsigned) clock() + (unsigned) time(NULL));
    };
} __initon;
//衝突対策
#define ws ___ws
struct T {
    int f, s, t;
    T() { f = -1, s = -1, t = -1; }
    T(int f, int s, int t) : f(f), s(s), t(t) {}
    bool operator<(const T &r) const {
        return f != r.f ? f < r.f : s != r.s ? s < r.s : t < r.t;
        //return f != r.f ? f > r.f : s != r.s ? s > r.s : t > r.t; 大きい順
    }
    bool operator>(const T &r) const {
        return f != r.f ? f > r.f : s != r.s ? s > r.s : t > r.t;
        //return f != r.f ? f > r.f : s != r.s ? s > r.s : t > r.t; 小さい順
    }
    bool operator==(const T &r) const {
        return f == r.f && s == r.s && t == r.t;
    }
    bool operator!=(const T &r) const {
        return f != r.f || s != r.s || t != r.t;
    }
    int operator[](int i) {
        assert(i < 3);
        return i == 0 ? f : i == 1 ? s : t;
    }
};
#define int long long
#define ll long long
#define double long double
#define ull unsigned long long
using dou = double;
using itn = int;
using str = string;
using bo= bool;
#define au auto
using P = pair<ll, ll>;

#define fi first
#define se second
#define vec vector
#define beg begin
#define rbeg rbegin
#define con continue
#define bre break
#define brk break
#define is ==


//マクロ省略系 コンテナ

using vi = vector<int>;
#define _overloadvvi(_1, _2, _3, _4, name, ...) name
#define vvi0() vec<vi>
#define vvi1(a) vec<vi> a
#define vvi2(a, b) vec<vi> a(b)
#define vvi3(a, b, c) vec<vi> a(b,vi(c))
#define vvi4(a, b, c, d) vec<vi> a(b,vi(c,d))
#define vvi(...) _overloadvvi(__VA_ARGS__,vvi4,vvi3,vvi2 ,vvi1,vvi0)(__VA_ARGS__)


using vl = vector<ll>;
#define _overloadvvl(_1, _2, _3, _4, name, ...) name
#define vvl1(a) vec<vl> a
#define vvl2(a, b) vec<vl> a(b)
#define vvl3(a, b, c) vec<vl> a(b,vl(c))
#define vvl4(a, b, c, d) vec<vl> a(b,vl(c,d))
#define vvl(...) _overloadvvl(__VA_ARGS__,vvl4,vvl3,vvl2 ,vvl1)(__VA_ARGS__)

using vb = vector<bool>;
#define _overloadvvb(_1, _2, _3, _4, name, ...) name
#define vvb1(a) vec<vb> a
#define vvb2(a, b) vec<vb> a(b)
#define vvb3(a, b, c) vec<vb> a(b,vb(c))
#define vvb4(a, b, c, d) vec<vb> a(b,vb(c,d))
#define vvb(...) _overloadvvb(__VA_ARGS__,vvb4,vvb3,vvb2 ,vvb1)(__VA_ARGS__)

using vs = vector<string>;
#define _overloadvvs(_1, _2, _3, _4, name, ...) name
#define vvs1(a) vec<vs> a
#define vvs2(a, b) vec<vs> a(b)
#define vvs3(a, b, c) vec<vs> a(b,vs(c))
#define vvs4(a, b, c, d) vec<vs> a(b,vs(c,d))
#define vvs(...) _overloadvvs(__VA_ARGS__,vvs4,vvs3,vvs2 ,vvs1)(__VA_ARGS__)

using vd = vector<double>;
#define _overloadvvd(_1, _2, _3, _4, name, ...) name
#define vvd1(a) vec<vd> a
#define vvd2(a, b) vec<vd> a(b)
#define vvd3(a, b, c) vec<vd> a(b,vd(c))
#define vvd4(a, b, c, d) vec<vd> a(b,vd(c,d))
#define vvd(...) _overloadvvd(__VA_ARGS__,vvd4,vvd3,vvd2 ,vvd1)(__VA_ARGS__)

using vc=vector<char>;
#define _overloadvvc(_1, _2, _3, _4, name, ...) name
#define vvc1(a) vec<vc> a
#define vvc2(a, b) vec<vc> a(b)
#define vvc3(a, b, c) vec<vc> a(b,vc(c))
#define vvc4(a, b, c, d) vec<vc> a(b,vc(c,d))
#define vvc(...) _overloadvvc(__VA_ARGS__,vvc4,vvc3,vvc2 ,vvc1)(__VA_ARGS__)

using vp = vector<P>;
#define _overloadvvp(_1, _2, _3, _4, name, ...) name
#define vvp1(a) vec<vp> a
#define vvp2(a, b) vec<vp> a(b)
#define vvp3(a, b, c) vec<vp> a(b,vp(c))
#define vvp4(a, b, c, d) vec<vp> a(b,vp(c,d))

using vt = vector<T>;
#define _overloadvvt(_1, _2, _3, _4, name, ...) name
#define vvt1(a) vec<vt> a
#define vvt2(a, b) vec<vt> a(b)
#define vvt3(a, b, c) vec<vt> a(b,vt(c))
#define vvt4(a, b, c, d) vec<vt> a(b,vt(c,d))

#define v3i(a, b, c, d) vector<vector<vi>> a(b, vector<vi>(c, vi(d)))
#define v3d(a, b, c, d) vector<vector<vd>> a(b, vector<vd>(c, vd(d)))
#define v3m(a, b, c, d) vector<vector<vm>> a(b, vector<vm>(c, vm(d)))

#define _vvi vector<vi>
#define _vvl vector<vl>
#define _vvb vector<vb>
#define _vvs vector<vs>
#define _vvd vector<vd>
#define _vvc vector<vc>
#define _vvp vector<vp>

#define PQ priority_queue<ll, vector<ll>, greater<ll> >
#define tos to_string
using mapi = map<int, int>;
using mapd = map<dou, int>;
using mapc = map<char, int>;
using maps = map<str, int>;
using seti = set<int>;
using setd = set<dou>;
using setc = set<char>;
using sets = set<str>;
using qui = queue<int>;
#define bset bitset
#define uset unordered_set
#define mset multiset
#define umap unordered_map
#define umapi unordered_map<int,int>
#define umapp unordered_map<P,int>
#define mmap multimap

//マクロ 繰り返し
#define _overloadrep(_1, _2, _3, _4, name, ...) name
# define _rep(i, n) for(int i = 0,_lim=n; i < _lim ; i++)
#define repi(i, m, n) for(int i = m,_lim=n; i < _lim ; i++)
#define repadd(i, m, n, ad) for(int i = m,_lim=n; i < _lim ; i+= ad)
#define rep(...) _overloadrep(__VA_ARGS__,repadd,repi,_rep,)(__VA_ARGS__)
#define _rer(i, n) for(int i = n; i >= 0 ; i--)
#define reri(i, m, n) for(int i = m,_lim=n; i >= _lim ; i--)
#define rerdec(i, m, n, dec) for(int i = m,_lim=n; i >= _lim ; i-=dec)
#define rer(...) _overloadrep(__VA_ARGS__,rerdec,reri,_rer,)(__VA_ARGS__)
#define fora(a, b) for(auto&& a : b)

//マクロ 定数
#define k3 1010
#define k4 10101
#define k5 101010
#define k6 1010101
#define k7 10101010
const int inf = (int) 1e9 + 100;
const ll linf = (ll) 1e18 + 100;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795029L;
ll ma = numeric_limits<ll>::min();
ll mi = numeric_limits<ll>::max();
const int y4[] = {-1, 1, 0, 0};
const int x4[] = {0, 0, -1, 1};
const int y8[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int x8[] = {1, 0, -1, 0, 1, -1, 1, -1};

//マクロ省略形 関数等
#define arsz(a) (sizeof(a)/sizeof(a[0]))
#define sz(a) ((int)(a).size())
#define rs resize
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()


inline void sort(string &a) { sort(a.begin(), a.end()); }
template<class T> inline void sort(vector<T> &a) { sort(a.begin(), a.end()); };
template<class T> inline void sort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len); };
template<class T, class F> inline void sort(vector<T> &a, F f) { sort(a.begin(), a.end(), [&](T l, T r) { return f(l) < f(r); }); };
enum ___pcomparator {
    fisi, fisd, fdsi, fdsd, sifi, sifd, sdfi, sdfd
};
inline void sort(vector<P> &a, ___pcomparator type) {
    switch (type) {
        case fisi:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi < r.fi : l.se < r.se; });
            break;
        case fisd:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi < r.fi : l.se > r.se; });
            break;
        case fdsi:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi > r.fi : l.se < r.se; });
            break;
        case fdsd:
            sort(all(a), [&](P l, P r) { return l.fi != r.fi ? l.fi > r.fi : l.se > r.se; });
            break;
        case sifi:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se < r.se : l.fi < r.fi; });
            break;
        case sifd:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se < r.se : l.fi > r.fi; });
            break;
        case sdfi:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se > r.se : l.fi < r.fi; });
            break;
        case sdfd:
            sort(all(a), [&](P l, P r) { return l.se != r.se ? l.se > r.se : l.fi > r.fi; });
            break;
    }
};
inline void sort(vector<T> &a, ___pcomparator type) {
    switch (type) {
        case fisi:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f < r.f : l.s < r.s; });
            break;
        case
            fisd:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f < r.f : l.s > r.s; });
            break;
        case
            fdsi:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f > r.f : l.s < r.s; });
            break;
        case
            fdsd:
            sort(all(a), [&](T l, T r) { return l.f != r.f ? l.f > r.f : l.s > r.s; });
            break;
        case
            sifi:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s < r.s : l.f < r.f; });
            break;
        case
            sifd:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s < r.s : l.f > r.f; });
            break;
        case
            sdfi:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s > r.s : l.f < r.f; });
            break;
        case
            sdfd:
            sort(all(a), [&](T l, T r) { return l.s != r.s ? l.s > r.s : l.f > r.f; });
            break;
    }
};
template<class T> inline void rsort(vector<T> &a) { sort(a.begin(), a.end(), greater<T>()); };
template<class T> inline void rsort(vector<T> &a, int len) { sort(a.begin(), a.begin() + len, greater<T>()); };
template<class U, class F> inline void rsort(vector<U> &a, F f) { sort(a.begin(), a.end(), [&](U l, U r) { return f(l) > f(r); }); };
template<class U> inline void sortp(vector<U> &a, vector<U> &b) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    sort(c);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;;
    }
};
//F = T<T>
//例えばreturn p.fi + p.se;
template<class U, class F> inline void sortp(vector<U> &a, vector<U> &b, F f) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    sort(c, f);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U, class F> inline void sortp(vector<U> &a, vector<U> &b, char type) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    sort(c, type);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U> inline void rsortp(vector<U> &a, vector<U> &b) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    rsort(c);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U, class F> inline void rsortp(vector<U> &a, vector<U> &b, F f) {
    vp c;
    int n = sz(a);
    assert(n == sz(b));
    rep(i, n)c.eb(a[i], b[i]);
    rsort(c, f);
    rep(i, n) {
        a[i] = c[i].first;
        b[i] = c[i].second;
    }
};
template<class U> inline void sortt(vector<U> &a, vector<U> &b, vector<U> &c) {
    vt r;
    int n = sz(a);
    assert(n == sz(b));
    assert(n == sz(c));
    rep(i, n)r.eb(a[i], b[i], c[i]);
    sort(r);
    rep(i, n) {
        a[i] = r[i].f;
        b[i] = r[i].s;
        c[i] = r[i].t;
    }
};
template<class U, class F> inline void sortt(vector<U> &a, vector<U> &b, vector<U> &c, F f) {
    vt r;
    int n = sz(a);
    assert(n == sz(b));
    assert(n == sz(c));
    rep(i, n)r.eb(a[i], b[i], c[i]);
    sort(r, f);
    rep(i, n) {
        a[i] = r[i].f;
        b[i] = r[i].s;
        c[i] = r[i].t;
    }
};
template<class U, class F> inline void rsortt(vector<U> &a, vector<U> &b, vector<U> &c, F f) {
    vt r;
    int n = sz(a);
    assert(n == sz(b));
    assert(n == sz(c));
    rep(i, n)r.eb(a[i], b[i], c[i]);
    rsort(r, f);
    rep(i, n) {
        a[i] = r[i].f;
        b[i] = r[i].s;
        c[i] = r[i].t;
    }
};
template<class T> inline void sort2(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)sort(a[i]); }
template<class T> inline void rsort2(vector<vector<T>> &a) { for (int i = 0, n = a.size(); i < n; i++)rsort(a[i]); }
template<typename A, size_t N, typename T> void fill(A (&a)[N], const T &v) { rep(i, N)a[i] = v; }
template<typename A, size_t N, size_t O, typename T> void fill(A (&a)[N][O], const T &v) { rep(i, N)rep(j, O)a[i][j] = v; }
template<typename A, size_t N, size_t O, size_t P, typename T> void fill(A (&a)[N][O][P], const T &v) { rep(i, N)rep(j, O)rep(k, P)a[i][j][k] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, typename T> void fill(A (&a)[N][O][P][Q], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)a[i][j][k][l] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, typename T> void fill(A (&a)[N][O][P][Q][R], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)a[i][j][k][l][m] = v; }
template<typename A, size_t N, size_t O, size_t P, size_t Q, size_t R, size_t S, typename T> void fill(A (&a)[N][O][P][Q][R][S], const T &v) { rep(i, N)rep(j, O)rep(k, P)rep(l, Q)rep(m, R)rep(n, S)a[i][j][k][l][m][n] = v; }

template<typename V, typename T>
void fill(V &xx, const T vall) {
    xx = vall;
}
template<typename V, typename T>
void fill(vector<V> &vecc, const T vall) {
    for (auto &&vx: vecc) fill(vx, vall);
}

//@汎用便利関数 入力
template<typename T = int> T _in() {
    T x;
    cin >> x;
    return (x);
}
#define _overloadin(_1, _2, _3, _4, name, ...) name
#define in0() _in()
#define in1(a) cin>>a
#define in2(a, b) cin>>a>>b
#define in3(a, b, c) cin>>a>>b>>c
#define in4(a, b, c, d) cin>>a>>b>>c>>d
#define in(...) _overloadin(__VA_ARGS__,in4,in3,in2 ,in1,in0)(__VA_ARGS__)

#define _overloaddin(_1, _2, _3, _4, name, ...) name
#define din1(a) int a;cin>>a
#define din2(a, b) int a,b;cin>>a>>b
#define din3(a, b, c) int a,b,c;cin>>a>>b>>c
#define din4(a, b, c, d) int a,b,c,d;cin>>a>>b>>c>>d
#define din(...) _overloadin(__VA_ARGS__,din4,din3,din2 ,din1)(__VA_ARGS__)

#define _overloaddind(_1, _2, _3, _4, name, ...) name
#define din1d(a) int a;cin>>a;a--
#define din2d(a, b) int a,b;cin>>a>>b;a--,b--
#define din3d(a, b, c) int a,b,c;cin>>a>>b>>c;a--,b--,c--
#define din4d(a, b, c, d) int a,b,c,d;cin>>a>>b>>c>>d;;a--,b--,c--,d--
#define dind(...) _overloaddind(__VA_ARGS__,din4d,din3d,din2d ,din1d)(__VA_ARGS__)


string sin() { return _in<string>(); }
ll lin() { return _in<ll>(); }
#define na(a, n) a.resize(n); rep(i,n) cin >> a[i];
#define nao(a, n) a.resize(n+1); rep(i,n) cin >> a[i+1];
#define nad(a, n) a.resize(n); rep(i,n){ cin >> a[i]; a[i]--;}
#define na2(a, b, n) a.resize(n),b.resize(n);rep(i, n)cin >> a[i] >> b[i];
#define na2d(a, b, n) a.resize(n),b.resize(n);rep(i, n){cin >> a[i] >> b[i];a[i]--,b[i]--;}
#define na3(a, b, c, n) a.resize(n),b.resize(n),c.resize(n);   rep(i, n)cin >> a[i] >> b[i] >> c[i];
#define na3d(a, b, c, n) a.resize(n),b.resize(n),c.resize(n);   rep(i, n){cin >> a[i] >> b[i] >> c[i];a[i]--,b[i]--,c[i]--;}
#define nt(a, h, w) resize(a,h,w);rep(hi,h)rep(wi,w) cin >> a[hi][wi];
#define ntd(a, h, w) rs(a,h,w);rep(hi,h)rep(wi,w) cin >> a[hi][wi], a[hi][wi]--;
#define ntp(a, h, w) fill(a,'#');rep(hi,1,h+1)rep(wi,1,w+1) cin >> a[hi][wi];

//デバッグ
#define sp << " " <<

#define debugName(VariableName) # VariableName

#define _deb1(x) cerr <<  debugName(x)<<" = "<<x << endl
#define _deb2(x, y) cerr <<  debugName(x)<<" = "<<x<<", "<< debugName(y)<<" = "<<y<< endl
#define _deb3(x, y, z) cerr <<  debugName(x)<<" = "<<x  << ", " <<  debugName(y)<<" = "<<y <<", " debugName(z)<<" = "<<z <<endl
#define _deb4(x, y, z, a) cerr <<  debugName(x)<<" = "<<x <<", " <<   debugName(y)<<" = "<<y <<", " <<  debugName(z)<<" = "<<z <<", " <<  debugName(a)<<" = "<<a<<endl
#define _deb5(x, y, z, a, b) cerr <<  debugName(x)<<" = "<<x <<", " <<   debugName(y)<<" = "<<y <<", " <<  debugName(z)<<" = "<<z <<", " <<  debugName(a)<<" = "<<a<<", " <<  debugName(b)<<" = "<<b<<endl


#define _overloadebug(_1, _2, _3, _4, _5, name, ...) name
#define debug(...) _overloadebug(__VA_ARGS__,_deb5,_deb4,_deb3,_deb2,_deb1)(__VA_ARGS__)
#define deb(...) _overloadebug(__VA_ARGS__,_deb5,_deb4,_deb3,_deb2,_deb1)(__VA_ARGS__)
#define debugline(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n'
void ole() {
#ifdef _DEBUG
    debugline("ole");
    exit(0);
#endif
    string a = "a";
    rep(i, 30)a += a;
    rep(i, 1 << 17)cout << a << endl;
    cout << "OLE 出力長制限超過" << endl;
    exit(0);
}
void tle() { while (inf)cout << inf << endl; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll gcd(vi b) {
    ll res = b[0];
    for (auto &&v :b)res = gcd(v, res);
    return res;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll rev(ll a) {
    ll res = 0;
    while (a) {
        res *= 10;
        res += a % 10;
        a /= 10;
    }
    return res;
}
template<class T> void rev(vector<T> &a) {
    reverse(all(a));
}
void rev(string &a) {
    reverse(all(a));
}
ll ceil(ll a, ll b) {
    if (b == 0) {
        debugline("ceil");
        deb(a, b);
        ole();
        return -1;
    } else return (a + b - 1) / b;
}
ll sqrt(ll a) {
    if (a < 0) {
        debugline("sqrt");
        deb(a);
        ole();
    }
    ll res = (ll) std::sqrt(a);
    while (res * res < a)res++;
    return res;
}
double log(double e, double x) { return log(x) / log(e); }
ll sig(ll t) { return (1 + t) * t / 2; }
ll sig(ll s, ll t) { return (s + t) * (t - s + 1) / 2; }

vi divisors(int v) {
    vi res;
    double lim = std::sqrt(v);
    for (int i = 1; i <= lim; ++i) {
        if (v % i == 0) {
            res.pb(i);
            if (i != v / i)res.pb(v / i);
        }
    }
    return res;
}

vb isPrime;
vi primes;

void setPrime() {
    int len = 4010101;
    isPrime.resize(4010101);
    fill(isPrime, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= sqrt(len) + 5; ++i) {
        if (!isPrime[i])continue;
        for (int j = 2; i * j < len; ++j) {
            isPrime[i * j] = false;
        }
    }
    rep(i, len)if (isPrime[i])primes.pb(i);
}

vi factorization(int v) {
    int tv = v;
    vi res;
    if (isPrime.size() == 0)setPrime();
    for (auto &&p :primes) {
        if (v % p == 0)res.push_back(p);
        while (v % p == 0) {
            v /= p;
        }
        if (v == 1 || p * p > tv)break;
    }
    if (v > 1)res.pb(v);
    return res;
}
inline bool inside(int h, int w, int H, int W) { return h >= 0 && w >= 0 && h < H && w < W; }
inline bool inside(int v, int l, int r) { return l <= v && v < r; }
#define ins inside
ll u(ll a) { return a < 0 ? 0 : a; }
template<class T> vector<T> u(const vector<T> &a) {
    vector<T> ret = a;
    fora(v, ret)v = u(v);
    return ret;
}
#define MIN(a) numeric_limits<a>::min()
#define MAX(a) numeric_limits<a>::max()

void yn(bool a) {
    if (a)cout << "yes" << endl;
    else cout << "no" << endl;
}
void Yn(bool a) {
    if (a)cout << "Yes" << endl;
    else cout << "No" << endl;
}
void YN(bool a) {
    if (a)cout << "YES" << endl;
    else cout << "NO" << endl;
}
void fyn(bool a) {
    if (a)cout << "yes" << endl;
    else cout << "no" << endl;
    exit(0);
}
void fYn(bool a) {
    if (a)cout << "Yes" << endl;
    else cout << "No" << endl;
    exit(0);
}
void fYN(bool a) {
    if (a)cout << "YES" << endl;
    else cout << "NO" << endl;
    exit(0);
}
void Possible(bool a) {
    if (a)cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    exit(0);
}
void POSSIBLE(bool a) {
    if (a)cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    exit(0);
}
template<class T, class U> set<T> &operator+=(set<T> &a, U v) {
    a.insert(v);
    return a;
}
template<class T, class U> vector<T> &operator+=(vector<T> &a, U v) {
    a.pb(v);
    return a;
}
template<class T> T sum(vector<T> &v, int s = 0, int t = inf) {
    T ret = 0;
    rep(i, s, min(sz(v), t))ret += v[i];
    return ret;
}
void mod(int &a, int m) { a = (a % m + m) % m; }
template<class F> inline int mgr(int ok, int ng, F f) {
#define _mgrbody int mid = (ok + ng) / 2; if (f(mid))ok = mid; else ng = mid;
    if (ok < ng)while (ng - ok > 1) { _mgrbody } else while (ok - ng > 1) { _mgrbody }
    return ok;
}

template<class F> inline int mgr(int ok, int ng, int second, F f) {
#define _mgrbody2 int mid = (ok + ng) / 2; if (f(mid, second))ok = mid; else ng = mid;
    if (ok < ng) while (ng - ok > 1) { _mgrbody2 } else while (ok - ng > 1) { _mgrbody2 }
    return ok;
}
template<typename T> ostream &operator<<(ostream &os, vector<T> &m) {
    for (auto &&v:m) os << v << " ";
    return os;
}
constexpr bool bget(ll m, int keta) { return (m >> keta) & 1; }
int bget(ll m, int keta, int sinsuu) {
    m /= (ll) pow(sinsuu, keta);
    return m % sinsuu;
}
ll bit(int n) { return (1LL << (n)); }
ll bit(int n, int sinsuu) { return (ll) pow(sinsuu, n); }
int mask(int n) { return (1ll << n) - 1; }
#define bcou __builtin_popcountll
template<class T> vector<T> ruiv(vector<T> &a) {
    vector<T> ret(a.size() + 1);
    rep(i, a.size())ret[i + 1] = ret[i] + a[i];
    return ret;
}
template<class T, class U> inline bool chma(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class U> inline bool chma(const U &b) { return chma(ma, b); }
template<class T, class U> inline bool chmi(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<class U> inline bool chmi(const U &b) { return chmi(mi, b); }
#define unique(v) v.erase( unique(v.begin(), v.end()), v.end() );
int max(vi &a) {
    int res = a[0];
    fora(v, a) {
        res = max(res, v);
    }
    return res;
}
int min(vi &a) {
    int res = a[0];
    fora(v, a) {
        res = min(res, v);
    }
    return res;
}
int n, m, k, d, H, W, x, y, z, q;
int cou;
vi a, b, c;
vvi (s, 0, 0);
vvc (ba, 0, 0);
vp p;
//@formatter:off
template<typename T> T minv(T a, T m);
template<typename T> T minv(T a);

template<typename T>
class Modular {
public:
    using Type = typename decay<decltype(T::value)>::type;    constexpr Modular() : value() {}    template<typename U>    Modular(const U &x) {        value = normalize(x);    }    template<typename U>    static Type normalize(const U &x) {        Type v;        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);        else v = static_cast<Type>(x % mod());        if (v < 0) v += mod();        return v;    }    const Type &operator()() const { return value; }    template<typename U>explicit operator U() const { return static_cast<U>(value); }    constexpr static Type mod() { return T::value; }    Modular &operator+=(const Modular &other) {        if ((value += other.value) >= mod()) value -= mod();        return *this;    }    Modular &operator-=(const Modular &other) {        if ((value -= other.value) < 0) value += mod();        return *this;    }    template<typename U> Modular &operator+=(const U &other) { return *this += Modular(other); }    template<typename U> Modular &operator-=(const U &other) { return *this -= Modular(other); }    Modular &operator++() { return *this += 1; }    Modular &operator--() { return *this -= 1; }    Modular operator++(signed) {        Modular result(*this);        *this += 1;        return result;    }    Modular operator--(signed) {        Modular result(*this);        *this -= 1;        return result;    }    Modular operator-() const { return Modular(-value); }
    template<typename U = T>typename enable_if<is_same<typename Modular<U>::Type, signed>::value, Modular>::type &operator*=(const Modular &rhs) {
#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;asm("divl %4; \n\t": "=a" (d), "=d" (m): "d" (xh), "a" (xl), "r" (mod()));value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }
    template<typename U = T>    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &operator*=(const Modular &rhs) {        int64_t q = static_cast<int64_t>(static_cast<double>(value) * rhs.value / mod());        value = normalize(value * rhs.value - q * mod());        return *this;    }    template<typename U = T>    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs) {        value = normalize(value * rhs.value);        return *this;    }    Modular &operator/=(const Modular &other) { return *this *= Modular(minv(other.value)); }    template<typename U> friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);    template<typename U> friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);    template<typename U> friend std::istream &operator>>(std::istream &stream, Modular<U> &number);    operator int() { return value; }private:    Type value;
};
template<typename T> bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }template<typename T, typename U> bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }template<typename T, typename U> bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }template<typename T> bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }template<typename T, typename U> bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }template<typename T, typename U> bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }template<typename T> bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }template<typename T> Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }template<typename T, typename U> Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }template<typename T, typename U> Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }template<typename T> Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }template<typename T, typename U> Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }template<typename T, typename U> Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }template<typename T> Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }template<typename T, typename U> Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }template<typename T, typename U> Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }template<typename T> Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }template<typename T, typename U> Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }template<typename T, typename U> Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

constexpr signed MOD =
//        998244353;
1e9 + 7;//MOD
using mint = Modular<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;
constexpr int mint_len = 1400001;
vi fac, finv, inv;
vi p2;
mint com(int n, int r) {    if (r < 0 || r > n) return 0;    return mint(finv[r] * fac[n] % MOD * finv[n - r]);}
mint pom(int n, int r) {/*    if (!sz(fac)) com(0, -1);*/    if (r < 0 || r > n) return 0;    return mint(fac[n] * finv[n - 1]);}
mint npr(int n, int r) {/*    if (!sz(fac)) com(0, -1);*/    if (r < 0 || r > n) return 0;    return mint(fac[n] * finv[n - r]);}
int nprin(int n, int r) {/*    if (!sz(fac)) com(0, -1);*/    if (r < 0 || r > n) return 0;    return fac[n] * finv[n - r] % MOD;}
int icom(int n, int r) {    const int NUM_ = 1400001;    static ll fac[NUM_ + 1], finv[NUM_ + 1], inv[NUM_ + 1];    if (fac[0] == 0) {        inv[1] = fac[0] = finv[0] = 1;        for (int i = 2; i <= NUM_; ++i) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;        for (int i = 1; i <= NUM_; ++i) fac[i] = fac[i - 1] * i % MOD, finv[i] = finv[i - 1] * inv[i] % MOD;    }    if (r < 0 || r > n) return 0;    return ((finv[r] * fac[n] % MOD) * finv[n - r]) % MOD;}
#define ncr com
#define ncri icom
//n個の場所にr個の物を置く
mint nhr(int n, int r) { return com(n + r - 1, r); }
mint hom(int n, int r) { return com(n + r - 1, r); }
int nhri(int n, int r) { return icom(n + r - 1, r); }
template<typename T> T minv(T a, T m) {    T u = 0, v = 1;    while (a != 0) {        T t = m / a;        m -= t * a;        swap(a, m);        u -= t * v;        swap(u, v);    }    assert(m == 1);    return u;}
template<typename T> T minv(T a) {    if (a < mint_len)return inv[a];    T u = 0, v = 1;    T m = MOD;    while (a != 0) {        T t = m / a;        m -= t * a;        swap(a, m);        u -= t * v;        swap(u, v);    }    assert(m == 1);    return u;}
template<typename T, typename U> Modular<T> mpow(const Modular<T> &a, const U &b) {    assert(b >= 0);    int x = a(), res = 1;    U p = b;    while (p > 0) {        if (p & 1) (res *= x) %= MOD;        (x *= x) %= MOD;        p >>= 1;    }    return res;}
template<typename T, typename U, typename V> mint mpow(const T a, const U b, const V m = MOD) {    assert(b >= 0);    int x = a, res = 1;    U p = b;    while (p > 0) {        if (p & 1) (res *= x) %= m;        (x *= x) %= m;        p >>= 1;    }    return res;}
template<typename T, typename U> mint mpow(const T a, const U b) {    assert(b >= 0);    int x = a, res = 1;    U p = b;    while (p > 0) {        if (p & 1) (res *= x) %= MOD;        (x *= x) %= MOD;        p >>= 1;    }    return res;}
template<typename T, typename U, typename V> int mpowi(const T &a, const U &b, const V &m = MOD) {    assert(b >= 0);    int x = a, res = 1;    U p = b;    while (p > 0) {        if (p & 1) (res *= x) %= m;        (x *= x) %= m;        p >>= 1;    }    return res;}
template<typename T> string to_string(const Modular<T> &number) {    return to_string(number());}
string yuri(const mint &a) {    stringstream st;    rep(i, 300) {rep(j, 300) {if ((mint) i / j == a) {st << i << " / " << j;return st.str();}}}    rep(i, 1000) {rep(j, 1000) {if ((mint) i / j == a) {st << i << " / " << j;return st.str();}}}    return st.str();}
template<typename T> std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {stream << number();
#ifdef _DEBUG
//    stream << " -> " << yuri(number);
#endif
    return stream;
}
//@formatter:off
template<typename T> std::istream &operator>>(std::istream &stream, Modular<T> &number) {    typename common_type<typename Modular<T>::Type, int64_t>::type x;    stream >> x;    number.value = Modular<T>::normalize(x);    return stream;}
using PM = pair<mint, mint>;
using vm = vector<mint>;
using mapm = map<int, mint>;
using umapm = umap<int, mint>;
#define vvm(...) o_vvt(__VA_ARGS__,vvt4,vvt3,vvt2 ,vvt1,vvt0)(mint,__VA_ARGS__)
#define vnm(name, ...) auto name = make_v<mint>(__VA_ARGS__)

struct setmod{
    setmod() {
//    p2.resize(mint_len);p2[0] = 1; for (int i = 1; i < mint_len; ++i) p2[i] = p2[i - 1] * 2 % MOD;
        fac.resize(mint_len);    finv.resize(mint_len);    inv.resize(mint_len);    inv[1] = fac[0] = finv[0] = 1;    for (int i = 2; i < mint_len; ++i) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;    for (int i = 1; i < mint_len; ++i) fac[i] = fac[i - 1] * i % MOD, finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}setmodv;
//@formatter:on
//nhr n個の場所にr個の物を分ける

signed main() {
    din(H,W);
    vm add(k5 * 3);
    add[0] = 2;
    add[1] = 4;
    rep(i, 2, k5 * 3) {
        add[i] = add[i - 1] + add[i - 2];
    }
    mint res = add[W-1];
    res += add[H-1]-2;
    cout << res << endl;

    return 0;
}