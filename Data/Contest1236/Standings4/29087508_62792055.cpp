#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
int mul(int a, int b)
{
  return (1ll * a * b) % mod;
}

int fastpow(int base, int power)
{
  if(!power)
    return 1;
  int ret = fastpow(base, power / 2);
  ret = mul(ret, ret);
  if(power & 1)
    ret = mul(ret, base);
  return ret;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    cout << fastpow(fastpow(2, m) - 1, n);
    return 0;
}
