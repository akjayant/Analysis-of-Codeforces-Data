#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n,In[N],fa[N],to[N<<1],nxt[N<<1],Col[N],root=1,head[N<<1],col[N],cnt;

long long tmp,a[N][4],ans=0x3f3f3f3f3f3f3f3f;

bool flag;

void add(int x,int y){
	to[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
}

void sol(int u){
	queue<int>que;que.push(u);
	while(!que.empty()){
		int x=que.front();que.pop();
		for(int i=head[x];i;i=nxt[i])
			if(to[i]!=fa[x]){
				que.push(to[i]);fa[to[i]]=x;
				col[to[i]]=col[x]^col[fa[x]]^1^2^3;
				tmp+=a[to[i]][col[to[i]]];
			}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i][1]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i][2]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i][3]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		In[x]++;In[y]++;
	}
	for(int i=1;i<=n;i++){
		if(In[i]>2) {flag=1;break;}
		if(In[i]==1) root=i;
	}
	if(flag) printf("-1\n");
	else {
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				if(i!=j){
					col[root]=i;tmp=a[root][i];
					for(int k=head[root];k;k=nxt[k]){
						col[to[k]]=j;fa[to[k]]=root;
						tmp+=a[to[k]][j];sol(to[k]);
					}
					if(ans>tmp) {
						ans=tmp;
						memcpy(Col,col,sizeof(col));
					}
				}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d ",Col[i]);
	}
	return 0;
}