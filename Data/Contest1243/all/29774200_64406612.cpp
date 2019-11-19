/*
  |\      _,,,---,,_
  /,`--'`'    -.  ;-;;,_
 |,4-. ) )-,_..;\ (  `'-'
'--'' (_/`--' `-'\_)
*/

#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
typedef pair<int, int> II;

const int N = 200005;
const int oo = 1000000007;


int main() {
#ifdef THELAZYCAT
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // THELAZYCAT

    ll n;
    cin >> n;
    ll ans = n;
    for (ll i = 2; i*i <= n; ++i)
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            if (n == 1) ans = i;
            else ans = 1;
            break;
        }
    cout << ans;
}