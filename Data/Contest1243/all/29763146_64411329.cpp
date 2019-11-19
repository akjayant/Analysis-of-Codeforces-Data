#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=200010;
const int INF=0x3f3f3f3f;
int Laxt[maxn],Next[maxn],To[maxn],dis[maxn],num[maxn];
int q[maxn],tot,cnt,S,N;
void add(int u,int v){
    Next[++cnt]=Laxt[u]; Laxt[u]=cnt; To[cnt]=v;
}
void BFS(int s)
{
    dis[s]=0;
    set<int>S1,S2;
    set<int>::iterator it;
    queue<int>q;
    q.push(s);
    rep(i,1,N) if(i!=s&&dis[i]==INF) S1.insert(i);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=Laxt[u];i;i=Next[i]){
            int v=To[i]; if(S1.find(v)==S1.end()) continue;
            S1.erase(v); S2.insert(v);
        }
        for(it=S1.begin();it!=S1.end();it++) dis[*it]=dis[u]+1,q.push(*it);
        S1.swap(S2); S2.clear();
    }
}
int main()
{
    memset(dis,0x3f,sizeof(dis));
    int M,u,v;
    scanf("%d%d",&N,&M);
    rep(i,1,M){
        scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }
    int cnt=0;
    for(int i=1;i<=N;i++){
        if(dis[i]==INF){
            BFS(i);
            cnt++;
        }
    }
    printf("%d\n",cnt-1);
}