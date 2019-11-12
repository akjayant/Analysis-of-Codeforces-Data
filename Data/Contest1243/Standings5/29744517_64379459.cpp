#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 112;
const int M = 19;
const int MOD = 1e9 + 7;

signed main () {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;  
        int n;
        cin >> n;
        cin >> s1 >> s2;
        int p1 = -1, p2 = -1;
        bool f = 1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (p1 == -1) p1 = i;
                else if (p2 == -1) p2 = i;
                else f = 0;
            }
        }
        if (p2 == -1) f = 0;
        else {
            if (s1[p1] == s1[p2] && s2[p2] == s2[p1]);
            else f = 0;
        }
        if (f) cout << "Yes\n";
        else cout << "No\n";
    }    

}