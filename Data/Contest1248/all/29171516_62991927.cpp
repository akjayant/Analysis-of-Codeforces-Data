//Sometimes you just need cheese

#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e5+10 ;
const int mod = 1e9+7 ;

long long dp[maxn] ;

int main(){

  ios::sync_with_stdio(false) ;
  cin.tie(0) ;

  int a, b ;
  cin >> a >> b ;
  a-- ;
  b-- ;

  dp[0] = 1;
  dp[1] = 2 ;
  for(int i  = 2; i < maxn; i++){

    dp[i]=(dp[i-1]+dp[i-2])%mod ;

  }
  cout << (2*dp[a]+2*dp[b]-2)%mod ;

}

