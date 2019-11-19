#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int maxn=2000+5;
LL x[maxn],y[maxn],c[maxn],k[maxn];
int fa[maxn],n;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
vector<int> a1;
vector<pair<int,int> >a2;
struct edge{
  int a,b;LL len;
  edge(int a=0,int b=0,LL len=0):a(a),b(b),len(len){}
  bool operator<(edge rhs)const{return len<rhs.len;}
};
vector<edge> e;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
  for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
  for(int i=1;i<=n;i++)scanf("%lld",&k[i]);
  for(int i=1;i<=n+1;i++)fa[i]=i;
  for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++){
      LL d=abs(x[i]-x[j])+abs(y[i]-y[j]);
      e.push_back(edge(i,j,(k[i]+k[j])*d));
  }
  for(int i=1;i<=n;i++)
    e.push_back(edge(i,n+1,c[i]));
  sort(e.begin(),e.end());
  LL ans=0;
  for(int k=0,cnt=0;k<e.size()&&cnt<n;k++){
    int fx=find(e[k].a),fy=find(e[k].b);
    if(fx!=fy){
      fa[fx]=fy,ans+=e[k].len,cnt++;
      if(e[k].b==n+1)a1.push_back(e[k].a);
      else a2.push_back(make_pair(e[k].a,e[k].b));
    }
  }
  printf("%lld\n",ans);
  printf("%d\n",a1.size());
  for(int i=0;i<a1.size();i++)
    printf("%d ",a1[i]);
  printf("\n%d\n",a2.size());
  for(int i=0;i<a2.size();i++)
    printf("%d %d\n",a2[i].first,a2[i].second);
  return 0;
}