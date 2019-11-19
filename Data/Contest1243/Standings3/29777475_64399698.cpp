#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

#define dbg(a) cout << "-> " << __LINE__ << ": " << #a << " = " << a << endl

int main() {
    long long n;
    scanf("%lld", &n);
    long long cp = n, ans = -1;
    int lim = sqrtl(n + 1), cnt = 0;
    for (int i = 2; i <= lim; i++) {
        if (n % i == 0) {
            ++cnt;
            if (ans == -1) {
                ans = i;
            }
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1 and cp != n) {
        ++cnt;
    }
    if (ans == -1) {
        ans = n;
    }
    if (cnt > 1) {
        ans = 1;
    }
    printf("%lld\n", ans);
    return 0;
}
