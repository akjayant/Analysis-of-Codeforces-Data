#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        string s,t;
        cin >> n >> s >> t;

        if (s == t){
            cout << "No\n";
            continue;
        }
        
        int freq[26];
        memset(freq, 0, sizeof freq);
        for (int i=0; i<n; i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']++;
        }
        bool ok = true;
        for (int i=0; i<26; i++){
            if (freq[i] & 1){
                cout << "No\n";
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        cout << "Yes\n";

        vector<pair<int, int>> resp;
        for (int i=0; i<n; i++){
            if (s[i] == t[i]) continue;
            else{
                int j;
                for (j=i+1; j<n; j++){
                    if (s[i] == t[j] || s[i] == s[j]) break;
                }
                if (s[i] == t[j]){
                    resp.push_back({j+1, j+1});
                    swap(s[j], t[j]);
                    resp.push_back({j+1, i+1});
                    swap(s[j], t[i]);
                } else{
                    resp.push_back({j+1, i+1});
                    swap(s[j], t[i]);
                }
            }
        }
        cout << resp.size() << endl;
        for (int i=0; i<resp.size(); i++){
            cout << resp[i].first << " " << resp[i].second << endl;
        }
    }
}