#include <bits/stdc++.h>

using namespace std;

int t, n, f[26];
string a, b;

int main()
{
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> a >> b;
    vector<int>v;
    for (int i = 0; i < n; i++)
      if (a[i] != b[i]) {
        v.push_back(i);
      }
    if (v.size() > 2 || v.size() == 1) {
      cout << "No\n";
    }
    else {
      swap(a[v[0]], b[v[1]]);
      if (a == b) {
        cout << "Yes\n";
        continue;
      }
      swap(a[v[0]], b[v[1]]);
      swap(a[v[1]], b[v[0]]);
      if (a == b) {
        cout << "Yes\n";
        continue;
      }
      cout << "No\n";
    }
  }
  return 0;
}
