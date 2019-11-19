#include <bits/stdc++.h>
using namespace std;
#define me(a, b) memset(a, b, sizeof(a))
#define IOS() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll prime(ll x)
{
    ll ans = x;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            ans = gcd(ans, i);
            // cout << "ans = " << ans << endl;
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) ans = gcd(ans, x);
    return ans;
}

int main()
{
    IOS();
    ll n;
    cin >> n;
    cout << prime(n) << endl;
    return 0;
}