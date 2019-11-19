#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000007
#define LINF 100000000000000007
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

using namespace std  ;

vi edge[100002] , tree;
int answer[100002] ;
long long c1[100002] , c2[100002] , c3[100002] ;
void dfs ( int src , int par ) {
    tree.pb ( src ) ;
    for ( int i = 0 ; i < edge[src].size() ; i++ ) {
        if ( edge[src][i] != par ) {
            dfs ( edge[src][i] , src ) ;
        }
    }
}
int main () {
    int n ; scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &c1[i] ) ;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &c2[i] ) ;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &c3[i] ) ;
    }
    for ( int u,v,i = 1 ; i < n ; i++ ) {
        scanf ( "%d %d" , &u , &v ) ;
        edge[u].pb ( v ) ;
        edge[v].pb ( u ) ;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( (int)edge[i].size() >= 3 ) {
            printf ( "-1\n" ) ;
            return 0 ;
        }
    }
    int leaf = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( edge[i].size() == 1 ) leaf = i ;
    }
    dfs ( leaf , 0 );
    assert ( tree.size() == n ) ;
    vi perm ; int color_ans[3] ;
    perm.pb ( 1 ) ;
    perm.pb ( 2 ) ;
    perm.pb ( 3 ) ;
    long long fin = LINF ;
    do {
        long long ans = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            int node = tree[i-1] ;
            int color = perm[(i-1)%3] ;
            if ( color == 1 ) {
                ans += c1[node] ;
            }
            else if ( color == 2 ) {
                ans += c2[node] ;
            }
            else ans += c3[node] ;
        }
        if ( ans < fin ) {
            fin = ans ;
            color_ans[0] = perm[0] ;
            color_ans[1] = perm[1] ;
            color_ans[2] = perm[2] ;
        }
    } while ( next_permutation(perm.begin(),perm.end()) ) ;

    printf ( "%lld\n" , fin ) ;
    assert ( fin < LINF ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        answer[tree[i-1]] = color_ans[(i-1)%3] ;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d " , answer[i] ) ;
    }
    printf ( "\n" ) ;
    return 0 ;
}
