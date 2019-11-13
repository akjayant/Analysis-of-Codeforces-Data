#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
vector<int>v1,v2;
map<char,int>mp;

void solve(){
    string s,t;
    int n;
    cin >> n;
    cin >> s >> t;
    mp.clear();
    v1.clear();
    v2.clear();
    for(int i=0;i<n;i++){
        mp[s[i]]++;
        mp[t[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp[s[i]] % 2 != 0 || mp[t[i]] % 2 != 0){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    for(int i=0;i<n;i++){
        if(s[i] != t[i]){
            int flg = 0;
            for(int j=i+1;j<n;j++){
                if(s[j] == s[i]){
                    v1.push_back(j+1);
                    v2.push_back(i+1);
                    swap(s[j],t[i]);
                    flg = 1;
                    break;
                }
            }
            if(flg == 0){
                for(int j=i+1;j<n;j++){
                    if(t[j] == s[i]){
                        // cout << t[j] << ' ' << s[i] << endl;
                        v1.push_back(n);
                        v2.push_back(j+1);
                        swap(s[n-1],t[j]);
                        v1.push_back(n);
                        v2.push_back(i+1);
                        swap(s[n-1],t[i]);
                        flg = 1;
                        break;
                    }
                }
            }
        }
    }
    // cout << s << ' ' << t << endl;
    cout << v1.size() << endl;
    for(int i=0;i<v1.size();i++){
        cout << v1[i] << ' ' << v2[i] << endl;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}