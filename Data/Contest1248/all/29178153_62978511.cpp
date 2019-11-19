#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
int a[100007],b[100007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ji=0,jiji=0,ou=0,ouou=0;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            if(a[i]&1)
                ++ji;
            else
                ++ou;
        }
        int m;
        cin>>m;
        for(int i=1;i<=m;++i){
            cin>>b[i];
            if(b[i]&1)
                ++jiji;
            else
                ++ouou;
        }
        long long ans=0;
        ans=1ll*ji*jiji+1ll*ou*ouou;
        cout<<ans<<"\n";
    }
    return 0;
}
