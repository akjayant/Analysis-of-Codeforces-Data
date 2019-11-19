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

ll n, m, a[N], t;

int main() {
    file();
    cin >> t;
    for (int ii = 0; ii < t; ++ii) {
        ll x = 0, y = 0, ans = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            ll z;
            cin >> z;
            if (z % 2 == 0) ++x;
            else ++y;
        }
        cin >> m;
        for (int j = 0; j < m; ++j) {
            ll z;
            cin >> z;
            if (z % 2 == 0) ans += x;
            else ans += y;
        }
        cout << ans << endl;
    }
}


/**
3 3 2
...
*.*
...

a * b == 1 (mod p)
*/
