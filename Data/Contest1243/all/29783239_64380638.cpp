#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  string t; cin >> t;

  set<int> idx;
  set<char> sChar;
  set<char> tChar;

  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      idx.insert(i);
      sChar.insert(s[i]);
      tChar.insert(t[i]);
    }
  }

  if (idx.size() != 2) {
    cout << "No" << endl;
  } else if (sChar.size() > 1 || tChar.size() > 1) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int k; cin >> k;

  while (k--) {
    solve();
  }


  return 0;
}
