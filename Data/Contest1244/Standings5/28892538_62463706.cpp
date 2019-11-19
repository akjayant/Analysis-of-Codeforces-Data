#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ff first
#define ss second
#define int long long

using namespace std;

void run(){
  int a,b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  int kc = a / c + bool (a % c);
  int kd = b / d + bool (b % d);
  if (kc + kd <= k) {
    cout << kc <<  ' ' << kd << '\n';
  } else {
    cout << -1 << '\n';
  }

}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) run();
  return 0;
}