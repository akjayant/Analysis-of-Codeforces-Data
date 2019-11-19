#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n;
        ll x=0,y=0;
        for(int i=1;i<=n;i++){
            ll ss;
            scanf("%lld",&ss);
            if(ss%2==1) y++;
            else x++;
        }
        ll xx=0,yy=0;
        cin>>m;
        for(int i=1;i<=m;i++){
            ll u;
            scanf("%lld",&u);
            if(u%2==0) xx++;
            else yy++;
        }
        ll ans=0;
        ans+=xx*x+yy*y;
        cout<<ans<<endl;
    }
    return 0;
}
