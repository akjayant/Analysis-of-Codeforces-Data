#include <bits/stdc++.h>

using namespace std;

long long dp_n[100001], dp_m[100001];

int main()
{
    int n, m;
    cin >> n >> m;
    dp_n[0] = 1;
    dp_n[1] = 1;
    dp_m[0] = 1;
    dp_m[1] = 1;
    for(int i = 2; i <= n; i ++){
        dp_n[i] += dp_n[i - 1];
        dp_n[i] %= 1000000007;
        dp_n[i] += dp_n[i - 2];
        dp_n[i] %= 1000000007;
    }
    for(int i = 2; i <= m; i ++){
        dp_m[i] += dp_m[i - 1];
        dp_m[i] %= 1000000007;
        dp_m[i] += dp_m[i - 2];
        dp_m[i] %= 1000000007;
    }
    cout << (dp_n[n] * 2 % 1000000007 + dp_m[m] * 2 % 1000000007 - 2) % 1000000007;
}
