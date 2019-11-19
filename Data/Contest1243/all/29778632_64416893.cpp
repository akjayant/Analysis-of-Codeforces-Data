#include<bits/stdc++.h>
using namespace std;
const int maxn= 2e5+10;;
int n, m;
int father[maxn], vis[maxn];
vector<int> rec[maxn], ans;
void init(){
  for(int i=1;i<=100010;i++) father[i]=i;
}
int findfather(int x) {
    if(father[x]==x)return father[x];
    return father[x]=findfather(father[x]);
}
queue<int>q;
int st=1;
void dfs(int x){
 if(x<=10) return ;
 else if(x%2==1) st=1;
 else st=2;
 dfs(x-1);
}
void bfs(int s) {
  while(q.size()) q.pop();
  q.push(s);
  int te=findfather(s+1);
  father[s] = te;
  ans.push_back(st);
  while(q.size()) {
    int x = q.front();
    q.pop();
    for(int i=0;i<rec[x].size();i++){
        vis[rec[x][i]]=x;
    }
    for (int i = findfather(st); i <= n; i = findfather(i + 1)) {
      if (vis[i] != x) {
            father[i] = findfather(i + 1);
             q.push(i);
             ++ans.back();
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  int x,y;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    rec[x].push_back(y);
    rec[y].push_back(x);
  }
  dfs(20);
  for (int i = 1; i <= n; i = findfather(i + 1)) {
        bfs(i);
  }
  printf("%d\n", (int)ans.size()-1);
  return 0;
}
