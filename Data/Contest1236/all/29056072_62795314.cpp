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
int n, m, K, T, Q, cn;//}
const int inf = 1000000007, mxn = 305;

int a[mxn][mxn];

signed main() { ios::sync_with_stdio(0); cin.tie(NULL); cout.precision(11);
/*
1 6 7
2 5 8
3 4 9

1 8 9  16
2 7 10 15
3 6 11 14
4 5 12 13
*/
    cin >> n;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (i&1) {
            for (int j = n-1; j >= 0; j--) {
                a[j][i] = cur++;
            }
        } else {
            for (int j = 0; j < n; j++) {
                a[j][i] = cur++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j==n-1];
        }
    }
}