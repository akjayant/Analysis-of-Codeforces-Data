#include <bits/stdc++.h>

using namespace std;

int n,m;
long long v[100100];
const int mod = 1e9 + 7;

int main() {
    v[1] = v[2] = 2;

    for (int i = 3; i < 100100; ++i) 
        v[i] = (v[i - 2] + v[i - 1]) % mod;
    
   
    cin >> n >> m;

    long long ans = v[n + 1];

    for (int i = 1; i < m; ++i) {
        ans += v[i];
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}
