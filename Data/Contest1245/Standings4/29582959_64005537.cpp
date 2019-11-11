#include<bits/stdc++.h>
using namespace std;
int n,Q,r,p,s,ans;
bool vis[105];
char a[105],b[105];
int main(){
    scanf("%d",&Q);
    while (Q--){
        scanf("%d",&n);
        ans=0;
        scanf("%d%d%d",&r,&p,&s);
        for (int i=0;i<=n;i++)scanf("%c",&a[i]);
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++){
            if (a[i]=='R'&&p>0){
                p--;b[i]='P';vis[i]=1;ans++;
            }else if (a[i]=='P'&&s>0){
                s--;b[i]='S';vis[i]=1;ans++;
            }else if (a[i]=='S'&&r>0){
                r--;b[i]='R';vis[i]=1;ans++;
            }
        }
        for (int i=1;i<=n;i++)
            if (!vis[i]){
                if (r>0){
                    r--;b[i]='R';
                }else if (s>0){
                    s--;b[i]='S';
                }else{
                    p--;b[i]='P';
                }
            }
        if (ans>=(n+1)/2){
            printf("YES\n");
            for (int i=1;i<=n;i++)printf("%c",b[i]);
            printf("\n");
        }else printf("NO\n");
    }
    return 0;
}