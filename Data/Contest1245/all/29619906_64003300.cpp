#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;

  while(t--) {
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;

    string s; cin >> s;
    string t(n, '?');
    int ret = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == 'R' && b) { b--; ret++; t[i] = 'P'; };
      if(s[i] == 'P' && c) { c--; ret++; t[i] = 'S'; };
      if(s[i] == 'S' && a) { a--; ret++; t[i] = 'R'; };
    }

    for(int i = 0; i < n; i++) {
      if(t[i] == '?') {
        if(a) { a--; t[i] = 'R'; }
        else if(b) { b--; t[i] = 'P'; }
        else { c--; t[i] = 'S'; }
      }
    }

    if(ret >= (n+1)/2) {
      cout << "YES" << endl;
      cout << t << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
