#include <bits/stdc++.h>
using namespace std;
struct P{
  int w,x,y;
};
bool cmp(P l,P r){
  return l.w<r.w;
}
int pred[100000];
int get(int v){
 if (pred[v]==v) return v;
 return pred[v]=get(pred[v]);
}
int kol[1010][1010];
set<int> st[100010];
queue<int> q;
set<int> color;
int main()
{
 //freopen("bath.in","r",stdin);
 //freopen("bath.out","w",stdout);
 ios_base::sync_with_stdio(0);
 int n,m;
 cin>>n>>m;
 if (n<=1e3){
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    kol[x][y]=1;
    kol[y][x]=1;
  }
  vector<P> edge;
  for(int i=1;i<=n;i++)
   for(int j=i+1;j<=n;j++){
    edge.push_back({kol[i][j],i,j});
    pred[i]=i;
  }
  sort(edge.begin(),edge.end(),cmp);
  int ans=0;
  for(int i=0;i<edge.size();i++){
    int l=get(edge[i].x),r=get(edge[i].y);
    if (l!=r) {
        pred[r]=l;
        ans+=edge[i].w;
    }
  }
  cout<<ans;
  return 0;
 }
 for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    st[x].insert(y);
    st[y].insert(x);
 }
 for(int i=1;i<=n;i++){
    color.insert(i);
 }
 int ans=0;
 for(int i=1;i<=n;i++)if (color.find(i)!=color.end()){
   color.erase(color.find(i));
   q.push(i);
   ans++;

   while(!q.empty()){
     if(color.size()==0) break;
     int cur=q.front();
     q.pop();
     auto it=color.begin();
     while(true){//cout<<i<<endl;
       if (color.size()==0) break;
       if (it==color.end()) break;
       int kol=*it;
       if (st[cur].find(kol)!=st[cur].end()) {it++;continue;}
       it--;
       color.erase(color.find(kol));
       q.push(kol);
       it++;
     }
   }
  if(color.size()==0) break;
 }
 cout<<ans-1;
}



