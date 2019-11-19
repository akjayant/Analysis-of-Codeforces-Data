#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  long long x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n / 2; i++) {
    x += a[i];
  }
  for (int i = n / 2; i < n; i++) {
    y += a[i];
  }
  cout << x * x + y * y;
  return 0;
} 