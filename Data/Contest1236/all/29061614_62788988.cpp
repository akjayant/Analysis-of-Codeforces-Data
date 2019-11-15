#include <bits/stdc++.h>
#define INF 1e18
#define M 1000000007
#define ll long long
using namespace std;

ll power(ll a, ll b)
{
    if(b == 0) return 1;
    ll p = power(a, b / 2);
    p = (p*p) % M;
    if(b & 1) p = (a*p) % M;
    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    cout << power((power(2, m) - 1), n) << endl;
}