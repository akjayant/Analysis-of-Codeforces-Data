#include<bits/stdc++.h>
using namespace std;
const int boss=2e5+10;
map<int,bool> lj[boss];
bitset<boss> b;
int n,m,k,ans[boss];
void dfs(int u)
{
b[u]=0,ans[k]++;
for (int i=b._Find_first();i<b.size();i=b._Find_next(i)) if (!lj[u][i]) dfs(i);
}
int main()
{
int i;
scanf("%d%d",&n,&m);
for (i=1;i<=n;i++) b[i]=1;
for (i=1;i<=m;i++) 
  {
  int u,v;
  scanf("%d%d",&u,&v);
  lj[u][v]=lj[v][u]=1;
  }
for (i=1;i<=n;i++) if (b[i]) dfs(i),++k;
printf("%d\n",k-1);
// for (i=0;i<k;i++) printf("%d ",ans[i]);
}
