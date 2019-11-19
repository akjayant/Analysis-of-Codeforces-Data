#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
vector<int>v[100005],vv[100005];
int main() {
  ll n,m,k;
  scanf("%lld%lld%lld",&n,&m,&k);
  for(int i=1;i<=n;i++){
    v[i].push_back(0);
    v[i].push_back(m+1);
  }
  for(int i=1;i<=m;i++){
    vv[i].push_back(0);
    vv[i].push_back(n+1);
  }
  ll ans=1;
  for(int i=0;i<k;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    v[x].push_back(y);
    vv[y].push_back(x);
  }
  for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
  for(int i=1;i<=m;i++) sort(vv[i].begin(),vv[i].end());
  int tmp=1,x=1,y=1;
  int maxx=0,minn=n+1,maxxx=0,minnn=m+1;
  int f=0;
  while(1){
    //cout<<tmp<<" "<<x<<" "<<y<<endl;
    if(tmp==1){
      int in=upper_bound(v[x].begin(),v[x].end(),y)-v[x].begin();
      ll xx=min(minnn,v[x][in])-y-1;
      //cout<<xx<<endl;
      if(f==0){
        f=1;
      }
      else {
        if(xx==0) break;
      }
      ans+=xx;
      tmp++;
      y=min(minnn,v[x][in])-1;
      maxx=max(maxx,x);
    }
    else if(tmp==2){
      int in=upper_bound(vv[y].begin(),vv[y].end(),x)-vv[y].begin();
      ll xx=min(minn,vv[y][in])-x-1;
      //cout<<xx<<endl;
      if(xx==0){
        break;
      }
      ans+=xx;
      tmp++;
      x=min(minn,vv[y][in])-1;
      minnn=min(minnn,y);
    }
    else if(tmp==3){
      int in=upper_bound(v[x].begin(),v[x].end(),y)-v[x].begin()-1;
      ll xx=y-max(maxxx,v[x][in])-1;
      if(xx==0){
        break;
      }
      ans+=xx;
      tmp++;
      y=max(maxxx,v[x][in])+1;
      minn=min(minn,x);
    }
    else {
      int in=upper_bound(vv[y].begin(),vv[y].end(),x)-vv[y].begin()-1;
      ll xx=x-max(maxx,vv[y][in])-1;
      if(xx==0) {
        break;
      }
      ans+=xx;
      tmp=1;
      x=max(maxx,vv[y][in])+1;
      maxxx=max(maxxx,y);
    }
  }
  if(ans==n*m-k) printf("Yes");
  else printf("No");
  //cout<<ans<<endl;
  return 0;
}
