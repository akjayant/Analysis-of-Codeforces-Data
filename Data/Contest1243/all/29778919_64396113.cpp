#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    long long ans = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans = __gcd(ans, i);
            ans = __gcd(ans, n / i);
        }
    }
    printf("%lld\n", ans);
}