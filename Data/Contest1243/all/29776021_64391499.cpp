
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <cmath>
#include <random>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
 
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <array>
#include <iterator>
#include <bitset>
#include <initializer_list>
 
//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
 
//template<class T, class C = null_type> using Tree = tree<T, C, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
namespace io{
 
    template<typename A, typename B> ostream& operator << ( ostream &os, pair<A, B> &p ) { return os << p.first << " " << p.second; }
    template<typename A> ostream& operator << ( ostream &os, vector<A> &v ) { for( A p : v ) cout << p << " "; return os; }
    template<typename A, typename B> ostream& operator << ( ostream &os, vector<pair<A, B>> &v ) { for( auto p : v ) cout << p << endl; return os; }
    template<typename A, typename B> ostream& operator << ( ostream &os, map<A, B> &mp ) { for( auto it : mp ) os << it.first << " " << it.second << endl; return os; }
    template<typename A> ostream& operator << ( ostream &os, set<A> &st ) { for( A p : st ) cout << p << " "; return os; }
 
    template<typename A, typename B> istream& operator >> ( istream &is, pair<A, B> &p ) { return is >> p.first >> p.second; }
    template<typename A> istream& operator >> ( istream &is, vector<A> &v ) { for( A &p : v ) is >> p; return is; }
    template<typename A, typename B> istream& operator >> ( istream &is, vector<pair<A, B>> &v ) { for( auto &p : v ) is >> p.first >> p.second; return is; }
 
    template<typename A, typename B> inline void output( pair<A, B> &p ) { cout << "{" << p.first << ", " << p.second << "}" << endl; }
    template<typename A, typename B> inline void output( map<A, B> &mp ){ cout << endl; for( auto it: mp ) cout << "{" << it.first << ", " << it.second << "}" << endl; }
    template<typename A> inline void output( vector<A> &v ){ cout << "{"; for( int i = 0; i < v.size(); i++ ){ cout << v[i]; if( i < v.size() - 1 ) cout << ", "; } cout << "}"; cout << endl; }
    template<typename A, typename B> inline void output( vector<pair<A, B>> &v ) { cout << endl; for( auto p : v ) cout << "{" << p.first << ", " << p.second << "}" << endl; }
    template<typename A> inline void output( set<A> &st ){ cout << "{"; for( A p : st ){ cout << p; if( p != *st.rbegin() ) cout << ", "; } cout << "}"; cout << endl; }
 
    long long read(){ char c; long long d = 1, x = 0; do c = getchar(); while( c == ' ' || c == '\n' ); if( c == '-' ) c = getchar(), d = -1; while( isdigit( c ) ){ x = x * 10 + c - '0'; c = getchar(); } return d * x;}
 
}

using namespace io;

const int MOD = ( int ) 1e9 + 7; // 998244353
const double EPS = 1e-9;
const double PI = acos ( -1. );
long long llinf = __INT64_MAX__;
int inf = INT_MAX;


#define int long long
#define add push_back
#define F first
#define S second
 

#define ALL( x ) x.begin(), x.end()
#define RALL( x ) x.rbegin(), x.rend()
#define SORT( x ) sort( ALL( x ) )
#define REV( x ) reverse( ALL( x ) )
#define print( x ) cout << #x << " = " << x << endl;
#define write( x ) cout << #x << ": "; output( x ); 


#define forn( i, a, b ) for( int i = a; i <= b; i++ )
#define forv( i, a, b ) for( int i = a; i >= b; i-- )
#define sqr( x ) ( x ) * ( x )
#define gcd( a, b ) __gcd( a, b )
#define lcm( a, b ) ( ( a ) * ( ( b ) / gcd( a, b ) ) )
inline int gcd( int a, int b ) { while( b ) { a %= b; swap( a, b ); } return a; }
 

template<typename T1, typename T2> auto max ( T1 a, T2 b ) { auto max = a > b ? a : b; return max; }
template<typename T1, typename T2> auto min ( T1 a, T2 b ) { auto min = a < b ? a : b; return min; }
 
template<typename T1, typename T2> void updmax ( T1 &a, T2 b ) { a = a > b ? a : b; }
template<typename T1, typename T2> void updmin ( T1 &a, T2 b ) { a = a < b ? a : b; }
 

const int MAXN = ( int ) 1e6 + 10;
const int N = 1001;

static int a[MAXN], b[MAXN];
static int c[N][N];
 
int n, m, k;
string s, t;
 
int p[MAXN];

int find_set( int n )
{
    return p[n] == n ? n : p[n] = find_set( p[n] );
}

