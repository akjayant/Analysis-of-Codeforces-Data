#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll po(ll a,ll b){
  ll r=1,bas=a;
  while(b){
    if(b&1) r*=bas;
    bas*=bas;
    bas=bas%1000000007;
    r=r%1000000007;
    b>>=1;
  }
  return r%1000000007;
}
int main(){
    ll a,b;
    cin>>a>>b;
    ll ans=po(2,b)-1;
    ans=po(ans,a);
    cout<<ans;
}