#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int q;
    cin >> q;
    for (int z = 0;z < q;++z) {
        int n;
        string s,t;
        cin >> n >> s >> t;
        int cnt[26];
        bool ng = false;
        for (int i = 0;i < 26;++i) cnt[i] = 0;
        for (int i = 0;i < n;++i) cnt[s[i]-'a']++;
        for (int i = 0;i < n;++i) cnt[t[i]-'a']++;
        for (int i = 0;i < 26;++i) if (cnt[i]&1) {
            cout << "No" << "\n";
            ng = true;
            break;
        }
        if (ng) continue;
        cout << "Yes" << "\n";
        vector<P> ans;
        for (int i = 0;i < n;++i) if (s[i] != t[i]) {
            bool ok = false;
            for (int j = i+1;j < n;++j) if (t[i] == t[j]) {
                ok = true;
                ans.push_back(P(i,j));
                swap(s[i],t[j]);
                break;
            }
            if (!ok) {
                for (int j = i+1;j < n;++j) if (t[i] == s[j]) {
                    ans.push_back(P(j,j));
                    ans.push_back(P(i,j));
                    swap(s[j],t[j]);
                    swap(s[i],t[j]);
                    break;
                }
            }

        }
        cout << ans.size() << "\n";
        for (P& p : ans) cout << p.first+1 << " " << p.second+1 << "\n";
    }
}