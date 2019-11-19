#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD=1e9+7;
 
//const int MOD=998244353;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        
        int a1=(a/c)+(bool)(a%c), a2=(b/d)+(bool)(b%d);
        
        if(a1+a2<=k) cout<<a1<<' '<<a2<<'\n';
        else cout<<-1<<'\n';
    }
    
   
    
    
    
    
    return 0;
}
