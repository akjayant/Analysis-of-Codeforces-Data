#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt, qq = 0;
  cin >> tt;
  while (tt--)
  {
    int a, b;
    cin >> a >> b;
    if (__gcd(a, b) == 1) {
      cout << "Finite\n";
    } else {
      cout << "Infinite\n";
    }
  }
  return 0;
}