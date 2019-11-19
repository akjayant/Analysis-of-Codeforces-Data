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
  
vector<ll> prime_factors(ll num) {
    
    vector<ll> res;

    if((num%2)==0) {
        res.push_back(2);
        while((num%2)==0) {
            num/=2;
        }
    }
    
    for(ll i=3;i<=sqrt(num);i+=2) {
        if((num%i)==0) {
            res.push_back(i);
            while((num%i)==0) {
                num/=i;
            }
        }
        
    }

    if(num>1)
        res.push_back(num);

    // for(auto i:res)
    //  printf("%lld ",i);
    // printf("\n");

    return res;
}

int main() {
 
    get(n);
    vector<ll> facts = prime_factors(n);
    if(facts.size()==1) {
        printf("%lld\n",facts[0]);
    } else {
        printf("1\n");
    }
    
    return 0;  
}