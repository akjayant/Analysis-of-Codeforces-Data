// By Stefan Radu

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define sz(x) (int)(x).size()

typedef pair < int, int > pii;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

int main() {

#ifdef STEF
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int t;
  cin >> t;

  while (t --) {

    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    while (c >= 2 and b) {
      b -= 1;
      c -= 2;
      ans += 3;
    }

    while (b >= 2 and a) {
      a -= 1;
      b -= 2;
      ans += 3;
    }

    cout << ans << '\n';
  }
}
