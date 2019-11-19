#include<bits/stdc++.h>
using namespace std ;

const long long maxn = 1e5 ;
vector<long long> adj[maxn] ;
long long c[3][maxn] ;
long long cost[6] ;
bool mark[maxn] ;
long long ans[maxn] ;

long long M[6][3] ;
void d(){
M[0][0] = 1 ;
M[0][1] = 2 ;
M[0][2] = 3 ;
M[1][0] = 1 ;
M[1][1] = 3 ;
M[1][2] = 2 ;
M[2][0] = 2 ;
M[2][1] = 1 ;
M[2][2] = 3 ;
M[3][0] = 2 ;
M[3][1] = 3 ;
M[3][2] = 1 ;
M[4][0] = 3 ;
M[4][1] = 1 ;
M[4][2] = 2 ;
M[5][0] = 3 ;
M[5][1] = 2 ;
M[5][2] = 1 ;
}

void dfs(long long u, long long d = 0){

    mark[u] = 1 ;

    for(auto v:adj[u])
        if(!mark[v])
            dfs(v, (d+1)%3) ;

    for(long long i = 0; i < 6; i++){

        cost[i] += c[(M[i][d]-1)][u] ;

    }

}

void andfs(long long u, long long mod, long long d = 0){

    mark[u] = 0 ;
    for(auto v:adj[u])
        if(mark[v])
            andfs(v, mod, (d+1)%3) ;

    ans[u] = M[mod][d] ;

}

int main(){

    ios::sync_with_stdio(false) ;
    cin.tie(0) ;

    d() ;
    long long n ;
    cin >> n ;

    for(long long i = 0; i < 3; i++){

        for(long long j = 0; j < n; j++){

            cin >> c[i][j] ;

        }

    }

    for(long long i = 0; i < n-1; i++){

        long long u, v ;
        cin >> u >> v ;
        u-- ;
        v-- ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
        if(adj[u].size() > 2 || adj[v].size() > 2){

            cout << -1 ;
            return 0 ;

        }

    }

    long long st ;
    for(long long i = 0; i < n; i++){

        if(adj[i].size() == 1){

            st = i ;
            dfs(i) ;
            break ;

        }

    }
    long long j = cost[0] ;
    long long ji = 0 ;
    for(long long i = 0; i < 6; i++){

        if(cost[i] < j){

            j = cost[i] ;
            ji = i ;

        }

    }
    cout << j << '\n' ;
    andfs(st,ji) ;
    for(long long i = 0; i < n; i++){

        cout << ans[i] << ' ' ;

    }

}
