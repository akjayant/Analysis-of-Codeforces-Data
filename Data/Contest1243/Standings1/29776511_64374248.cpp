
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
  vector<int>in (n);
  for(int i = 0; i < n; ++i) {
    cin >> in[i];
  }
  sort(in.begin(), in.end());
  reverse(in.begin(), in.end());
  for(int i = 0; i < n; ++i) {
    if(in[i] < i + 1) {
      cout << i << "\n";
      return;
    }
  }
  cout << n << "\n";
  return;
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