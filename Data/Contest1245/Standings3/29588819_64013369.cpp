#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <queue>
#include <stdarg.h>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

#define ll long long

using namespace std;

ll dp[100005] = {0};

int
main() {
 
  string s;
  cin>>s;

  int n = s.length();
  int md = 1e9+7;
  dp[1] = 1;
  dp[2] = 2;
  for (int i=3; i<=n; i++) 
    dp[i] = (dp[i-1] + dp[i-2]) % md;

  ll ans = 1;
  int start_n = -1, start_u = -1;
  for (int i=0; i<n; i++) {
    if (s[i] == 'm') {
      ans = 0;
      break;
    }
    else if (s[i] == 'w') {
      ans = 0;
      break;
    }
    else if (s[i] == 'n') {
      if (start_n == -1) 
        start_n = i;

      if (i == n-1 || s[i+1] != 'n') {
        int count = i-start_n+1;
        ans *= dp[count];
        ans %= md;
        start_n = -1;
      }
    }
    else if (s[i] == 'u') {
      if (start_u == -1)
        start_u = i;

      if (i == n-1 || s[i+1] != 'u') {
        int count = i-start_u+1;
        ans *= dp[count];
        ans %= md;
        start_u = -1;
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}
