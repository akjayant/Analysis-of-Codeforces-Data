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
    int t ; scanf ( "%d" , &t );
    while ( t-- ) {
        int a , b , c , d , k ;
        scanf ( "%d %d %d %d %d" , &a , &b , &c , &d , &k ) ;
        int pen = (a+c-1)/c ;
        int pencils = (b+d-1)/d ;
        if ( pen+pencils <= k ) {
            printf ( "%d %d\n" , pen, pencils );
        }
        else printf ( "-1\n" ) ;
    }
    return 0 ;
}
