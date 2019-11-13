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

  int n;
  cin>>n;

  int ans[305][305];
  for (int i=1; i<=n; i++) {
    if (i&1) {
      for (int j=1; j<=n; j++) {
        ans[i][j] = (i-1)*n + j;
      }
    }
    else {
      for (int j=1; j<=n; j++) {
        ans[i][n+1-j] = (i-1)*n + j;
      }
    }
  }

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++)
      cout<<ans[j][i]<<" ";
    cout<<endl;
  }

  return 0;
}
