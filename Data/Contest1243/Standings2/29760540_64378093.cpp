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
    int pos1 = -1, pos2 = -1, cnt = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] != t[i]) {
        cnt++;
        if (cnt == 1) {
          pos1 = i;
        } else if (cnt == 2) {
          pos2 = i;
        }
      }
    }
    if (cnt == 0) {
      cout << "Yes\n";
    } else if (cnt == 2 && s[pos1] == s[pos2] && t[pos1] == t[pos2]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}