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

    vector<ll> dp(100001,1);
    rep2(i,2,100001) {
        dp[i] = (dp[i-1] + dp[i-2])%N;
    }

    string s;
    cin >> s;

    ll n = s.length();

    rep(i,n) {
        if(s[i]=='m' || s[i]=='w') {
            cout<<"0\n";
            return 0;
        }
    }

    vector<ll> A;
    for(int i=0;i<n;i++) {
        if(s[i]=='n') {
            ll c = 0;
            while(i<n && s[i]=='n') {
                c++; i++;
            }

            A.pb(c);
            i--;
        }
        else if(s[i]=='u') {
            ll c = 0;
            while(i<n && s[i]=='u') {
                c++; i++;
            }

            A.pb(c);
            i--;
        }
    }

    ll res = 1;
    rep(i,A.size()) {
        res = (res*dp[A[i]])%N;
    }
    cout<<res<<endl;
     
    return 0;
}
