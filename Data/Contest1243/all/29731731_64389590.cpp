#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const long double pi = acos(-1);
const double PI = acos(-1.);

#define MOD 1000000007

const int N = 1e5 + 5;
const int K = 2e2 + 2;
const int Ai = 1e6 + 6;
const int LOGN = 30;

int main() {
    ios_base::sync_with_stdio(false);

    ll n; cin >> n;

    if(n == 2) {
        cout << "2\n";
        return 0;
    }

    ll gcd = n;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            gcd = __gcd(gcd, i);

            if(n / i != i) {
                gcd = __gcd(gcd, n / i);
            }
        }
    }

    cout << gcd << "\n";

    return 0;
}

