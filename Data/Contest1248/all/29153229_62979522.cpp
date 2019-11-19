#include <bits/stdc++.h>

using namespace std;

int t;
array<long long, 2> lines1;
array<long long, 2> lines2;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m, tmp;
    lines1.fill(0);
    lines2.fill(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      lines1[tmp % 2]++;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> tmp;
      lines2[tmp % 2]++;
    }

    cout << lines1[0] * lines2[0] + lines1[1] * lines2[1] << endl;
  }

  return 0;
}
