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

        ll idx1=-1, idx2=-1, count=0;
        rep(i,n) {
            if(a[i]!=b[i]) {
                count++;
                if(idx1==-1)
                    idx1 = i;
                else if(idx2==-1)
                    idx2 = i;
            } 
        }

        if(count==2) {
            swap(a[idx1],b[idx2]);
            if(a==b) {
                printf("Yes\n");
                continue;
            }
            swap(a[idx1],b[idx2]);
            swap(a[idx2],b[idx1]);
            if(a==b) {
                printf("Yes\n");
                continue;
            }
        }

        printf("No\n");
    }

    
    return 0;  
}