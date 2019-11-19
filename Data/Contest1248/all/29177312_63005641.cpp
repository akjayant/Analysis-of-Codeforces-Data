#include  <bits/stdc++.h>
using namespace std;
#define ll long long

inline ll read() {
    ll x = 0, y = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') y = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch & 15); ch = getchar(); }
    return x * y;
}

const ll N = 1e5 + 9, P = 1e9 + 7;
ll n, m, f[N];

int main() {
    register ll i, j;
    n = read(), m = read();
    f[1] = 2, f[2] = 4;
    for (i = 3; i <= max(n, m); i ++) f[i] = (f[i - 1] + f[i - 2]) % P;
    cout << (f[n] + f[m] - 2 + P) % P << endl;
    return 0;
}