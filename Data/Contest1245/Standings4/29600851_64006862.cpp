#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int MAXN = 105;
const int INF = 0X3f3f3f3f;
const int MOD = 1e9+7;
char ans[MAXN];
int main(){
    int T; cin>>T;
    while(T--){
        int n,a,b,c; cin>>n>>a>>b>>c;
        string ss;
        cin>>ss;
        memset(ans,0,sizeof(ans));
        int R=0,S=0,P=0,cnt=0;
        int up = (n+1)/2;
        for(int i=0;i<n;i++){
            if(ss[i]=='R'){
                if(b)
                    ans[i] = 'P',cnt++,b--;
            }
            if(ss[i]=='P'){
                if(c)
                    ans[i] = 'S',cnt++,c--;
            }
            if(ss[i]=='S'){
                if(a)
                    ans[i] = 'R',cnt++,a--;
            }
        }
        if(cnt>=up){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
                if(ans[i]=='P' || ans[i]=='R' || ans[i]=='S') cout<<ans[i];
                else {
                    if(a) cout<<'R',a--;
                    else if(b) cout<<'P',b--;
                    else if(c) cout<<'S',c--;
                }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
