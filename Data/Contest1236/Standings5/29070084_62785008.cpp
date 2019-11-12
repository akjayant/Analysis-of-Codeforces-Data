#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

bool ff[maxn][maxn][maxn];
int f[maxn][maxn][maxn];

int solve(int a, int b, int c) {
  if (a < 0 || b < 0 || c < 0) return -1;
  if (ff[a][b][c]) return f[a][b][c];
  int res = 0;
  res = max(solve(a - 1, b - 2, c), solve(a, b - 1, c - 2));
  ff[a][b][c] = true;
  if (res == -1)
    res = 0;
  else
    res += 3;
  return f[a][b][c] = res;
}

int main() {
  int nTest;
  cin >> nTest;
  while (nTest--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
  }
}