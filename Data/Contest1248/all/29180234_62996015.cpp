#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
typedef long long ll;
const ll mod = 1e9 + 7;
ll f[maxn];
void init()
{
    f[0] = 1;
    f[1] = 1;
    for(int i = 2;i <= 100005; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= mod; 
    }
}

int n,m;
int main()
{
    cin >> n >> m;
    init();
    cout << 2 * (f[n] + f[m] - 1) % mod << endl;
    return 0;
}