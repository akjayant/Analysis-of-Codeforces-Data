#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
  int n;
  cin >> n;
  vector<ll> d(n);
  ll t = 0;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    t += d[i];
  }
  sort(d.begin(), d.end());
  ll curt = 0;
  for (int i = 0; i <n/2; i++)
    curt += d[i];
  cout << curt*curt+ (t-curt)*(t-curt) << endl;
}

