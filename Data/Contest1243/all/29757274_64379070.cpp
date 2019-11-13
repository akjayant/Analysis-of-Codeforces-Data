#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  while(q--) {
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    int f = -1 , ss = -1;
    int fl = 0;
    for(int i = 0; i < n; i++){
      if(s[i] != t[i]) {
        if(f == -1) {
          f = i;
        }
        else if(ss == -1) {
          ss = i;
        }
        else {
          cout << "No" << endl;
          fl = 1;
          break;
        }
      }
    }
    if(fl)continue;
    swap(s[f], t[ss]);
    if(s == t) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl; 
    }
  }
	return 0;
}