#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD=1e9+7;
 
//const int MOD=998244353;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(s.find('1')==-1){
            cout<<n<<'\n';
            continue;
        }
        int md=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                md=max(md,max(i+1,n-i));
            }
        }
        cout<<2*md<<'\n';
        
        
    }
    
    
    
    return 0;
}
