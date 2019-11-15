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

int 
gcd(int a, int b) {
  if (b < a)
    return gcd(b, a);

  if (a == 0)
    return b;

  return gcd(b % a, a);
}

int
main() {
 
  int n;
  cin>>n;

  int a, b;
  for (int i=0; i<n; i++) {
    cin>>a>>b;
    if (gcd(a, b) > 1)
      cout<<"Infinite"<<endl;
    else
      cout<<"Finite"<<endl;
  }

  return 0;
}

