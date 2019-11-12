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
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++) {
      f[a[i] - 'a']++; f[b[i] - 'a']++;
    }
    bool ok = 1;
    for (int i = 0; i < 26; i++)
      if (f[i] % 2)
      ok = 0;
    if (!ok) {
      cout << "No\n";
    }
    else {
      a = '$' + a;
      b = '$' + b;
      vector<pair<int, int> >ans;
      for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
          int p = -1;
          for (int j = i + 1; j <= n; j++)
            if (b[j] == b[i])
              p = j;
          if (p != -1) {
            swap(a[i], b[p]);
            ans.push_back({i, p});
            continue;
          }
          p = -1;
          for (int j = i + 1; j <= n; j++)
            if (a[j] == a[i])
              p = j;
          if (p !=-1) {
            swap(b[i], a[p]);
            ans.push_back({p, i});
            continue;
          }
          bool ok = 0;
          for (int j = 0; j < 26; j++)
            if (j != a[i] - 'a' && b[i] - 'a' != j) {
              int poz1 = -1, poz2 = -1;
              for (int j1 = i + 1; j1 <= n; j1++) {
                if (a[j1] - 'a' == j) {poz1 = j1;}
                if (b[j1] - 'a' == j) {poz2 = j1;}
              }
              if (poz1 != -1 && poz2 != -1) {
                swap(a[i], b[poz2]);
                swap(b[i], a[poz1]);
                ans.push_back({i, poz2});
                ans.push_back({poz1, i});
                ok = 1;
                break;
              }
            }
          if (!ok) {
            swap(a[i], b[i]);
            ans.push_back({i, i});
            i--;
          }
        }
      }
      if (a != b) {
        cout << "No\n";
        continue;
      }
      cout << "Yes\n";
      cout << ans.size() << "\n";
      if (ans.size() > 2 * n) {
        cout << 0/0;
      }
      for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
  }
  return 0;
}
