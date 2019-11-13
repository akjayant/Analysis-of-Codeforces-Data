#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const ll maxn = 2e5+10;
const ll mod = 998244353;

ll n, m, q;
ll a[maxn];

int main()
{
    cin>> q;
    while(q--)
    {
        ll a, b, c; cin>> a >> b >> c;
        ll x = min(b,c/2);
        b -= x;
        x += min(a, b/2);
        cout<< 3*x <<"\n";
    }
}