#include <bits/stdc++.h>
#define fi first
#define se second
using ll = long long;
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<pair<char, char>> bad;
        for(int i = 0; i < n; ++i) {
            if(s[i] != t[i]) {
                bad.push_back({s[i], t[i]}); 
            }
        }
        if(bad.size() == 0) {
            cout << "Yes\n";
        } else if(bad.size() == 2) {
            cout << (bad.front() == bad.back() ? "Yes" : "No") << '\n'; 
        } else {
            cout << "No\n";
        }
    }
}
