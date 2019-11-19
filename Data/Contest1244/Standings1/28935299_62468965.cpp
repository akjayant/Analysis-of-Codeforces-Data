#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;
const int N=5e3+10, base=1e9+123;
int t,n;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>s;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') ans=max(ans,max(2*(i+1),2*(n-i)));
        }
        if(!ans) ans=n;
        cout<<ans<<'\n';
    }
    return 0;
}
