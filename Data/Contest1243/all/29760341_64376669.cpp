#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  cin >> tt;
  for(int te = 1; te <= tt; ++te) {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> m;
    for(int i = 0; i < n; ++i) {
      if(s[i] != t[i]) {
        m.push_back(i);
      }
    }
    if(m.empty()) cout << "Yes\n";
    else if((int) m.size() == 1) cout << "No\n";
    else {
      if((int) m.size() > 2) cout << "No\n";
      else {
        assert(m.size() == (size_t) 2);
        swap(s[m[0]], t[m[1]]);
        cout << (s == t ? "Yes" : "No") << '\n';
      }
    }
  }   
  return 0;
}
