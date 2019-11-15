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
        // vector<int> v;
        map<char, int> m1, m2;
        m1.clear();
        m2.clear();
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                m1[s[i]]++;
                m2[t[i]]++;
            }
        }
        bool flag = true;
        for (char ch = 'a'; ch <= 'z'; ++ch)
            if ((m1[ch] + m2[ch]) % 2 == 1) {
                flag = false;
                break;
            }
        if (!flag) {
            cout << "No\n";
            continue;
        }
        vector<II> ans;
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) continue;
            for (int j = i+1; j < n; ++j) {
                if (s[j] == t[j]) continue;
                if (s[j] == s[i]) {
                    swap(s[j], t[i]);
                    ans.push_back(make_pair(j, i));
                    break;
                } else if (t[j] == s[i]) {
                    swap(s[j], t[j]);
                    ans.push_back(make_pair(j, j));
                    swap(s[j], t[i]);
                    ans.push_back(make_pair(j, i));
                    break;
                }
            }
        }
        cout << "Yes\n";
        cout << ans.size() << endl;
        for (auto p : ans) cout << p.first+1 << ' ' << p.second+1 << endl;
        // if (v.size() > 2 || v.size() == 1) {
        //     cout << "No\n";
        // } else if (v.size() == 2) {
        //     if (s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]]) cout << "Yes\n";
        //     else cout << "No\n";
        // } else {
        //     cout << "Yes\n";
        // }
    }

}