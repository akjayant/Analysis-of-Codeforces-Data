#include<bits/stdc++.h>
#define ll          long long int
#define pb          push_back
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define sll      set<ll>
#define msll    multiset<ll>
#define io  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
vi vv;
ll expo(ll base, ll exponent) {                //return base^exponent modulo modulus
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            // ans = ans%mod;
        }
        base = base*base;
        // base %= mod;
        exponent>>= 1;
    }
    return ans;
}
bool check(ll n, ll prime){
  for(ll i=0;i<43;i++){
    if(expo(prime,i)==n) return 1;
  }
  return 0;
}
int main()
{
  io
  ll i,j,n;
  cin>>n;
  if(n==1){
    cout<<1;
    return 0;
  }
  for(i=1;i*i<=n;i++){
    if(n%i==0){
      vv.pb(i);
      if((i*i)!=n){
        vv.pb(n/i);
      }
    }
  }
  sort(all(vv));
  cout<<(check(n,vv[1])?vv[1]:1LL);
 
  
 
  return 0;
}