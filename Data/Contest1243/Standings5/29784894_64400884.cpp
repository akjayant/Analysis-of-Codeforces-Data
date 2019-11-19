#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define INF 2000000000000000000;

ll solve1(ll i) {

    vector<ll> a(i);

    for (ll j = 0; j < i; ++j) {
        a[j] = j;
    }

    for (ll j = 0; j < i; ++j) {
        for (ll k = j + 2; k < i; ++k) {
            if (i % (k - j) == 0) {
                a[k] = a[j];
            }
        }
    }

    set<ll> answer;
    for (ll j = 0; j < i; ++j) {
        answer.insert(a[j]);
    }

    return (answer.size());
    // cout << i << " : " << answer.size() << endl;
}

ll solve2(ll n) {

    if (n == 1) {
        return 1;
    }

    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return i;
        }
    }

    return (n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    set<ll> primes;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            primes.insert(i);
        }
        while (n % i == 0) {
            n /= i;
        }
    }

    if (n != 1) {
        primes.insert(n);
    }


    if(primes.size() > 1)
        cout << 1;
    else
        cout << *primes.begin();

    return 0;
}



