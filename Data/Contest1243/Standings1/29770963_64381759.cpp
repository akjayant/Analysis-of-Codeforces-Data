// a nu cheeki reeki i v damke !

#include<bits/stdc++.h>
using namespace std ;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define F first
#define S second

const int maxn = 1e3+10 ;

int cnt[maxn] ;

int main(){

  ios::sync_with_stdio(false) ;
  cin.tie(0) ;

  int t ;
  cin >> t ;
  for(int T = 0; T < t; T++){

    int n ;
    cin >> n ;
    int ans = 0 ;
    memset(cnt, 0, sizeof cnt) ;
    for(int i = 0; i < n; i++){

      int t ;
      cin >> t ;
      cnt[t]++ ;

    }
    int sum = 0 ;
    for(int i = n; i > 0; i--){

      sum += cnt[i] ;
      ans = max(ans, min(sum, i)) ;

    }
    cout << ans << '\n' ;

  }

}
