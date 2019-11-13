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

int a[N];
int main() {
#ifdef THELAZYCAT
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // THELAZYCAT

    int __;
    cin >> __;
    while (__--) {
        int n;
        cin >> n;
        // cout << "n = " << n << endl;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a+1, a+1+n);
        reverse(a+1, a+1+n);
        a[n+1] = 0;
        for (int i = 1; i <= n+1; ++i) {
            if (i > a[i]) {
                cout << i-1 << endl;
                break;
            }
        }
    }

}