#include <bits/stdc++.h>
using namespace std;

int k,n,said;
string s,t;
char x,y;
int main() {
  cin >> k;
  while(k--) {
    cin >> n;
    cin >> s;
    cin >> t;
    x = y = 0;
    said = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] != t[i]) {
        if(!x && !y) {
          x = s[i], y = t[i];
        } else if(s[i] == x && t[i] == y) {
          for(int j = i + 1; j < n; j++) {
            if(s[j] != t[j]) {
              cout << "No\n";
              said = 1;
              break;
            }
          }
          if(said) break;
          cout << "Yes\n";
          said = 1;
          break;
        } else {
          cout << "No\n";
          said = 1;
          break;
        }
      }
    }
    if(!said) cout << "No\n";
  }
  return 0;
}