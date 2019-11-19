#include<iostream>
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;

long long m, n, f[1000001][2];
int main()
{
    cin >> n >> m;
    f[1][0] = 2;
    for(int i = 2; i <= max(n, m); i ++)
    {
        f[i][1] = f[i - 1][0] % mod;
        f[i][0] = (f[i - 1][1] + f[i - 1][0] ) % mod;
    }
    cout << (f[m][1] + f[m][0] + f[n][1] + f[n][0] - 2) % mod;
}