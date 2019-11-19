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

constexpr auto INF = LIM< LL >::max() / 2;

void dfs( const VVI &G, VI &path, const int u, const int prev = -1 )
{
	path.PB( u );
	int cnt = 0;
	FOR( v, G[u] )
	{
		if ( v == prev )
		{
			continue;
		}
		dfs( G, path, v, u );
		++cnt;
	}
	
	if ( 2 <= cnt )
	{
		path.clear();
	}

	return;
}

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );
	cout << setprecision( 12 ) << fixed;

	IN( int, N );
	VVI C( 3, VI( N ) );
	cin >> C;

	VVI G( N );
	REP( N - 1 )
	{
		IN( int, u, v );
		--u, --v;
		G[u].PB( v );
		G[v].PB( u );
	}

	const int r = [&]
	{
		REP( i, N )
		{
			if ( SZ( G[i] ) == 1 )
			{
				return i;
			}
		}
		assert( false );
		return -1;
	}();

	VI path;
	dfs( G, path, r );
	if ( path.empty() )
	{
		cout << -1 << endl;
		return 0;
	}
	assert( SZ( path ) == N );

	VI colors( 3 );
	iota( ALL( colors ), 0 );
	LL res = INF;
	VI painting( N );
	do
	{
		LL score = 0;
		REP( i, N )
		{
			score += C[ colors[ i % 3 ] ][ path[i] ];
		}
		if ( !chmin( res, score ) )
		{
			continue;
		}

		REP( i, N )
		{
			painting[ path[i] ] = colors[ i % 3 ] + 1;
		}
	}
	while ( next_permutation( ALL( colors ) ) );

	cout << res << endl;
	cout << painting << endl;

	return 0;
}