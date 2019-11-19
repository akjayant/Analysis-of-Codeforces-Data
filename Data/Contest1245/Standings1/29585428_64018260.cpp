#define DEBUG(...)
#include<stdio.h>

typedef long long int LL;

LL low[66], hi[66];
LL dp[2][66][2][2][2][2][2];

LL serc(int m, int x, int l, int h, int l2, int h2, int take) {
  if (x == -1) {
    return 1;
  }
  if (dp[m][x][l][h][l2][h2][take] != -1) return dp[m][x][l][h][l2][h2][take];
  LL &ret = dp[m][x][l][h][l2][h2][take];
  ret = 0;
  if (m == 0) {
    for (int i = 0; i < 2; i++) {
      if ((l || low[x] <= i) && (h || hi[x] >= i)) {
        int nl = l;
        if (low[x] < i) nl = 1;
        int nh = h;
        if (hi[x] > i) nh = 1;
        ret += serc(m^1, x, nl, nh, l2, h2, i > 0);
      }
    }
  }
  if (m == 1) {
    for (int i = 0; i < 2; i++) {
      if (take && i) continue;
      if ((l2 || low[x] <= i) && (h2 || hi[x] >= i)) {
        int nl = l2;
        if (low[x] < i) nl = 1;
        int nh = h2;
        if (hi[x] > i) nh = 1;
        ret += serc(m^1, x-1, l, h, nl, nh, 0);
      }
    }
  }
  // DEBUG(printf("on %d %d %d %d %d %d %d -> %lld\n", m, x, l, h, l2, h2, take, ret);)
  return ret;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    LL l, h;
    scanf("%lld %lld", &l, &h);
    for (int i = 0; i < 66; i++) {
      low[i] = l % 2;
      hi[i] = h % 2;
      l /= 2;
      h /= 2;
    }
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 66; j++) {
        for (int k = 0; k < 2; k++) {
          for (int l = 0; l < 2; l++) {
            for (int kk = 0; kk < 2; kk++) {
              for (int ll = 0; ll < 2; ll++) {
                dp[i][j][k][l][kk][ll][0] = dp[i][j][k][l][kk][ll][1] = -1;
              }
            }
          }
        }
      }
    }
    printf("%lld\n", serc(0, 65, 0, 0, 0, 0, 0));
  }
  return 0;
}
