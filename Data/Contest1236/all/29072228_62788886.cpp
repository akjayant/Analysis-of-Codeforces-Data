#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll ppow(ll x,int y){
    ll res=1;
    while(y){
        if(y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    ll ans=ppow(2,m)-1;
    ans=(ans%mod+mod)%mod;
    ans=ppow(ans,n);
    cout<<ans<<endl;
    return 0;
}
