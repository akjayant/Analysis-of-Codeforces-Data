#include <iostream>

int n;

using namespace std;

const int MAXN = 300;

int a[MAXN][MAXN];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int v = n * n - (i * n + j);
      if (i % 2 == 0) {
        a[j][i] = v;
      } else {
        a[n - j - 1][i] = v;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
