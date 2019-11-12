#include<bits/stdc++.h>
//#define int long long

typedef long long ll;
typedef long double ld;

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> lt(26, 0);
    for(char x : s){
        lt[x - 'a']++;
    }
    for(char x : t){
        lt[x - 'a']++;
    }
    for(int x : lt){
        if(x % 2){
            cout << "NO" << "\n";
            return;
        }
    }
    vector<pair<int, int> > ans;
    for(int i = 0 ;i < n; i++){
        if(s[i] == t[i]) continue;
        bool f = 0;
        for(int j = i + 1; j < n; j++){
            if(t[j] == s[i]){
                ans.push_back({j + 1, j + 1});
                swap(s[j], t[j]);
            }
            if(s[i] == s[j]){
                ans.push_back({j + 1, i + 1});
                swap(s[j], t[i]);
                break;
            }
        }
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << x.first << ' ' << x.second << "\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test =  1;
    cin >> test;
    while(test--){
        solve();
    }
}
