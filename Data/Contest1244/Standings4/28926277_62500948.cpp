#include<bits/stdc++.h>
#define TASK "ABC"
#define BASIC \
		freopen(TASK".inp", "r", stdin); \
		freopen(TASK".out", "w", stdout);
#define BASE ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define maxn 200001

using namespace std;
typedef long long ll;

ll n, p, w, d;
int main(){
     BASE
    cin >> n >> p >> w >> d;
    ll gd = __gcd(w, d);
    if (p % gd) return cout << -1, 0;
    p /= gd;
    w /= gd;
    d /= gd;
    ll r = 0;
    for (r = 0; r <= d; ++r)
        if ((p - r * w) % d == 0) break;
    if (r == d) return cout << -1, 0;
    ll ret = min(n, p / w);
    ll x = (ret / d - 2) * d + r;
    while (x + d <= ret) x += d;
    if ((p - x * w) % d || x < 0 || (p - x * w) / d < 0 || n - x - (p - x * w) / d < 0)
    cout << -1;
    else cout << x << ' ' << (p - x * w) / d << ' ' << n - x - (p - x * w) / d;
    return 0;
}
