#include <bits/stdc++.h>
#define endl '\n'
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int oo = numeric_limits<int>::max();

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);

  ll x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (i < n/2) x += a[i];
    else y += a[i];
  }
  cout << x*x + y*y << endl;

  return 0;
}
