#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Mx=1e5+10;
int n,ans[Mx],link[Mx][2],de[Mx],ty;
LL dp[Mx][3],c[Mx][3],vans;
void addEdge(int x,int y){
    if(de[x])link[x][1]=y;else link[x][0]=y;de[x]++;
    if(de[y])link[y][1]=x;else link[y][0]=x;de[y]++;
}
int main(){
    scanf("%d",&n);
    for(int t=0;t<3;t++)
        for(int i=1;i<=n;i++)scanf("%lld",&c[i][t]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addEdge(x,y);
    }
    for(int i=1;i<=n;i++)if(de[i]>=3)return puts("-1"),0;
    int st=1,pre;
    for(int i=1;i<=n;i++)
        if(de[i]==1)st=i;
    pre=link[st][0];
    vans=LLONG_MAX;
    LL tmpans=0;
    int pr,x,now;
    int prc,nowc;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j)continue;
            tmpans=0;
            tmpans+=c[st][i];
            tmpans+=c[pre][j];
            pr=st,x,now=pre;
            prc=i,nowc=j;
            while(de[now]!=1){
                if(pr==link[now][0])x=link[now][1];
                else x=link[now][0];
                int colx=3-prc-nowc;
                tmpans+=c[x][colx];
                prc=nowc;
                nowc=colx;
                pr=now;
                now=x;
            }
            if(tmpans<vans){
                vans=tmpans;
                ty=i*3+j;
            }
        }
    }
    pr=st;now=pre;
    prc=ty/3,nowc=ty%3;
    ans[st]=prc;ans[pre]=nowc;
    while(de[now]!=1){
        if(pr==link[now][0])x=link[now][1];
        else x=link[now][0];
        int colx=3-prc-nowc;
        tmpans+=c[x][colx];
        prc=nowc;
        nowc=colx;
        ans[x]=colx;
        pr=now;
        now=x;
    }
    printf("%lld\n",vans);
    for(int i=1;i<=n;i++)printf("%d ",ans[i]+1);
}