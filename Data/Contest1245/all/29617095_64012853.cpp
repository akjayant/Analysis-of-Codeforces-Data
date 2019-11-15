#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e6 + 5;
const ll INF = 1e9 + 7;

ll T, a, b;

int main() {
    //freopen("1245A.INP", "r", stdin);
    //freopen("1245A.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> a >> b;
        ll c = __gcd(a,b);
        if (c == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
    return 0;
}
