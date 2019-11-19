// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define Nmax 500001
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(ll i=m;i<(n);i++)
#define get(n) ll (n); scanf("%lld",&(n));
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);
#define pi 3.1415926535897


int main() {

    get(n);
    vector<ll> x(n,0), y(n,0), c(n,0), k(n,0);
    
    rep(i,n)
        scanf("%lld%lld",&x[i],&y[i]);

    fill_nums(c,n);
    fill_nums(k,n);

    vector<vector<ll>> dist(n, vector<ll>(n,1e18));

    rep(i,n) {
        rep(j,n) {
            if(i==j) continue;
            dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
        }
    }

    vector<char> vis(n,0), p(n,0);
    vector<ll> par(n,-1);
    vector<pair<ll,ll>> conn;
    ll cost = 0, st=0, counter=0;


    while(counter!=n) {
        ll m = -1;
        for(int i=0;i<n;i++) {
            if(!vis[i] && (m==-1 || c[i]<c[m]))
                m = i;
        }

        vis[m]=1;
        cost+=c[m];
        if(par[m]==-1) {
            p[m] = 1;
            st++;
        }
        else {
            conn.push_back({par[m]+1,m+1});
        }
        counter++;

        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                ll c1 = (k[i]+k[m])*dist[i][m];
                if(c1<c[i]) {
                    c[i] = c1;
                    par[i] = m;
                }
            }
        }
    }
    

    
    // std::function<void(ll)> dfs = [&](ll idx) {
    //     for(ll i=0;i<n;i++) {
    //         if(!vis[i]) {
    //             if(mindist[i]==dist[i][idx]) {
    //                 cost += min(mindist[i], c[i]);
    //                 if(c[i]==cost){
    //                     p[i]=1;
    //                     st++;
    //                 }
    //                 else {

    //                     conn.push_back({idx+1,i+1});
    //                 }
    //                 vis[i]=1;
    //                 dfs(i);
    //             }
    //         }
    //     }
    // };

    // for(int j=0;j<n;j++) {
    //     while(!vis[j]) {
    //         ll m = -1;
    //         for(int i=0;i<n;i++) {
    //             if(!vis[i] && (m==-1 || c[i]<c[m]))
    //                 m = i;
    //         }

    //         p[m] = 1; st++;
    //         vis[m] = 1;
    //         cost += c[m];

    //         dfs(m);
    //     }
    // }

    printf("%lld\n",cost);
    printf("%lld\n",st);

    rep(i,n) {
        if(p[i])
            printf("%lld ",i+1);
    }
    printf("\n");
    printf("%lld\n",(ll)conn.size());
    rep(i,conn.size()) {
        printf("%lld %lld\n",conn[i].fi,conn[i].se);
    }


    return 0;  
}
