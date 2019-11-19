#include<bits/stdc++.h>
#define rap(i,s,n) for(int i=s;i<=n;i++)
#define drap(i,n,s) for(int i=n;i>=s;i--)
using namespace std;
char s[1010];
int main(){
    int T; cin>>T; while(T--){
        int n;
        scanf("%d",&n); scanf("%s",s+1);
        int l=-1,r=-1,ans=n;
        rap(i,1,n) if(s[i]=='1') {l=i; break;}
        drap(i,n,1) if(s[i]=='1') {r=i; break;}
        if(l!=-1) ans=max(ans,(n-l+1)*2);
        if(r!=-1) ans=max(ans,r*2);
        printf("%d\n",ans);
    }
}