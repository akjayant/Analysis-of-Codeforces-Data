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

    get(t);

    while(t--) {
        get(n);
        get(a);
        get(b);
        get(c);

        string s;
        cin >> s;

        string r;
        rep(i,n)
            r+='0';

        int j=0,w=0;
        for(auto i:s) {
            if(i=='R') {
                if(b>0) {
                    b--;
                    w++;
                    r[j]='P';
                }
            } 
            else if(i=='P') {
                if(c>0) {
                    c--;
                    w++;
                    r[j]='S';
                }
            }
            else {
                if(a>0) {
                    a--;
                    w++;
                    r[j]='R';
                }
            }
            j++;
        }

        rep(i,n) {
            if(r[i]=='0') {
                if(b) {
                    r[i] = 'P';
                    b--;
                }
                else if(c) {
                    r[i] = 'S';
                    c--;
                }
                else {
                    r[i] = 'R';
                    a--;
                }
            }
        }

        if(w>=ceil(n/2.0)) {
            cout<<"YES\n";
            cout<<r<<endl;
        }
        else
            cout<<"NO\n";
    }   
     
    return 0;
}
