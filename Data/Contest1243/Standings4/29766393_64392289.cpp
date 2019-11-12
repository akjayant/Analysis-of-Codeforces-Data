#include<bits/stdc++.h>
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    auto ans = vector<pair<int, int>>{};
    for(auto i = 0; i < n; ++i) {
        if(s[i] == t[i])
            continue;
        
        auto c = t[i];
        auto pos = find(t.begin() + i + 1, t.end(), c);
        if(pos != t.end()) {
            int idx = pos - t.begin();
            swap(s[i], t[idx]);
            ans.push_back({i + 1, idx + 1});
            continue;
        }

        pos = find(s.begin() + i + 1, s.end(), c);
        if(pos != s.end()) {
            int idx = pos - s.begin();
            swap(s[idx], t[idx]);
            swap(s[i], t[idx]);
            ans.push_back({idx + 1, idx + 1});
            ans.push_back({i + 1, idx + 1});
            continue;
        }

        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for(auto& p : ans)
        cout << p.first << " " << p.second << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
    for(auto i = 0; i < t; ++i)
        solve();
}