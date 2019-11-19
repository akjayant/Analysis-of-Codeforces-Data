#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#define MEM(x,y) memset ( x , y , sizeof ( x ) )
#define rep(i,a,b) for (int i = (a) ; i <= (b) ; ++ i)
#define per(i,a,b) for (int i = (a) ; i >= (b) ; -- i)
#define pii pair < int , int >
#define one first
#define two second
#define rint read<int>
#define int long long
#define pb push_back
#define db double
#define ull unsigned long long
#define lowbit(x) ( x & ( - x ) )

using std::queue ;
using std::set ;
using std::pair ;
using std::max ;
using std::min ;
using std::priority_queue ;
using std::vector ;
using std::swap ;
using std::sort ;
using std::unique ;
using std::greater ;

template < class T >
    inline T read () {
        T x = 0 , f = 1 ; char ch = getchar () ;
        while ( ch < '0' || ch > '9' ) {
            if ( ch == '-' ) f = - 1 ;
            ch = getchar () ;
        }
       while ( ch >= '0' && ch <= '9' ) {
            x = ( x << 3 ) + ( x << 1 ) + ( ch - 48 ) ;
            ch = getchar () ;
       }
       return f * x ;
}

const int N = 1e5 + 100 ;
const int inf = 1e18 ;
vector < int > G[N] ;
int n , c[3][N] , ans = inf ;
int f[N] , deep[N] ;
int p[] = { 0 , 1 , 2 } ;
int col[N] , tmp[N] ;

inline void dfs (int cur , int anc , int dep) {
    f[cur] = anc ; deep[cur] = dep ;
    for (int k : G[cur] ) {
        if ( k == anc ) continue ;
        dfs ( k , cur , dep + 1 ) ;
    }
    return ;
}

inline void work (int x , int y) {
    int ptr = 0 , res = 0 ;
    for (int i = x ; i ; i = f[i] ) {
        tmp[i] = p[ptr] ; res += c[p[ptr]][i] ;
        ptr = ( ptr + 1 ) % 3 ;
    }
    if ( res < ans ) swap ( col , tmp ) , ans = res ;
    return ;
}

signed main (int argc , char * argv[]) {
    n = rint () ;
    rep ( i , 1 , n ) c[0][i] = rint () ;
    rep ( i , 1 , n ) c[1][i] = rint () ;
    rep ( i , 1 , n ) c[2][i] = rint () ;
    rep ( i , 2 , n )  {
        int u = rint () , v = rint () ;
        G[u].pb ( v ) ; G[v].pb ( u ) ;
    }

    rep ( i , 1 , n ) if ( G[i].size () > 2 ) return puts ("-1") , 0 ;

    dfs ( 1 , 0 , 1 ) ; int maxn = - 1 , rt = 1 ;
    rep ( i , 1 , n ) if ( maxn < deep[i] ) maxn = deep[i] , rt = i ;
    dfs ( rt , 0 , 1 ) ; int maxt = - 1 , beg = 1 ;
    rep ( i , 1 , n ) if ( maxt < deep[i] ) maxt = deep[i] , beg = i ;

    do { work ( beg , rt ) ; } while ( std::next_permutation ( p , p + 3 ) ) ;
    printf ("%lld\n" , ans ) ; rep ( i , 1 , n ) printf ("%lld " , col[i] + 1 ) ;
    return 0 ;
}