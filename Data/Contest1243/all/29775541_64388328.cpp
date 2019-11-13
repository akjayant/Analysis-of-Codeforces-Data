#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int M = 30 + 10;
int cnt[M];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        memset(cnt, 0, sizeof cnt);
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
                v.push_back(i);
        bool ok = true;
        for (int i = 0; i < 26; i++)
            if (cnt[i] % 2)
                ok = false;
        if (!ok)
            cout << "No\n";
        else {
            cout << "Yes\n";
            vector<pii> ans;
            for (int i = 0; i < v.size(); i++) {
                if (s[v[i]] != t[v[i]]) {
                    for (int j = i + 1; j < v.size(); j++) {
                        if (s[v[i]] == s[v[j]]) {
                            ans.push_back({v[j], v[i]});
                            swap(s[v[j]], t[v[i]]);
                            break;
                        }
                        else if (s[v[i]] == t[v[j]]) {
                            ans.push_back({v[j], v[j]});
                            swap(s[v[j]], t[v[j]]);
                            ans.push_back({v[j], v[i]});
                            swap(s[v[j]], t[v[i]]);
                            break;
                        }
                    }
                }    
            }
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
        }
    }
    return 0;
}