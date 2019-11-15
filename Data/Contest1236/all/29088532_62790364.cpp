#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define f first
#define s second

using namespace std;

const int N = 1e5 + 10;
const int md = 1e9 + 7;

int binpow(int a, int n) {
    if (!n) return 1;
    if (n & 1) return binpow(a, n - 1) * 1LL * a % md;
    else {
        int b = binpow(a, n / 2);
        return b * 1LL * b % md;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int x = binpow(2, m);
    int ans = binpow((x - 1), n);
    cout << ans;
    return 0;
}
