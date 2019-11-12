#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        map< char, int > q;
        for(char j : s) q[j]++;
        for(char j : t) q[j]++;

        bool flag = true;
        for(auto j : q){
            if(j.second % 2 != 0) flag = false;
        }
        if(!flag) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;

        vector< pair< int, int > > ans;
        for(int j = 0; j < n; j++) {
            if(s[j] == t[j]) continue;
            bool fnd = false;
            for(int u = j + 1; u < n; u++) {
                if(s[u] == s[j]) {
                    ans.push_back({u, j});
                    //ans.push_back({j, u});
                    s[u] = t[j];
                    t[j] = s[j];
                    fnd = true;
                    break;
                }
            }
            if(fnd) continue;

            for(int u = j + 1; u < n; u++) {
                if(t[u] == s[j]) {
                    ans.push_back({u, u});
                    ans.push_back({u, j});
                    swap(t[u], s[u]);
                    s[u] = t[j];
                    t[j] = s[j];
                    break;
                }
            }
        }

        cout << ans.size() << endl;
        for(int j = 0; j < ans.size(); j++) {
            cout << ans[j].first + 1 << " " << ans[j].second + 1 << endl;
        }
    }
    return 0;
}
