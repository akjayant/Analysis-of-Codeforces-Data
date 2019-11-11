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

string S;

const int MAXN = 1.1e5;

int memo[MAXN];

int go(int pos) {
  if (pos == S.size())
    return 1;
  int& ref = memo[pos];
  if (ref != -1)
    return ref;
  ref = go(pos + 1);
  if (pos + 1 < S.size()) {
    if (S[pos] == 'n' && S[pos + 1] == 'n') {
      ref += go(pos + 2);
      ref %= MOD;
    }
    if (S[pos] == 'u' && S[pos + 1] == 'u') {
      ref += go(pos + 2);
      ref %= MOD;
    }
  }
  return ref;
}
int main() {
  ios_base::sync_with_stdio(false);
  memset(memo, -1, sizeof(memo));
  cin >> S;
  if (count(S.begin(), S.end(), 'w')) {
    cout << "0\n";
    exit(0);
  }
  if (count(S.begin(), S.end(), 'm')) {
    cout << "0\n";
    exit(0);
  }
  cout << go(0) << '\n';
  return 0;
}
