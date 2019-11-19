#include<bits/stdc++.h>
#define int long long
using namespace std; const int maxn = 1e5+10;
typedef long long ll;
main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n,a=0,b=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int t;cin>>t;
            if(t&1) a++;
            else b++;
        }
        int m,c=0,d=0;
        cin>>m;
        for(int i=1;i<=m;i++){
            int t;cin>>t;
            if(t&1) c++;
            else d++;
        }
        ll ans=1ll*a*c+b*d;
        cout<<ans<<endl;
    }
    return 0;
}
