#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int n;
    string s;
    cin >> n >> s;
    int ans = n;
    int c = 0;
    for(int i = 0; i < n; ++i){
      if(s[i] == '0') continue;
      ++c;
      ans = max({ans,2*(i+1),2*(n-i)});
    }
    ans = max(ans,n+c);
    cout << ans << endl;
  }
}
