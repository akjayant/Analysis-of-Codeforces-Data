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
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int a1 = (a + c - 1) / c, a2 = (b + d - 1) / d;
    if (a1 + a2 > k)
      cout << "-1\n";
    else
      cout << a1 << " " << a2 << "\n";
  }


  return 0;
}