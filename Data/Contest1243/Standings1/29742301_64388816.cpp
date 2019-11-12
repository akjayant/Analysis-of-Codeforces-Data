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
 
    get(k);
    while(k--) {
        get(n);
        string a,b;
        cin >> a >> b;

        unordered_map<char,ll> vals;
        rep(i,n)
            vals[a[i]]++;
        rep(i,n)
            vals[b[i]]++;

        bool flag=0;
        for(auto i:vals)
            if(i.second%2) {
                flag=1;
                break;
            }
        if(flag==1) {
            printf("No\n");
            continue;
        }
        
        printf("Yes\n");
        
        vector<pll> res;
        rep(i,n) {
            if(a[i]==b[i])
                continue;

            flag = 0;
            for(ll j=i+1;j<n;j++)
                if(a[j]==a[i]) {
                    swap(a[j],b[i]);
                    res.push_back({j+1,i+1});
                    // printf("%lld %lld\n",j+1,i+1);
                    flag=1;
                    break;
                }
            if(!flag) {
                for(ll j=i+1;j<n;j++) {
                    if(b[j]==a[i]) {
                        swap(a[n-1],b[j]);
                        res.push_back({n,j+1});
                        // printf("%lld %lld\n",n,j+1);

                        swap(a[n-1],b[i]);
                        res.push_back({n,i+1});
                        // printf("%lld %lld\n",n,i+1);
                        break;
                    }
                }
            }
        }

        printf("%lld\n",(ll)res.size());
        rep(i,res.size()) {
            printf("%lld %lld\n",res[i].fi,res[i].se);
        }
        
    }

    
    return 0;  
}