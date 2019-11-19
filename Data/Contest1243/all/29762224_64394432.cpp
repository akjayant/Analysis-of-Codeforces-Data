#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int head[100010],to[4000010],nxt[4000010],cnt;
int l[100010],r[100010];
bool used[100010];
bool tmp[100010];
int sum[100010];
inline void insert(int x,int y){to[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void del(int x){used[x]=1,r[l[x]]=r[x],l[r[x]]=l[x];}
int main()
{
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){cin>>a>>b;insert(a,b);insert(b,a);}
    queue<int>line;
    int he=1,ta=n;
    for(int i=1;i<=n;i++)l[i]=i-1,r[i]=i+1;r[n]=0;
    for(int i=1;i<=n;i++)if(!used[i]){
        del(i);++ans;
        line.push(i);
        while(!line.empty()){
            int u=line.front();line.pop();
            for(int j=head[u];j;j=nxt[j])tmp[to[j]]=1;
            for(int j=r[0];j;j=r[j])if(!tmp[j]&&!used[j])line.push(j),++sum[ans],del(j);
            for(int j=head[u];j;j=nxt[j])tmp[to[j]]=0;
        }
    }
    sort(sum+1,sum+ans+1);
    printf("%d\n",ans-1);
    return 0;
}