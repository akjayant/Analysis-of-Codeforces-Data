#include<bits/stdc++.h>
using namespace std;
typedef long long ll;




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int q;
    cin>>q;
    while(q--){
        ll n;
        string s;
        cin>>n>>s;
        ll l=-1,r=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(l==-1) l = i;
                r=i;
            }
        }
        ll ans = n;
        if(l>=0){
            ans = max(ans,max(l + l+2, (n-l)*2));
        }
        if(r>=0){
            ans = max(ans, max(r+r+2,(n-r)*2));
        }
        cout << ans << "\n";

    }
}