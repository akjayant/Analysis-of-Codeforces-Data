#include<bits/stdc++.h>
using namespace std;
struct A{
  int a,b;
  long long c;
  bool operator<(const A&o)const{
    return c<o.c;
  }
};
A d[5000000];
int pa[3000];
int fp(int x){
  if(pa[x]==x)return x;
  return pa[x]=fp(pa[x]);
}
pair<long long,long long>p[3000];
long long c[3000],k[3000];
long long ans=0;
vector<int>ans1;
vector<pair<int,int> >ans2;
int main(){
  int n,i,j,l,x,y;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%I64d%I64d",&p[i].first,&p[i].second);
  }
  for(i=1;i<=n;i++)scanf("%I64d",&c[i]);
  for(i=1;i<=n;i++)scanf("%I64d",&k[i]);
  l=0;
  for(i=1;i<=n;i++){
    for(j=i+1;j<=n;j++){
      d[l].a=i;
      d[l].b=j;
      d[l].c=(k[i]+k[j])*(abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second));
      l++;
    }
  }
  for(i=1;i<=n;i++){
    pa[i]=i;
    d[l].a=0;
    d[l].b=i;
    d[l].c=c[i];
    l++;
  }
  sort(d,d+l);
  for(i=0;i<l;i++){
    x=d[i].a;
    y=d[i].b;
    if(fp(x)==fp(y))continue;
    ans+=d[i].c;
    pa[fp(y)]=fp(x);
    if(x==0){
      ans1.push_back(y);
    }
    else{
      ans2.push_back(make_pair(x,y));
    }
  }
  printf("%I64d\n",ans);
  printf("%d\n",ans1.size());
  for(i=0;i<ans1.size();i++){
      printf("%d ",ans1[i]);
  }
  printf("\n%d\n",ans2.size());
  for(i=0;i<ans2.size();i++)printf("%d %d\n",ans2[i].first,ans2[i].second);
  return 0;
}
