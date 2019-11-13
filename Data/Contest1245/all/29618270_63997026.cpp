#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
  if(b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for(; t > 0; t--)
  {
    int a, b;
    cin >> a >> b;
    int gc = gcd(a, b);
    if(gc == 1) cout << "Finite" << endl;
    else cout << "Infinite" << endl;
  }
  return 0;
}
