#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  string t; cin >> t;

  map<char,int> all;
  map<char,set<int>> sIdx;
  map<char,set<int>> tIdx;
  for (int i = 0; i < n; i++) {
    all[s[i]]++;
    all[t[i]]++;
  }
  for (auto x: all) {
    if (x.second % 2 != 0) {
      cout << "No" << endl;
      return;
    }
  }

  int ans = 0;
  vector<pair<int,int>> swaps;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      size_t sFind = s.find(s[i], i+1);
      size_t tFind = t.find(s[i], i+1);

      if (sFind != string::npos) {
        ans++;
        swaps.push_back(make_pair(sFind, i));
        char temp = t[i];
        t.replace(i, 1, 1, s[sFind]);
        s.replace(sFind, 1, 1, temp);
      } else if (sFind == string::npos && tFind != string::npos) {
        ans += 2;
        swaps.push_back(make_pair(n-1, tFind));
        swaps.push_back(make_pair(n-1, i));
        char temp = s[n-1];
        s.replace(n-1, 1, 1, t[tFind]);
        t.replace(tFind, 1, 1, temp);
        char temp2 = t[i];
        t.replace(i, 1, 1, s[n-1]);
        s.replace(n-1, 1, 1, temp2);
      } else if (sFind == string::npos && tFind == string::npos) {
        cout << "No" << endl;
        return;
      }

    }
  }

  if (ans > 2*n) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    cout << ans << endl;
    for (auto x: swaps) {
      cout << x.first+1 << " " << x.second+1 << endl;
    }
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
