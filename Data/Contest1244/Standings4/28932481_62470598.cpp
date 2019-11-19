#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s , v;
        cin>>s;
        v = s;
        reverse(v.begin() , v.end());
        int ss = 1e9 , vv = 1e9;
        for(int i = 0;i<n;i++){
            if(s[i] == '1'){
                ss = i;
                break;
            }
        }
        for(int i = 0;i<n;i++){
            if(v[i] == '1'){
                vv = i;
                break;
            }
        }
        if(ss == 1e9){
            cout<<n<<'\n';
        }else{
            cout<<2*(n-min(ss, vv))<<'\n';
        }
    }
    return 0;
}