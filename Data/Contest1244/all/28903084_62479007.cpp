#include<bits/stdc++.h>
#define bclz(x) (__builtin_clz(x))
#define x first
#define y second
#define pb push_back
#define inf 0x3f3f3f3f3f3f3f3fLL

using namespace std;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int,int> pii;

#define NN 1000010
int w[5][NN];
VI adj[NN];
int ans[NN];
int f[NN];
int st[5];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++) scanf("%d",&w[i][j]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		if(adj[i].size()>2){
			flag=1;
			break;
		}
		if(adj[i].size()==1){
			f[1]=i;
		}
	}
	if(flag){
		puts("-1");
		return 0;
	}
	f[2]=adj[f[1]][0];
	for(int i=3;i<=n;i++){
		for(int j=0;j<adj[f[i-1]].size();j++){
			int x=adj[f[i-1]][j];
			if(x!=f[i-2]){
				f[i]=x;
				break;
			}
		}
	}
	INT tot=inf;
	for(int a=1;a<=3;a++){
		for(int b=1;b<=3;b++){
			for(int c=1;c<=3;c++){
				if(a==b||b==c||a==c) continue;
				st[0]=a;
				st[1]=b;
				st[2]=c;
				INT sum=0;
				for(int i=1;i<=n;i++){
					int r=i%3;
					sum+=w[st[r]][f[i]];
				}
				if(sum<tot){
					tot=sum;
					for(int i=1;i<=n;i++){
						int r=i%3;
						ans[f[i]]=st[r];
					}
				}
			}
		}
	}
	printf("%I64d\n",tot);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
                                