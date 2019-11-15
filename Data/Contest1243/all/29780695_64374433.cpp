#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
  int k;
  cin >> k;
  for (int kk = 0; kk < k; ++kk) {
    int n;
    cin >> n;
    vector<int> dt(n);
    for (auto& x : dt) {
      cin >> x;
    }

    int l = 0;
    int r = n + 1;
    while (l < r - 1) {
      int m = (l + r) / 2;
      int cnt = 0;
      for (auto x : dt) {
        if (x >= m) {
          ++cnt;
        }
      }
      if (cnt >= m) {
        l = m;
      } else {
        r = m;
      }
    }
    cout << l << endl;
  }
}