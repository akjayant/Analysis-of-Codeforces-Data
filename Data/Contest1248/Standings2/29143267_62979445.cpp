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

ll n, m, a[N], x, y;

int main() {
    file();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort (a, a + n);
    ll i = 0, j = n - 1;
    while (i < j) {
        x += a[i];
        y += a[j];
        ++i, --j;
    }
    if (i == j) y += a[i];
    cout << x * x + y * y;
}


/**
4
4 * 4
2 * 2 + 2 * 2

3 3 1 1
3 + 3
1 + 1
6 * 6 + 2 * 2 = 36 + 4 = 40

*/
