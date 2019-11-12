#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll bigmod(ll n, ll k)
{
    if(k == 0) return 1;
    ll re = bigmod(n, k / 2);
    re = (re * re) % mod;
    if(k % 2) re = (re * n) % mod;
    return re;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    ll xx = bigmod(2, m) - 1;
    if(xx < 0) xx += mod;
    xx = bigmod(xx, n);

    cout << xx << endl;

    return 0;
}
