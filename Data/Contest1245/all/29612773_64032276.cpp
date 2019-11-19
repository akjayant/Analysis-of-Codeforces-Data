#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MAX_INF 0x7f
#define MAX_INF_VAL 0x7f7f7f7f
#define pi 3.141592653589
#define eps 1e-10
//#define p 2173412051LL
#define sz 2
 
using namespace std;

struct p {
	int u, v;
	ll dis;
};
p a[ 4000010 ];
bool cmp( const p &a, const p &b ) {
	return a.dis < b.dis;
};

int n, m;
int f[ 2010 ];
bool vis[ 2010 ];
ll x[ 2010 ], y[ 2010 ];
ll cost[ 2010 ], k[ 2010 ];
vector< p > eg;
vector< p > ans_eg;

int find( int );
void merge( int, int );
void kruskal();

int main() {
	int xx, yy;
	int deal, fk = 0;
	ll ans = 0, tmp;
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ) {
		scanf( "%lld%lld", &x[ i ], &y[ i ] );
		f[ i ] = i;
	}
	for( int i = 1; i <= n; ++i ) {
		scanf( "%lld", &cost[ i ] );
		ans += cost[ i ];
		vis[ i ] = true;
		++fk;
	}
	for( int i = 1; i <= n; ++i )
		scanf( "%lld", &k[ i ] );
	for( int i = 1; i <= n; ++i )
		for( int j = i + 1; j <= n; ++j ) {
			a[ m ].u = i;
			a[ m ].v = j;
			a[ m++ ].dis = ( abs( x[ i ] - x[ j ] ) + abs( y[ i ] - y[ j ] ) ) * ( k[ i ] + k[ j ] );
		}
	sort( a, a + m, cmp );
	kruskal();
	for( int i = 1; i <= n; ++i )
		f[ i ] = i;
	for( int i = 0; i < eg.size(); ++i ) {
		xx = find( eg[ i ].u );
		yy = find( eg[ i ].v );
		if( cost[ xx ] > cost[ yy ] )
			deal = xx;
		else
			deal = yy;
		tmp = eg[ i ].dis - cost[ deal ];
		if( tmp >= 0 )
			continue;
		ans += tmp;
		vis[ deal ] = false;
		ans_eg.push_back( eg[ i ] );
		--fk;
		if( xx == deal )
			merge( xx, yy );
		else
			merge( yy, xx );
	}			
	printf( "%lld\n", ans );
	printf( "%d\n", fk );
	for( int i = 1; i <= n; ++i )
		if( vis[ i ] )
			printf( "%d ", i );
	if( fk )
		printf( "\n" );
	printf( "%d\n", ans_eg.size() );
	for( int i = 0; i < ans_eg.size(); ++i )
		printf( "%d %d\n", ans_eg[ i ].u, ans_eg[ i ].v );
	return 0;
}

int find( int x ) {
	if( f[ x ] == x )
		return x;
	return f[ x ] = find( f[ x ] );
}

void merge( int x, int y ) {
	x = find( x );
	y = find( y );
	f[ x ] = y;
}

void kruskal() {
	int t = 0;
	for( int i = 0; i < m; ++i ) {
		if( find( a[ i ].u ) != find( a[ i ].v ) ) {
			merge( a[ i ].u, a[ i ].v );
			eg.push_back( a[ i ] );
		}
	}
}