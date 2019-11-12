#include <deque>
#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <map>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <unordered_map>

using namespace std;

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> ans(300, vector<int>(300));
  int count = 0;
  for (int col = 0; col < n; ++col) {
    if (col & 1) {
      for (int row = n - 1; row >= 0; --row) {
        ans[row][col] = ++count;
      }
    } else {
      for (int row = 0; row < n; ++row) {
        ans[row][col] = ++count;
      }
    }
  }

  ostringstream oss;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j > 0) {
        oss << " ";
      }
      oss << ans[i][j];
    }
    oss << endl;
  }
  cout << oss.str() << flush;

  return 0;
}
