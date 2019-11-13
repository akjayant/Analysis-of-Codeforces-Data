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

const int N = 100005;
const int oo = 1000000007;

ll f[N];
int main() {
#ifdef THELAZYCAT
//    freopen("input.inp", "r", stdin);
    freopen("input.inp", "r", stdin);
//    freopen("output.out", "w", stdout);
#endif // THELAZYCAT

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0 << endl;
            return 0;
        }
    f[0] = f[1] = 1;
    for (int i = 2; i <= s.size(); ++i) f[i] = (f[i-1] + f[i-2]) % oo;
    ll ans = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'u' || s[i] == 'n') {
            int j = i;
            while (s[i] == s[j] && i < s.size()) ++i;
            int cnt = i-j;
            --i;
            ans *= f[cnt];
            ans %= oo;
        }
    }
    cout << ans << endl;
}