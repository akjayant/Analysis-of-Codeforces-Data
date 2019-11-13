/**
 *    created by : PawPaw       
**/

#include<bits/stdc++.h>
using namespace std;

int solve(){
  int a, b;
  cin >> a >> b;
  if(__gcd(a, b) != 1) cout << "Infinite\n";
  else cout << "Finite\n";
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