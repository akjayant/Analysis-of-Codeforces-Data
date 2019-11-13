#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define int long long
#define sz(a) (int)(a.size())
#define pb emplace_back

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

signed main() {
  int k;
  cin >> k;
  for (int test = 0; test < k; test++) {
    int len;
    cin >> len;
    string s, t;
    cin >> s >> t;
    vector<pair<int, int>> ans;
    bool out = false;
    for (int i = 0; i < len; i++) {
      if (s[i] != t[i]) {
        bool found = false;
        for (int j = i + 1; j < len; j++) {
          if (s[j] == s[i]) {
            ans.pb(pair<int, int>(j + 1, i + 1));
            swap(s[j], t[i]);
            //cout << j << ' ' << i << '\n' << s << '\n' << t << "\n\n";
            found = true;
            break;
          }
        }
        if (!found) {
          for (int j = i + 1; j < len; j++) {
            if (t[j] == s[i]) {
              ans.pb(pair<int, int>(j + 1, j + 1));
              ans.pb(pair<int, int>(j + 1, i + 1));
              swap(s[j], t[j]);
              //cout << j << ' ' << j << '\n' << s << '\n' << t << "\n\n";
              swap(s[j], t[i]);
              //cout << j << ' ' << i << '\n' << s << '\n' << t << "\n\n";
              found = true;
              break;
            }
          }
        }
        if (!found) {
          cout << "No\n";
          out = true;
          break;
        }
      }
    }
    if (!out) {
      cout << "Yes\n";
      if (sz(ans) == 0) {
        cout << "1\n"
                "1 1\n";
      } else {
        cout << sz(ans) << '\n';
        for (auto [from, to] : ans) {
          cout << from << ' ' << to << '\n';
        }
      }
    }
  }
}