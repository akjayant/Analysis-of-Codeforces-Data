#include <bits/stdc++.h>
 
using namespace std;

int f[20000];

int main(){
    int t;
    cin >>t;
    vector <int> poses;
    while (t--){
        string s, t;
        int n;
        cin >>n;
        cin >>s >>t;
        poses.clear();
        for (int i=0; i<n; ++i){
            f[i] = s[i] == t[i];
            if (f[i] == 0){
                poses.push_back(i);
            }
        }
        if (poses.size() == 1 || poses.size() > 2){
            cout <<"No\n";
            continue;
        } else if (s[poses[0]] == s[poses[1]] && t[poses[1]] == t[poses[0]]){
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }
    }
    return 0;
}
