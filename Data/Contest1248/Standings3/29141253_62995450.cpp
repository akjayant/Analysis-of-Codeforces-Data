#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
ll dp[maxn];

int main()
{
    dp[0] = 1;
    dp[1] = 1;
    int n, m;
    cin >> n >> m;
    for(int i = 2; i <= maxn - 3; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    cout << (2LL * dp[n] % mod + 2LL * dp[m] % mod - 2 + mod) % mod << endl;
}
