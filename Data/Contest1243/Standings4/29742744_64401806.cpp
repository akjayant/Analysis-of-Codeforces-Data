#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  scanf("%lld", &n);
  vector<long long> divs;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      divs.push_back(i);
      divs.push_back(n / i);
    }
  }
  if (int(divs.size()) == 0) {
    printf("%lld\n", n);
  } else {
    long long g = divs[0];
    for (int i = 1; i < int(divs.size()); ++i)
      g = __gcd(g, divs[i]);
    printf("%lld\n", g);
  }
  return 0;
}