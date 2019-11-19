
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

long long gcd(long long a, long long b) {
  while(b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

void solve() {
  long long n;
  cin >> n;

  long long ans = n;
  for(long long i = 2; i * i <= n; ++i) {
    if(n % i == 0) {
      ans = gcd(ans, i);
      while(n % i == 0) {
        n /= i;
      }
    }
  }
  if(n > 1) {
    ans = gcd(ans, n); 
  }
  cout << ans << "\n"; 
  return;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
}