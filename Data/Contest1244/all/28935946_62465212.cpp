#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <typeinfo>
#include <utility>

using namespace std;

#define ll long long

int main() {
  int t;
  cin >> t;

  while(t--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    int pens = a / c;
    if (a % c != 0) {
      pens++;
    }

    int pensils = b / d;
    if (b % d != 0) {
      pensils++;
    }

    if (pens + pensils > k) {
      cout << "-1\n";
    } else {
      cout << pens << " " << pensils << "\n";
    }
  }
  return 0;
}