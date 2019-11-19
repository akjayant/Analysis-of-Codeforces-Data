#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t;
ll gcd(ll x,ll y)
{
  if(y==0) return x;
  else return gcd(y,x%y);
}
int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>n;
      ll ans=0;
      for(ll i=2;i*i<=n;i++){
        if(n%i==0){
           ans=gcd(i,ans);
           ans=gcd(n/i,ans);
        }
      }
      if(ans==0)cout<<n;
      else cout<<ans;
}