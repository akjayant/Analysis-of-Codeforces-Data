#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int ppow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", ppow(ppow(2, m) - 1 + mod, n) % mod);
}
