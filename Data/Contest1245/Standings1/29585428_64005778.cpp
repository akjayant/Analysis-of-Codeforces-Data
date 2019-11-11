#include<stdio.h>
#include<algorithm>

using namespace std;

int A, B, C;
char str[105];
int dp[105][105][105];
int bt[105][105][105];
int N;

int serc(int x, int a, int b) {
  if (a > A || b > B) return -1000000;
  if (x == N) {
    if (a != A || b != B) return -1000000;
    return 0;
  }
  if (dp[x][a][b] != -1) return dp[x][a][b];
  int &ret = dp[x][a][b];
  ret = -1000000;
  if (a + 1 <= A) {
    int tmp = serc(x+1, a+1, b);
    if (str[x] == 'S') {
      tmp++;
    }
    if (tmp > ret) {
      ret = tmp;
      bt[x][a][b] = 1;
    }
  }
  if (b + 1 <= B) {
    int tmp = serc(x+1, a, b+1);
    if (str[x] == 'R') {
      tmp++;
    }
    if (tmp > ret) {
      ret = tmp;
      bt[x][a][b] = 2;
    }
  }
  int tmp = serc(x+1, a, b);
  if (str[x] == 'P') {
    tmp++;
  }
  if (tmp > ret) {
    ret = tmp;
    bt[x][a][b] = 3;
  }
  return ret;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d %d %d", &N, &A, &B, &C);
    scanf("%s", str);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= A; j++) {
        for (int k = 0; k <= B; k++) {
          dp[i][j][k] = -1;
        }
      }
    }
    int ans = serc(0, 0, 0);
    if (ans >= (N+1)/2) {
      printf("YES\n");
      int a = 0, b = 0;
      for (int i = 0; i < N; i++) {
        if (bt[i][a][b] == 1) printf("R"), a++;
        else if (bt[i][a][b] == 2) printf("P"), b++;
        else printf("S");
      }
      printf("\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
