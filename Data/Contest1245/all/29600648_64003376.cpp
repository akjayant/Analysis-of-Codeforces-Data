#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  map<char,int> W, D, L;
  string h = "RPS";
  for(int i = 0; i < 3; ++i){
    W[h[i]] = (i+1)%3;
    D[h[i]] = i;
    L[h[i]] = (i+2)%3;
  }
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int c[3];
    for(int i = 0; i < 3; ++i) cin >> c[i];
    string s;
    cin >> s;
    int cnt = 0;
    string ans(n,'?');
    for(int i = 0; i < n; ++i){
      char e = s[i];
      if(c[W[e]] > 0) --c[W[e]], ++cnt, ans[i] = h[W[e]];
    }
    for(int i = 0; i < n; ++i){
      if(ans[i] != '?') continue;
      for(int j = 0; j < 3; ++j){
        if(c[j] > 0){
          --c[j], ans[i] = h[j];
          break;
        }
      }
    }
    if(cnt >= (n+1)/2) cout << "YES" << endl << ans << endl;
    else cout << "NO" << endl;
  }
}
