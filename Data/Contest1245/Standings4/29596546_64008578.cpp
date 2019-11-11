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

    int __;
    cin >> __;
    while (__--) {
        int n, ra, pa, sa;
        cin >> n >> ra >> pa >> sa;
        string s;
        cin >> s;
        int rb = 0, pb = 0, sb = 0;
        for (int i = 0; i < s.size(); ++i) {
            rb += (s[i] == 'R');
            pb += (s[i] == 'P');
            sb += (s[i] == 'S');
        }
        if (min(ra,sb)+min(pa,rb)+min(sa,pb)>=(n-1)/2+1) {
            cout << "YES" << endl;
            string ans = s;
            for (int i = 0; i < ans.size(); ++i) ans[i] = '*';
            for (int i = 0; i < s.size() && ra > 0; ++i)
                if (s[i] == 'S') {
                    ans[i] = 'R';
                    ra--;
                }
            for (int i = 0; i < s.size() && pa > 0; ++i)
                if (s[i] == 'R') {
                    ans[i] = 'P';
                    pa--;
                }
            for (int i = 0; i < s.size() && sa > 0; ++i)
                if (s[i] == 'P') {
                    ans[i] = 'S';
                    sa--;
                }
            // cout << ans << endl;
            // cout << ra << ' ' << sa << ' ' << pa << endl;
            for (int i = 0; i < ans.size(); ++i)
                if (ans[i] == '*') {
                    if (ra) ans[i] = 'R', --ra;
                    else if (pa) ans[i] = 'P', --pa;
                    else ans[i] = 'S', --sa;
                }
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}