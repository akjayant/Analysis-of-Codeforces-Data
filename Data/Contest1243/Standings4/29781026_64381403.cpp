#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
vector<int>v1;
map<char,int>mp;

void solve(){
    string s,t;
    int n;
    cin >> n;
    cin >> s >> t;
    v1.clear();
    mp.clear();
    for(int i=0;i<n;i++){
        if(s[i] != t[i]){
            v1.push_back(i);
        }
    }
    if(v1.size() == 0){
        for(int i=0;i<n;i++){
            if(mp[s[i]] != 0){
                cout << "Yes" << endl;
                return;
            }
            mp[s[i]]++;
        }
        cout << "No" << endl;
        return;
    }
    if(v1.size() == 2){
        if(s[v1[0]] == s[v1[1]] && t[v1[1]] == t[v1[0]]) cout << "Yes" << endl;
        else cout << "No" << endl;
        return;
    }
    cout << "No" << endl;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}