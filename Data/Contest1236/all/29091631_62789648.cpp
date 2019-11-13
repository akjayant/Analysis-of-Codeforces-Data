#include<bits/stdc++.h>
using namespace std;
mt19937 rng(0);
typedef long long ll;
const ll mod=1e9+7;
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    ll c=po(2,b)-1;
    ll d=po(c,a);
    if(d<0)d+=mod;
    printf("%lld",d);
}