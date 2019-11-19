#include<bits/stdc++.h>
//#define int long long
using namespace std; const int maxn = 1e5+10;
typedef long long ll;
ll s[maxn]={2,2};
const ll mod = 1e9+7;
main(){
    ios::sync_with_stdio(false);
    for(int i=2;i<maxn;i++){
        s[i]=(s[i-1]+s[i-2])%mod;
    }
    ll n,m;cin>>n>>m;
    ll r=max(n,m),l=min(n,m);
    ll ans=s[r]+s[l]-2;
    cout<<ans%mod<<endl;
}
