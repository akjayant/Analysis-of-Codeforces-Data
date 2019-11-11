#include <bits/stdc++.h>

using namespace std;

#define forn(a, e) for (int a = 0; a < (int)(e); a++)
#define forr(a, s, e) for (int a = s; a < (int)(e); a++)
#define fore(e, a) for (auto& e : a)

#ifdef LOCAL
#define logv(a) {cerr << #a << " = "; fore(e, a) {cerr << e << " ";} cerr << "\n";}
#define logvp(a) {cerr << #a << " = "; fore(e, a) {cerr << "(" << e.first << ", " << e.second << ") ";} cerr << "\n";}
#define logvv(a) {cerr << #a << " = \n"; fore(r, a) { fore(e, r) {cerr << e << " ";} cerr << "\n";} }
#define logvf(a, field) {cerr << #a"."#field << " = \n"; fore(e, a) { cerr << e.field << " ";} cerr << "\n"; }
#define logs(a) cerr << #a << " = " << (a) << "\n";
#define logss(a, b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << "\n";
#define logp(a) cerr << #a << " = " << "(" << a.first << ", " << a.second << ")" << "\n";
#define cond(pred, stmt) if (pred) { stmt }
#else
#define logv(a)
#define logvp(a)
#define logvv(a)
#define logvf(a, field)
#define logs(a)
#define logss(a, b)
#define logp(a)
#define cond(pred, stmt)
#endif

using i64 = long long;
using iip = pair<i64, i64>;
using ivec = vector<int>;
using llvec = vector<i64>;
using svec = vector<string>;

template<typename T, typename Dim>
auto make_vec(T value, Dim dim) { return vector<T>(dim, value); }
template<typename T, typename Dim1, typename... Dim>
auto make_vec(T value, Dim1 dim1, Dim... dims) { return make_vec(make_vec(value, dims...), dim1); }

template<typename T>
bool uax(T& v, const T& newv) { if (v < newv) { v = newv; return true; } else return false; }
template<typename T>
bool uin(T& v, const T& newv) { if (v > newv) { v = newv; return true; } else return false; }

template<typename T>
istream& operator>>(istream& is, vector<T>& c) { for (auto& e : c) is >> e; return is; }

template<typename ...T>
istream& read(T&... args) { return (cin >> ... >> args); }

static mt19937 rande(123123);
template<typename T>
T rand_int(T from, T to) { uniform_int_distribution<T> distr(from, to); return distr(rande); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        read(a, b);
        if (gcd(a, b) == 1) {
            cout << "Finite" << endl;
        } else {
            cout << "Infinite" << endl;
        }
    }
}
 