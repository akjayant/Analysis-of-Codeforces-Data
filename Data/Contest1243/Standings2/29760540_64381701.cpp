#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define int long long
#define sz(a) (int)(a.size())
#define pb emplace_back

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

signed main() {
  int n;
  cin >> n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      if (n == 1) {
        cout << i;
      } else {
        cout << 1;
      }
      return 0;
    }
  }
  cout << n;
}