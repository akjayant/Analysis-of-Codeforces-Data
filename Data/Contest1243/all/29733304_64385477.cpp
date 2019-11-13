#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        string s , t;
        cin >> s >> t;
        int flag = 0;
        string pre = "";
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] != t[i]){
                if(pre.empty()){
                    pre += s[i];
                    pre += t[i];
                }
                else{
                    string req = "";
                    req += s[i];
                    req += t[i];
                    if(req != pre){
                        flag = 1;
                        break;
                    }
                }
                ++cnt;
                if(cnt > 2){
                    flag = 1;
                }
            }
        }
        if(cnt == 1){
            flag = 1;
        }
        if(flag == 0){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
return 0;
}
