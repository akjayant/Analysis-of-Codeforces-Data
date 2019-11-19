#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
ll a[maxn],tot;
int main(){
  ll n;
  scanf("%lld",&n);
  for(ll i=2;i*i<=n;i++){
    if(n%i==0) {
            a[tot++]=i;
            a[tot++]=n/i;
    }
  }
  ll ans=n;
  for(int i=0;i<tot;i++){
    ans=__gcd(ans,a[i]);
  }
  printf("%lld\n",ans);
  return 0;
}
