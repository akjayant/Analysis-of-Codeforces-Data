#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inarr(a,k,n) for(int i=k;i<n;i++){cin>>a[i];}
#define outarr(a,k,n) for(int i=k;i<n;i++){cout<<a[i]<<" ";}
#define inpair(a) cin>>a.first>>a.ss
#define outpair(a) cout<<a.ff<<" "<<a.ss<<endl
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c
#define fastio ios_base::sync_with_stdio(false)
ll cst = 100000;
int main(){
    cst*=cst;
    fastio;cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        int n;cin>>n;
        int i =0;
        vector<ll> len;
        ll sm=0;
        while(i<n){
            ll x;cin>>x;sm+=x;
            len.pb(x);i++;
        }
        sort(len.begin(),len.end());
        n=n/2;ll d=0;i=0;
        while(i<n){
            d+=len[i];i++;
        }
        sm-=d;
        sm*=sm;d*=d;
        ll ans=sm+d;
        cout<<ans<<endl;
    }
    return 0;
}