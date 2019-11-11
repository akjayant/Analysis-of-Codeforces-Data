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

int gcd(int a, int b) {
    while (b) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
#ifdef THELAZYCAT
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // THELAZYCAT
    int __;
    cin >> __;
    while (__--) {
        int a,b;
        cin >> a >> b;
        cout << ((gcd(a,b) == 1) ? "Finite" : "Infinite") << endl;
    }


}