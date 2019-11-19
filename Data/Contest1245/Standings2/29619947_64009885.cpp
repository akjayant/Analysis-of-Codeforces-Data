    #include <bits/stdc++.h>
    using namespace std;
     
    #define ll long long
     
    ll dp[35][2][2][2][2];
    int l, r;
    ll fun ( int ind, bool l1, bool r1, bool l2, bool r2) {
      if ( ind == -1 ) {
        return 1;
      }
      ll ans = 0;
      if (dp[ind][l1][r1][l2][r2] != -1 ) {
        return dp[ind][l1][r1][l2][r2] ;
      }
      int bit1 = ( (l >> ind) & 1 );
      int bit2 = ( (r >> ind) & 1 );
      for(int i = 0 ; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
          if(l1 && i < bit1) continue;
          if(l2 && j < bit1) continue;
          if(r1 && i > bit2) continue;
          if(r2 && j > bit2) continue;
          if(i == j && i==1) continue;
          ans += fun( ind - 1, ( l1 && i == bit1), ( r1 && i == bit2), ( l2 && j == bit1), ( r2 && j == bit2) );
        }
      }
      return dp[ind][l1][r1][l2][r2] = ans;
    }
    int main() {
      int t;
      scanf("%d",&t);
      while(t--) {
        memset(dp, -1, sizeof(dp) ) ;
        scanf("%d %d", &l, &r);
        cout << fun(31, 1, 1, 1, 1) << '\n';
      }
      return 0 ;
    }