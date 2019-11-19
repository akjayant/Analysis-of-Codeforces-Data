#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4+20;
const ll MOD = 1e9+7;
vector<ll>fac;
int factor(ll n)
{
  for(ll i=2,a=1; i*i<=n; i+=a,a=2)
  {
    if(n%i==0){
      while(n%i==0){
        n /= i;
      }
      fac.push_back(i);
    }
  }
  if(n > 1)fac.push_back(n);
  return fac.size();
}
int main()
{
  ll n;
  cin >> n;
  int len = factor(n);
  //cout << len << endl;
  //cout << fac[0] << fac[1] << endl;
  if(len==1){
    cout << fac[0] << endl;
  }
  else cout << 1 << endl;
}
