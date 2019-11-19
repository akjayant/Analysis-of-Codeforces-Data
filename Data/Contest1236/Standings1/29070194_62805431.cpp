#include<bits/stdc++.h>
#define ll long long
#define N 100010
#define iter set<int>::iterator
using namespace std;
int n,m,k,LL,RR,UU,DD;ll res;
set<int>L[N],H[N];
int main()
{
  int x,y,pos,tag=0;iter it;
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=n;i++)
    L[i].insert(0),L[i].insert(m+1);
  for(int i=1;i<=m;i++)
    H[i].insert(0),H[i].insert(n+1);
  for(int i=1;i<=k;i++)
  {
    scanf("%d%d",&x,&y);
	L[x].insert(y);H[y].insert(x);
  }
  res=1ll*n*m-k-1;x=1;y=1;
  LL=0;RR=m+1;UU=1;DD=n+1;
  while(1)
  {
  	//cout<<x<<"---"<<y<<' '<<res<<endl;
    it=L[x].lower_bound(y);
    while((*it)<y)++it;
    pos=min((*it)-1,RR-1);
    if(y==pos&&tag)break;tag=1;
    res-=pos-y;y=pos;
	RR=pos;
    //(x,y+1)
    //cout<<x<<"---"<<y<<' '<<res<<endl;
    it=H[y].lower_bound(x);
    while((*it)<x)++it;
    pos=min((*it)-1,DD-1);
    if(x==pos)break;
    res-=pos-x;x=pos;
    DD=pos;
    //(x+1,y)
    //cout<<x<<"---"<<y<<' '<<res<<endl;
	it=L[x].lower_bound(y);
    while((*it)>y)--it;
    pos=max((*it)+1,LL+1);
    if(y==pos)break;
    res-=y-pos;y=pos;
	LL=pos;
	//(x,y-1)
	//cout<<x<<"---"<<y<<' '<<res<<endl;
	it=H[y].lower_bound(x);
    while((*it)>x)--it;
    pos=max((*it)+1,UU+1);
    if(x==pos)break;
    res-=x-pos;x=pos;
    UU=pos;
    //(x-1,y)
  }
  //cout<<res<<"+++"<<endl;
  if(res>0)printf("No\n");
  else printf("Yes\n");
  return 0;
}