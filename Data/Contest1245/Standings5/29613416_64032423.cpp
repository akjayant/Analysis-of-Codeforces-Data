#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
char ch[N];
int num[3][N],top[3],sl[2][N],tl[2],pl[N],col[N];
void mian()
{
    int n,s[3],t[3],ans=0;scanf("%d%d%d%d",&n,&s[0],&s[1],&s[2]);
    for(int i=1;i<=n;i++)pl[i]=-1;
    t[0]=t[1]=t[2]=top[0]=top[1]=top[2]=tl[0]=tl[1]=0;scanf("%s",ch+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        if(ch[i]=='R')x=0;
        if(ch[i]=='P')x=1;
        if(ch[i]=='S')x=2;
        t[x]++;num[x][++top[x]]=i;
        col[i]=x;
    }
    for(int i=0;i<3;i++)
    {
        int j=(i+2)%3;
        if(s[i]>=t[j])
        {
            ans+=t[j];s[i]-=t[j];t[j]=0;
            top[j]=0;
        }
        else
        {
            ans+=s[i];t[j]-=s[i];top[j]-=s[i];
            s[i]=0;
        }
    }
    if(ans>=(n+1)/2)printf("YES\n");
    else {printf("NO\n");return ;}
    for(int i=0;i<3;i++)
    {
        for(int j=1;j<=top[i];j++)sl[0][++tl[0]]=num[i][j];
        for(int j=1;j<=s[i];j++)sl[1][++tl[1]]=i;
    }
    for(int i=1;i<=tl[0];i++)pl[sl[0][i]]=sl[1][i];
    for(int i=1;i<=n;i++)
    {
        int x;char cc;
        if(pl[i]==-1)x=(col[i]+1)%3;
        else x=pl[i];
        if(x==0)cc='R';
        if(x==1)cc='P';
        if(x==2)cc='S';
        printf("%c",cc);
    }
    printf("\n");
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)mian();
}
