#include"bits/stdc++.h"
using namespace std;

/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
*/

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int tc,n,m,p,q;
  long long oddn,evenn;
  long long oddm,evenm;
  cin>>tc;
  while(tc--){
    cin>>n;
    oddn=oddm=evenn=evenm=0;
    for(int x=0;x<n;x++){
      cin>>p;
      if((p%2)==0){
        evenn++;
      }else oddn++;
    }
    cin>>m;
    for(int x=0;x<m;x++){
      cin>>q;
      if((q%2)==0){
        evenm++;
      }else oddm++;
    }
    cout<<(oddn*oddm) + (evenn*evenm)<<'\n';
  }
  return 0;
}
