/*
  I_🧡🧡🧡_QMsh
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds; // gp_hash_table<int, int> table;

template <typename T> void smin(T &a, const T &b) { a = (a < b ? a : b); }
template <typename T> void smax(T &a, const T &b) { a = (a > b ? a : b); }

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

signed main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    string s;
    cin >> n >> s;
    int l = -1, r = n;
    for (int i =  0; i < n; i++)
    {
      if (s[i] == '1')
      {
        smax(l, i);
        smin(r, i);
      }
    }
    int ans = n;
    if (l != -1)
      smax(ans, max(2 * max(l + 1, n - l), 2 * max(r + 1, n - r)));

    cout << ans << '\n';
  }


  return 0;
}