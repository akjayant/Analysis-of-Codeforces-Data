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
main() {
 
  int t;
  cin>>t;

  for (int ii=0; ii<t; ii++) {
    int n;
    cin>>n;

    int a, b, c;
    cin>>a>>b>>c;

    string s = "";
    char ch;
    while (1) {
      ch = getchar();
      if (isupper(ch))
        s += ch;
      else if (s.length() > 0)
        break;
    }

    string out = "";
    for (int i=0; i<s.length(); i++)
      out += ' ';

    int count = 0;
    for (int i=0; i<s.length(); i++) {
      if (s[i] == 'P') {
        if (c > 0) {
          out[i] = 'S';
          c--;
          count++;
        }
      }
      else if (s[i] == 'R') {
        if (b > 0) {
          out[i] = 'P';
          b--;
          count++;
        }
      }
      else if (s[i] == 'S') {
        if (a > 0) {
          out[i] = 'R';
          a--;
          count++;
        }
      }
    }
    for (int i=0; i<out.length(); i++) {
      if (out[i] == ' ') {
        if (a > 0) {
          out[i] = 'R';
          a--;
        }
        else if (b > 0) {
          out[i] = 'P';
          b--;
        }
        else {
          out[i] = 'S';
          c--;
        }
      }
    }

    int win = n / 2;
    if (n % 2 == 1) win++;

    if (count >= win) {
      cout<<"YES"<<endl;
      cout<<out<<endl;
    }
    else {
      cout<<"NO"<<endl;
    }
  }

  return 0;
}

