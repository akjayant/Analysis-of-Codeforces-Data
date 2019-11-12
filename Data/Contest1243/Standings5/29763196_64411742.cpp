#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;

int main() {
    //freopen("in","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s,t;
        cin >> n >> s >> t;
        map<char,int> cnt;
        for(int i = 0;i < n;++i) {
            cnt[s[i]]++;
            cnt[t[i]]++;
        }
        bool f = 1;
        for(auto p : cnt) {
            if(p.second & 1) {
                f = 0;
                break;
            }
        }
        if(!f) {
            cout << "No\n";
            continue;
        }
        vector<pair<int,int>> ans;
        for(int i = 0;i < n;++i) {
            if(s[i] == t[i]) continue;
            for(int j = i + 1;j < n;++j) {
                if(s[j] == s[i]) {
                    swap(s[j],t[i]);
                    ans.push_back(make_pair(j,i));
                    break;
                } else if(t[j] == s[i]) {
                    swap(s[j],t[j]);
                    ans.push_back(make_pair(j,j));
                    swap(s[j],t[i]);
                    ans.push_back(make_pair(j,i));
                    break;
                }
            }
        }
        cout << "Yes\n" << ans.size() << '\n';
        for(auto p : ans) {
            cout << ++p.first << ' ' << ++p.second << '\n';
        }
    }
    return 0;
}