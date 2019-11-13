#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double lf;

const int N = 1e5+2;
const ll oo = 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #else
    #define endl '\n'
  #endif
  
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    string s; cin >> s;
    int wins = 0;
    string ans;
    for(char ch : s) {
      if(ch == 'R') {
        if(b) ans.push_back('P'), b--, wins++;
        else ans.push_back(' ');
      }
      if(ch == 'P') {
        if(c) ans.push_back('S'), c--, wins++;
        else ans.push_back(' ');
      }
      if(ch == 'S') {
        if(a) ans.push_back('R'), a--, wins++;
        else ans.push_back(' ');
      }
    }
    for(char &ch : ans) {
      if(ch == ' ') {
        if(a) ch = 'R', a--;
        else if(b) ch = 'P', b--;
        else ch = 'S', c--;
      }
    }
    if(wins >= (n + 1) / 2) {
      cout << "YES" << endl;
      cout << ans << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  
}