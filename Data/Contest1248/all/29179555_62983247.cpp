#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cout.precision(15);

  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  long long suml = 0, sumr = 0;
  for(int i = 0; i < n / 2; ++i) suml += a[i];
  for(int i = n / 2; i < n; ++i) sumr += a[i];
  cout << suml * suml + sumr * sumr;

  return 0;
}
