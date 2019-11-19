#define bug(x) cout<<#x<<" is "<<x<<endl
#define IO std::ios::sync_with_stdio(0)
#include <bits/stdc++.h>
#define iter ::iterator
#define pa pair<int,ll>
#define pp pair<int,pa>
using namespace  std;
#define ll long long
#define mk make_pair
#define pb push_back
#define se second
#define fi first
#define ls o<<1
#define rs o<<1|1
const ll mod=1e9+7;
const int N=1e5+10;
int T,n,m;
ll f[N],d[N],p[N];
int main(){
    f[1]=2,f[2]=4;
    d[1]=0,d[2]=2;
    for(int i=3;i<=1e5;i++){
        f[i]=(f[i-1]+f[i-2])%mod;
        d[i]=(d[i-1]+d[i-2]+2)%mod;
    }
    /*for(int i=1;i<=6;i++){
        cout<<d[i]<<endl;
    }*/
    IO;
    cin>>n>>m;
    if(n>m)swap(n,m);
    ll ans;
    ll p1=f[n],p2=f[n]+2;
    if(m==1)ans=p1;
    if(m==2)ans=p2;
    for(int i=3;i<=m;i++){
        ans=((p1+p2)%mod-d[n]+mod)%mod;
        p1=p2;
        p2=ans;
    }
    cout<<ans<<endl;
}
