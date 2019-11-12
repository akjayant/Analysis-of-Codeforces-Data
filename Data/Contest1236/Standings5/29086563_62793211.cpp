#include<bits/stdc++.h>
using namespace std;
int pow_mod(int a, int n, int m)
{
    if(n == 0) return 1;
    int x = pow_mod(a, n/2, m);
    long long ans = (long long)x * x % m;
    if(n % 2 == 1) ans = ans *a % m;
    return (int)ans;
}
int main()
{
    int n, m, mod;
    cin >> n >> m;
    mod = 1e9+7;
    int a = pow_mod(2, m, mod) - 1;
    //cout << "a = " << a << endl;
    int ans = pow_mod(a, n, mod);
    cout << ans << endl;
    
}