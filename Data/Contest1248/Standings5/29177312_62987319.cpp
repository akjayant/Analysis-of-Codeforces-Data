#include  <bits/stdc++.h>
using namespace std;
#define ll long long

inline ll read() {
    ll x = 0, y = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') y = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch & 15); ch = getchar(); }
    return x * y;
}

const int N = 1e5 + 9;
ll n, sum1, sum2;
ll a[N];
int main() {
    register int i;
    n = read();
    for (i = 1; i <= n; i ++) a[i] = read();
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n / 2; i ++) sum1 += a[i];
    for (i = n / 2 + 1; i <= n; i ++) sum2 += a[i];
    cout << sum1 * sum1 + sum2 * sum2 << endl;
}