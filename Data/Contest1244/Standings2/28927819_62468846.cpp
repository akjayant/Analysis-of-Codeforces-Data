#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std;
char s[1007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cin>>s+1;
        int ans=0;
        for(int i=1;i<=n;++i){
            if(s[i]=='1'){
                int tamp=max(i,n-i+1);
                ans=max(ans,tamp);
            }
        }
        ans*=2;
        ans=max(ans,n);
        cout<<ans<<"\n";
    }
    return 0;
}
