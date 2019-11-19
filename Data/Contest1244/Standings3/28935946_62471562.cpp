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

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int var1 = s.find('1');
    int var2 = s.size() - s.rfind('1') - 1;

    //cout << var1 << " " << var2 << "\n";
    if (var2 == s.size()) {
      cout << n << "\n";
    } else if (var1 < var2) {
      cout << 2 * (n - var1) << "\n";
    } else {
      cout << 2 * (n - var2) << "\n";
    }
  }
  return 0;
}