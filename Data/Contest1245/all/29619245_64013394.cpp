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

const int MOD = 1e9 + 7; 

int main() {

#ifdef STEF
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  
  string s;
  cin >> s;
  s = ' ' + s;

  int n = sz(s);

  vector < int > dp(n + 1);

  dp[0] = 1;
  for (int i = 1; i <= n; ++ i) {

    char c = s[i];
    if (c == 'w' or c == 'm') {
      cout << 0 << '\n';
      return 0;
    }

    if (s[i] == 'u' and s[i - 1] == 'u') {
      dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    else if (s[i] == 'n' and s[i - 1] == 'n') {
      dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    else {
      dp[i] = dp[i - 1];
    }
  }

  cout << dp[n] << '\n';
}
