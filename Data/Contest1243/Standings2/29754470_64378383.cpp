#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10, mod=1e9+7;
int tc,n;
string s, t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
        cin>>n>>s>>t;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]) v.push_back(i);
        }
        if(v.size()!=2){
            cout<<"No\n";
            continue;
        }
            char c=t[v[1]];
            t[v[1]]=s[v[0]];
            s[v[0]]=c;

        bool ok=1;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]) ok=0;
        }
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
