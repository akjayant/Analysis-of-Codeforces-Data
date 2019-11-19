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
        int n ; scanf ( "%d" , &n ) ;
        string s ; cin >> s ;
        int f = n+1 , l = -1 ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( s[i] == '0' ) continue ;
            f = min ( f , i ) ;
            l = max ( l , i ) ;
        }
        if ( l == -1 ) {
            printf ( "%d\n", n ) ;
        }
        else {
            f++ ; l++ ;
            int ans = n+1 ;
            ans = max ( ans , 2*l ) ;
            ans = max ( ans , 2*(n-f+1) ) ;
            printf ( "%d\n" , ans ) ;
        }
    }
    return 0 ;
}
