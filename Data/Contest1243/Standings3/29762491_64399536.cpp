#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n;
        string s1, s2;
        cin >> n;
        cin >> s1 >> s2;
        int cnt[26]={};
        for(int i=0;i<n;++i) {
            ++cnt[s1[i]-'a'];
            ++cnt[s2[i]-'a'];
        }
        int flag=0;
        for(int i=0;i<26;++i)
            if(cnt[i]%2) flag=1;
        if(flag) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        vector<pair<int,int> > ans;
        for(int i=0;i<n;++i) {
            if(s1[i]!=s2[i]) {
                flag=0;
                for(int j=i+1;j<n;++j)
                    if(s1[i]==s1[j]) {
                        swap(s1[j],s2[i]);
                        ans.push_back({j,i});
                        flag=1;
                        break;
                    }
                if(flag) continue;
                for(int j=i+1;j<n;++j)
                    if(s1[i]==s2[j]) {
                        swap(s1[j],s2[j]);
                        ans.push_back({j,j});
                        swap(s1[j],s2[i]);
                        ans.push_back({j,i});
                        break;
                    }
            }
        }
        cout << ans.size() << endl;
        for(auto it:ans)
            cout << it.first+1 << " " << it.second+1 << endl;
        
    }
}
