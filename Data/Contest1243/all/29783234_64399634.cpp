#include "bits/stdc++.h"

using namespace std;
//vector<long long> factors;
#define ll long long

#define pii pair<int,int>
#define pll pair<ll,ll>
#define _ <<'\n'
#define __ << ' '
#define all(x) (x).begin(), (x).end()
#define gcd __gcd
int IT_MAX = 1 << 17;
int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x0f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
#define szz(x) (int)(x).size()
#define IOS ios_base::sync_with_stdio(false); cout.tie(0);cin.tie(0);
#define flush fflush(stdout)

ll mod(ll a, ll m) { return (a + (abs(a) / m) * m + m) % m; }

//****************************don't use int!!!!!!!****************************//
//***************************code starts here!!!!!****************************//

map<ll, ll> prime_cnt(ll n) {
    map<ll, ll> primes;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                primes[i]++;
                n /= i;
            }
        }
    }
    if (n != 1) {
        primes[n]++;
    }
    return primes;
}

int main() {
    IOS

    ll n;
    cin >> n;
    map<ll, ll> cnt_del = prime_cnt(n);
    if (cnt_del.size() != 1) {
        cout << 1;
        return 0;
    } else {
        cout << cnt_del.begin()->first;
        return 0;
    }
    return 0;
}