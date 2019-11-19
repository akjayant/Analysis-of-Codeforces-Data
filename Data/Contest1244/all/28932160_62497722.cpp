#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100000 + 5;

int N; long long K;
long long A[MaxN];

void init() {
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
  std::sort(A + 1, A + 1 + N);
}

long long calc() {
  static long long Suf[MaxN];
  Suf[N + 1] = 0;
  for (int i = N; i >= 1; --i) Suf[i] = Suf[i + 1] + A[i];

  long long res = A[N] - A[1];
  long long k = K;
  for (int i = 1, j = 0; i <= N; ++i) {
    k -= (i - 1) * (A[i] - A[i - 1]);
    if (k < 0) return res;
    while (j + 1 < N && Suf[j + 1] - A[j + 1] * (N - j) > k) j++;
    long long remain = k - (Suf[j + 1] - A[j + 1] * (N - j));
//    printf("i = %d, j = %d, remain = %lld\n", i, j, remain);
    res = std::min(res, max(A[j + 1] - remain / (N - j), A[i]) - A[i]);
  }
  return res;
}

void solve() {
  long long ans = calc();
  for (int i = 1; i <= N / 2; ++i) swap(A[i], A[N - i + 1]);
  for (int i = 1; i <= N; ++i) A[i] *= -1;
  ans = min(ans, calc());
  cout << ans << endl;
}

int main() {
  init();
  solve();
  return 0;
}