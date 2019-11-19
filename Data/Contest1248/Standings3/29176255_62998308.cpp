#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int MOD = 1e9+7;
long long fib[N];
int main()
{
    int n,m;
    cin >> n >> m;
    if (n<m)
        swap(n,m);
    fib[1] = 2; fib[2] = 4;
    for (int i = 3; i<=n; i++)
        fib[i] = (fib[i-1]+fib[i-2])%MOD;
    long long ans = fib[n];
    fib[1] = 0; fib[2] = 2;
    for (int i = 3; i<=m; i++)
        fib[i] = (fib[i-1]+fib[i-2])%MOD;
    for (int i = 1; i<=m; i++)
        ans = (ans+fib[i])%MOD;
    cout << ans;
}
