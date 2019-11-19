#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

using namespace std;

template <class T, class M>
using trtr = __gnu_pbds::tree <T, M, less <T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define sp ' '
#define en '\n'
#define En '\n'
#define eN '\n'
#define EN '\n'

#define _str(x) #x
#define ww(x) _str(x) << " = " << x << sp
#define wn(x) _2d << _str(x) << " = " << en << x << en

struct _flag_t { string val; } _1d{", "}, _2d{"\n  "};
_flag_t _flag = _1d;

ostream &operator<<(ostream &os, _flag_t flag) { _flag = flag; return os; }

template < class Ch, class Tr, class It >
basic_ostream < Ch, Tr > &
_out(basic_ostream < Ch, Tr > &os, It f, It l) {
    if (f == l) return os << "{}";
    auto cur_flag = _flag;
    os << _1d << "{ " << *f;
    for (; ++f != l; os << cur_flag.val << *f);
    return os << " }";
}

template < class Ch, class Tr, class C >
basic_ostream < Ch, Tr > &operator<<(basic_ostream < Ch, Tr > &os, C const &cont)
{ return _out(os, begin(cont), end(cont)); }

template <class X, class Y>
ostream &operator<<(ostream &os, pair < X, Y > const &p) { return os << "[" << p.first << ", " << p.second << "]"; }
template <class X, class Y, class Z>
ostream &operator<<(ostream &os, tuple < X, Y, Z > const &p)
{ return os << "[" << get < 0 >(p) << ", " << get < 1 >(p) << ", " << get < 2 >(p) << "]"; }

template <class X> X &maxi(X &x, X const &y) { return x < y ? x = y : x; }
template <class X> X &mini(X &x, X const &y) { return x > y ? x = y : x; }
template <class X> bool bmaxi(X &x, X const &y) { return x < y ? (x = y, true) : false; }
template <class X> bool bmini(X &x, X const &y) { return x > y ? (x = y, true) : false; }

#define int ll
#define qq auto
#define qr auto &
#define qrr auto &&
#define qc auto const&
#define sz(x) int( x.size() )
#define mp(x, y) make_pair( x, y )
#define ff first
#define ss second

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pdd = pair < double, double >;
using bit32 = bitset <32>;
using bit64 = bitset <64>;

template <class K, class T, class ...A>
using hash_table = __gnu_pbds::cc_hash_table <K, T, A...>;
//using hash_table = unordered_map<K, T>;
//using hash_table = map<K, T>;

const double PI = acos(-1);
const double PIH = PI * 0.5;
const double PID = PI * 2.0;

template <class T = ll>
vector <vector <T>> make_mat(size_t n, size_t m = 0, T val = T())
{ return vector <vector <T>>(n, vector <T>(m, val)); }

#define forr(i, n) for(int i = 0; i < (n); i ++)
#define forn(i, b, n) for(int i = b; i < (n); i ++)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define def(f, ...) qq f = [&] (qc f, __VA_ARGS__)
#define call(f, ...) f(f, __VA_ARGS__)

int32_t main()
{
    ios_base::sync_with_stdio(false);

    int n; cin >> n;


    auto slv = [&](qc s) {

        vector <int> st;
        forr(i, n) {
            int x = s[i] == '(' ? +1 : -1;
            if( st.size() == 0 ) {
                st.push_back( x );
            }
            else if( st.back() == -x && x == -1 ) st.pop_back();
            else st.push_back(x);
        }

        int l = count( all(st), -1 );
        int r = count( all(st), +1 );

        int ans{};
        int L = l, R = r;
        forr(i, n) {
            if( L == 0 && R == 0 ) ans ++;
            int x = s[i] == '(' ? +1 : -1;
            if( x == 1 ) {
                L ++;
                R ++;
            }
            else {
                L --;
                R --;
            }
        }
        return ans;
    };

    string s; cin >> s;

    int ans{};
    int x = 1, y = 1;
    forr(i, n) {
        forn(j, i, n) {
            swap( s[i], s[j] );
            if( bmaxi( ans, slv(s) ) ) {
                x = i+1;
                y = j+1;
            }
            swap( s[i], s[j] );
        }
    }

    cout << ans << en << x << sp << y;
}
/*
10
()()())(()
10
()()()()()


*/
