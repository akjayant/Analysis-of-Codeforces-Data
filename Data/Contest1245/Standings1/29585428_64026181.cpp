#define DEBUG(...)
#include<stdio.h>
#include<utility>
#include<algorithm>

using namespace std;

double dp[15][15];
int ar[15][15];

pair<int,int> trav(int x, int y, int m) {
  if (m == 0) return pair<int,int>(x, y);
  if (x % 2) {
    if (y < 10) {
      return trav(x, y+1, m-1);
    } else {
      return trav(x+1, y, m-1);
    }
  } else {
    if (y > 1) {
      return trav(x, y-1, m-1);
    } else {
      return trav(x+1, y, m-1);
    }
  }
}

double serc(int x, int y) {
  if (x == 10 && y == 1) {
    return 0;
  }
  if (dp[x][y] > -1e-9) return dp[x][y];
  double &ret = dp[x][y];
  ret = 0;
  int bolong = 0;
  for (int i = 1; i <= 6; i++) {
    pair<int,int> nxt = trav(x, y, i);
    if (nxt.first > 10) {
      bolong++;
    }
    double tmp = (1.0 + serc(nxt.first, nxt.second)) / 6;
    if (ar[nxt.first][nxt.second]) {
      tmp = min(tmp, (1.0 + serc(nxt.first+ar[nxt.first][nxt.second], nxt.second)) / 6);
    }
    ret += tmp;
  }
  ret = ret * 6 / (6 - bolong);
  return ret;
}

int main() {
  for (int i = 10; i >= 1; i--) {
    for (int j = 1; j <= 10; j++) {
      scanf("%d", &ar[i][j]);
      dp[i][j] = -1;
    }
  }
  printf("%.9f\n", serc(1, 1));
  return 0;
}