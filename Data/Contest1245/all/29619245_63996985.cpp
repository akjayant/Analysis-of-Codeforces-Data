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

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++ i) {
    int a, b;
    cin >> a >> b;

    if (__gcd(a, b) == 1) {
      cout << "Finite\n";
    }
    else {
      cout << "Infinite\n";
    }
  }
}
