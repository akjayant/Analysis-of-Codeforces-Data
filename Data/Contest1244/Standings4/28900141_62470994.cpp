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

  int n;
  string s;
  int start, end;
  for (int tt=0; tt<t; tt++) {
    scanf("%d\n", &n);
    cin>>s;

    start = -1;
    end = -1;
    for (int i=0; i<s.length(); i++) {
      if (s[i] == '1') {
        if (start == -1) start = i;
        end = i;
      }
    }

    if (start == -1) {
      cout<<n<<endl;
    }
    else {
      int left = start;
      int right = s.length()-1-end;
      int skip = min(left, right);
      cout<<n*2-skip*2<<endl;
    }
  }

  return 0;
}
 
