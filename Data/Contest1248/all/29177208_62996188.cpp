#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const ll mod = 1e9 + 7;
const int N = 2e5 + 10;
ll n, m, a[N], b[N], c[N];
int main() {
    cin >> n >> m;
    if(n > m)
        swap(n, m);
    a[1] = 2, a[2] = 6, a[3] = 10, a[4] = 18;
    b[1] = 2, b[2] = 4, b[3] = 6, b[4] = 10;
    for(int i = 5; i <= n; i++) {
        b[i] = (2 * b[i - 1] % mod + mod - b[i - 3]) % mod;
    }
    for(int i = 5; i <= n; i++) {
        a[i] = (2 * a[i - 1] % mod + mod - a[i - 3]) % mod;
    }
    c[1] = b[n], c[2] = c[1] + 2, c[3] = c[2] + 2;
    for(int i = 4; i <= m; i++) {
        c[i] = (2 * c[i - 1] % mod + mod - c[i - 3]) % mod;
    }
    cout << c[m];
    return 0;
}
