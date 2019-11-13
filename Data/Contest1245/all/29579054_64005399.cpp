#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=100+7;
char ans[maxn],S[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n,r,p,s;
        scanf("%d",&n);
        scanf("%d %d %d",&r,&p,&s);
        memset(ans,0,sizeof(ans));
        scanf("%s",S+1);
        int res=n;
        for(int i=1;i<=n;i++){
            if(S[i]=='R'&&p)ans[i]='P',p--;
            else if(S[i]=='P'&&s)ans[i]='S',s--;
            else if(S[i]=='S'&&r)ans[i]='R',r--;
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==0){
                res--;
                if(r)r--,ans[i]='R';
                else if(p)p--,ans[i]='P';
                else if(s)s--,ans[i]='S';
            }
        }
        if(res>=(n+1)/2){
            printf("YES\n");
            printf("%s\n",ans+1);
        }else printf("NO\n");
    }
    return 0;
}
