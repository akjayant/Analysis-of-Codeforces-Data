#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  constexpr int N = 32;
  long long dp[N+1][2][2][2][2];
  while(t--){
    long long L, R;
    cin >> L >> R;
    if(L == R){
      cout << 0 << endl;
      continue;
    }
    for(int i = 0; i < N+1; ++i)
      for(int j = 0; j < 2; ++j)
        for(int k = 0; k < 2; ++k)
          for(int l = 0; l < 2; ++l)
            for(int m = 0; m < 2; ++m)
              dp[i][j][k][l][m] = 0;
            
    dp[0][1][1][1][1] = 1;
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < 2; ++j){
        for(int k = 0; k < 2; ++k){
          for(int l = 0; l < 2; ++l){
            for(int m = 0; m < 2; ++m){
              if(dp[i][j][k][l][m] == 0) continue;
              for(int n = 0; n < 2; ++n){
                for(int o = 0; o < 2; ++o){
                  if(o&n) continue;
                  if(j and (((L>>(N-1-i))&1) > n)) continue;
                  if(k and (((R>>(N-1-i))&1) < n)) continue;
                  if(l and (((L>>(N-1-i))&1) > o)) continue;
                  if(m and (((R>>(N-1-i))&1) < o)) continue;
                  int j_ = j&(((L>>(N-1-i))&1) == n);
                  int k_ = k&(((R>>(N-1-i))&1) == n);
                  int l_ = l&(((L>>(N-1-i))&1) == o);
                  int m_ = m&(((R>>(N-1-i))&1) == o);
                  dp[i+1][j_][k_][l_][m_] += dp[i][j][k][l][m];
                }
              }
            }
          }
        }
      }
    }
    long long ans = 0;
    for(int i = 0; i < 2; ++i){
      for(int j = 0; j < 2; ++j){
        for(int k = 0; k < 2; ++k){
          for(int l = 0; l < 2; ++l){
            ans += dp[N][i][j][k][l];
          }
        }
      }
    }
    
    cout << ans << endl;
  }
}
