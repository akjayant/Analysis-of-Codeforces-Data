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
int K, T, Q, cn;//}
const int inf = 1000000007, mxn = -1;

struct Int// Make sure to not do any operation with non-modded(except *, which must be int)//{
{
    int x;
    operator int() { return x; }
    Int() = default;
    Int(const int &rs) : x(rs) {};
    Int operator +(const Int &rs) const { return x+rs.x>=inf ? x+rs.x-inf : x+rs.x; }
    Int operator -(const Int &rs) const { return x-rs.x<0 ? x-rs.x+inf : x-rs.x; }
    Int operator *(const Int &rs) const { return int(x*ll(rs.x)%inf); }
    Int operator <<(const int &rs) { return rs==1 ? *this+*this : *this*Int{1<<rs}; }
    Int& operator <<=(const int &rs) { return *this = *this<<rs; }
    Int& operator >>=(const int &rs) { return x>>=rs, *this; }  // only for power()
    Int& operator +=(const Int &rs) { return *this = *this+rs; }
    Int& operator -=(const Int &rs) { return *this = *this-rs; }
    Int& operator *=(const Int &rs) { return *this = *this*rs; }
    Int& operator ++() { return *this += 1; }
    Int operator ++(int) { return Int(x++); }
    Int& operator --() { return *this -= 1; }
    Int operator --(int) { return Int(x--); }
    friend istream& operator >>(istream &is, Int &rs) { return is>>rs.x; }
    friend ostream& operator <<(ostream &os, const Int &rs) { return os<<rs.x; }
};

Int operator""_i(unsigned long long x) { return Int{int(x)}; }//}

#include <ext/numeric>
using namespace __gnu_cxx;

signed main() { ios::sync_with_stdio(0); cin.tie(NULL); cout.precision(11);
    Int n, m;
    cin >> n >> m;
    Int x = power(2_i, m);
    x--;
    cout << power(x, n) << '\n';
}