#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
  int q;
  cin >> q;
  while(q--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    map<char, int> cl;
    cl.clear();
    for(int i = 0; i < n; i++) {
      cl[s[i]]++;
      cl[t[i]]++;
    }
    int fl = 0;
    for(int i = 0; i < 26; i++) {
      char ss = i + 'a';
      if(cl[ss] % 2 == 1) {
        fl = 1;
        break;
      }
    }
    if(fl) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
    string s1 = s, t1 = t; 
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
      if(s[i] == t[i])continue;
      for(int j = i + 1; j < n; j++) {
        if(s[i] == t[j]) {
          swap(s[i + 1], t[j]);
          swap(s[i + 1], t[i]);
          ans += 2;
          break;
        }
        if(s[i] == s[j]) {
          swap(t[i], s[j]);
          ans++;
          break;
        }
      }
    }
    cout << ans << endl;
    for(int i = 0; i < n - 1; i++) {
      if(s1[i] == t1[i])continue;
      for(int j = i + 1; j < n; j++) {
        if(s1[i] == t1[j]) {
          swap(s1[i + 1], t1[j]);
          swap(s1[i + 1], t1[i]);
          cout << i + 2 << ' ' << j + 1 << endl;
          cout << i + 2 << ' ' << i + 1 << endl;
          break;
        }
        if(s1[i] == s1[j]) {
          swap(t1[i], s1[j]);
          cout << j + 1 << ' ' << i + 1 << endl;
          break;
        }
      }
    }    
  }
	return 0;
}