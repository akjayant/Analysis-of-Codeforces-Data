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

ll n, m, k, a[305][305];

int main() {
    file();
    cin >> n;
    ll k = 1;
    ll p = 0;
    for (int j = 0; j < n; ++j) {
        if (p) {
            for (int i = n - 1; i >= 0; --i, ++k) {
                a[i][j] = k;
            }
            p = 0;
            continue;
        }
        for (int i = 0; i < n; ++i, ++k) {
            a[i][j] = k;
        }
        p = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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
