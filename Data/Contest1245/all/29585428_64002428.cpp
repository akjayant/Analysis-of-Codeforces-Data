#include<stdio.h>
#include<string.h>

typedef long long int LL;
const LL MOD = 1000000007;

LL dp[100005];
char str[100005];
int L;

LL serc(int x) {
  if (x >= L) {
    return 1;
  }
  if (dp[x] != -1) return dp[x];
  LL &ret = dp[x];
  ret = 0;
  if (x + 1 < L && str[x] == 'u' && str[x+1] == 'u') {
    ret = (ret + serc(x + 2)) % MOD;
  }
  if (x + 1 < L && str[x] == 'n' && str[x+1] == 'n') {
    ret = (ret + serc(x + 2)) % MOD;
  }
  ret = (ret + serc(x + 1)) % MOD;
  return ret;
}

int main() {
  scanf("%s", str);
  L = strlen(str);
  int val = 1;
  for (int i = 0; i < L && val; i++) {
    if (str[i] == 'm' || str[i] == 'w') {
      val = 0;
    }
    dp[i] = -1;
  }
  if (val) printf("%lld\n", serc(0));
  else printf("0\n");
  return 0;
}
