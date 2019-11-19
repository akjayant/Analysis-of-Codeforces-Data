#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000007
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define vi vector < int >
#define pii pair < int , int >
#define vii vector < pair < int , int > >
#define MAXN 100005
#define SQRTN 355
#define MAXXN 1000005

using namespace std ;
int main () {
    long long n , p , w , d ;

    scanf ( "%lld %lld %lld %lld" , &n , &p , &w , &d ) ;
    long long xmodd = -1 ;
    for ( int i = 0 ; i < d ; i++ ) {
        long long temp = ((w%d)*i)%d ;
        if ( temp == (p%d) ) {
            xmodd = i ; break ; }
    }
    if ( xmodd == -1 ) printf ( "-1\n" ) ;
    else {
        long long xr = (p/w) ;
        xr = min ( xr , n ) ;
        long long temp = (xr-xmodd)/d ;
        long long x = xmodd + temp*d  ;
        long long y = (p-x*w)/d ;
        if ( x >= 0 && y >= 0 && x+y <= n ) {
            printf ( "%lld %lld %lld\n" , x , y , (n-x-y) ) ;
        }
        else {
            printf ( "-1\n" ) ;
        }
    }
    return 0 ;
}
