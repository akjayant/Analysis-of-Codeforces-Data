#include <cstdio>
#include <vector>
const int maxn = 100010;

std::vector<long long> prime;

int main() {
  long long n;
  scanf("%I64d", &n);
  if (n == 1) return puts("1"), 0;
  for (long long i = 2; i * i <= n; ++i) {
    if (!(n % i)) {
      while (!(n % i)) n /= i;
      prime.push_back(i);
    }
  }
  if (n > 1) prime.push_back(n);
  printf("%I64d\n", prime.size() == 1 ? (*prime.begin()) : 1ll);
  return 0;
}
