#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;

ll mpow(ll x,ll n){
    ll ans=1;
    while(n){
        if(n&1) ans=ans*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    ll ans=mpow(2,m);
    ans=(ans-1+mod)%mod;
    ans=mpow(ans,n);
    printf("%lld\n",ans);
    return 0;
}
