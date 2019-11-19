#include"bits/stdc++.h"
using namespace std;

/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
*/

typedef long long ll;
static ll mod=1e9+7;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m;
  ll ans=0;
  cin>>n>>m;
  ll cnt[100005];cnt[0]=1;cnt[1]=1;
  for(int x=2;x<=max(n,m);x++){
    cnt[x]=cnt[x-1]+cnt[x-2];
    cnt[x]%=mod;
  }
  cout<<((cnt[n]+cnt[m]-1)*2)%mod;
  return 0;
}
