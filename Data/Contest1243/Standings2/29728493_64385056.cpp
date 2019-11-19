#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;

const double pi = acos(-1);
const int N = 1e6 + 6, mod = 998244353, M = 1e7 + 7;
const ll MAX = 5e18;

ll n, ans;

int main()
{
    cin >> n;
    ans = n;
    for(ll i = 2; i * i <= n; i++)
        if(n % i == 0){
            ans = __gcd(ans, i);
            ans = __gcd(ans, n / i);
        }
    cout << ans;
    return 0;
}
