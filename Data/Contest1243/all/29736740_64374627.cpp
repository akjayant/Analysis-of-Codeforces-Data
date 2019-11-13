#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  cin >> k;
  for(; k > 0; k--)
  {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0, mx = INF;
    for(int i = n - 1, j = 1; i >= 0; i--)
    {
      mx = min(mx, a[i]);
      ans = max(ans, min(mx, j));
      j++;
    }
    cout << ans << endl;
  }
  return 0;
}
