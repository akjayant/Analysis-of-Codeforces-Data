#include <algorithm>
#include <iostream>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cstring>
#include <assert.h>
#include <chrono>
#include <random>
#include <functional>
#include <bitset>
#include <iterator>

using namespace std;

using ll = long long;

const int MOD = (int)(1e9 + 7);
const double PI = 3.14159265358979323846;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    if (gcd(a, b) == 1) {
      cout << "Finite\n";
    } else {
      cout << "Infinite\n";
    }
  }
  return 0;
}
