#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int k,n;
    string s,t;
    vector<int> v;
    cin>>k;
    while(k--){
        cin>>n;
        cin>>s>>t;
        v.clear();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]) v.push_back(i);
        }
        if(v.empty()) cout<<"Yes\n";
        else if(v.size()==1) cout<<"No\n";
        else if(v.size()==2){
            if(s[v[0]]==s[v[1]] && t[v[1]]==t[v[0]]) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"No\n";
    }
    return 0;
}
