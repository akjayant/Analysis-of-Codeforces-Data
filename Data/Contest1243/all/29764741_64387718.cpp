#include <bits/stdc++.h>
#define eb emplace_back
#define em emplace
#define all(v) v.begin(), v.end()
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int MAX = 1010101;
const int INF = 1 << 30;
const ll LINF = 1LL << 62;

bool chk[1010101];

ll gcd(ll x, ll y) {
    if(!y) return x;
    return gcd(y, x % y);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n;
    cin >> n;
    for(ll i = 2; i * i <= MAX; i++) {
        if(chk[i]) continue;
        for(ll j = i * i; j <= MAX; j += i) {
            chk[j] = true;
        }
    }

    ll ans = n;
    for(ll i = 2; i * i <= n; i++) {
        if(chk[i]) continue;
        if(n % i == 0) {
            ans = gcd(ans, i);
            while(n % i == 0) n /= i;
        }
    }
    if(n != 1) ans = gcd(ans, n);
    cout << ans;
}