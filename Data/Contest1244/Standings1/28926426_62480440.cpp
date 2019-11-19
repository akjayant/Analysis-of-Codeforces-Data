#include<bits/stdc++.h>
using namespace std;
long long ans,sum;
int C[234234][5],H[234234],ansH[234234],du[234234];
int wz[234234],rdt[234234],rd[234234];
int n,tot,TOT;

void cnct(int x,int y)
{
  rdt[++tot]=wz[x],wz[x]=tot,rd[tot]=y;
}

void dfs(int x,int from)
{
  int t=wz[x];
  H[++TOT]=x;
  while(t)
    {
	  if(rd[t]!=from)
	    {
		  dfs(rd[t],x);
		}
	  t=rdt[t];
	}
}

int main()
{
  int i,j,t,x,y,k,ty;
  scanf("%d",&n),ans=1000000000000000000LL;
  for(i=1;i<=n;i++) scanf("%d",&C[i][0]);
  for(i=1;i<=n;i++) scanf("%d",&C[i][1]);
  for(i=1;i<=n;i++) scanf("%d",&C[i][2]);
  for(i=1;i<n;i++)
    {
	  scanf("%d%d",&x,&y),cnct(x,y),cnct(y,x);
	  du[x]++,du[y]++;
	  if(du[x]>2 || du[y]>2) {printf("-1");return 0;}
	}
  for(i=1;i<=n;i++)
    {
	  if(du[i]==1) {dfs(i,0);break;} 
	} 
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      {
      	if(i==j) continue;
	    sum=C[H[1]][i]+C[H[2]][j];
	    t=(2*j-i+3)%3;
	    for(k=3;k<=n;k++)
	      {
		    sum+=C[H[k]][t];
		    t=(t+j-i+3)%3;
		  }
		if(sum<ans) ans=sum,ty=i*10+j;
	  }
  printf("%lld\n",ans);
  ansH[H[1]] = (i=ty/10)+1;
  ansH[H[2]] = (j=ty%10)+1;
  t=(2*j-i+3)%3;
  for(k=3;k<=n;k++)
    {
	  ansH[H[k]]=t+1;
	   t=(t+j-i+3)%3;
	}
   for(i=1;i<n;i++) printf("%d ",ansH[i]);
   printf("%d\n",ansH[i]);
} 