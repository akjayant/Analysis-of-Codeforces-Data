#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
long long n;
bool p[2000010];

int main() {
    cin >> n;
    long long ub = min(n - 1, (ll)sqrt(n) + 10), ans = 0;
    bool flag = 1;
    for (int i = 2; i <= 2000000; i++) if (!p[i]) {
        for (int j = i + i; j <= 2000000; j += i) p[j] = 1;
    }
    for (ll i = ub; i > 1; i--) {
        if (!(n % i) && !p[i]) {
            flag = 0;
            long long m = n;
            while (!(m % i)) m /= i;
            if (m == 1) printf("%lld\n", i), exit(0);
        }
    }
    if (flag) printf("%lld\n", n), exit(0);
    printf("1\n");
    return 0;
}