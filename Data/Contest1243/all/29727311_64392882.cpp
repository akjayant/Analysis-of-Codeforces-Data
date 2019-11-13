#include <bits/stdc++.h>
 
using namespace std;

int f[20000];

int main(){
    int t;
    cin >>t;
    vector <pair <int, int> > ans;
    map <int, int> mp;
    while (t--){
        string s, t;
        int n;
        cin >>n;
        cin >>s >>t;
        mp.clear();
        ans.clear();
        for (int i=0; i<n; ++i){
            mp[s[i]]++;
            mp[t[i]]++;
        }
        bool nt = false;
        for (auto it = mp.begin(); it != mp.end(); ++it){
            if (it -> second & 1){
                nt = true;
                break;
            }
        }
        if (nt){
            cout <<"No\n";
        } else {
            for (int i=0; i<n; ++i){
                if (s[i] != t[i]){
                    for (int pos = i + 1; pos < n; ++pos){
                        if (s[pos] != t[pos]){
                            if (s[pos] == s[i]){
                                swap(s[pos], t[i]);
                                ans.push_back({pos + 1, i + 1});
                                break;
                            } else if (t[pos] == s[i]){
                                swap(s[n - 1], t[pos]);
                                swap(s[n - 1], t[i]);
                                ans.push_back({n, pos + 1});
                                ans.push_back({n, i + 1});
                                break;
                            }
                        }
                    }
                }
            }
            cout <<"Yes\n";
            cout <<ans.size() <<'\n';
            for (int i=0; i<ans.size(); ++i){
                cout <<ans[i].first <<' ' <<ans[i].second <<'\n';
            }
        }
    }
    return 0;
}
