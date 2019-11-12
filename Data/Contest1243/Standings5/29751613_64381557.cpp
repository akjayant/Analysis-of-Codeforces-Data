#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        string s, t;
        cin>>s>>t;
        vector<char> sv;
        vector<char> tv;
        bool br = 0;
        for (int i=0; i<n; i++){
            if (s[i] != t[i]){
                if (sv.size() >= 2){
                    br = 1;
                    break;
                }
                if (sv.size() == 1){
                    if (sv.back() != s[i] || tv.back()!= t[i]){
                        br = 1;
                        break;
                    }
                }
                sv.push_back(s[i]);
                tv.push_back(t[i]);
            }
        }
        if (br || sv.size()==1){
            cout<<"No"<<endl;
        } else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
