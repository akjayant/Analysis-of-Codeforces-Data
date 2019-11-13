#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
#define fi first
#define se second
#define pb push_back
int t,n,a,b,c,q[N];
char d[N],ans[N];
int main() {
    ios::sync_with_stdio(false);
    for(cin>>t;t;t--){
        cin>>n>>a>>b>>c>>d+1;int tot=0;
        for(int i=1;i<=n;i++)q[i]=0;
        for(int i=1;i<=n;i++){
            if(d[i]=='R'){
                if(b>0){
                    q[i]=1;
                    b--;
                    tot++;
                    ans[i]='P';
                }
            }else if(d[i]=='P'){
                if(c>0){
                    c--;
                    q[i]=1;
                    tot++;
                    ans[i]='S';
                }
            }else{
                if(a>0){
                    a--;
                    q[i]=1;
                    tot++;
                    ans[i]='R';
                }
            }
        }
        if(tot*2>=n){
            cout<<"YES\n";
            for(int i=1;i<=n;i++){
                if(!q[i]){
                    if(a>0){
                        ans[i]='R';
                        a--;
                    }else if(b>0){
                        ans[i]='P';
                        b--;
                    }else{
                        c--;
                        ans[i]='S';
                    }
                }
            }
            for(int i=1;i<=n;i++)cout<<ans[i];
            cout<<endl;
        }else cout<<"NO\n";
    }
    return 0;
}