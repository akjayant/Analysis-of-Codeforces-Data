#include <bits/stdc++.h>

using namespace std;

int n, v[1002];

int main()
{
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> v[i];
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
    if (v[i] >= n - i + 1) {
      cout << n - i + 1 << "\n";
      break;
    }
  }
  return 0;
}
