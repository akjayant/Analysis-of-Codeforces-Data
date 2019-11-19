#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> nei[1000005];

bool lgl[1000005];
int stk[1000005],stktop;
int dfn[1000005],low[1000005],tmc;
vector<int> blk[1000005];
int bl2[1000005];
int cnt;
int deg[1000005];

void tarjan(int now){
	stk[stktop++]=now;
	dfn[now]=low[now]=++tmc;
	lgl[now]=1;
	for(int i=0;i<nei[now].size();i++){
		int to=nei[now][i];
		if(!dfn[to]){
			tarjan(to);
			low[now]=min(low[now],low[to]);
		}else if(lgl[to]){
			low[now]=min(low[now],dfn[to]);
		}
	}
	if(low[now]==dfn[now]){
		cnt++;
		int cur;
		do{
			cur=stk[--stktop];
			blk[cnt].push_back(cur);
			bl2[cur]=cnt;
			lgl[cur]=0;
		}while(cur!=now);
	}
}

void clean(){
	for(int i=1;i<=n;i++){
		nei[i].clear();
		lgl[i]=0;
		dfn[i]=0;
	}
	for(int i=1;i<=cnt;i++){
		blk[i].clear();
		deg[i]=0;
	}
	cnt=0;
	tmc=0;
	stktop=0;
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b){
			continue;
		}
		nei[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	if(cnt==1){
		clean();
		puts("No");
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<nei[i].size();j++){
			if(bl2[i]!=bl2[nei[i][j]]){
				deg[bl2[i]]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(!deg[i]){
			puts("Yes");
			printf("%d %d\n",(int)blk[i].size(),n-(int)blk[i].size());
			for(int j=0;j<blk[i].size();j++){
				printf("%d ",blk[i][j]);
			}
			puts("");
			for(int j=1;j<=n;j++){
				if(bl2[j]!=i){
					printf("%d ",j);
				}
			}
			puts("");
			clean();
			return;
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}