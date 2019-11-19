#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
char a[100005];
char b[100005];
int main(){
  ll n;
  cin>>n;
  ll cnt=0;
  ll ans=1;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      while(n%i==0){
        n/=i;
      }
      ans=i;
      cnt++;
    }
  }
  if(n!=1) {
    cnt++;
    ans=n;
  }
  if(cnt>=2){
    printf("1");
  }
  else {
    printf("%lld",ans);
  }
  return 0;
}