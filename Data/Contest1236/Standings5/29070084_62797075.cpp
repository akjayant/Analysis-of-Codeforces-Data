#include <bits/stdc++.h>

using namespace std;

int a[500][500];

int main() {
  int n;
  cin >> n;
  int x = 1;
  for (int j = 1; j <= n; j++) {
    int start = (j - 1) * n;
    if (x%2==0) {
      for (int i = 1; i <= n; i++) a[i][j] = i + start;
    }
    else {
      for (int i = 1; i <= n; i++) a[i][j] = n + 1 - i + start;
    }
    x++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << a[i][j] << ' ';
    cout << endl;
  }
}