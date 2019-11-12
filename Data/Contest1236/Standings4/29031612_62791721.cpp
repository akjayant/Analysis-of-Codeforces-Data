#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    ll q;
    cin>>q;
    while(q--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans = 0;
        for(ll i=0;i<=a;i++){
            for(ll j=0;2*i+j<=b;j++){
                if(2*j<=c){
                    ans = max(ans,i+2*i+j+2*j);
                }
            }
        }
        cout << ans << "\n";
    }
    
    
    
}