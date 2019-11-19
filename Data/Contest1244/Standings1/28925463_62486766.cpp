#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;

int n,K;
char str[M],tmp[M];

void Operator()
{
    for(int i=1;i<=n;i++)
    {
        int l=i==1?n:i-1;
        int r=i==n?1:i+1;
        int cnt=(str[i]=='W')+(str[l]=='W')+(str[r]=='W');
        tmp[i]=cnt>=2?'W':'B';
    }
    for(int i=1;i<=n;i++)str[i]=tmp[i];
    // printf("%s\n",str+1);
}

bool Ty[M];
int Pre[M],Pref[M],Nxt[M],Nxtf[M];
void dfs_Pre(int pos)
{
    int r=pos==n?1:pos+1;
    if(Ty[r])return;
    Pre[r]=Pre[pos]+1;Pref[r]=Pref[pos];
    dfs_Pre(r);
}
void dfs_Nxt(int pos)
{
    int l=pos==1?n:pos-1;
    if(Ty[l])return;
    Nxt[l]=Nxt[pos]+1;Nxtf[l]=Nxtf[pos];
    dfs_Nxt(l);
}

void Solve()
{
    for(int i=1;i<=n;i++)
    {
        int l=i==1?n:i-1;
        int r=i==n?1:i+1;
        int cnt=(str[i]=='W')+(str[l]=='W')+(str[r]=='W');
        Ty[i]=(str[i]==(cnt>=2?'W':'B'));
    }
    bool f=false;
    for(int i=1;i<=n;i++)f|=Ty[i];
    if(!f){if(K&1)Operator();printf("%s\n",str+1);return;}
    for(int i=1;i<=n;i++)
    {
        if(!Ty[i])continue;
        Pre[i]=0;Pref[i]=i;dfs_Pre(i);
        Nxt[i]=0;Nxtf[i]=i;dfs_Nxt(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(Ty[i])continue;
        if(Pre[i]<=K && Pre[i]<=Nxt[i])str[i]=str[Pref[i]];
        else if(Nxt[i]<=K && Nxt[i]<=Pre[i])str[i]=str[Nxtf[i]];
        else if(K&1)str[i]^='B'^'W';
    }
    printf("%s\n",str+1);
}

char tbl[M];
void Baoli_Solve()
{
    for(int i=1;i<=n;i++)tbl[i]=str[i];
    for(int i=1;i<=K;i++)Operator();
    printf("%s\n",str+1);
    for(int i=1;i<=n;i++)str[i]=tbl[i];
}

int main()
{
    scanf("%d%d%s",&n,&K,str+1);
    // Baoli_Solve();
    Solve();
    return 0;
}