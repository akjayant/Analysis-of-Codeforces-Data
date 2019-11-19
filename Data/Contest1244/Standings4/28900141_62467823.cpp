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

  int a, b, c, d, k;
  for (int tt=0; tt<t; tt++) {
    cin>>a>>b>>c>>d>>k;

    int x = a/c;
    int y = b/d;
    if (a%c>0) x++;
    if (b%d>0) y++;

    if (x+y > k)
      cout<<-1<<endl;
    else
      cout<<x<<" "<<k-x<<endl;
  }

  return 0;
}
 