void union_set( int a, int b ){
    a = find_set( a );
    b = find_set( b );
    if( a != b ){
        p[a] = b;
    }
}


namespace number {
 
    int mod = ( int ) 1e9 + 7;
 
    inline int norm( int a ) { while( a < 0 ) a += mod; while( a >= mod ) a -= mod; return a; }
    inline int add( int a, int b ) { return norm( a + b ); }
    inline int sub( int a, int b ) { return norm( a - b ); }
    inline int mul( int a, int b, int m = mod ) { return ( 1ll * a * b ) % m; }
 
    int mul_mod( int a, int n, int m = mod ) { int s = 0; while( n ) { if( n & 1 ) s = ( s + a ) % m; a = ( a + a ) % m; n >>= 1; } return s; }
    int pow_mod( int a, int n, int m = mod ) { int p = 1; while( n ) { if( n & 1 ) p = mul( p, a, m ); a = mul( a, a, m ); n >>= 1; } return p; }
    int _pow_mod( int a, int n, int m = mod ) { int p = 1; while( n ) { if( n & 1 ) p = mul_mod( p, a, m ); a = mul_mod( a, a, m ); n >>= 1; } return p; }
 
    inline int inv( int a ) { return pow_mod( a, mod - 2 ); }
    inline int div_mod( int a, int b ) { return mul( a, inv( b ) ); }
    
    inline int gcd( int a, int b )
    {
        while( b ){
            a %= b;
            swap( a, b );
        }
        return a;
    }

    bool miller_rabin( long long m ) {
        random_device rd; mt19937 mt( rd( ) );
        uniform_int_distribution<int> dist( 0, llinf );
        int s = 0, d = m - 1;
        while( d % 2 == 0 ) s++, d /= 2;
        int a = 1 + dist( mt ) % ( m - 1 );
        int x = _pow_mod( a, d, m );
        if( x == 1 ) return true;
        for( int r = 0; r < s; r++ ) { if( x == m - 1 ) return true; x = mul_mod( x, x, m ); }
        return false;
    }
 
    bool is_prime( long long n ) {
        if( n < 2 ) return 1; 
        for( int i = 2; i * i <= n; i++ ) 
            if( n % i == 0 || n % ( i + 2 ) == 0 )
                return 0; 
        return 1;
    }
    
    long long pollard_rho( long long n, int it = 50000 ) {
        random_device rd; mt19937 mt( rd( ) );
        uniform_int_distribution<int> dist( 0, llinf );
        long long b0 = dist( mt ) % n, b1 = b0, g;
        b1 = mul_mod( b1, b1, n );
        if( ++b1 == n ) b1 = 0;
        g = gcd( abs( b1 - b0 ), n );
        for( int count = 0; count < it && ( g == 1 || g == n ); count++ ) {
            b0 = mul_mod( b0, b0, n );
            if( ++b0 == n ) b0 = 0;
            b1 = mul_mod( b1, b1, n ); ++b1;
            b1 = mul_mod( b1, b1, n );
            if( ++b1 == n ) b1 = 0;
            g = gcd( abs( b1 - b0 ), n );
        }
        return g;
    }
 
    int gcdex( int a, int b, int & x, int & y ) {
        if( a == 0 ) { x = 0; y = 1; return b; }
        int x1, y1, d = gcdex( b % a, a, x1, y1 );
        x = y1 - ( b / a ) * x1; y = x1;
        return d;
    }
}

void solution()
{
    cin >> n;
    if( number::is_prime( n ) ){
        cout << n << endl;
        return;
    }
    set<int> st;
    for( int i = 2; i * i <= n; i++ ){
        if( n % i == 0 ){
            st.insert( i );
           while( n % i == 0 ){
               n /= i;
           } 
        }
    }
    if( n > 1 ){
        st.insert( n );
    }
    if( st.size() > 1 ){
        cout << 1 << endl;
    } else {
        cout << *st.begin() << endl;
    }

    
    

}
 
 
int32_t main ( )
{
 
    int T1 = clock();
 
    //freopen("FILE_NAME.in", "r", stdin);
    //freopen("FILE_NAME.out", "w", stdout);
 
    ios_base::sync_with_stdio ( false ); cin.tie ( nullptr ); cout.tie ( nullptr );
    //cout.precision(15);
 
    int query = 1;
    // cin >> query;
 
    while ( query-- ) solution();

    int T2 = clock();

    cerr << "Time: " << ( T2 - T1 ) / 1000. << " s." << endl;
 
    return 0;
 
}