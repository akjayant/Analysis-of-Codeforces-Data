#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> cnt_s(26,0), cnt_t(26,0);
    for(int i=0;i<n;i++) cnt_s[s[i]-'a']++;
    for(int i=0;i<n;i++) cnt_t[t[i]-'a']++;


    for(int i=0;i<26;i++) {
        if(cnt_s[i]%2!=cnt_t[i]%2) {
            cout << "No\n";
            return;
        }
    }

    int cnt = 0;
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++) {
        if(s[i]==t[i]) continue;
        else {
            bool flag = false;
            for(int j=i+1;j<n;j++) {
                
                if(s[j]==s[i]) {
                    cnt_t[t[i]-'a']--;
                    cnt_s[s[j]-'a']--;

                    swap(s[j],t[i]);
                    ans.push_back({j+1,i+1});
                    cnt_t[t[i]-'a']++;
                    cnt_s[s[j]-'a']++;
                    flag = true;
                    break;
                }
            }

            if(!flag) {
                for(int j=i+1;j<n;j++) {
                
                    if(t[j]==s[i]) {
                        cnt_t[t[j]-'a']--;
                        cnt_s[s[i+1]-'a']--;

                        swap(s[i+1],t[j]);
                        ans.push_back({i+2,j+1});
                        cnt_t[t[j]-'a']++;
                        cnt_s[s[i+1]-'a']++;

                        cnt_t[t[i]-'a']--;
                        cnt_s[s[i+1]-'a']--;

                        swap(s[i+1],t[i]);
                        ans.push_back({i+2,i+1});
                        cnt_t[t[i]-'a']++;
                        cnt_s[s[i+1]-'a']++;
                        break;
                    }
                }

            }
        }
    }

    cout << "Yes\n";
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }


    return 0;
}