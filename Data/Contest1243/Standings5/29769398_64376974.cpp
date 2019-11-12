/**
 *    author:  tourist
 *    created: 03.11.2019 18:32:17       
**/
#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  while(k--){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(auto &a : vec)cin >> a;
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    int ans = 0;
    for(int x =0; x<n; x++){
      ans = max(ans, min(x+1, vec[x]));
    }
    cout << ans << "\n";
  }
  return 0;
}
