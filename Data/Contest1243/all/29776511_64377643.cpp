
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int p1 = -1, p2 = -1;
  for(int i = 0; i < n; ++i) {
    if(s[i] != t[i]) {
      if(p1 == -1) {
        p1 = i;
      } else if(p2 == -1) {
        p2 = i;
      } else {
        cout << "No\n";
        return;
      }
    }
  }
  if(p1 == -1 || p2 == -1) {
    cout << "No\n";
    return;
  }
  if(s[p1] == s[p2] && t[p1] == t[p2]) {
    cout << "Yes\n";
    return;
  } 
  else {
    cout << "No\n";
    return;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int k;
  cin >> k;
  for(int i = 0; i < k; ++i) {
    solve();
  }
}