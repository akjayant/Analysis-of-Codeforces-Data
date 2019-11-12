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

  int t;
  cin>>t;

  int a, b, c;
  int ans;
  for (int i=0; i<t; i++) {
    cin>>a>>b>>c;

    ans = 0;
    int left = min(c/2, b);
    ans += left*3;
    b -= left;
    left = min(b/2, a);
    ans += left*3;

    cout<<ans<<endl;
  }

  return 0;
}

