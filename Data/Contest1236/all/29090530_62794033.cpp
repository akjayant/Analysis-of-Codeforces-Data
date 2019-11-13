#include <iostream>

using namespace std;

const int kMaxN = 301;

int a[kMaxN][kMaxN];
int n, t = 0;

int main() {
  cin >> n;
  for (int j = 1; j <= n; j++) {
    if ((j & 1) == 1) {
      for (int i = 1; i <= n; i++) {
        t++;
        a[i][j] = t;
      }
    } else {
      for (int i = n; i >= 1; i--) {
        t++;
        a[i][j] = t;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}