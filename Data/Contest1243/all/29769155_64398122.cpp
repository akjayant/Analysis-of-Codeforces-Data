#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s1,s2;
        cin >> n >> s1 >> s2;
        vector<pair<int,int>> ans; 
        bool ret = true;
        for(int i = 0 ; i < n ; i += 1){
            if(s1[i] == s2[i]){
                continue;
            }else{
                bool t = false;
                for(int j = i+1 ; j < n ; j += 1){
                    if(s1[i] == s1[j]){
                        ans.push_back({j,i});
                        swap(s2[i],s1[j]);
                        t = true;
                        break;
                    }
                }
                if(!t){
                    for(int j = i+1 ; j < n ; j += 1){
                        if(s2[j] == s1[i]){
                            ans.push_back({j,j});
                            swap(s1[j],s2[j]);
                            ans.push_back({j,i});
                            swap(s1[j],s2[i]);
                            t = true;
                            break;
                        }
                    }
                }
                if(!t){
                    ret = false;
                    break;
                }
            }
        }
        if(!ret){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl << ans.size() << endl;
            for(pair<int,int> i : ans){
                cout << i.first+1 << " " << i.second+1 << endl;
            }
        }
    }
}