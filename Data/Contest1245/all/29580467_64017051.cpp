/**
 *    created by : PawPaw       
**/

#include<bits/stdc++.h>
using namespace std;
#define N 100123
#define MOD 1000000007

int solve(){
  int dp[N], n;
  dp[0] = 1;
  string s;
  cin >> s;
  n = (int)s.size();
  for(int i = 0 ; i <= n ; i++){
    dp[i+1] = dp[i];
    if(i){
      if(s[i] == s[i-1] && (s[i] == 'u' || s[i] == 'n')){
        dp[i+1] = (dp[i+1]+dp[i-1]) % MOD;
      }
    }
    if(s[i] == 'w' || s[i] == 'm') {
      dp[n] = 0;
      break;
    }
  }
  cout << dp[n] << endl;
  return 0;
}

void fun(){
  int t = 1;
  // cin >> t;
  while(t--) solve();
} 

int main(){
  ios::sync_with_stdio(false); 
  cin.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("fi", "r", stdin);
    freopen("fo", "w", stdout);
    clock_t startClock, endClock;
    startClock = clock();
  #endif

  fun();

  #ifndef ONLINE_JUDGE
    endClock = clock(); 
    cout << "Time taken by program is : " << fixed <<  double(endClock - startClock) / double(CLOCKS_PER_SEC) << setprecision(5) << " sec " << endl; 
  #endif
  
  return 0;
}