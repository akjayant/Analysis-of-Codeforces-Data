#include<bits/stdc++.h>
#define rep(i,b,e) for(LL i=(b);i<(e);++i)
#define dep(i,b,e) for(LL i=(b);i>=(e);--i)
#define LL long long

using namespace std;

int t,a,c,b,n;string s;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>c>>s;
        int bt=0;string ans;
        rep(i,0,n) ans+='0';
        rep(i,0,n){
            if(s[i]=='R'&&b) bt++,b--,ans[i]='P';
            if(s[i]=='P'&&c) bt++,c--,ans[i]='S';
            if(s[i]=='S'&&a) bt++,a--,ans[i]='R';
        }
        rep(i,0,n){
            if(ans[i]=='0'){
                if(a) ans[i]='R',a--;
                else if(b) ans[i]='P',b--;
                else ans[i]='S',c--;
            }
        }
        if(bt>=n-bt) cout<<"YES"<<endl<<ans<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}
