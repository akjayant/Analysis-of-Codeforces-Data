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

using namespace std;

int
main() {

  int mod = 1e9+7;
  int n, m;
  cin>>n>>m;

  vector<int> values;
  while (m > 0) {
    values.push_back(m % 2);
    m /= 2;
  }

  long long ans = 1;
  for (int i=values.size()-1; i>=0; i--) {
    ans = (ans * ans) % mod;
    if (values[i] == 1) ans = (ans * 2) % mod;
  }
  ans = (ans - 1 + mod) % mod;

  values.clear();
  while (n > 0) {
    values.push_back(n % 2);
    n /= 2;
  }

  long long v = ans;
  ans = 1;
  for (int i=values.size()-1; i>=0; i--) {
    ans = (ans * ans) % mod;
    if (values[i] == 1) ans = (ans * v) % mod;
  }

  cout<<ans<<endl;
 
  return 0;
}
