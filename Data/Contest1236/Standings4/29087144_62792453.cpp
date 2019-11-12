#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
ll pow(ll i,ll p){
    if(p==1)return i;
    if(p==0)return 1LL;
    ll k=pow(i,p/2LL);
    k=k*k%mod;
    if(p%2LL)return k*i%mod;
    return k%mod;
}
int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",pow(pow(2LL,b)-1LL,a));
}
