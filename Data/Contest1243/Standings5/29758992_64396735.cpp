#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

int main()
{
  cin >> n;
  bool ok = 1;
  for (int i = 2; 1ll * i * i <= n; i++)
  if (n % i == 0) {
    ok = 0;
    t = i;
    break;
  }
  if (ok) {
    cout << n;
  }
  else {
    while (n % t == 0)
      n /= t;
    if (n > 1)
      cout << 1;
    else
      cout << t;
  }
  return 0;
}
