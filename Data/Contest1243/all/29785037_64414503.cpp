#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>g[N];
int p[N];
int Find(int x){return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x,int y){x=Find(x);y=Find(y);p[x]=y;}
int n,m,deg[N];
bool used2[N],used[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    int best,mn=1e5+5;
    for(int i=1;i<=n;i++){
        p[i]=i;
        int x=i;
        if(deg[x]<mn){
            mn=deg[x];
            best=x;
        }
        used[x]=true;
    }
    //printf("ok\n");
    used[best]=false;
    for(auto&y:g[best]){
        used[y]=false;
    }
    for(int i=1;i<=n;i++){
        if(used[i])
            Union(i,best);
    }
    for(auto&y:g[best]){
        for(int i=1;i<=n;i++){
            used2[i]=true;
        }
        for(auto&z:g[y]){
            used2[z]=false;
        }
        for(int i=1;i<=n;i++){
            if(used2[i]&&(Find(y)!=Find(i))){
                Union(y,i);
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        //printf("i:%d Find(i):%d\n",i,Find(i));
        if(i==Find(i)){
            cnt++;
        }
    }
    printf("%d\n",cnt-1);
    return 0;
}
