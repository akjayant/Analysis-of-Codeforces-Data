#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<string.h>
#include<set>
#include<map>
#include<stdlib.h>
#define LL long long
#define pr pair<int,int>
#define fr first
#define sc second
#define mp make_pair
using namespace std;
LL read( ){LL sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) return -sum;return sum;}
void read(int &sum){sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) sum=-sum;}
void read(LL &sum){sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) sum=-sum;}
const int N=100005;
vector<int>S[N];
int n,col[N];
LL C[N][4];
void fail( )
{
  puts("-1");
  exit(0);
}
bool ED[4];
void DFS(int x,int f,int h1,int h2)
{
  ED[1]=ED[2]=ED[3]=0;
  ED[h1]=1;ED[h2]=1;
  int i,j;
  for(i=1;i<=3;i++) if(!ED[i]) {col[x]=i;break;}
  if(!col[x]) fail( );
  for(auto &y:S[x])
    {
      if(y==f) continue;
      DFS(y,x,col[x],h1);
      if(!h1) h1=col[y];
    }
}
const LL INF=(1LL<<60);
LL ans=INF;
int sx[4],ax[N];
void check( )
{
  LL res=0;
  for(int i=1;i<=n;i++)
    res+=C[i][sx[col[i]]];
  if(res<ans)
    {
      ans=res;
      for(int i=1;i<=n;i++)
	ax[i]=sx[col[i]];
    } 
}
void dfs(int k)
{
  if(k==4) {check( );return;}
  for(int i=1;i<=3;i++)
    if(!ED[i]) {sx[k]=i;ED[i]=1;dfs(k+1);ED[i]=0;}
}
int main( )
{
  int i,j,x,y;
  read(n);
  for(j=1;j<=3;j++)
    for(i=1;i<=n;i++)
      read(C[i][j]);
  for(i=1;i<n;i++)
    {
      read(x);read(y);
      S[x].push_back(y);
      S[y].push_back(x);
    }
  for(i=1;i<=n;i++)
    if(S[i].size( )>=3) fail( );
  DFS(1,0,0,0);
  ED[1]=ED[2]=ED[3]=0;
  dfs(1);
  cout<<ans<<endl;
  for(i=1;i<=n;i++)
    printf("%d ",ax[i]);
  return 0;
}
