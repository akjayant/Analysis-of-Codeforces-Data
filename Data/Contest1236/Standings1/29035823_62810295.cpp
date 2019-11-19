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

  int n, m, k;
  cin>>n>>m>>k;

  map<pair<int, int>, bool> matrix;
  int x, y;
  for (int i=0; i<k; i++) {
    cin>>x>>y;
    matrix[{x, y}] = true;
  }

  int top = 1, left = 1, right = m, bottom = n;
  int d = 0;
  int path = m*n-k;
  int count = 0;

  while (1) {
    if (right < left || bottom < top) break;

    if (d == 0) {
      while (right >= left && matrix[{top, right}]) {
        for (int i=top; i<=bottom; i++)
          if (!matrix[{i, right}]) {
            cout<<"No"<<endl;
            return 0;
          }
        right--;
      }
      top++;
      if (right >= left) count += right-left+1;
    }
    else if (d == 1) {
      while (bottom >= top && matrix[{bottom, right}]) {
        for (int i=left; i<=right; i++) 
          if (!matrix[{bottom, i}]) {
            cout<<"No"<<endl;
            return 0;
          }
        bottom--;
      }
      right--;
      if (bottom >= top) count += bottom-top+1;
    }
    else if (d == 2) {
      while (left <= right && matrix[{bottom, left}]) {
        for (int i=top; i<=bottom; i++) 
          if (!matrix[{i, left}]) {
            cout<<"No"<<endl;
            return 0;
          }
        left++;
      }
      bottom--;
      if (left <= right) count += right-left+1;
    }
    else {
      while (top <= bottom && matrix[{top, left}]) {
        for (int i=left; i<=right; i++) 
          if (!matrix[{top, i}]) {
            cout<<"No"<<endl;
            return 0;
          }
        top++;
      }
      left++;
      if (top <= bottom) count += bottom-top+1;
    }

    d = (d+1)%4;
  }

  if (count == path)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

  return 0;
}


