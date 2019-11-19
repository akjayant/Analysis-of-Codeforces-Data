#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100010
#define M 2000010
int head[N],to[M<<1],nxt[M<<1],idx,nxtt[N],pre[N],ans[N],n,m; bool is[N];
void add(int a,int b) {nxt[++idx]=head[a],to[idx]=b,head[a]=idx;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(int i=0;i<n;i++) nxtt[i]=i+1,pre[i]=i-1; pre[n]=n-1;
	queue <int> q;
	while(nxtt[0])
	{
		q.push(nxtt[0]),ans[0]++;
		int tmp=nxtt[0]=nxtt[nxtt[0]],tmp2; pre[tmp]=0;
		while(!q.empty())
		{
			int p=q.front(); q.pop(),ans[ans[0]]++;
			for(int i=head[p];i;i=nxt[i]) is[to[i]]=true;
			// for(int i=nxtt[0];i;i=nxtt[i]) printf("%d ",i); printf("\n");
			// for(int i=nxtt[0];i;i=nxtt[i]) printf("%d ",pre[i]); printf("\n");
			// for(int i=nxtt[0];i;i=nxtt[i]) printf("%d ",is[i]); printf("\n");
			for(int i=nxtt[0];i;i=nxtt[i]) if(!is[i])
				q.push(i),tmp=pre[i],tmp2=nxtt[i],nxtt[tmp]=tmp2,pre[tmp2]=tmp;
			for(int i=head[p];i;i=nxt[i]) is[to[i]]=false;
		}
	} printf("%d\n",ans[0]-1);
}