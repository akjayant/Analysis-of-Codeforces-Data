#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int fa[N],vis[N],n,m;
vector<int>g[N],ans;
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void Bfs(int s){
  queue<int>q;q.push(s),fa[s]=find(s+1);
  ans.push_back(1);
  while(q.size()){
    int x=q.front();q.pop();
    for(auto v:g[x]) vis[v]=x;
    for(int i=find(1);i<=n;i=find(i+1))if(vis[i]!=x){
    	fa[i]=find(i+1);
		q.push(i);
		ans.back()++;
	}
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i=1;i<=m;i++) {
    int x,y;
	scanf("%d%d",&x,&y);
    g[x].push_back(y),g[y].push_back(x);
  }
  for(int i=1;i<=n;i++) fa[i]=i;
  fa[n+1]=n+1;
  for(int i=1;i<=n;i=find(i+1)) Bfs(i);
  printf("%d\n",ans.size()-1);
  return 0;
}