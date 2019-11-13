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

    int __; cin >> __;
    while (__--) {
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) v.push_back(i);
        }
        if (v.size() > 2 || v.size() == 1) {
            cout << "No\n";
        } else if (v.size() == 2) {
            if (s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]]) cout << "Yes\n";
            else cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

}