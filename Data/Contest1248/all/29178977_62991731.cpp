#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <type_traits>
#include <cmath>
#include <cassert>
#include <cstdio>

using namespace std;
using namespace placeholders;

using LL = long long;
using ULL = unsigned long long;
using VI = vector< int >;
using VVI = vector< vector< int > >;
using VS = vector< string >;
using ISS = istringstream;
using OSS = ostringstream;
using PII = pair< int, int >;
using VPII = vector< pair< int, int > >;
template < typename T = int > using VT = vector< T >;
template < typename T = int > using VVT = vector< vector< T > >;
template < typename T = int > using LIM = numeric_limits< T >;

template < typename T > inline istream& operator>>( istream &s, vector< T > &v ){ for ( T &t : v ) { s >> t; } return s; }
template < typename T > inline ostream& operator<<( ostream &s, const vector< T > &v ){ for ( int i = 0; i < int( v.size() ); ++i ){ s << ( " " + !i ) << v[i]; } return s; }

void in_impl(){};
template < typename T, typename... TS > void in_impl( T &head, TS &... tail ){ cin >> head; in_impl( tail ... ); }
#define IN( T, ... ) T __VA_ARGS__; in_impl( __VA_ARGS__ );

template < typename T > inline T fromString( const string &s ) { T res; istringstream iss( s ); iss >> res; return res; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); }

#define NUMBERED( name, number ) NUMBERED2( name, number )
#define NUMBERED2( name, number ) name ## _ ## number
#define REP1( n ) REP2( NUMBERED( REP_COUNTER, __LINE__ ), n )
#define REP2( i, n ) REP3( i, 0, n )
#define REP3( i, m, n ) for ( int i = ( int )( m ); i < ( int )( n ); ++i )
#define GET_REP( a, b, c, F, ... ) F
#define REP( ... ) GET_REP( __VA_ARGS__, REP3, REP2, REP1 )( __VA_ARGS__ )
#define FOR( e, c ) for ( auto &&e : c )
#define ALL( c ) begin( c ), end( c )
#define AALL( a ) ( remove_all_extents< decltype( a ) >::type * )a, ( remove_all_extents< decltype( a ) >::type * )a + sizeof( a ) / sizeof( remove_all_extents< decltype( a ) >::type )

#define SZ( v ) ( (int)( v ).size() )
#define EXISTS( c, e ) ( ( c ).find( e ) != ( c ).end() )

template < typename T > inline bool chmin( T &a, const T &b ){ if ( b < a ) { a = b; return true; } return false; }
template < typename T > inline bool chmax( T &a, const T &b ){ if ( a < b ) { a = b; return true; } return false; }

#define PB push_back
#define EM emplace
#define EB emplace_back
#define BI back_inserter

#define MP make_pair
#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

constexpr int MOD = 1'000'000'007;

// a^x を mod で求める
// 反復二乗法
// O( log x )
long long mod_pow( long long a, long long x, long long mod )
{
	a %= mod;

	long long res = 1;
	for ( ; x; x >>= 1, ( a *= a ) %= mod )
	{
		if ( x & 1 )
		{
			( res *= a ) %= mod;
		}
	}
	return res;
}

// p が素数のとき、p を法とする剰余体での逆元を求める
// Fermat の小定理を利用
// a^{ p - 1 } \equiv 1 ( mod p )
// a^{ p - 2 } \equiv a^{-1} ( mod p )
// incluide : mod_pow
int mod_inverse( long long a, long long p )
{
	return mod_pow( a, p - 2, p );
}

// 素数を法とする剰余体での n! を求める
class modFact
{
private:
	const int MAX_N, MOD;
	vector<int> fact;

public:
	modFact( const int n, const int mod ) : MAX_N( n ), MOD( mod ), fact( min( MAX_N + 1, MOD ) )
	{
		fact[0] = 1;
		for ( int i = 1; i < (int)fact.size(); ++i )
		{
			fact[i] = 1LL * fact[ i - 1 ] * i % MOD;
		}
		return;
	}

	int operator()( const int n )
	{
		int e;
		return operator()( n, e );
	}

	int operator()( const int n, int &e )
	{
		e = 0;
		if ( n == 0 )
		{
			return 1;
		}

		const long long res = operator()( n / MOD, e );
		e += n / MOD;

		if ( n / MOD % 2 != 0 )
		{
			return res * ( MOD - fact[ n % MOD ] ) % MOD;
		}
		return res * fact[ n % MOD ] % MOD;
	}
};
// modfact( max_n, mod )
// ()( n )
// ()( n, e )

// nCr
// include : modFact, mod_inverse
class modComb
{
private:
	const int MOD;
	modFact mod_fact;

public:
	modComb( const int n, const int mod ) : MOD( mod ), mod_fact( n, mod ) {};

	int operator()( const int n, const int r )
	{
		if ( n < 0 || r < 0 || n < r )
		{
			return 0;
		}

		int e1, e2, e3;
		long long a1 = mod_fact( n, e1 ), a2 = mod_fact( r, e2 ), a3 = mod_fact( n - r, e3 );
		if ( e1 > e2 + e3 )
		{
			return 0;
		}
		return a1 * mod_inverse( a2 * a3 % MOD, MOD ) % MOD;
	}
};
// modComb( n, mod )
// ()( n, r )

modComb nCr( 100'001, MOD );

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );
	cout << setprecision( 12 ) << fixed;

	IN( int, H, W );

	LL res = 1;
	REP( i, ( H + 1 ) / 2, H )
	{
		( res += nCr( i, H - i ) ) %= MOD;
// 		DUMP( i );
// 		DUMP( H - i );
// 		DUMP( res ) << endl;
	}
	REP( j, ( W + 1 ) / 2, W )
	{
		( res += nCr( j, W - j ) ) %= MOD;
// 		DUMP( j );
// 		DUMP( W - j );
// 		DUMP( res ) << endl;
	}
	( res *= 2 ) %= MOD;

	cout << res << endl;

	return 0;
}