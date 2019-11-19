#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;

int main() {
    scanf("%lld", &n);
    ll res = n;
    for (ll i = 2; i * i <= n; ++i) {
        if(n%i==0) {
            res = __gcd(res, i);
            res = __gcd(res, n/i);
        }
    }
    printf("%lld\n", res);
    return 0;
}