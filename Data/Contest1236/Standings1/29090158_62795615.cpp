#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1000000007;

ll quick_pow(ll x,ll n){
    ll ans=1;
    while(n){
        if(n&1) ans=ans*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ans;
}
int main(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll t=(quick_pow(2,m)-1+mod)%mod;
    ll ans=quick_pow(t,n);
    printf("%lld\n",ans);
    return 0;
}
