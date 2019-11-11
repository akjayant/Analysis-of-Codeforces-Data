/**
 *    created by : PawPaw       
**/

#include<bits/stdc++.h>
using namespace std;

int solve(){
  int n, r, p, s, win = 0;
  string bob, ans = "";
  cin >> n;
  cin >> r >> p >> s;
  cin >> bob;

  for(char i : bob){
      if(i == 'R'){
        if(p) {
          ans.push_back('P');
          win++, p--;
        } else ans.push_back('x');
      }
      else if(i == 'P'){
        if(s) {
          ans.push_back('S');
          win++, s--;
        } else ans.push_back('x');  
      }
      else {
        if(r) {
          ans.push_back('R');
          win++, r--;
        } else ans.push_back('x');
      }
  }
  for(int i = 0 ; i < n ; i++){
    if(ans[i] == 'x'){
      if(p) {ans[i] = 'P'; p--;}
      else if(s) {ans[i] = 'S'; s--;}
      else ans[i] = 'R'; 
    }
  }
  if(win >= (n/2) + (n%2)) cout << "YES\n" << ans << '\n';
  else cout << "NO\n";
  return 0;
}

void fun(){
  int t = 1;
  cin >> t;
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