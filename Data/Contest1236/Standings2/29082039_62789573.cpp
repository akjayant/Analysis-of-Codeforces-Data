#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define st string
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define endl '\n'

void file() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen ("monotony.in", "r", stdin); freopen ("monotony.out", "w", stdout);
}

const ll N = 2e5 + 7;
const ll MOD = 1e9 + 7;

ll n, m, k;

ll bin_pow (ll x, ll y) {
    if (y == 1) return x;
    ll z = bin_pow(x, y / 2);
    if (y % 2 == 0) {
        return z * z % MOD;
    } else {
        return z * z % MOD * x % MOD;
    }
}

int main() {
    file();
    cin >> m >> n;
    ll k = (bin_pow(2, n) - 1) % MOD;
//    cout << k << endl;
    ll p = bin_pow(k, m) % MOD;
    cout << p;
}


/**
101010
0

101010
01010

3 3
3 4
...f
....
s...

*/
