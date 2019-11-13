#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int a[105];
ll qpow(ll x,ll n)
{
  ll res=1;
  while(n>0)
  {
    if(n%2==1)
    {
      res=res*x;
      res=res%mod;
    }
    x=x*x;
    x=x%mod;
    n>>=1;
  }
  return res;
}
int main() {

  ll a,b;
  cin>>a>>b;
  ll tmp=(qpow(2,b)-1)%mod;
  cout<<qpow(tmp,a)%mod;
  return 0;
}
