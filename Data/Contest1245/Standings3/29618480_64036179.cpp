#include <cstdio>
#include <iostream>

using namespace std;

long long f[39][2][2][2][2];

long long solve(int a, int b) {
  if (a == -1 || b == -1) {
    return 0;
  }
  for (int i = 0; i <= 30; ++i) {
    for (int la = 0; la <= 1; ++la) {
      for (int za = 0; za <= 1; ++za) {
        for (int lb = 0; lb <= 1; ++lb) {
          for (int zb = 0; zb <= 1; ++zb) {
            f[i][la][za][lb][zb] = 0;
          }
        }
      }
    }
  }
  f[30][0][0][0][0] = 1;
  for (int i = 29; i >= 0; --i) {
    for (int la = 0; la <= 1; ++la) {
      for (int nza = 0; nza <= 1; ++nza) {
        for (int ba = 0; ba <= 1; ++ba) {
          int va = a >> i & 1;
          if (ba == 1 && la == 0 && va == 0) {
            continue;
          }
          for (int lb = 0; lb <= 1; ++lb) {
            for (int nzb = 0; nzb <= 1; ++nzb) {
              for (int bb = 0; bb <= 1; ++bb) {
                int vb = b >> i & 1;
                if (bb == 1 && lb == 0 && vb == 0) {
                  continue;
                }
                if (ba == 1 && bb == 1) {
                  continue;
                }
                f[i][la | (ba == 0 && va == 1)][nza | (ba == 1)][lb | (bb == 0 && vb == 1)][nzb | (bb == 1)] += f[i + 1][la][nza][lb][nzb];
              }
            }
          }
        }
      }
    }
  }
  long long res = 0;
  for (int la = 0; la <= 1; ++la) {
    for (int lb = 0; lb <= 1; ++lb) {
      res += f[0][la][1][lb][1];
    }
  }
  return res;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int l, r;
    scanf("%d%d", &l, &r);
    long long ans = solve(r, r) - 2 * solve(r, l - 1) + solve(l - 1, l - 1);
    if (l == 0) {
      ans += 2 * r + 1;
    }
    printf("%lld\n", ans);
  }
}
