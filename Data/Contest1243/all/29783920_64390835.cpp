#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int k;
    cin >> k;
    for (int t1 = 0; t1 < k; t1++){
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        vector< pair<int, int> > v;
        int ck = 0;
        for (int i = 0; i < n - 1; i++){
            if (s[i] == t[i]){
                continue;
            }
            int r = (int)v.size();
            for (int j = i + 1; j < n && r == (int)v.size(); j++){
                if (s[j] == s[i]){
                    v.push_back(make_pair(j + 1, i + 1));
                    swap(s[j], t[i]);
                }
            }
            for (int j = i + 1; j < n && r == (int)v.size(); j++){
                if (s[i] == t[j]){
                    v.push_back(make_pair(i + 1 + 1, j + 1));
                    swap(s[i + 1], t[j]);
                    v.push_back(make_pair(i + 1 + 1, i + 1));
                    swap(s[i + 1], t[i]);
                }
            }
            if (r == (int)v.size()){
                ck = 1;
                cout << "No\n";
                break;
            }
        }
        if (ck == 0 && s[n - 1] == t[n - 1]){
            cout << "Yes\n";
            cout << v.size() << "\n";
            for (int i = 0; i < v.size(); i++){
                cout << v[i].first << " " << v[i].second << "\n";
            }
        }
        if (ck == 0 && s[n - 1] != t[n - 1]){
            cout << "No\n";
        }
    }



}

