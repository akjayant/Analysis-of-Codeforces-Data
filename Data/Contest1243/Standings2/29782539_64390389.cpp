#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    auto g = n;
    for (auto i = 2LL; i * i <= n; i++) {
      if (n % i == 0) {
	auto f1 = n / i;
	auto f2 = i;

	g = gcd(g, f1);
	g = gcd(g, f2);
      }
    }
    cout << g << '\n';
}
