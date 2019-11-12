#include <bits/stdc++.h>

typedef long long lint;

using namespace std;

const int mod = 1e9 + 7;
int n, m;

lint power(lint a, int b) {
    lint res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    printf("%I64d\n", power((power(2, m) - 1 + mod) % mod, n) % mod);
}
