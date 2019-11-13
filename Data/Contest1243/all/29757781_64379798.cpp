#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
string s,t;
vector<int>v;
int main(){
    cin>>T;
    while(T--){
        v.clear();
        cin>>n>>s>>t;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                v.push_back(i);
            }
        }
        if(v.size()>2 || v.size()==1)cout<<"No\n";
        else {
            if(v.size()==0) cout<<"Yes\n";
            else {
                if(s[v[0]]==s[v[1]] && t[v[0]]==t[v[1]]) cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
    }
}
