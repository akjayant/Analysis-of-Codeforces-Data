#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e5+10;
const ll mod=1e9+7;
ll quick_mod(ll a,ll x){
  ll ans=1;
  while(x){
    if(x%2==1){
        ans=ans*a%mod;
    }
    a=a*a%mod;
    x/=2;
  }
  return ans;
}
int main() {
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll ans=(quick_mod((ll)2,m)-1+mod)%mod;
    ans=quick_mod(ans,n);
    printf("%lld\n",ans);
    //freopen("in.txt","r",stdin);
    return 0;
}
