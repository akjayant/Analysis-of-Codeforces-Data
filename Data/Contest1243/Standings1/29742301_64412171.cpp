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
    get(m);

    set<pll> adj;
    for(ll i=0;i<m;i++) {
        ll a, b; 
        scanf("%lld %lld",&a,&b); 
        --a; --b;
        adj.insert({a,b});
        adj.insert({b,a});
    }

    // for(auto i:adj)
    //     cout<<i.fi<<" - "<<i.se<<endl;
    set<ll> se;
    rep(i,n)
        se.insert(i);

    ll c = 0;
    rep(i,n) {
        if(se.count(i)) { 
            // cout<<i<<endl;
            queue<ll> q;
            q.push(i);
            se.erase(i);

            while(!q.empty()) {
                ll t = q.front();
                q.pop();

                set<ll> se2;
                for(auto j:se) {
                    if(!adj.count({t,j})) {
                        se2.insert(j);
                    }
                }

                for(auto j:se2) {
                    // cout<<j<<endl;
                    se.erase(j);
                    q.push(j);
                }
            }

            c++;
        }
    }

    printf("%lld\n",c-1);
    return 0;  
}