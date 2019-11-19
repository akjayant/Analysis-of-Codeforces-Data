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
ll md = 1000000007;
ll cst = 100000;
ll b[3]={0};
ll w[3]={0};
ll getit(int n){
    if(n==1){
        b[1]=1;b[2]=0;w[1]=1;w[2]=0;
        return 2;
    }
    if(n==2){
        b[1]=1;b[2]=1;w[1]=1;w[2]=1;return 4;
    }
    getit(n-1);
    ll b1 =w[1]+w[2];b1%=md;
    ll w1 =b[1]+b[2];w1%=md;
    ll b2 =b[1];b2%=md;
    ll w2 =w[1];w2%=md;
    b[1]=b1;b[2]=b2;w[1]=w1;w[2]=w2;
    return (b[1]+b[2]+w[1]+w[2]);
}
int main(){
    cst*=cst;
    fastio;cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;

    t=1;

    while(t--){
        int n,m;cin>>n>>m;
        ll h = getit(n);
        ll ans = h;ans-=2;ans%=md;
        //cout<<h<<endl;
        h=getit(m);
        //cout<<h<<endl;
        ans+=h;ans%=md;
        cout<<ans<<endl;
    }
    return 0;
}