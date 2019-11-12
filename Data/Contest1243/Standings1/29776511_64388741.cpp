
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
  string sum = s + t;
  vector<int> cnt(26, 0), cs(26, 0), ct(26, 0);
  for(int c : sum) {
    cnt[c - 'a']++;
  }
  for(int a : cnt) {
    if(a % 2 != 0) {
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";
  vector<pair<int,int>> ans;
  
  
  for(int i = 0; i < n; ++i) {
    if(s[i] == t[i]) continue;

    for(int j = i + 1; j < n; ++j) {
      if(s[j] == s[i]) {
        swap(s[j], t[i]);
        ans.push_back({j, i});
        break;
      }
    }
    if(s[i] == t[i]) continue;
    for(int j = i + 1; j < n; ++j) {
      if(t[i] == t[j]) {
        swap(s[i], t[j]);
        ans.push_back({i, j});
        break;
      }
    }
    
    if(s[i] != t[i]) {
      swap(s[i], t[i]);
      ans.push_back({i, i});
      i--;
    }
  }
  cout << ans.size() << "\n";
  for(auto i : ans) {
    cout << i.first + 1 << " " << i.second + 1 << "\n";
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